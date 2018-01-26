// MESSAGE TX1_CONTROL_SETUP_PIPE PACKING

#define MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE 65506

MAVPACKED(
typedef struct __mavlink_tx1_control_setup_pipe_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t target_id; /*<  The id of the target pipeline
			*/
}) mavlink_tx1_control_setup_pipe_t;

#define MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN 3
#define MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN 3
#define MAVLINK_MSG_ID_65506_LEN 3
#define MAVLINK_MSG_ID_65506_MIN_LEN 3

#define MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC 210
#define MAVLINK_MSG_ID_65506_CRC 210



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_SETUP_PIPE { \
	65506, \
	"TX1_CONTROL_SETUP_PIPE", \
	3, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_setup_pipe_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_control_setup_pipe_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_control_setup_pipe_t, target_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_SETUP_PIPE { \
	"TX1_CONTROL_SETUP_PIPE", \
	3, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_control_setup_pipe_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_control_setup_pipe_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_tx1_control_setup_pipe_t, target_id) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_control_setup_pipe message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_setup_pipe_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN);
#else
	mavlink_tx1_control_setup_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC);
}

/**
 * @brief Pack a tx1_control_setup_pipe message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_setup_pipe_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN);
#else
	mavlink_tx1_control_setup_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC);
}

/**
 * @brief Encode a tx1_control_setup_pipe struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_setup_pipe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_setup_pipe_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_control_setup_pipe_t* tx1_control_setup_pipe)
{
	return mavlink_msg_tx1_control_setup_pipe_pack(system_id, component_id, msg, tx1_control_setup_pipe->target_system, tx1_control_setup_pipe->target_component, tx1_control_setup_pipe->target_id);
}

/**
 * @brief Encode a tx1_control_setup_pipe struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_setup_pipe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_setup_pipe_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_control_setup_pipe_t* tx1_control_setup_pipe)
{
	return mavlink_msg_tx1_control_setup_pipe_pack_chan(system_id, component_id, chan, msg, tx1_control_setup_pipe->target_system, tx1_control_setup_pipe->target_component, tx1_control_setup_pipe->target_id);
}

/**
 * @brief Send a tx1_control_setup_pipe message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_control_setup_pipe_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE, buf, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC);
#else
	mavlink_tx1_control_setup_pipe_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE, (const char *)&packet, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC);
#endif
}

/**
 * @brief Send a tx1_control_setup_pipe message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_control_setup_pipe_send_struct(mavlink_channel_t chan, const mavlink_tx1_control_setup_pipe_t* tx1_control_setup_pipe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_control_setup_pipe_send(chan, tx1_control_setup_pipe->target_system, tx1_control_setup_pipe->target_component, tx1_control_setup_pipe->target_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE, (const char *)tx1_control_setup_pipe, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_control_setup_pipe_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t target_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 2, target_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE, buf, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC);
#else
	mavlink_tx1_control_setup_pipe_t *packet = (mavlink_tx1_control_setup_pipe_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->target_id = target_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE, (const char *)packet, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_CONTROL_SETUP_PIPE UNPACKING


/**
 * @brief Get field target_system from tx1_control_setup_pipe message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_control_setup_pipe_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_control_setup_pipe message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_control_setup_pipe_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field target_id from tx1_control_setup_pipe message
 *
 * @return  The id of the target pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_control_setup_pipe_get_target_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a tx1_control_setup_pipe message into a struct
 *
 * @param msg The message to decode
 * @param tx1_control_setup_pipe C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_control_setup_pipe_decode(const mavlink_message_t* msg, mavlink_tx1_control_setup_pipe_t* tx1_control_setup_pipe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_control_setup_pipe->target_system = mavlink_msg_tx1_control_setup_pipe_get_target_system(msg);
	tx1_control_setup_pipe->target_component = mavlink_msg_tx1_control_setup_pipe_get_target_component(msg);
	tx1_control_setup_pipe->target_id = mavlink_msg_tx1_control_setup_pipe_get_target_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN? msg->len : MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN;
        memset(tx1_control_setup_pipe, 0, MAVLINK_MSG_ID_TX1_CONTROL_SETUP_PIPE_LEN);
	memcpy(tx1_control_setup_pipe, _MAV_PAYLOAD(msg), len);
#endif
}
