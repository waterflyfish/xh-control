// MESSAGE TX1_STATUS_COM PACKING

#define MAVLINK_MSG_ID_TX1_STATUS_COM 65512

MAVPACKED(
typedef struct __mavlink_tx1_status_com_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 char target[8]; /*<  Name of the target com channel
			*/
 uint8_t target_id; /*<  The id of the target com channel
			*/
 uint8_t type; /*<  Type of the com channel
			*/
 uint8_t emit_status; /*<  Emit status messages status
			*/
 uint8_t mavlink; /*<  Is mavlink com channel or not
			*/
 uint8_t running; /*<  Com channel running status
			*/
 char value0[15]; /*< 
				
				
				
				
			*/
 char value1[5]; /*< 
				
				
				
				
			*/
 char value2[15]; /*< 
				
				
				
				
			*/
 char value3[5]; /*< 
				
				
				
				
			*/
}) mavlink_tx1_status_com_t;

#define MAVLINK_MSG_ID_TX1_STATUS_COM_LEN 55
#define MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN 55
#define MAVLINK_MSG_ID_65512_LEN 55
#define MAVLINK_MSG_ID_65512_MIN_LEN 55

#define MAVLINK_MSG_ID_TX1_STATUS_COM_CRC 24
#define MAVLINK_MSG_ID_65512_CRC 24

#define MAVLINK_MSG_TX1_STATUS_COM_FIELD_TARGET_LEN 8
#define MAVLINK_MSG_TX1_STATUS_COM_FIELD_VALUE0_LEN 15
#define MAVLINK_MSG_TX1_STATUS_COM_FIELD_VALUE1_LEN 5
#define MAVLINK_MSG_TX1_STATUS_COM_FIELD_VALUE2_LEN 15
#define MAVLINK_MSG_TX1_STATUS_COM_FIELD_VALUE3_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_COM { \
	65512, \
	"TX1_STATUS_COM", \
	12, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_com_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_com_t, target_component) }, \
         { "target", NULL, MAVLINK_TYPE_CHAR, 8, 2, offsetof(mavlink_tx1_status_com_t, target) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tx1_status_com_t, target_id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tx1_status_com_t, type) }, \
         { "emit_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tx1_status_com_t, emit_status) }, \
         { "mavlink", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tx1_status_com_t, mavlink) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tx1_status_com_t, running) }, \
         { "value0", NULL, MAVLINK_TYPE_CHAR, 15, 15, offsetof(mavlink_tx1_status_com_t, value0) }, \
         { "value1", NULL, MAVLINK_TYPE_CHAR, 5, 30, offsetof(mavlink_tx1_status_com_t, value1) }, \
         { "value2", NULL, MAVLINK_TYPE_CHAR, 15, 35, offsetof(mavlink_tx1_status_com_t, value2) }, \
         { "value3", NULL, MAVLINK_TYPE_CHAR, 5, 50, offsetof(mavlink_tx1_status_com_t, value3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TX1_STATUS_COM { \
	"TX1_STATUS_COM", \
	12, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_tx1_status_com_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_tx1_status_com_t, target_component) }, \
         { "target", NULL, MAVLINK_TYPE_CHAR, 8, 2, offsetof(mavlink_tx1_status_com_t, target) }, \
         { "target_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_tx1_status_com_t, target_id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_tx1_status_com_t, type) }, \
         { "emit_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tx1_status_com_t, emit_status) }, \
         { "mavlink", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_tx1_status_com_t, mavlink) }, \
         { "running", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_tx1_status_com_t, running) }, \
         { "value0", NULL, MAVLINK_TYPE_CHAR, 15, 15, offsetof(mavlink_tx1_status_com_t, value0) }, \
         { "value1", NULL, MAVLINK_TYPE_CHAR, 5, 30, offsetof(mavlink_tx1_status_com_t, value1) }, \
         { "value2", NULL, MAVLINK_TYPE_CHAR, 15, 35, offsetof(mavlink_tx1_status_com_t, value2) }, \
         { "value3", NULL, MAVLINK_TYPE_CHAR, 5, 50, offsetof(mavlink_tx1_status_com_t, value3) }, \
         } \
}
#endif

/**
 * @brief Pack a tx1_status_com message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target  Name of the target com channel
			
 * @param target_id  The id of the target com channel
			
 * @param type  Type of the com channel
			
 * @param emit_status  Emit status messages status
			
 * @param mavlink  Is mavlink com channel or not
			
 * @param running  Com channel running status
			
 * @param value0 
				
				
				
				
			
 * @param value1 
				
				
				
				
			
 * @param value2 
				
				
				
				
			
 * @param value3 
				
				
				
				
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_com_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, const char *target, uint8_t target_id, uint8_t type, uint8_t emit_status, uint8_t mavlink, uint8_t running, const char *value0, const char *value1, const char *value2, const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_COM_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, emit_status);
	_mav_put_uint8_t(buf, 13, mavlink);
	_mav_put_uint8_t(buf, 14, running);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 15);
	_mav_put_char_array(buf, 30, value1, 5);
	_mav_put_char_array(buf, 35, value2, 15);
	_mav_put_char_array(buf, 50, value3, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN);
#else
	mavlink_tx1_status_com_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.type = type;
	packet.emit_status = emit_status;
	packet.mavlink = mavlink;
	packet.running = running;
	mav_array_memcpy(packet.target, target, sizeof(char)*8);
	mav_array_memcpy(packet.value0, value0, sizeof(char)*15);
	mav_array_memcpy(packet.value1, value1, sizeof(char)*5);
	mav_array_memcpy(packet.value2, value2, sizeof(char)*15);
	mav_array_memcpy(packet.value3, value3, sizeof(char)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_COM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_CRC);
}

/**
 * @brief Pack a tx1_status_com message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param target  Name of the target com channel
			
 * @param target_id  The id of the target com channel
			
 * @param type  Type of the com channel
			
 * @param emit_status  Emit status messages status
			
 * @param mavlink  Is mavlink com channel or not
			
 * @param running  Com channel running status
			
 * @param value0 
				
				
				
				
			
 * @param value1 
				
				
				
				
			
 * @param value2 
				
				
				
				
			
 * @param value3 
				
				
				
				
			
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tx1_status_com_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,const char *target,uint8_t target_id,uint8_t type,uint8_t emit_status,uint8_t mavlink,uint8_t running,const char *value0,const char *value1,const char *value2,const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_COM_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, emit_status);
	_mav_put_uint8_t(buf, 13, mavlink);
	_mav_put_uint8_t(buf, 14, running);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 15);
	_mav_put_char_array(buf, 30, value1, 5);
	_mav_put_char_array(buf, 35, value2, 15);
	_mav_put_char_array(buf, 50, value3, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN);
#else
	mavlink_tx1_status_com_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.type = type;
	packet.emit_status = emit_status;
	packet.mavlink = mavlink;
	packet.running = running;
	mav_array_memcpy(packet.target, target, sizeof(char)*8);
	mav_array_memcpy(packet.value0, value0, sizeof(char)*15);
	mav_array_memcpy(packet.value1, value1, sizeof(char)*5);
	mav_array_memcpy(packet.value2, value2, sizeof(char)*15);
	mav_array_memcpy(packet.value3, value3, sizeof(char)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TX1_STATUS_COM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_CRC);
}

/**
 * @brief Encode a tx1_status_com struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_com C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_com_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tx1_status_com_t* tx1_status_com)
{
	return mavlink_msg_tx1_status_com_pack(system_id, component_id, msg, tx1_status_com->target_system, tx1_status_com->target_component, tx1_status_com->target, tx1_status_com->target_id, tx1_status_com->type, tx1_status_com->emit_status, tx1_status_com->mavlink, tx1_status_com->running, tx1_status_com->value0, tx1_status_com->value1, tx1_status_com->value2, tx1_status_com->value3);
}

/**
 * @brief Encode a tx1_status_com struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tx1_status_com C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tx1_status_com_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tx1_status_com_t* tx1_status_com)
{
	return mavlink_msg_tx1_status_com_pack_chan(system_id, component_id, chan, msg, tx1_status_com->target_system, tx1_status_com->target_component, tx1_status_com->target, tx1_status_com->target_id, tx1_status_com->type, tx1_status_com->emit_status, tx1_status_com->mavlink, tx1_status_com->running, tx1_status_com->value0, tx1_status_com->value1, tx1_status_com->value2, tx1_status_com->value3);
}

/**
 * @brief Send a tx1_status_com message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param target  Name of the target com channel
			
 * @param target_id  The id of the target com channel
			
 * @param type  Type of the com channel
			
 * @param emit_status  Emit status messages status
			
 * @param mavlink  Is mavlink com channel or not
			
 * @param running  Com channel running status
			
 * @param value0 
				
				
				
				
			
 * @param value1 
				
				
				
				
			
 * @param value2 
				
				
				
				
			
 * @param value3 
				
				
				
				
			
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tx1_status_com_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const char *target, uint8_t target_id, uint8_t type, uint8_t emit_status, uint8_t mavlink, uint8_t running, const char *value0, const char *value1, const char *value2, const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TX1_STATUS_COM_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, emit_status);
	_mav_put_uint8_t(buf, 13, mavlink);
	_mav_put_uint8_t(buf, 14, running);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 15);
	_mav_put_char_array(buf, 30, value1, 5);
	_mav_put_char_array(buf, 35, value2, 15);
	_mav_put_char_array(buf, 50, value3, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_COM, buf, MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_CRC);
#else
	mavlink_tx1_status_com_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.target_id = target_id;
	packet.type = type;
	packet.emit_status = emit_status;
	packet.mavlink = mavlink;
	packet.running = running;
	mav_array_memcpy(packet.target, target, sizeof(char)*8);
	mav_array_memcpy(packet.value0, value0, sizeof(char)*15);
	mav_array_memcpy(packet.value1, value1, sizeof(char)*5);
	mav_array_memcpy(packet.value2, value2, sizeof(char)*15);
	mav_array_memcpy(packet.value3, value3, sizeof(char)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_COM, (const char *)&packet, MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_CRC);
#endif
}

/**
 * @brief Send a tx1_status_com message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tx1_status_com_send_struct(mavlink_channel_t chan, const mavlink_tx1_status_com_t* tx1_status_com)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tx1_status_com_send(chan, tx1_status_com->target_system, tx1_status_com->target_component, tx1_status_com->target, tx1_status_com->target_id, tx1_status_com->type, tx1_status_com->emit_status, tx1_status_com->mavlink, tx1_status_com->running, tx1_status_com->value0, tx1_status_com->value1, tx1_status_com->value2, tx1_status_com->value3);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_COM, (const char *)tx1_status_com, MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_CRC);
#endif
}

#if MAVLINK_MSG_ID_TX1_STATUS_COM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tx1_status_com_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, const char *target, uint8_t target_id, uint8_t type, uint8_t emit_status, uint8_t mavlink, uint8_t running, const char *value0, const char *value1, const char *value2, const char *value3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);
	_mav_put_uint8_t(buf, 10, target_id);
	_mav_put_uint8_t(buf, 11, type);
	_mav_put_uint8_t(buf, 12, emit_status);
	_mav_put_uint8_t(buf, 13, mavlink);
	_mav_put_uint8_t(buf, 14, running);
	_mav_put_char_array(buf, 2, target, 8);
	_mav_put_char_array(buf, 15, value0, 15);
	_mav_put_char_array(buf, 30, value1, 5);
	_mav_put_char_array(buf, 35, value2, 15);
	_mav_put_char_array(buf, 50, value3, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_COM, buf, MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_CRC);
#else
	mavlink_tx1_status_com_t *packet = (mavlink_tx1_status_com_t *)msgbuf;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->target_id = target_id;
	packet->type = type;
	packet->emit_status = emit_status;
	packet->mavlink = mavlink;
	packet->running = running;
	mav_array_memcpy(packet->target, target, sizeof(char)*8);
	mav_array_memcpy(packet->value0, value0, sizeof(char)*15);
	mav_array_memcpy(packet->value1, value1, sizeof(char)*5);
	mav_array_memcpy(packet->value2, value2, sizeof(char)*15);
	mav_array_memcpy(packet->value3, value3, sizeof(char)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TX1_STATUS_COM, (const char *)packet, MAVLINK_MSG_ID_TX1_STATUS_COM_MIN_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN, MAVLINK_MSG_ID_TX1_STATUS_COM_CRC);
#endif
}
#endif

#endif

// MESSAGE TX1_STATUS_COM UNPACKING


/**
 * @brief Get field target_system from tx1_status_com message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_tx1_status_com_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from tx1_status_com message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_tx1_status_com_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field target from tx1_status_com message
 *
 * @return  Name of the target com channel
			
 */
static inline uint16_t mavlink_msg_tx1_status_com_get_target(const mavlink_message_t* msg, char *target)
{
	return _MAV_RETURN_char_array(msg, target, 8,  2);
}

/**
 * @brief Get field target_id from tx1_status_com message
 *
 * @return  The id of the target com channel
			
 */
static inline uint8_t mavlink_msg_tx1_status_com_get_target_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field type from tx1_status_com message
 *
 * @return  Type of the com channel
			
 */
static inline uint8_t mavlink_msg_tx1_status_com_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field emit_status from tx1_status_com message
 *
 * @return  Emit status messages status
			
 */
static inline uint8_t mavlink_msg_tx1_status_com_get_emit_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field mavlink from tx1_status_com message
 *
 * @return  Is mavlink com channel or not
			
 */
static inline uint8_t mavlink_msg_tx1_status_com_get_mavlink(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field running from tx1_status_com message
 *
 * @return  Com channel running status
			
 */
static inline uint8_t mavlink_msg_tx1_status_com_get_running(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field value0 from tx1_status_com message
 *
 * @return 
				
				
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_com_get_value0(const mavlink_message_t* msg, char *value0)
{
	return _MAV_RETURN_char_array(msg, value0, 15,  15);
}

/**
 * @brief Get field value1 from tx1_status_com message
 *
 * @return 
				
				
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_com_get_value1(const mavlink_message_t* msg, char *value1)
{
	return _MAV_RETURN_char_array(msg, value1, 5,  30);
}

/**
 * @brief Get field value2 from tx1_status_com message
 *
 * @return 
				
				
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_com_get_value2(const mavlink_message_t* msg, char *value2)
{
	return _MAV_RETURN_char_array(msg, value2, 15,  35);
}

/**
 * @brief Get field value3 from tx1_status_com message
 *
 * @return 
				
				
				
				
			
 */
static inline uint16_t mavlink_msg_tx1_status_com_get_value3(const mavlink_message_t* msg, char *value3)
{
	return _MAV_RETURN_char_array(msg, value3, 5,  50);
}

/**
 * @brief Decode a tx1_status_com message into a struct
 *
 * @param msg The message to decode
 * @param tx1_status_com C-struct to decode the message contents into
 */
static inline void mavlink_msg_tx1_status_com_decode(const mavlink_message_t* msg, mavlink_tx1_status_com_t* tx1_status_com)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	tx1_status_com->target_system = mavlink_msg_tx1_status_com_get_target_system(msg);
	tx1_status_com->target_component = mavlink_msg_tx1_status_com_get_target_component(msg);
	mavlink_msg_tx1_status_com_get_target(msg, tx1_status_com->target);
	tx1_status_com->target_id = mavlink_msg_tx1_status_com_get_target_id(msg);
	tx1_status_com->type = mavlink_msg_tx1_status_com_get_type(msg);
	tx1_status_com->emit_status = mavlink_msg_tx1_status_com_get_emit_status(msg);
	tx1_status_com->mavlink = mavlink_msg_tx1_status_com_get_mavlink(msg);
	tx1_status_com->running = mavlink_msg_tx1_status_com_get_running(msg);
	mavlink_msg_tx1_status_com_get_value0(msg, tx1_status_com->value0);
	mavlink_msg_tx1_status_com_get_value1(msg, tx1_status_com->value1);
	mavlink_msg_tx1_status_com_get_value2(msg, tx1_status_com->value2);
	mavlink_msg_tx1_status_com_get_value3(msg, tx1_status_com->value3);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TX1_STATUS_COM_LEN? msg->len : MAVLINK_MSG_ID_TX1_STATUS_COM_LEN;
        memset(tx1_status_com, 0, MAVLINK_MSG_ID_TX1_STATUS_COM_LEN);
	memcpy(tx1_status_com, _MAV_PAYLOAD(msg), len);
#endif
}
