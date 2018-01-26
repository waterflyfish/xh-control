// MESSAGE TX1_STATUS_ACK PACKING

#define MAVLINK_MSG_ID_TX1_STATUS_ACK 65514

MAVPACKED(
typedef struct __mavlink_tx1_status_ack_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t status; /*<  ACK status of the command this message is acknowledgeing
			*/
}) mavlink_tx1_status_ack_t;

#define MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN 3
#define MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN 3
#define MAVLINK_MSG_ID_65514_LEN 3
#define MAVLINK_MSG_ID_65514_MIN_LEN 3

#define MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC 197
#define MAVLINK_MSG_ID_65514_CRC 197



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_ACK { \
	65514, \
	"TX1_STATUS_ACK", \
	3, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_ack_t, target_component) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_status_ack_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_ACK { \
	"TX1_STATUS_ACK", \
	3, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_ack_t, target_component) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_status_ack_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_status_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param status  ACK status of the command this message is acknowledgeing
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN);
#else
	mavlink_tx1_status_ack_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC);
}

/**
 * @brief Pack a tx1_status_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param status  ACK status of the command this message is acknowledgeing
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN);
#else
	mavlink_tx1_status_ack_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC);
}

/**
 * @brief Encode a tx1_status_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_status_ack_t* tx1_status_ack)
{
	return mavlink_msg_tx1_status_ack_pack(system_id, component_id, msg, tx1_status_ack->target_system, tx1_status_ack->target_component, tx1_status_ack->status);
}

/**
 * @brief Encode a tx1_status_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_status_ack_t* tx1_status_ack)
{
	return mavlink_msg_tx1_status_ack_pack_chan(system_id, component_id, chan, msg, tx1_status_ack->target_system, tx1_status_ack->target_component, tx1_status_ack->status);
}

/**
 * @brief Send a tx1_status_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param status  ACK status of the command this message is acknowledgeing
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_status_ack_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_ACK, buf, MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC);
#else
	mavlink_tx1_status_ack_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_ACK, (const char *)&packet, MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC);
#endif
}

/**
 * @brief Send a tx1_status_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_status_ack_send_struct(mavlink_channel_t chan, const mavlink_tx1_status_ack_t* tx1_status_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_status_ack_send(chan, tx1_status_ack->target_system, tx1_status_ack->target_component, tx1_status_ack->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_ACK, (const char *)tx1_status_ack, MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_status_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_ACK, buf, MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC);
#else
	mavlink_tx1_status_ack_t *packet = (mavlink_tx1_status_ack_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_ACK, (const char *)packet, MAVLINK_MSG_ID_TX1_STATUS_ACK_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN, MAVLINK_MSG_ID_TX1_STATUS_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_STATUS_ACK UNPACKING


/**
 * @brief Get field target_system from tx1_status_ack message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_status_ack_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_status_ack message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_status_ack_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field status from tx1_status_ack message
 *
 * @return  ACK status of the command this message is acknowledgeing
			
 */
static inline uint8_t mavlink_msg_tx1_status_ack_get_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a tx1_status_ack message into a struct
 *
 * @param msg The message to decode
 * @param tx1_status_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_status_ack_decode(const mavlink_message_t* msg, mavlink_tx1_status_ack_t* tx1_status_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_status_ack->target_system = mavlink_msg_tx1_status_ack_get_target_system(msg);
	tx1_status_ack->target_component = mavlink_msg_tx1_status_ack_get_target_component(msg);
	tx1_status_ack->status = mavlink_msg_tx1_status_ack_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN? msg->len : MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN;
        memset(tx1_status_ack, 0, MAVLINK_MSG_ID_TX1_STATUS_ACK_LEN);
	memcpy(tx1_status_ack, _MAV_PAYLOAD(msg), len);
#endif
}
