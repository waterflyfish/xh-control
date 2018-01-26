// MESSAGE TX1_STATUS_SYSTEM_PIPE PACKING

#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE 65511

MAVPACKED(
typedef struct __mavlink_tx1_status_system_pipe_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t target_ids[8]; /*<  The ids of all pipelines
			*/
 uint8_t types[8]; /*<  Types of the pipelines
			*/
 uint8_t running[8]; /*<  Running status of the pipelines
			*/
 uint8_t recording[8]; /*<  Recording status of the pipelines
			*/
 uint8_t tracking[8]; /*<  Tracking status of the pipelines
			*/
}) mavlink_tx1_status_system_pipe_t;

#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN 42
#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN 42
#define MAVLINK_MSG_ID_65511_LEN 42
#define MAVLINK_MSG_ID_65511_MIN_LEN 42

#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC 181
#define MAVLINK_MSG_ID_65511_CRC 181

#define MAVLINK_MSG_TX1_STATUS_SYSTEM_PIPE_FIELD_TARGET_IDS_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_PIPE_FIELD_TYPES_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_PIPE_FIELD_RUNNING_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_PIPE_FIELD_RECORDING_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_PIPE_FIELD_TRACKING_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_SYSTEM_PIPE { \
	65511, \
	"TX1_STATUS_SYSTEM_PIPE", \
	7, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_system_pipe_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_system_pipe_t, target_component) }, \
         { "target_ids", NULL, MAVLINK_TYPE_UINT8_T, 8, 2, offsetof(mavlink_tx1_status_system_pipe_t, target_ids) }, \
         { "types", NULL, MAVLINK_TYPE_UINT8_T, 8, 10, offsetof(mavlink_tx1_status_system_pipe_t, types) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 8, 18, offsetof(mavlink_tx1_status_system_pipe_t, running) }, \
         { "recording", NULL, MAVLINK_TYPE_UINT8_T, 8, 26, offsetof(mavlink_tx1_status_system_pipe_t, recording) }, \
         { "tracking", NULL, MAVLINK_TYPE_UINT8_T, 8, 34, offsetof(mavlink_tx1_status_system_pipe_t, tracking) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_SYSTEM_PIPE { \
	"TX1_STATUS_SYSTEM_PIPE", \
	7, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_system_pipe_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_system_pipe_t, target_component) }, \
         { "target_ids", NULL, MAVLINK_TYPE_UINT8_T, 8, 2, offsetof(mavlink_tx1_status_system_pipe_t, target_ids) }, \
         { "types", NULL, MAVLINK_TYPE_UINT8_T, 8, 10, offsetof(mavlink_tx1_status_system_pipe_t, types) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 8, 18, offsetof(mavlink_tx1_status_system_pipe_t, running) }, \
         { "recording", NULL, MAVLINK_TYPE_UINT8_T, 8, 26, offsetof(mavlink_tx1_status_system_pipe_t, recording) }, \
         { "tracking", NULL, MAVLINK_TYPE_UINT8_T, 8, 34, offsetof(mavlink_tx1_status_system_pipe_t, tracking) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_status_system_pipe message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_ids  The ids of all pipelines
			
 * @param types  Types of the pipelines
			
 * @param running  Running status of the pipelines
			
 * @param recording  Recording status of the pipelines
			
 * @param tracking  Tracking status of the pipelines
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, const uint8_t *target_ids, const uint8_t *types, const uint8_t *running, const uint8_t *recording, const uint8_t *tracking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, running, 8);
	_mav_put_uint8_t_array(buf, 26, recording, 8);
	_mav_put_uint8_t_array(buf, 34, tracking, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN);
#else
	mavlink_tx1_status_system_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	mav_array_memcpy(packet.target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.running, running, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.recording, recording, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.tracking, tracking, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC);
}

/**
 * @brief Pack a tx1_status_system_pipe message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_ids  The ids of all pipelines
			
 * @param types  Types of the pipelines
			
 * @param running  Running status of the pipelines
			
 * @param recording  Recording status of the pipelines
			
 * @param tracking  Tracking status of the pipelines
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,const uint8_t *target_ids,const uint8_t *types,const uint8_t *running,const uint8_t *recording,const uint8_t *tracking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, running, 8);
	_mav_put_uint8_t_array(buf, 26, recording, 8);
	_mav_put_uint8_t_array(buf, 34, tracking, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN);
#else
	mavlink_tx1_status_system_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	mav_array_memcpy(packet.target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.running, running, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.recording, recording, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.tracking, tracking, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC);
}

/**
 * @brief Encode a tx1_status_system_pipe struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_system_pipe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_status_system_pipe_t* tx1_status_system_pipe)
{
	return mavlink_msg_tx1_status_system_pipe_pack(system_id, component_id, msg, tx1_status_system_pipe->target_system, tx1_status_system_pipe->target_component, tx1_status_system_pipe->target_ids, tx1_status_system_pipe->types, tx1_status_system_pipe->running, tx1_status_system_pipe->recording, tx1_status_system_pipe->tracking);
}

/**
 * @brief Encode a tx1_status_system_pipe struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_system_pipe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_status_system_pipe_t* tx1_status_system_pipe)
{
	return mavlink_msg_tx1_status_system_pipe_pack_chan(system_id, component_id, chan, msg, tx1_status_system_pipe->target_system, tx1_status_system_pipe->target_component, tx1_status_system_pipe->target_ids, tx1_status_system_pipe->types, tx1_status_system_pipe->running, tx1_status_system_pipe->recording, tx1_status_system_pipe->tracking);
}

/**
 * @brief Send a tx1_status_system_pipe message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_ids  The ids of all pipelines
			
 * @param types  Types of the pipelines
			
 * @param running  Running status of the pipelines
			
 * @param recording  Recording status of the pipelines
			
 * @param tracking  Tracking status of the pipelines
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_status_system_pipe_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const uint8_t *target_ids, const uint8_t *types, const uint8_t *running, const uint8_t *recording, const uint8_t *tracking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, running, 8);
	_mav_put_uint8_t_array(buf, 26, recording, 8);
	_mav_put_uint8_t_array(buf, 34, tracking, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE, buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC);
#else
	mavlink_tx1_status_system_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	mav_array_memcpy(packet.target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.running, running, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.recording, recording, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.tracking, tracking, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE, (const char *)&packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC);
#endif
}

/**
 * @brief Send a tx1_status_system_pipe message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_status_system_pipe_send_struct(mavlink_channel_t chan, const mavlink_tx1_status_system_pipe_t* tx1_status_system_pipe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_status_system_pipe_send(chan, tx1_status_system_pipe->target_system, tx1_status_system_pipe->target_component, tx1_status_system_pipe->target_ids, tx1_status_system_pipe->types, tx1_status_system_pipe->running, tx1_status_system_pipe->recording, tx1_status_system_pipe->tracking);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE, (const char *)tx1_status_system_pipe, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_status_system_pipe_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, const uint8_t *target_ids, const uint8_t *types, const uint8_t *running, const uint8_t *recording, const uint8_t *tracking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, running, 8);
	_mav_put_uint8_t_array(buf, 26, recording, 8);
	_mav_put_uint8_t_array(buf, 34, tracking, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE, buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC);
#else
	mavlink_tx1_status_system_pipe_t *packet = (mavlink_tx1_status_system_pipe_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	mav_array_memcpy(packet->target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->running, running, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->recording, recording, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->tracking, tracking, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE, (const char *)packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_STATUS_SYSTEM_PIPE UNPACKING


/**
 * @brief Get field target_system from tx1_status_system_pipe message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_status_system_pipe_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_status_system_pipe message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_status_system_pipe_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field target_ids from tx1_status_system_pipe message
 *
 * @return  The ids of all pipelines
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_get_target_ids(const mavlink_message_t* msg, uint8_t *target_ids)
{
	return _MAV_RETURN_uint8_t_array(msg, target_ids, 8,  2);
}

/**
 * @brief Get field types from tx1_status_system_pipe message
 *
 * @return  Types of the pipelines
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_get_types(const mavlink_message_t* msg, uint8_t *types)
{
	return _MAV_RETURN_uint8_t_array(msg, types, 8,  10);
}

/**
 * @brief Get field running from tx1_status_system_pipe message
 *
 * @return  Running status of the pipelines
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_get_running(const mavlink_message_t* msg, uint8_t *running)
{
	return _MAV_RETURN_uint8_t_array(msg, running, 8,  18);
}

/**
 * @brief Get field recording from tx1_status_system_pipe message
 *
 * @return  Recording status of the pipelines
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_get_recording(const mavlink_message_t* msg, uint8_t *recording)
{
	return _MAV_RETURN_uint8_t_array(msg, recording, 8,  26);
}

/**
 * @brief Get field tracking from tx1_status_system_pipe message
 *
 * @return  Tracking status of the pipelines
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_pipe_get_tracking(const mavlink_message_t* msg, uint8_t *tracking)
{
	return _MAV_RETURN_uint8_t_array(msg, tracking, 8,  34);
}

/**
 * @brief Decode a tx1_status_system_pipe message into a struct
 *
 * @param msg The message to decode
 * @param tx1_status_system_pipe C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_status_system_pipe_decode(const mavlink_message_t* msg, mavlink_tx1_status_system_pipe_t* tx1_status_system_pipe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_status_system_pipe->target_system = mavlink_msg_tx1_status_system_pipe_get_target_system(msg);
	tx1_status_system_pipe->target_component = mavlink_msg_tx1_status_system_pipe_get_target_component(msg);
	mavlink_msg_tx1_status_system_pipe_get_target_ids(msg, tx1_status_system_pipe->target_ids);
	mavlink_msg_tx1_status_system_pipe_get_types(msg, tx1_status_system_pipe->types);
	mavlink_msg_tx1_status_system_pipe_get_running(msg, tx1_status_system_pipe->running);
	mavlink_msg_tx1_status_system_pipe_get_recording(msg, tx1_status_system_pipe->recording);
	mavlink_msg_tx1_status_system_pipe_get_tracking(msg, tx1_status_system_pipe->tracking);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN? msg->len : MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN;
        memset(tx1_status_system_pipe, 0, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_PIPE_LEN);
	memcpy(tx1_status_system_pipe, _MAV_PAYLOAD(msg), len);
#endif
}
