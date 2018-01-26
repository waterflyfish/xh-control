// MESSAGE TX1_CONTROL_PIPE_TRACK PACKING

#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK 65503

MAVPACKED(
typedef struct __mavlink_tx1_control_pipe_track_t {
 uint16_t tl_x; /*<  Top left corner x coordinate of target to track
			*/
 uint16_t tl_y; /*<  Top left corner y coordinate of target to track
			*/
 uint16_t rb_x; /*<  Bottom right corner x coordinate of target to track
			*/
 uint16_t rb_y; /*<  Bottom right corner y coordinate of target to track
			*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t target_id; /*<  The id of the target pipeline
			*/
 uint8_t track; /*<  Start/Stop tracking
			*/
}) mavlink_tx1_control_pipe_track_t;

#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN 12
#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN 12
#define MAVLINK_MSG_ID_65503_LEN 12
#define MAVLINK_MSG_ID_65503_MIN_LEN 12

#define MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC 163
#define MAVLINK_MSG_ID_65503_CRC 163



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_PIPE_TRACK { \
	65503, \
	"TX1_CONTROL_PIPE_TRACK", \
	8, \
	{  { "tl_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tx1_control_pipe_track_t, tl_x) }, \
         { "tl_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tx1_control_pipe_track_t, tl_y) }, \
         { "rb_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tx1_control_pipe_track_t, rb_x) }, \
         { "rb_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tx1_control_pipe_track_t, rb_y) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_tx1_control_pipe_track_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_tx1_control_pipe_track_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tx1_control_pipe_track_t, target_id) }, \
         { "track", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tx1_control_pipe_track_t, track) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_CONTROL_PIPE_TRACK { \
	"TX1_CONTROL_PIPE_TRACK", \
	8, \
	{  { "tl_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_tx1_control_pipe_track_t, tl_x) }, \
         { "tl_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_tx1_control_pipe_track_t, tl_y) }, \
         { "rb_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tx1_control_pipe_track_t, rb_x) }, \
         { "rb_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_tx1_control_pipe_track_t, rb_y) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_tx1_control_pipe_track_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_tx1_control_pipe_track_t, target_component) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tx1_control_pipe_track_t, target_id) }, \
         { "track", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tx1_control_pipe_track_t, track) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_control_pipe_track message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @param track  Start/Stop tracking
			
 * @param tl_x  Top left corner x coordinate of target to track
			
 * @param tl_y  Top left corner y coordinate of target to track
			
 * @param rb_x  Bottom right corner x coordinate of target to track
			
 * @param rb_y  Bottom right corner y coordinate of target to track
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t target_id, uint8_t track, uint16_t tl_x, uint16_t tl_y, uint16_t rb_x, uint16_t rb_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN];
	_mav_put_uint16_t(buf, 0, tl_x);
	_mav_put_uint16_t(buf, 2, tl_y);
	_mav_put_uint16_t(buf, 4, rb_x);
	_mav_put_uint16_t(buf, 6, rb_y);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, track);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN);
#else
	mavlink_tx1_control_pipe_track_t packet;
	packet.tl_x = tl_x;
	packet.tl_y = tl_y;
	packet.rb_x = rb_x;
	packet.rb_y = rb_y;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.track = track;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC);
}

/**
 * @brief Pack a tx1_control_pipe_track message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @param track  Start/Stop tracking
			
 * @param tl_x  Top left corner x coordinate of target to track
			
 * @param tl_y  Top left corner y coordinate of target to track
			
 * @param rb_x  Bottom right corner x coordinate of target to track
			
 * @param rb_y  Bottom right corner y coordinate of target to track
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t target_id,uint8_t track,uint16_t tl_x,uint16_t tl_y,uint16_t rb_x,uint16_t rb_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN];
	_mav_put_uint16_t(buf, 0, tl_x);
	_mav_put_uint16_t(buf, 2, tl_y);
	_mav_put_uint16_t(buf, 4, rb_x);
	_mav_put_uint16_t(buf, 6, rb_y);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, track);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN);
#else
	mavlink_tx1_control_pipe_track_t packet;
	packet.tl_x = tl_x;
	packet.tl_y = tl_y;
	packet.rb_x = rb_x;
	packet.rb_y = rb_y;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.track = track;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC);
}

/**
 * @brief Encode a tx1_control_pipe_track struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_pipe_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_control_pipe_track_t* tx1_control_pipe_track)
{
	return mavlink_msg_tx1_control_pipe_track_pack(system_id, component_id, msg, tx1_control_pipe_track->target_system, tx1_control_pipe_track->target_component, tx1_control_pipe_track->target_id, tx1_control_pipe_track->track, tx1_control_pipe_track->tl_x, tx1_control_pipe_track->tl_y, tx1_control_pipe_track->rb_x, tx1_control_pipe_track->rb_y);
}

/**
 * @brief Encode a tx1_control_pipe_track struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_control_pipe_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_control_pipe_track_t* tx1_control_pipe_track)
{
	return mavlink_msg_tx1_control_pipe_track_pack_chan(system_id, component_id, chan, msg, tx1_control_pipe_track->target_system, tx1_control_pipe_track->target_component, tx1_control_pipe_track->target_id, tx1_control_pipe_track->track, tx1_control_pipe_track->tl_x, tx1_control_pipe_track->tl_y, tx1_control_pipe_track->rb_x, tx1_control_pipe_track->rb_y);
}

/**
 * @brief Send a tx1_control_pipe_track message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target_id  The id of the target pipeline
			
 * @param track  Start/Stop tracking
			
 * @param tl_x  Top left corner x coordinate of target to track
			
 * @param tl_y  Top left corner y coordinate of target to track
			
 * @param rb_x  Bottom right corner x coordinate of target to track
			
 * @param rb_y  Bottom right corner y coordinate of target to track
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_control_pipe_track_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t target_id, uint8_t track, uint16_t tl_x, uint16_t tl_y, uint16_t rb_x, uint16_t rb_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN];
	_mav_put_uint16_t(buf, 0, tl_x);
	_mav_put_uint16_t(buf, 2, tl_y);
	_mav_put_uint16_t(buf, 4, rb_x);
	_mav_put_uint16_t(buf, 6, rb_y);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, track);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK, buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC);
#else
	mavlink_tx1_control_pipe_track_t packet;
	packet.tl_x = tl_x;
	packet.tl_y = tl_y;
	packet.rb_x = rb_x;
	packet.rb_y = rb_y;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.track = track;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK, (const char *)&packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC);
#endif
}

/**
 * @brief Send a tx1_control_pipe_track message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_control_pipe_track_send_struct(mavlink_channel_t chan, const mavlink_tx1_control_pipe_track_t* tx1_control_pipe_track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_control_pipe_track_send(chan, tx1_control_pipe_track->target_system, tx1_control_pipe_track->target_component, tx1_control_pipe_track->target_id, tx1_control_pipe_track->track, tx1_control_pipe_track->tl_x, tx1_control_pipe_track->tl_y, tx1_control_pipe_track->rb_x, tx1_control_pipe_track->rb_y);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK, (const char *)tx1_control_pipe_track, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_control_pipe_track_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t target_id, uint8_t track, uint16_t tl_x, uint16_t tl_y, uint16_t rb_x, uint16_t rb_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, tl_x);
	_mav_put_uint16_t(buf, 2, tl_y);
	_mav_put_uint16_t(buf, 4, rb_x);
	_mav_put_uint16_t(buf, 6, rb_y);
	_mav_put_uint8_t(buf, 8, target_system);
	_mav_put_uint8_t(buf, 9, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, track);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK, buf, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC);
#else
	mavlink_tx1_control_pipe_track_t *packet = (mavlink_tx1_control_pipe_track_t *)msgbuf;
	packet->tl_x = tl_x;
	packet->tl_y = tl_y;
	packet->rb_x = rb_x;
	packet->rb_y = rb_y;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->target_id = target_id;
	packet->track = track;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK, (const char *)packet, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_MIN_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_CONTROL_PIPE_TRACK UNPACKING


/**
 * @brief Get field target_system from tx1_control_pipe_track message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_track_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from tx1_control_pipe_track message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_track_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field target_id from tx1_control_pipe_track message
 *
 * @return  The id of the target pipeline
			
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_track_get_target_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field track from tx1_control_pipe_track message
 *
 * @return  Start/Stop tracking
			
 */
static inline uint8_t mavlink_msg_tx1_control_pipe_track_get_track(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field tl_x from tx1_control_pipe_track message
 *
 * @return  Top left corner x coordinate of target to track
			
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_get_tl_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field tl_y from tx1_control_pipe_track message
 *
 * @return  Top left corner y coordinate of target to track
			
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_get_tl_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field rb_x from tx1_control_pipe_track message
 *
 * @return  Bottom right corner x coordinate of target to track
			
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_get_rb_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field rb_y from tx1_control_pipe_track message
 *
 * @return  Bottom right corner y coordinate of target to track
			
 */
static inline uint16_t mavlink_msg_tx1_control_pipe_track_get_rb_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Decode a tx1_control_pipe_track message into a struct
 *
 * @param msg The message to decode
 * @param tx1_control_pipe_track C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_control_pipe_track_decode(const mavlink_message_t* msg, mavlink_tx1_control_pipe_track_t* tx1_control_pipe_track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_control_pipe_track->tl_x = mavlink_msg_tx1_control_pipe_track_get_tl_x(msg);
	tx1_control_pipe_track->tl_y = mavlink_msg_tx1_control_pipe_track_get_tl_y(msg);
	tx1_control_pipe_track->rb_x = mavlink_msg_tx1_control_pipe_track_get_rb_x(msg);
	tx1_control_pipe_track->rb_y = mavlink_msg_tx1_control_pipe_track_get_rb_y(msg);
	tx1_control_pipe_track->target_system = mavlink_msg_tx1_control_pipe_track_get_target_system(msg);
	tx1_control_pipe_track->target_component = mavlink_msg_tx1_control_pipe_track_get_target_component(msg);
	tx1_control_pipe_track->target_id = mavlink_msg_tx1_control_pipe_track_get_target_id(msg);
	tx1_control_pipe_track->track = mavlink_msg_tx1_control_pipe_track_get_track(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN? msg->len : MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN;
        memset(tx1_control_pipe_track, 0, MAVLINK_MSG_ID_TX1_CONTROL_PIPE_TRACK_LEN);
	memcpy(tx1_control_pipe_track, _MAV_PAYLOAD(msg), len);
#endif
}
