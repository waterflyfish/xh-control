// MESSAGE TX1_CONTROL_COM_FLOW PACKING

#define MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW 65504

MAVPACKED(
typedef struct __mavlink_tx1_control_com_flow_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t target_id; /*<  The id of the target com channel
			*/
}) mavlink_tx1_control_com_flow_t;

#define MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN 3
#define MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN 3
#define MAVLINK_MSG_ID_65504_LEN 3
#define MAVLINK_MSG_ID_65504_MIN_LEN 3

#define MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC 30
#define MAVLINK_MSG_ID_65504_CRC 30



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_COM_FLOW { \
	65504, \
	"TX1_CONTROL_COM_FLOW", \
	3, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_com_flow_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_control_com_flow_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_control_com_flow_t, target_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_COM_FLOW { \
	"TX1_CONTROL_COM_FLOW", \
	3, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_com_flow_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_control_com_flow_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_control_com_flow_t, target_id) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_control_com_flow message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target com channel
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_com_flow_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN);
#else
	mavlink_tx1_control_com_flow_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC);
}

/**
 * @brief Pack a tx1_control_com_flow message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target com channel
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_com_flow_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN);
#else
	mavlink_tx1_control_com_flow_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC);
}

/**
 * @brief Encode a tx1_control_com_flow struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_com_flow C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_com_flow_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_control_com_flow_t* tx1_control_com_flow)
{
	return mavlink_msg_tx1_control_com_flow_pack(system_id, component_id, msg, tx1_control_com_flow->target_system, tx1_control_com_flow->target_component, tx1_control_com_flow->target_id);
}

/**
 * @brief Encode a tx1_control_com_flow struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_com_flow C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_com_flow_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_control_com_flow_t* tx1_control_com_flow)
{
	return mavlink_msg_tx1_control_com_flow_pack_chan(system_id, component_id, chan, msg, tx1_control_com_flow->target_system, tx1_control_com_flow->target_component, tx1_control_com_flow->target_id);
}

/**
 * @brief Send a tx1_control_com_flow message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target com channel
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_control_com_flow_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW, buf, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC);
#else
	mavlink_tx1_control_com_flow_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW, (const char *)&packet, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC);
#endif
}

/**
 * @brief Send a tx1_control_com_flow message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_control_com_flow_send_struct(mavlink_channel_t chan, const mavlink_tx1_control_com_flow_t* tx1_control_com_flow)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_control_com_flow_send(chan, tx1_control_com_flow->target_system, tx1_control_com_flow->target_component, tx1_control_com_flow->target_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW, (const char *)tx1_control_com_flow, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_control_com_flow_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW, buf, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC);
#else
	mavlink_tx1_control_com_flow_t *packet = (mavlink_tx1_control_com_flow_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->target_id = target_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW, (const char *)packet, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_CONTROL_COM_FLOW UNPACKING


/**
 * @brief Get field target_system from tx1_control_com_flow message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_control_com_flow_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_control_com_flow message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_control_com_flow_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field target_id from tx1_control_com_flow message
 *
 * @return  The id of the target com channel
			
 */
static inline uint8_t mavlink_msg_tx1_control_com_flow_get_target_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a tx1_control_com_flow message into a struct
 *
 * @param msg The message to decode
 * @param tx1_control_com_flow C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_control_com_flow_decode(const mavlink_message_t* msg, mavlink_tx1_control_com_flow_t* tx1_control_com_flow)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_control_com_flow->target_system = mavlink_msg_tx1_control_com_flow_get_target_system(msg);
	tx1_control_com_flow->target_component = mavlink_msg_tx1_control_com_flow_get_target_component(msg);
	tx1_control_com_flow->target_id = mavlink_msg_tx1_control_com_flow_get_target_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN? msg->len : MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN;
        memset(tx1_control_com_flow, 0, MAVLINK_MSG_ID_TX1_CONTROL_COM_FLOW_LEN);
	memcpy(tx1_control_com_flow, _MAV_PAYLOAD(msg), len);
#endif
}
