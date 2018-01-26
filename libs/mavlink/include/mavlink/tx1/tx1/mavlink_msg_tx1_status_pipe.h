// MESSAGE TX1_STATUS_PIPE PACKING

#define MAVLINK_MSG_ID_TX1_STATUS_PIPE 65513

MAVPACKED(
typedef struct __mavlink_tx1_status_pipe_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 char target[8]; /*<  Name of the target pipeline
			*/
 uint8_t target_id; /*<  The id of the target pipeline
			*/
 uint8_t type; /*<  Type of the pipeline
			*/
 uint8_t running; /*<  Running status of the pipeline
			*/
 uint8_t recording; /*<  Recording status of the pipeline
			*/
 uint8_t tracking; /*<  Tracking status of the pipeline
			*/
 char value0[12]; /*< 
				
				
			*/
 char value1[4]; /*< 
				
				
			*/
 char value2[4]; /*< 
				
				
			*/
 char value3[4]; /*< 
				
				
			*/
}) mavlink_tx1_status_pipe_t;

#define MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN 39
#define MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN 39
#define MAVLINK_MSG_ID_65513_LEN 39
#define MAVLINK_MSG_ID_65513_MIN_LEN 39

#define MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC 99
#define MAVLINK_MSG_ID_65513_CRC 99

#define MAVLINK_MSG_TX1_STATUS_PIPE_FIELD_TARGET_LEN 8
#define MAVLINK_MSG_TX1_STATUS_PIPE_FIELD_VALUE0_LEN 12
#define MAVLINK_MSG_TX1_STATUS_PIPE_FIELD_VALUE1_LEN 4
#define MAVLINK_MSG_TX1_STATUS_PIPE_FIELD_VALUE2_LEN 4
#define MAVLINK_MSG_TX1_STATUS_PIPE_FIELD_VALUE3_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_PIPE { \
	65513, \
	"TX1_STATUS_PIPE", \
	12, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_pipe_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_pipe_t, target_component) }, \
         { "target", NULL, MAVLINK_TYPE_CHAR, 8, 2, offsetof(mavlink_tx1_status_pipe_t, target) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tx1_status_pipe_t, target_id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tx1_status_pipe_t, type) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tx1_status_pipe_t, running) }, \
         { "recording", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tx1_status_pipe_t, recording) }, \
         { "tracking", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tx1_status_pipe_t, tracking) }, \
         { "value0", NULL, MAVLINK_TYPE_CHAR, 12, 15, offsetof(mavlink_tx1_status_pipe_t, value0) }, \
         { "value1", NULL, MAVLINK_TYPE_CHAR, 4, 27, offsetof(mavlink_tx1_status_pipe_t, value1) }, \
         { "value2", NULL, MAVLINK_TYPE_CHAR, 4, 31, offsetof(mavlink_tx1_status_pipe_t, value2) }, \
         { "value3", NULL, MAVLINK_TYPE_CHAR, 4, 35, offsetof(mavlink_tx1_status_pipe_t, value3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_PIPE { \
	"TX1_STATUS_PIPE", \
	12, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_pipe_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_pipe_t, target_component) }, \
         { "target", NULL, MAVLINK_TYPE_CHAR, 8, 2, offsetof(mavlink_tx1_status_pipe_t, target) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tx1_status_pipe_t, target_id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tx1_status_pipe_t, type) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tx1_status_pipe_t, running) }, \
         { "recording", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tx1_status_pipe_t, recording) }, \
         { "tracking", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tx1_status_pipe_t, tracking) }, \
         { "value0", NULL, MAVLINK_TYPE_CHAR, 12, 15, offsetof(mavlink_tx1_status_pipe_t, value0) }, \
         { "value1", NULL, MAVLINK_TYPE_CHAR, 4, 27, offsetof(mavlink_tx1_status_pipe_t, value1) }, \
         { "value2", NULL, MAVLINK_TYPE_CHAR, 4, 31, offsetof(mavlink_tx1_status_pipe_t, value2) }, \
         { "value3", NULL, MAVLINK_TYPE_CHAR, 4, 35, offsetof(mavlink_tx1_status_pipe_t, value3) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_status_pipe message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target  Name of the target pipeline
			
 * @param target_id  The id of the target pipeline
			
 * @param type  Type of the pipeline
			
 * @param running  Running status of the pipeline
			
 * @param recording  Recording status of the pipeline
			
 * @param tracking  Tracking status of the pipeline
			
 * @param value0 
				
				
			
 * @param value1 
				
				
			
 * @param value2 
				
				
			
 * @param value3 
				
				
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, const char *target, uint8_t target_id, uint8_t type, uint8_t running, uint8_t recording, uint8_t tracking, const char *value0, const char *value1, const char *value2, const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, running);
	_mav_put_uint8_t(buf, 13, recording);
	_mav_put_uint8_t(buf, 14, tracking);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 12);
	_mav_put_char_array(buf, 27, value1, 4);
	_mav_put_char_array(buf, 31, value2, 4);
	_mav_put_char_array(buf, 35, value3, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN);
#else
	mavlink_tx1_status_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.type = type;
	packet.running = running;
	packet.recording = recording;
	packet.tracking = tracking;
	mav_array_memcpy(packet.target, target, sizeof(char)*8);
	mav_array_memcpy(packet.value0, value0, sizeof(char)*12);
	mav_array_memcpy(packet.value1, value1, sizeof(char)*4);
	mav_array_memcpy(packet.value2, value2, sizeof(char)*4);
	mav_array_memcpy(packet.value3, value3, sizeof(char)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_PIPE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC);
}

/**
 * @brief Pack a tx1_status_pipe message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target  Name of the target pipeline
			
 * @param target_id  The id of the target pipeline
			
 * @param type  Type of the pipeline
			
 * @param running  Running status of the pipeline
			
 * @param recording  Recording status of the pipeline
			
 * @param tracking  Tracking status of the pipeline
			
 * @param value0 
				
				
			
 * @param value1 
				
				
			
 * @param value2 
				
				
			
 * @param value3 
				
				
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,const char *target,uint8_t target_id,uint8_t type,uint8_t running,uint8_t recording,uint8_t tracking,const char *value0,const char *value1,const char *value2,const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, running);
	_mav_put_uint8_t(buf, 13, recording);
	_mav_put_uint8_t(buf, 14, tracking);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 12);
	_mav_put_char_array(buf, 27, value1, 4);
	_mav_put_char_array(buf, 31, value2, 4);
	_mav_put_char_array(buf, 35, value3, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN);
#else
	mavlink_tx1_status_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.type = type;
	packet.running = running;
	packet.recording = recording;
	packet.tracking = tracking;
	mav_array_memcpy(packet.target, target, sizeof(char)*8);
	mav_array_memcpy(packet.value0, value0, sizeof(char)*12);
	mav_array_memcpy(packet.value1, value1, sizeof(char)*4);
	mav_array_memcpy(packet.value2, value2, sizeof(char)*4);
	mav_array_memcpy(packet.value3, value3, sizeof(char)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_PIPE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC);
}

/**
 * @brief Encode a tx1_status_pipe struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_pipe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_status_pipe_t* tx1_status_pipe)
{
	return mavlink_msg_tx1_status_pipe_pack(system_id, component_id, msg, tx1_status_pipe->target_system, tx1_status_pipe->target_component, tx1_status_pipe->target, tx1_status_pipe->target_id, tx1_status_pipe->type, tx1_status_pipe->running, tx1_status_pipe->recording, tx1_status_pipe->tracking, tx1_status_pipe->value0, tx1_status_pipe->value1, tx1_status_pipe->value2, tx1_status_pipe->value3);
}

/**
 * @brief Encode a tx1_status_pipe struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_pipe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_status_pipe_t* tx1_status_pipe)
{
	return mavlink_msg_tx1_status_pipe_pack_chan(system_id, component_id, chan, msg, tx1_status_pipe->target_system, tx1_status_pipe->target_component, tx1_status_pipe->target, tx1_status_pipe->target_id, tx1_status_pipe->type, tx1_status_pipe->running, tx1_status_pipe->recording, tx1_status_pipe->tracking, tx1_status_pipe->value0, tx1_status_pipe->value1, tx1_status_pipe->value2, tx1_status_pipe->value3);
}

/**
 * @brief Send a tx1_status_pipe message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target  Name of the target pipeline
			
 * @param target_id  The id of the target pipeline
			
 * @param type  Type of the pipeline
			
 * @param running  Running status of the pipeline
			
 * @param recording  Recording status of the pipeline
			
 * @param tracking  Tracking status of the pipeline
			
 * @param value0 
				
				
			
 * @param value1 
				
				
			
 * @param value2 
				
				
			
 * @param value3 
				
				
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_status_pipe_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const char *target, uint8_t target_id, uint8_t type, uint8_t running, uint8_t recording, uint8_t tracking, const char *value0, const char *value1, const char *value2, const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, running);
	_mav_put_uint8_t(buf, 13, recording);
	_mav_put_uint8_t(buf, 14, tracking);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 12);
	_mav_put_char_array(buf, 27, value1, 4);
	_mav_put_char_array(buf, 31, value2, 4);
	_mav_put_char_array(buf, 35, value3, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_PIPE, buf, MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC);
#else
	mavlink_tx1_status_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.type = type;
	packet.running = running;
	packet.recording = recording;
	packet.tracking = tracking;
	mav_array_memcpy(packet.target, target, sizeof(char)*8);
	mav_array_memcpy(packet.value0, value0, sizeof(char)*12);
	mav_array_memcpy(packet.value1, value1, sizeof(char)*4);
	mav_array_memcpy(packet.value2, value2, sizeof(char)*4);
	mav_array_memcpy(packet.value3, value3, sizeof(char)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_PIPE, (const char *)&packet, MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC);
#endif
}

/**
 * @brief Send a tx1_status_pipe message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_status_pipe_send_struct(mavlink_channel_t chan, const mavlink_tx1_status_pipe_t* tx1_status_pipe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_status_pipe_send(chan, tx1_status_pipe->target_system, tx1_status_pipe->target_component, tx1_status_pipe->target, tx1_status_pipe->target_id, tx1_status_pipe->type, tx1_status_pipe->running, tx1_status_pipe->recording, tx1_status_pipe->tracking, tx1_status_pipe->value0, tx1_status_pipe->value1, tx1_status_pipe->value2, tx1_status_pipe->value3);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_PIPE, (const char *)tx1_status_pipe, MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_status_pipe_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, const char *target, uint8_t target_id, uint8_t type, uint8_t running, uint8_t recording, uint8_t tracking, const char *value0, const char *value1, const char *value2, const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, running);
	_mav_put_uint8_t(buf, 13, recording);
	_mav_put_uint8_t(buf, 14, tracking);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 12);
	_mav_put_char_array(buf, 27, value1, 4);
	_mav_put_char_array(buf, 31, value2, 4);
	_mav_put_char_array(buf, 35, value3, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_PIPE, buf, MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC);
#else
	mavlink_tx1_status_pipe_t *packet = (mavlink_tx1_status_pipe_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->target_id = target_id;
	packet->type = type;
	packet->running = running;
	packet->recording = recording;
	packet->tracking = tracking;
	mav_array_memcpy(packet->target, target, sizeof(char)*8);
	mav_array_memcpy(packet->value0, value0, sizeof(char)*12);
	mav_array_memcpy(packet->value1, value1, sizeof(char)*4);
	mav_array_memcpy(packet->value2, value2, sizeof(char)*4);
	mav_array_memcpy(packet->value3, value3, sizeof(char)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_PIPE, (const char *)packet, MAVLINK_MSG_ID_TX1_STATUS_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_PIPE_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_STATUS_PIPE UNPACKING


/**
 * @brief Get field target_system from tx1_status_pipe message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_status_pipe_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_status_pipe message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_status_pipe_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field target from tx1_status_pipe message
 *
 * @return  Name of the target pipeline
			
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_get_target(const mavlink_message_t* msg, char *target)
{
	return _MAV_RETURN_char_array(msg, target, 8,  2);
}

/**
 * @brief Get field target_id from tx1_status_pipe message
 *
 * @return  The id of the target pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_status_pipe_get_target_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field type from tx1_status_pipe message
 *
 * @return  Type of the pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_status_pipe_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field running from tx1_status_pipe message
 *
 * @return  Running status of the pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_status_pipe_get_running(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field recording from tx1_status_pipe message
 *
 * @return  Recording status of the pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_status_pipe_get_recording(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field tracking from tx1_status_pipe message
 *
 * @return  Tracking status of the pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_status_pipe_get_tracking(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field value0 from tx1_status_pipe message
 *
 * @return 
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_get_value0(const mavlink_message_t* msg, char *value0)
{
	return _MAV_RETURN_char_array(msg, value0, 12,  15);
}

/**
 * @brief Get field value1 from tx1_status_pipe message
 *
 * @return 
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_get_value1(const mavlink_message_t* msg, char *value1)
{
	return _MAV_RETURN_char_array(msg, value1, 4,  27);
}

/**
 * @brief Get field value2 from tx1_status_pipe message
 *
 * @return 
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_get_value2(const mavlink_message_t* msg, char *value2)
{
	return _MAV_RETURN_char_array(msg, value2, 4,  31);
}

/**
 * @brief Get field value3 from tx1_status_pipe message
 *
 * @return 
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_pipe_get_value3(const mavlink_message_t* msg, char *value3)
{
	return _MAV_RETURN_char_array(msg, value3, 4,  35);
}

/**
 * @brief Decode a tx1_status_pipe message into a struct
 *
 * @param msg The message to decode
 * @param tx1_status_pipe C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_status_pipe_decode(const mavlink_message_t* msg, mavlink_tx1_status_pipe_t* tx1_status_pipe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_status_pipe->target_system = mavlink_msg_tx1_status_pipe_get_target_system(msg);
	tx1_status_pipe->target_component = mavlink_msg_tx1_status_pipe_get_target_component(msg);
	mavlink_msg_tx1_status_pipe_get_target(msg, tx1_status_pipe->target);
	tx1_status_pipe->target_id = mavlink_msg_tx1_status_pipe_get_target_id(msg);
	tx1_status_pipe->type = mavlink_msg_tx1_status_pipe_get_type(msg);
	tx1_status_pipe->running = mavlink_msg_tx1_status_pipe_get_running(msg);
	tx1_status_pipe->recording = mavlink_msg_tx1_status_pipe_get_recording(msg);
	tx1_status_pipe->tracking = mavlink_msg_tx1_status_pipe_get_tracking(msg);
	mavlink_msg_tx1_status_pipe_get_value0(msg, tx1_status_pipe->value0);
	mavlink_msg_tx1_status_pipe_get_value1(msg, tx1_status_pipe->value1);
	mavlink_msg_tx1_status_pipe_get_value2(msg, tx1_status_pipe->value2);
	mavlink_msg_tx1_status_pipe_get_value3(msg, tx1_status_pipe->value3);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN? msg->len : MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN;
        memset(tx1_status_pipe, 0, MAVLINK_MSG_ID_TX1_STATUS_PIPE_LEN);
	memcpy(tx1_status_pipe, _MAV_PAYLOAD(msg), len);
#endif
}
