﻿/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


/// @file
///     @author Don Gagne <don@thegagnes.com>

#include "MissionManager.h"
#include "Vehicle.h"
#include "FirmwarePlugin.h"
#include "MAVLinkProtocol.h"
#include "QGCApplication.h"
#include "SimpleMissionItem.h"

QGC_LOGGING_CATEGORY(MissionManagerLog, "MissionManagerLog")

MissionManager::MissionManager(Vehicle* vehicle)
    : _vehicle(vehicle)
    , _dedicatedLink(NULL)
    , _ackTimeoutTimer(NULL)
    , _expectedAck(AckNone)
    , _readTransactionInProgress(false)
    , _writeTransactionInProgress(false)
    , _currentMissionItem(-1)
{
    connect(_vehicle, &Vehicle::mavlinkMessageReceived, this, &MissionManager::_mavlinkMessageReceived);
    connect(_vehicle, &Vehicle::mavlinkCameraFeedBack,  this, &MissionManager::_mavlinkMessageCameraFeed);

    _ackTimeoutTimer = new QTimer(this);
    _ackTimeoutTimer->setSingleShot(true);
    _ackTimeoutTimer->setInterval(_ackTimeoutMilliseconds);

    connect(_ackTimeoutTimer, &QTimer::timeout, this, &MissionManager::_ackTimeout);
}

MissionManager::~MissionManager()
{

}

void MissionManager::writeMissionItems(const QList<MissionItem*>& missionItems)
{
    if (_vehicle->isOfflineEditingVehicle()) {
        return;
    }

    if (inProgress()) {
        //qCDebug(MissionManagerLog) << "writeMissionItems called while transaction in progress";
        return;
    }

    bool skipFirstItem = !_vehicle->firmwarePlugin()->sendHomePositionToVehicle();

    _missionItems.clear();

    int firstIndex = skipFirstItem ? 1 : 0;

    for (int i=firstIndex; i<missionItems.count(); i++) {
        MissionItem* item = new MissionItem(*missionItems[i]);
        _missionItems.append(item);

        item->setIsCurrentItem(i == firstIndex);

        if (skipFirstItem) {
            // Home is in sequence 0, remainder of items start at sequence 1
            item->setSequenceNumber(item->sequenceNumber() - 1);
            if (item->command() == MAV_CMD_DO_JUMP) {
                item->setParam1((int)item->param1() - 1);
            }
        }
    }
    emit newMissionItemsAvailable();

    //qCDebug(MissionManagerLog) << "writeMissionItems count:" << _missionItems.count();

    // Prime write list
    for (int i=0; i<_missionItems.count(); i++) {
        _itemIndicesToWrite << i;
    }

    _writeTransactionInProgress = true;
    _retryCount = 0;
    emit inProgressChanged(true);
    _writeMissionCount();
}

/// This begins the write sequence with the vehicle. This may be called during a retry.
void MissionManager::_writeMissionCount(void)
{
    qCDebug(MissionManagerLog) << "_writeMissionCount retry count" << _retryCount;

    mavlink_message_t       message;
    mavlink_mission_count_t missionCount;

    missionCount.target_system = _vehicle->id();
    missionCount.target_component = MAV_COMP_ID_MISSIONPLANNER;
    missionCount.count = _missionItems.count();

    _dedicatedLink = _vehicle->priorityLink();
    mavlink_msg_mission_count_encode_chan(qgcApp()->toolbox()->mavlinkProtocol()->getSystemId(),
                                          qgcApp()->toolbox()->mavlinkProtocol()->getComponentId(),
                                          _dedicatedLink->mavlinkChannel(),
                                          &message,
                                          &missionCount);

    _vehicle->sendMessageOnLink(_dedicatedLink, message);
    _startAckTimeout(AckMissionRequest);
}

void MissionManager::writeArduPilotGuidedMissionItem(const QGeoCoordinate& gotoCoord, bool altChangeOnly)
{
    if (inProgress()) {
        qCDebug(MissionManagerLog) << "writeArduPilotGuidedMissionItem called while transaction in progress";
        return;
    }

    _writeTransactionInProgress = true;

    mavlink_message_t       messageOut;
    mavlink_mission_item_t  missionItem;

    missionItem.target_system =     _vehicle->id();
    missionItem.target_component =  _vehicle->defaultComponentId();
    missionItem.seq =               0;
    missionItem.command =           MAV_CMD_NAV_WAYPOINT;
    missionItem.param1 =            0;
    missionItem.param2 =            0;
    missionItem.param3 =            0;
    missionItem.param4 =            0;
    missionItem.x =                 gotoCoord.latitude();
    missionItem.y =                 gotoCoord.longitude();
    missionItem.z =                 gotoCoord.altitude();
    missionItem.frame =             MAV_FRAME_GLOBAL_RELATIVE_ALT;
    missionItem.current =           altChangeOnly ? 3 : 2;
    missionItem.autocontinue =      true;

    _dedicatedLink = _vehicle->priorityLink();
    mavlink_msg_mission_item_encode_chan(qgcApp()->toolbox()->mavlinkProtocol()->getSystemId(),
                                         qgcApp()->toolbox()->mavlinkProtocol()->getComponentId(),
                                         _dedicatedLink->mavlinkChannel(),
                                         &messageOut,
                                         &missionItem);

    _vehicle->sendMessageOnLink(_dedicatedLink, messageOut);
    _startAckTimeout(AckGuidedItem);
    emit inProgressChanged(true);
}

void MissionManager::requestMissionItems(void)
{
    if (_vehicle->isOfflineEditingVehicle()) {
        return;
    }

    qCDebug(MissionManagerLog) << "requestMissionItems read sequence";

    if (inProgress()) {
        qCDebug(MissionManagerLog) << "requestMissionItems called while transaction in progress";
        return;
    }

    _retryCount = 0;
    _readTransactionInProgress = true;
    emit inProgressChanged(true);
    _requestList();
}

/// Internal call to request list of mission items. May be called during a retry sequence.
void MissionManager::_requestList(void)
{
    qCDebug(MissionManagerLog) << "_requestList retry count" << _retryCount;

    mavlink_message_t               message;
    mavlink_mission_request_list_t  request;

    _itemIndicesToRead.clear();
    _readTransactionInProgress = true;
    _clearMissionItems();

    request.target_system = _vehicle->id();
    request.target_component = MAV_COMP_ID_MISSIONPLANNER;

    _dedicatedLink = _vehicle->priorityLink();
    mavlink_msg_mission_request_list_encode_chan(qgcApp()->toolbox()->mavlinkProtocol()->getSystemId(),
                                                 qgcApp()->toolbox()->mavlinkProtocol()->getComponentId(),
                                                 _dedicatedLink->mavlinkChannel(),
                                                 &message,
                                                 &request);

    _vehicle->sendMessageOnLink(_dedicatedLink, message);
    _startAckTimeout(AckMissionCount);
}

void MissionManager::_ackTimeout(void)
{
    if (_expectedAck == AckNone) {
        return;
    }

    switch (_expectedAck) {
    case AckNone:
        qCWarning(MissionManagerLog) << "_ackTimeout timeout with AckNone";
        _sendError(InternalError, tr("Internal error occurred during Mission Item communication: _ackTimeOut:_expectedAck == AckNone"));
        break;
    case AckMissionCount:
        // MISSION_COUNT message expected
        if (_retryCount > _maxRetryCount) {
            _sendError(VehicleError, QString(tr("Mission request list failed, maximum retries exceeded.")));
            _finishTransaction(false);
        } else {
            _retryCount++;
            qCDebug(MissionManagerLog) << "Retrying REQUEST_LIST retry Count" << _retryCount;
            _requestList();
        }
        break;
    case AckMissionItem:
        // MISSION_ITEM expected
        if (_retryCount > _maxRetryCount) {
            _sendError(VehicleError, QString(tr("Mission read failed, maximum retries exceeded.")));
            _finishTransaction(false);
        } else {
            _retryCount++;
            qCDebug(MissionManagerLog) << "Retrying MISSION_REQUEST retry Count" << _retryCount;
            _requestNextMissionItem();
        }
        break;
    case AckMissionRequest:
        // MISSION_REQUEST is expected, or MISSION_ACK to end sequence
        if (_itemIndicesToWrite.count() == 0) {
            // Vehicle did not send final MISSION_ACK at end of sequence
            _sendError(VehicleError, QString(tr("Mission write failed, vehicle failed to send final ack.")));
            _finishTransaction(false);
        } else if (_itemIndicesToWrite[0] == 0) {
            // Vehicle did not respond to MISSION_COUNT, try again
            if (_retryCount > _maxRetryCount) {
                _sendError(VehicleError, QString(tr("Mission write mission count failed, maximum retries exceeded.")));
                _finishTransaction(false);
            } else {
                _retryCount++;
                qCDebug(MissionManagerLog) << "Retrying MISSION_COUNT retry Count" << _retryCount;
                _writeMissionCount();
            }
        } else {
            // Vehicle did not request all items from ground station
            _sendError(AckTimeoutError, QString(tr("Vehicle did not request all items from ground station: %1")).arg(_ackTypeToString(_expectedAck)));
            _expectedAck = AckNone;
            _finishTransaction(false);
        }
        break;
    case AckGuidedItem:
        // MISSION_REQUEST is expected, or MISSION_ACK to end sequence
    default:
        _sendError(AckTimeoutError, QString(tr("Vehicle did not respond to mission item communication: %1")).arg(_ackTypeToString(_expectedAck)));
        _expectedAck = AckNone;
        _finishTransaction(false);
    }
}

void MissionManager::_startAckTimeout(AckType_t ack)
{
    _expectedAck = ack;
    _ackTimeoutTimer->start();
}

/// Checks the received ack against the expected ack. If they match the ack timeout timer will be stopped.
/// @return true: received ack matches expected ack
bool MissionManager::_checkForExpectedAck(AckType_t receivedAck)
{
    if (receivedAck == _expectedAck) {
        _expectedAck = AckNone;
        _ackTimeoutTimer->stop();
        return true;
    } else {
        if (_expectedAck == AckNone) {
            // Don't worry about unexpected mission commands, just ignore them; ArduPilot updates home position using
            // spurious MISSION_ITEMs.
        } else {
            // We just warn in this case, this could be crap left over from a previous transaction or the vehicle going bonkers.
            // Whatever it is we let the ack timeout handle any error output to the user.
            qCDebug(MissionManagerLog) << QString("Out of sequence ack expected:received %1:%2").arg(_ackTypeToString(_expectedAck)).arg(_ackTypeToString(receivedAck));
        }
        return false;
    }
}

void MissionManager::_readTransactionComplete(void)
{
    qCDebug(MissionManagerLog) << "_readTransactionComplete read sequence complete";

    mavlink_message_t       message;
    mavlink_mission_ack_t   missionAck;

    missionAck.target_system =      _vehicle->id();
    missionAck.target_component =   MAV_COMP_ID_MISSIONPLANNER;
    missionAck.type =               MAV_MISSION_ACCEPTED;

    mavlink_msg_mission_ack_encode_chan(qgcApp()->toolbox()->mavlinkProtocol()->getSystemId(),
                                        qgcApp()->toolbox()->mavlinkProtocol()->getComponentId(),
                                        _dedicatedLink->mavlinkChannel(),
                                        &message,
                                        &missionAck);

    _vehicle->sendMessageOnLink(_dedicatedLink, message);

    _finishTransaction(true);
    emit newMissionItemsAvailable();
}

void MissionManager::_handleMissionCount(const mavlink_message_t& message)
{
    mavlink_mission_count_t missionCount;

    if (!_checkForExpectedAck(AckMissionCount)) {
        return;
    }

    _retryCount = 0;

    mavlink_msg_mission_count_decode(&message, &missionCount);
    qCDebug(MissionManagerLog) << "_handleMissionCount count:" << missionCount.count;

    if (missionCount.count == 0) {
        _readTransactionComplete();
    } else {
        // Prime read list
        for (int i=0; i<missionCount.count; i++) {
            _itemIndicesToRead << i;
        }
        _requestNextMissionItem();
    }
}

void MissionManager::_requestNextMissionItem(void)
{
    if (_itemIndicesToRead.count() == 0) {
        _sendError(InternalError, "Internal Error: Call to Vehicle _requestNextMissionItem with no more indices to read");
        return;
    }

    qCDebug(MissionManagerLog) << "_requestNextMissionItem sequenceNumber:retry" << _itemIndicesToRead[0] << _retryCount;

    mavlink_message_t           message;
    mavlink_mission_request_t   missionRequest;

    missionRequest.target_system =      _vehicle->id();
    missionRequest.target_component =   MAV_COMP_ID_MISSIONPLANNER;
    missionRequest.seq =                _itemIndicesToRead[0];

    mavlink_msg_mission_request_encode_chan(qgcApp()->toolbox()->mavlinkProtocol()->getSystemId(),
                                            qgcApp()->toolbox()->mavlinkProtocol()->getComponentId(),
                                            _dedicatedLink->mavlinkChannel(),
                                            &message,
                                            &missionRequest);

    _vehicle->sendMessageOnLink(_dedicatedLink, message);
    _startAckTimeout(AckMissionItem);
}

void MissionManager::_handleMissionItem(const mavlink_message_t& message)
{
    mavlink_mission_item_t missionItem;
    //edit by wang.lichen
    double xx;
    double yy;

    if (!_checkForExpectedAck(AckMissionItem)) {
        return;
    }

    mavlink_msg_mission_item_decode(&message, &missionItem);

    qCDebug(MissionManagerLog) << "_handleMissionItem sequenceNumber:" << missionItem.seq;

    if (_itemIndicesToRead.contains(missionItem.seq)) {
        _itemIndicesToRead.removeOne(missionItem.seq);
        //edit by wang.lichen ============================
        int mm;
        memcpy(&mm,&missionItem.x,4);
        xx = (double)((double)mm/10000000.0);
        memcpy(&mm,&missionItem.y,4);
        yy = (double)((double)mm/10000000.0);
          //=====================
        MissionItem* item = new MissionItem(missionItem.seq,
                                            (MAV_CMD)missionItem.command,
                                            (MAV_FRAME)missionItem.frame,
                                            missionItem.param1,
                                            missionItem.param2,
                                            missionItem.param3,
                                            missionItem.param4,
                                            //edit by wang.lichen
                                            xx,
                                            yy,
                                            missionItem.z,
                                            missionItem.autocontinue,
                                            missionItem.current,
                                            this);

        if (item->command() == MAV_CMD_DO_JUMP && !_vehicle->firmwarePlugin()->sendHomePositionToVehicle()) {
            // Home is in position 0
            item->setParam1((int)item->param1() + 1);
        }

        _missionItems.append(item);
    } else {
        qCDebug(MissionManagerLog) << "_handleMissionItem mission item received item index which was not requested, disregrarding:" << missionItem.seq;
        // We have to put the ack timeout back since it was removed above
        _startAckTimeout(AckMissionItem);
        return;
    }

    _retryCount = 0;
    if (_itemIndicesToRead.count() == 0) {
        _readTransactionComplete();
    } else {
        _requestNextMissionItem();
    }
}

void MissionManager::_clearMissionItems(void)
{
    _itemIndicesToRead.clear();
    _missionItems.clear();
}

void MissionManager::_handleMissionRequest(const mavlink_message_t& message)
{
    mavlink_mission_request_t missionRequest;

    if (!_checkForExpectedAck(AckMissionRequest)) {
        return;
    }

    mavlink_msg_mission_request_decode(&message, &missionRequest);

    qCDebug(MissionManagerLog) << "_handleMissionRequest sequenceNumber:" << missionRequest.seq;

    if (!_itemIndicesToWrite.contains(missionRequest.seq)) {
        if (missionRequest.seq > _missionItems.count()) {
            _sendError(RequestRangeError, QString(tr("Vehicle requested item outside range, count:request %1:%2. Send to Vehicle failed.")).arg(_missionItems.count()).arg(missionRequest.seq));
            _finishTransaction(false);
            return;
        } else {
            qCDebug(MissionManagerLog) << "_handleMissionRequest sequence number requested which has already been sent, sending again:" << missionRequest.seq;
        }
    } else {
        _itemIndicesToWrite.removeOne(missionRequest.seq);
    }

    mavlink_message_t       messageOut;
    mavlink_mission_item_t  missionItem;

    MissionItem* item = _missionItems[missionRequest.seq];

    missionItem.target_system =     _vehicle->id();
    missionItem.target_component =  MAV_COMP_ID_MISSIONPLANNER;
    missionItem.seq =               missionRequest.seq;
    missionItem.command =           item->command();
    missionItem.param1 =            item->param1();
    missionItem.param2 =            item->param2();
    missionItem.param3 =            item->param3();
    missionItem.param4 =            item->param4();
    missionItem.x =                 item->param5();
    missionItem.y =                 item->param6();
    missionItem.z =                 item->param7();
    //edit by wang.lichen
    missionItem.frame =             item->frame()+100;
    missionItem.current =           missionRequest.seq == 0;
    missionItem.autocontinue =      item->autoContinue();
    //edit by wang.lichen =============================
    missionItem.command = item->command()+200;
    int tmp;
    tmp = item->param5()*10000000;
    memcpy(&missionItem.x,&tmp,sizeof(tmp));
    tmp = item->param6()*10000000;
    memcpy(&missionItem.y,&tmp,sizeof(tmp));
    //===================================================
    mavlink_msg_mission_item_encode_chan(qgcApp()->toolbox()->mavlinkProtocol()->getSystemId(),
                                         qgcApp()->toolbox()->mavlinkProtocol()->getComponentId(),
                                         _dedicatedLink->mavlinkChannel(),
                                         &messageOut,
                                         &missionItem);

    _vehicle->sendMessageOnLink(_dedicatedLink, messageOut);
    _startAckTimeout(AckMissionRequest);
}

void MissionManager::_handleMissionAck(const mavlink_message_t& message)
{
    mavlink_mission_ack_t missionAck;

    // Save the retry ack before calling _checkForExpectedAck since we'll need it to determine what
    // type of a protocol sequence we are in.
    AckType_t savedExpectedAck = _expectedAck;

    // We can get a MISSION_ACK with an error at any time, so if the Acks don't match it is not
    // a protocol sequence error. Call _checkForExpectedAck with _retryAck so it will succeed no
    // matter what.
    if (!_checkForExpectedAck(_expectedAck)) {
        return;
    }

    mavlink_msg_mission_ack_decode(&message, &missionAck);

    qCDebug(MissionManagerLog) << "_handleMissionAck type:" << _missionResultToString((MAV_MISSION_RESULT)missionAck.type);

    switch (savedExpectedAck) {
        case AckNone:
            // State machine is idle. Vehicle is confused.
            _sendError(VehicleError, QString(tr("Vehicle sent unexpected MISSION_ACK message, error: %1")).arg(_missionResultToString((MAV_MISSION_RESULT)missionAck.type)));
            break;
        case AckMissionCount:
            // MISSION_COUNT message expected
            _sendError(VehicleError, QString(tr("Vehicle returned error: %1.")).arg(_missionResultToString((MAV_MISSION_RESULT)missionAck.type)));
            _finishTransaction(false);
            break;
        case AckMissionItem:
            // MISSION_ITEM expected
            _sendError(VehicleError, QString(tr("Vehicle returned error: %1. Partial list of mission items may have been returned.")).arg(_missionResultToString((MAV_MISSION_RESULT)missionAck.type)));
            _finishTransaction(false);
            break;
        case AckMissionRequest:
            // MISSION_REQUEST is expected, or MISSION_ACK to end sequence
            if (missionAck.type == MAV_MISSION_ACCEPTED) {
                if (_itemIndicesToWrite.count() == 0) {
                    qCDebug(MissionManagerLog) << "_handleMissionAck write sequence complete";
                    _finishTransaction(true);
                } else {
                    _sendError(MissingRequestsError, QString(tr("Vehicle did not request all items during write sequence, missed count %1. Vehicle only has partial list of mission items.")).arg(_itemIndicesToWrite.count()));
                    _finishTransaction(false);
                }
            } else {
                _sendError(VehicleError, QString(tr("Vehicle returned error: %1. Vehicle only has partial list of mission items.")).arg(_missionResultToString((MAV_MISSION_RESULT)missionAck.type)));
                _finishTransaction(false);
            }
            break;
        case AckGuidedItem:
            // MISSION_REQUEST is expected, or MISSION_ACK to end sequence
            if (missionAck.type == MAV_MISSION_ACCEPTED) {
                qCDebug(MissionManagerLog) << "_handleMissionAck guided mode item accepted";
                _finishTransaction(true);
            } else {
                _sendError(VehicleError, QString(tr("Vehicle returned error: %1. Vehicle did not accept guided item.")).arg(_missionResultToString((MAV_MISSION_RESULT)missionAck.type)));
                _finishTransaction(false);
            }
            break;
    }
}

/// Called when a new mavlink message for out vehicle is received
void MissionManager::_mavlinkMessageReceived(const mavlink_message_t& message)
{
    switch (message.msgid) {
        case MAVLINK_MSG_ID_MISSION_COUNT:
            _handleMissionCount(message);
            break;

        case MAVLINK_MSG_ID_MISSION_ITEM:
        mavlink_mission_item_t missionflag;
        mavlink_msg_mission_item_decode(&message, &missionflag);
        if(missionflag.param1==100001||missionflag.param1==100002||missionflag.param1==100003||missionflag.param1==100004||missionflag.frame >=200)
        {
            if(missionflag.param1==100004){
                int mm;
                memcpy(&mm,& missionflag.x,4);
                double latitude = (double)((double)mm/10000000.0);
                memcpy(&mm,& missionflag.y,4);
                double longtitude = (double)((double)mm/10000000.0);
                qDebug()<<__FILE__<<" : "<<__LINE__<<" : lat : "<<latitude<<" : lng : "<<longtitude;
                emit missionItemsTempChanged(latitude, longtitude, 0);
            }else if(missionflag.param1==100001||missionflag.param1==100002||missionflag.param1==100003){
                _missionItemsflag.clear();
                int mm;
                memcpy(&mm,& missionflag.x,4);
                double xxx = (double)((double)mm/10000000.0);
                memcpy(&mm,& missionflag.y,4);
                double yyy = (double)((double)mm/10000000.0);
                MissionItem* item = new MissionItem(missionflag.seq,
                                                    (MAV_CMD)missionflag.command,
                                                    (MAV_FRAME)missionflag.frame,
                                                    missionflag.param1,
                                                    missionflag.param2,
                                                    missionflag.param3,
                                                    missionflag.param4,
                                                    xxx,
                                                    yyy,
                                                    missionflag.z,
                                                    missionflag.autocontinue,
                                                    missionflag.current,
                                                    this);
                _missionItemsflag.append(item);
            }else{
                qDebug()<<"receive from vehicle, the frame is :"<<missionflag.frame;
                emit missionItemReceived(true);
            }
        }else {
            _handleMissionItem(message);
        }
            break;

        case MAVLINK_MSG_ID_MISSION_REQUEST:
            _handleMissionRequest(message);
            break;

        case MAVLINK_MSG_ID_MISSION_ACK:
            _handleMissionAck(message);
            break;

        case MAVLINK_MSG_ID_MISSION_ITEM_REACHED:
            // FIXME: NYI
            break;

        case MAVLINK_MSG_ID_MISSION_CURRENT:
            _handleMissionCurrent(message);
            break;
    }
}
    /// Called when a new mavlink camera feedback message for out vehicle is received
void MissionManager::_mavlinkMessageCameraFeed(const mavlink_message_t& message)
{
    if(message.msgid != MAVLINK_MSG_ID_CAMERA_FEEDBACK){
        return ;
    }
    static int camera_feedback_count = 0;
    mavlink_camera_feedback_t camera_feedback;
    mavlink_msg_camera_feedback_decode(&message, &camera_feedback);
    printf("%d, lat : %d, lat : %lf, lng : %lf\n", camera_feedback_count++, camera_feedback.lat, camera_feedback.lat/double(1E7), camera_feedback.lng/double(1E7));
    if(_vehicle){
        int sequenceNumber = 0;
        QGeoCoordinate coordinate(camera_feedback.lat/double(1E7), camera_feedback.lng/double(1E7), camera_feedback.lat/double(1E7));
        SimpleMissionItem  newItem(_vehicle, this);
        newItem.setCoordinate(coordinate);
        newItem.setCommand(MavlinkQmlSingleton::MAV_CMD_NAV_WAYPOINT);
        if (_cameraFeedbackItems.size() != 0) {
                sequenceNumber = _cameraFeedbackItems.size();
        }
        newItem.setSequenceNumber(sequenceNumber);
        newItem.setDefaultsForCommand();
        _cameraFeedbackItems.append (newItem.missionItem ());
        if(_vehicle->active ()){
            emit cameraFeedItemsChanged (sequenceNumber);
        }
    }
}

void MissionManager::_sendError(ErrorCode_t errorCode, const QString& errorMsg)
{
    qCDebug(MissionManagerLog) << "Sending error" << errorCode << errorMsg;

    emit error(errorCode, errorMsg);
}

QString MissionManager::_ackTypeToString(AckType_t ackType)
{
    switch (ackType) {
        case AckNone:
            return QString(tr("No Ack"));
        case AckMissionCount:
            return QString(tr("MISSION_COUNT"));
        case AckMissionItem:
            return QString(tr("MISSION_ITEM"));
        case AckMissionRequest:
            return QString(tr("MISSION_REQUEST"));
        case AckGuidedItem:
            return QString(tr("Guided Mode Item"));
        default:
            qWarning(MissionManagerLog) << "Fell off end of switch statement";
            return QString(tr("QGC Internal Error"));
    }
}

QString MissionManager::_missionResultToString(MAV_MISSION_RESULT result)
{
    switch (result) {
        case MAV_MISSION_ACCEPTED:
            return QString(tr("Mission accepted (MAV_MISSION_ACCEPTED)"));
            break;
        case MAV_MISSION_ERROR:
            return QString(tr("Unspecified error (MAV_MISSION_ERROR)"));
            break;
        case MAV_MISSION_UNSUPPORTED_FRAME:
            return QString(tr("Coordinate frame is not supported (MAV_MISSION_UNSUPPORTED_FRAME)"));
            break;
        case MAV_MISSION_UNSUPPORTED:
            return QString(tr("Command is not supported (MAV_MISSION_UNSUPPORTED)"));
            break;
        case MAV_MISSION_NO_SPACE:
            return QString(tr("Mission item exceeds storage space (MAV_MISSION_NO_SPACE)"));
            break;
        case MAV_MISSION_INVALID:
            return QString(tr("One of the parameters has an invalid value (MAV_MISSION_INVALID)"));
            break;
        case MAV_MISSION_INVALID_PARAM1:
            return QString(tr("Param1 has an invalid value (MAV_MISSION_INVALID_PARAM1)"));
            break;
        case MAV_MISSION_INVALID_PARAM2:
            return QString(tr("Param2 has an invalid value (MAV_MISSION_INVALID_PARAM2)"));
            break;
        case MAV_MISSION_INVALID_PARAM3:
            return QString(tr("param3 has an invalid value (MAV_MISSION_INVALID_PARAM3)"));
            break;
        case MAV_MISSION_INVALID_PARAM4:
            return QString(tr("Param4 has an invalid value (MAV_MISSION_INVALID_PARAM4)"));
            break;
        case MAV_MISSION_INVALID_PARAM5_X:
            return QString(tr("X/Param5 has an invalid value (MAV_MISSION_INVALID_PARAM5_X)"));
            break;
        case MAV_MISSION_INVALID_PARAM6_Y:
            return QString(tr("Y/Param6 has an invalid value (MAV_MISSION_INVALID_PARAM6_Y)"));
            break;
        case MAV_MISSION_INVALID_PARAM7:
            return QString(tr("Param7 has an invalid value (MAV_MISSION_INVALID_PARAM7)"));
            break;
        case MAV_MISSION_INVALID_SEQUENCE:
            return QString(tr("Received mission item out of sequence (MAV_MISSION_INVALID_SEQUENCE)"));
            break;
        case MAV_MISSION_DENIED:
            return QString(tr("Not accepting any mission commands (MAV_MISSION_DENIED)"));
            break;
        default:
            qWarning(MissionManagerLog) << "Fell off end of switch statement";
            return QString(tr("QGC Internal Error"));
    }
}

void MissionManager::_finishTransaction(bool success)
{
    if (!success && _readTransactionInProgress) {
        // Read from vehicle failed, clear partial list
        _missionItems.clear();
        emit newMissionItemsAvailable();
    }

    _itemIndicesToRead.clear();
    _itemIndicesToWrite.clear();

    if (_readTransactionInProgress || _writeTransactionInProgress) {
        _readTransactionInProgress = false;
        _writeTransactionInProgress = false;
        emit inProgressChanged(false);
    }
}

bool MissionManager::inProgress(void)
{
    return _readTransactionInProgress || _writeTransactionInProgress;
}

void MissionManager::_handleMissionCurrent(const mavlink_message_t& message)
{
    mavlink_mission_current_t missionCurrent;

    mavlink_msg_mission_current_decode(&message, &missionCurrent);

    if (missionCurrent.seq != _currentMissionItem) {
        qCDebug(MissionManagerLog) << "_handleMissionCurrent seq:" << missionCurrent.seq;
        _currentMissionItem = missionCurrent.seq;
        emit currentItemChanged(_currentMissionItem);
    }
}
