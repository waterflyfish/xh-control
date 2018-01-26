// MESSAGE TX1_STATUS_SYSTEM_COM PACKING

#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM 65510

MAVPACKED(
typedef struct __mavlink_tx1_status_system_com_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t target_ids[8]; /*<  The ids of all com channels
			*/
 uint8_t types[8]; /*<  Types of the com channels
			*/
 uint8_t emit_status[8]; /*<  Emit status messages status of the com channels
			*/
 uint8_t mavlink[8]; /*<  Mavlink usage status of the com channels
			*/
 uint8_t running[8]; /*<  Running status of the com channels
			*/
}) mavlink_tx1_status_system_com_t;

#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN 42
#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN 42
#define MAVLINK_MSG_ID_65510_LEN 42
#define MAVLINK_MSG_ID_65510_MIN_LEN 42

#define MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC 58
#define MAVLINK_MSG_ID_65510_CRC 58

#define MAVLINK_MSG_TX1_STATUS_SYSTEM_COM_FIELD_TARGET_IDS_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_COM_FIELD_TYPES_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_COM_FIELD_EMIT_STATUS_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_COM_FIELD_MAVLINK_LEN 8
#define MAVLINK_MSG_TX1_STATUS_SYSTEM_COM_FIELD_RUNNING_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_SYSTEM_COM { \
	65510, \
	"TX1_STATUS_SYSTEM_COM", \
	7, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_system_com_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_system_com_t, target_component) }, \
         { "target_ids", NULL, MAVLINK_TYPE_UINT8_T, 8, 2, offsetof(mavlink_tx1_status_system_com_t, target_ids) }, \
         { "types", NULL, MAVLINK_TYPE_UINT8_T, 8, 10, offsetof(mavlink_tx1_status_system_com_t, types) }, \
         { "emit_status", NULL, MAVLINK_TYPE_UINT8_T, 8, 18, offsetof(mavlink_tx1_status_system_com_t, emit_status) }, \
         { "mavlink", NULL, MAVLINK_TYPE_UINT8_T, 8, 26, offsetof(mavlink_tx1_status_system_com_t, mavlink) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 8, 34, offsetof(mavlink_tx1_status_system_com_t, running) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_SYSTEM_COM { \
	"TX1_STATUS_SYSTEM_COM", \
	7, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_system_com_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_system_com_t, target_component) }, \
         { "target_ids", NULL, MAVLINK_TYPE_UINT8_T, 8, 2, offsetof(mavlink_tx1_status_system_com_t, target_ids) }, \
         { "types", NULL, MAVLINK_TYPE_UINT8_T, 8, 10, offsetof(mavlink_tx1_status_system_com_t, types) }, \
         { "emit_status", NULL, MAVLINK_TYPE_UINT8_T, 8, 18, offsetof(mavlink_tx1_status_system_com_t, emit_status) }, \
         { "mavlink", NULL, MAVLINK_TYPE_UINT8_T, 8, 26, offsetof(mavlink_tx1_status_system_com_t, mavlink) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 8, 34, offsetof(mavlink_tx1_status_system_com_t, running) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_status_system_com message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_ids  The ids of all com channels
			
 * @param types  Types of the com channels
			
 * @param emit_status  Emit status messages status of the com channels
			
 * @param mavlink  Mavlink usage status of the com channels
			
 * @param running  Running status of the com channels
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, const uint8_t *target_ids, const uint8_t *types, const uint8_t *emit_status, const uint8_t *mavlink, const uint8_t *running)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, emit_status, 8);
	_mav_put_uint8_t_array(buf, 26, mavlink, 8);
	_mav_put_uint8_t_array(buf, 34, running, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN);
#else
	mavlink_tx1_status_system_com_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	mav_array_memcpy(packet.target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.emit_status, emit_status, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.mavlink, mavlink, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.running, running, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC);
}

/**
 * @brief Pack a tx1_status_system_com message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_ids  The ids of all com channels
			
 * @param types  Types of the com channels
			
 * @param emit_status  Emit status messages status of the com channels
			
 * @param mavlink  Mavlink usage status of the com channels
			
 * @param running  Running status of the com channels
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,const uint8_t *target_ids,const uint8_t *types,const uint8_t *emit_status,const uint8_t *mavlink,const uint8_t *running)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, emit_status, 8);
	_mav_put_uint8_t_array(buf, 26, mavlink, 8);
	_mav_put_uint8_t_array(buf, 34, running, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN);
#else
	mavlink_tx1_status_system_com_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	mav_array_memcpy(packet.target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.emit_status, emit_status, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.mavlink, mavlink, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.running, running, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC);
}

/**
 * @brief Encode a tx1_status_system_com struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_system_com C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_status_system_com_t* tx1_status_system_com)
{
	return mavlink_msg_tx1_status_system_com_pack(system_id, component_id, msg, tx1_status_system_com->target_system, tx1_status_system_com->target_component, tx1_status_system_com->target_ids, tx1_status_system_com->types, tx1_status_system_com->emit_status, tx1_status_system_com->mavlink, tx1_status_system_com->running);
}

/**
 * @brief Encode a tx1_status_system_com struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_system_com C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_status_system_com_t* tx1_status_system_com)
{
	return mavlink_msg_tx1_status_system_com_pack_chan(system_id, component_id, chan, msg, tx1_status_system_com->target_system, tx1_status_system_com->target_component, tx1_status_system_com->target_ids, tx1_status_system_com->types, tx1_status_system_com->emit_status, tx1_status_system_com->mavlink, tx1_status_system_com->running);
}

/**
 * @brief Send a tx1_status_system_com message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_ids  The ids of all com channels
			
 * @param types  Types of the com channels
			
 * @param emit_status  Emit status messages status of the com channels
			
 * @param mavlink  Mavlink usage status of the com channels
			
 * @param running  Running status of the com channels
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_status_system_com_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const uint8_t *target_ids, const uint8_t *types, const uint8_t *emit_status, const uint8_t *mavlink, const uint8_t *running)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, emit_status, 8);
	_mav_put_uint8_t_array(buf, 26, mavlink, 8);
	_mav_put_uint8_t_array(buf, 34, running, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM, buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC);
#else
	mavlink_tx1_status_system_com_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	mav_array_memcpy(packet.target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.emit_status, emit_status, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.mavlink, mavlink, sizeof(uint8_t)*8);
	mav_array_memcpy(packet.running, running, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM, (const char *)&packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC);
#endif
}

/**
 * @brief Send a tx1_status_system_com message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_status_system_com_send_struct(mavlink_channel_t chan, const mavlink_tx1_status_system_com_t* tx1_status_system_com)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_status_system_com_send(chan, tx1_status_system_com->target_system, tx1_status_system_com->target_component, tx1_status_system_com->target_ids, tx1_status_system_com->types, tx1_status_system_com->emit_status, tx1_status_system_com->mavlink, tx1_status_system_com->running);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM, (const char *)tx1_status_system_com, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_status_system_com_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, const uint8_t *target_ids, const uint8_t *types, const uint8_t *emit_status, const uint8_t *mavlink, const uint8_t *running)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t_array(buf, 2, target_ids, 8);
	_mav_put_uint8_t_array(buf, 10, types, 8);
	_mav_put_uint8_t_array(buf, 18, emit_status, 8);
	_mav_put_uint8_t_array(buf, 26, mavlink, 8);
	_mav_put_uint8_t_array(buf, 34, running, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM, buf, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC);
#else
	mavlink_tx1_status_system_com_t *packet = (mavlink_tx1_status_system_com_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	mav_array_memcpy(packet->target_ids, target_ids, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->types, types, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->emit_status, emit_status, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->mavlink, mavlink, sizeof(uint8_t)*8);
	mav_array_memcpy(packet->running, running, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM, (const char *)packet, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_STATUS_SYSTEM_COM UNPACKING


/**
 * @brief Get field target_system from tx1_status_system_com message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_status_system_com_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_status_system_com message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_status_system_com_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field target_ids from tx1_status_system_com message
 *
 * @return  The ids of all com channels
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_get_target_ids(const mavlink_message_t* msg, uint8_t *target_ids)
{
	return _MAV_RETURN_uint8_t_array(msg, target_ids, 8,  2);
}

/**
 * @brief Get field types from tx1_status_system_com message
 *
 * @return  Types of the com channels
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_get_types(const mavlink_message_t* msg, uint8_t *types)
{
	return _MAV_RETURN_uint8_t_array(msg, types, 8,  10);
}

/**
 * @brief Get field emit_status from tx1_status_system_com message
 *
 * @return  Emit status messages status of the com channels
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_get_emit_status(const mavlink_message_t* msg, uint8_t *emit_status)
{
	return _MAV_RETURN_uint8_t_array(msg, emit_status, 8,  18);
}

/**
 * @brief Get field mavlink from tx1_status_system_com message
 *
 * @return  Mavlink usage status of the com channels
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_get_mavlink(const mavlink_message_t* msg, uint8_t *mavlink)
{
	return _MAV_RETURN_uint8_t_array(msg, mavlink, 8,  26);
}

/**
 * @brief Get field running from tx1_status_system_com message
 *
 * @return  Running status of the com channels
			
 */
static inline uint16_t mavlink_msg_tx1_status_system_com_get_running(const mavlink_message_t* msg, uint8_t *running)
{
	return _MAV_RETURN_uint8_t_array(msg, running, 8,  34);
}

/**
 * @brief Decode a tx1_status_system_com message into a struct
 *
 * @param msg The message to decode
 * @param tx1_status_system_com C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_status_system_com_decode(const mavlink_message_t* msg, mavlink_tx1_status_system_com_t* tx1_status_system_com)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_status_system_com->target_system = mavlink_msg_tx1_status_system_com_get_target_system(msg);
	tx1_status_system_com->target_component = mavlink_msg_tx1_status_system_com_get_target_component(msg);
	mavlink_msg_tx1_status_system_com_get_target_ids(msg, tx1_status_system_com->target_ids);
	mavlink_msg_tx1_status_system_com_get_types(msg, tx1_status_system_com->types);
	mavlink_msg_tx1_status_system_com_get_emit_status(msg, tx1_status_system_com->emit_status);
	mavlink_msg_tx1_status_system_com_get_mavlink(msg, tx1_status_system_com->mavlink);
	mavlink_msg_tx1_status_system_com_get_running(msg, tx1_status_system_com->running);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN? msg->len : MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN;
        memset(tx1_status_system_com, 0, MAVLINK_MSG_ID_TX1_STATUS_SYSTEM_COM_LEN);
	memcpy(tx1_status_system_com, _MAV_PAYLOAD(msg), len);
#endif
}
