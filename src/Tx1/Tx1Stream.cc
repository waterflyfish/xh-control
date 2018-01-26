/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


#include "Tx1Stream.h"
#include "MAVLinkProtocol.h"
#include "QGCApplication.h"
#include "Vehicle.h"

//QGC_LOGGING_CATEGORY(Tx1StreamLog, "Tx1StreamLog")


Tx1Stream::Tx1Stream(Vehicle* vehicle)
    : TX1(vehicle)
{
    if(vehicle){
        qDebug()<<"Initialization Tx1Stream , Tx1Stream start working success";
    }
}

Tx1Stream::~Tx1Stream(){
}

void Tx1Stream::receiveMessage(mavlink_message_t message){
    // receiveMessage is signalled will all mavlink messages so we need to filter everything else out but ours.
    if (message.msgid != MAVLINK_MSG_ID_TX1_CONTROL_PIPE_FLOW) {
        _errorMessage("Tx1Stream receive mistake message id.");
        return;
    }
}

void Tx1Stream::_sendMessage(QString target, uint8_t stream){

    if(!_vehicle || !_vehicle->active ()){
        _errorMessage("Vehicle is null or Vehicle is not active.");
        return ;
    }

    if(target.isEmpty ()){
        _errorMessage(QString("%1 is empty").arg ("target"));
        return ;
    }

    if(target.length () >= 16){
        _errorMessage(QString("%1 maximum length %2").arg ("target").arg (16 -1));
        return ;
    }

    _dedicatedLink = _vehicle->priorityLink();
    if (!_dedicatedLink) {
        _errorMessage("Command not sent. No Vehicle links.");
        return ;
    }

    if (_systemIdQGC == 0) {
        _systemIdQGC = qgcApp()->toolbox()->mavlinkProtocol()->getSystemId();
    }
    mavlink_message_t message;
    mavlink_msg_tx1_control_pipe_flow_pack(_systemIdQGC,                     // QGC System ID
                                           0,                                // QGC Component ID
                                           &message,                         // Mavlink Message to pack into
                                           target.toStdString ().c_str (),   // Tx1 stream target
                                           stream);                          // Tx1 stream
    _vehicle->sendMessageOnLink(_dedicatedLink, message);
}
