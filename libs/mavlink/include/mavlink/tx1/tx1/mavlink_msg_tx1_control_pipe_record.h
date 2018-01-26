// MESSAGE TX1_CONTROL_PIPE_RECORD PACKING

#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD 65501

MAVPACKED(
typedef struct __mavlink_tx1_control_pipe_record_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t target_id; /*<  The id of the target pipeline
			*/
 uint8_t record; /*<  Start/Stop recording on the pipeline
			*/
 char fileName[16]; /*<  Optional filename for the video recording
			*/
}) mavlink_tx1_control_pipe_record_t;

#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN 20
#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN 20
#define MAVLINK_MSG_ID_65501_LEN 20
#define MAVLINK_MSG_ID_65501_MIN_LEN 20

#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC 99
#define MAVLINK_MSG_ID_65501_CRC 99

#define MAVLINK_MSG_TX1_CONTROL_PIPE_RECORD_FIELD_FILENAME_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_PIPE_RECORD { \
	65501, \
	"TX1_CONTROL_PIPE_RECORD", \
	5, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_pipe_record_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_control_pipe_record_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_control_pipe_record_t, target_id) }, \
         { "record", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_tx1_control_pipe_record_t, record) }, \
         { "fileName", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_tx1_control_pipe_record_t, fileName) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_PIPE_RECORD { \
	"TX1_CONTROL_PIPE_RECORD", \
	5, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_pipe_record_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_control_pipe_record_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_control_pipe_record_t, target_id) }, \
         { "record", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_tx1_control_pipe_record_t, record) }, \
         { "fileName", NULL, MAVLINK_TYPE_CHAR, 16, 4, offsetof(mavlink_tx1_control_pipe_record_t, fileName) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_control_pipe_record message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @param record  Start/Stop recording on the pipeline
			
 * @param fileName  Optional filename for the video recording
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_record_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t target_id, uint8_t record, const char *fileName)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);
	_mav_put_uint8_t(buf, 3, record);
	_mav_put_char_array(buf, 4, fileName, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN);
#else
	mavlink_tx1_control_pipe_record_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.record = record;
	mav_array_memcpy(packet.fileName, fileName, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC);
}

/**
 * @brief Pack a tx1_control_pipe_record message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @param record  Start/Stop recording on the pipeline
			
 * @param fileName  Optional filename for the video recording
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_record_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t target_id,uint8_t record,const char *fileName)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);
	_mav_put_uint8_t(buf, 3, record);
	_mav_put_char_array(buf, 4, fileName, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN);
#else
	mavlink_tx1_control_pipe_record_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.record = record;
	mav_array_memcpy(packet.fileName, fileName, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC);
}

/**
 * @brief Encode a tx1_control_pipe_record struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_pipe_record C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_record_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_control_pipe_record_t* tx1_control_pipe_record)
{
	return mavlink_msg_tx1_control_pipe_record_pack(system_id, component_id, msg, tx1_control_pipe_record->target_system, tx1_control_pipe_record->target_component, tx1_control_pipe_record->target_id, tx1_control_pipe_record->record, tx1_control_pipe_record->fileName);
}

/**
 * @brief Encode a tx1_control_pipe_record struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_pipe_record C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_record_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_control_pipe_record_t* tx1_control_pipe_record)
{
	return mavlink_msg_tx1_control_pipe_record_pack_chan(system_id, component_id, chan, msg, tx1_control_pipe_record->target_system, tx1_control_pipe_record->target_component, tx1_control_pipe_record->target_id, tx1_control_pipe_record->record, tx1_control_pipe_record->fileName);
}

/**
 * @brief Send a tx1_control_pipe_record message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @param record  Start/Stop recording on the pipeline
			
 * @param fileName  Optional filename for the video recording
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_control_pipe_record_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t target_id, uint8_t record, const char *fileName)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);
	_mav_put_uint8_t(buf, 3, record);
	_mav_put_char_array(buf, 4, fileName, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD, buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC);
#else
	mavlink_tx1_control_pipe_record_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.record = record;
	mav_array_memcpy(packet.fileName, fileName, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD, (const char *)&packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC);
#endif
}

/**
 * @brief Send a tx1_control_pipe_record message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_control_pipe_record_send_struct(mavlink_channel_t chan, const mavlink_tx1_control_pipe_record_t* tx1_control_pipe_record)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_control_pipe_record_send(chan, tx1_control_pipe_record->target_system, tx1_control_pipe_record->target_component, tx1_control_pipe_record->target_id, tx1_control_pipe_record->record, tx1_control_pipe_record->fileName);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD, (const char *)tx1_control_pipe_record, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_control_pipe_record_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t target_id, uint8_t record, const char *fileName)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);
	_mav_put_uint8_t(buf, 3, record);
	_mav_put_char_array(buf, 4, fileName, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD, buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC);
#else
	mavlink_tx1_control_pipe_record_t *packet = (mavlink_tx1_control_pipe_record_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->target_id = target_id;
	packet->record = record;
	mav_array_memcpy(packet->fileName, fileName, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD, (const char *)packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_CONTROL_PIPE_RECORD UNPACKING


/**
 * @brief Get field target_system from tx1_control_pipe_record message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_record_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_control_pipe_record message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_record_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field target_id from tx1_control_pipe_record message
 *
 * @return  The id of the target pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_record_get_target_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field record from tx1_control_pipe_record message
 *
 * @return  Start/Stop recording on the pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_record_get_record(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field fileName from tx1_control_pipe_record message
 *
 * @return  Optional filename for the video recording
			
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_record_get_fileName(const mavlink_message_t* msg, char *fileName)
{
	return _MAV_RETURN_char_array(msg, fileName, 16,  4);
}

/**
 * @brief Decode a tx1_control_pipe_record message into a struct
 *
 * @param msg The message to decode
 * @param tx1_control_pipe_record C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_control_pipe_record_decode(const mavlink_message_t* msg, mavlink_tx1_control_pipe_record_t* tx1_control_pipe_record)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_control_pipe_record->target_system = mavlink_msg_tx1_control_pipe_record_get_target_system(msg);
	tx1_control_pipe_record->target_component = mavlink_msg_tx1_control_pipe_record_get_target_component(msg);
	tx1_control_pipe_record->target_id = mavlink_msg_tx1_control_pipe_record_get_target_id(msg);
	tx1_control_pipe_record->record = mavlink_msg_tx1_control_pipe_record_get_record(msg);
	mavlink_msg_tx1_control_pipe_record_get_fileName(msg, tx1_control_pipe_record->fileName);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN? msg->len : MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN;
        memset(tx1_control_pipe_record, 0, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_RECORD_LEN);
	memcpy(tx1_control_pipe_record, _MAV_PAYLOAD(msg), len);
#endif
}
