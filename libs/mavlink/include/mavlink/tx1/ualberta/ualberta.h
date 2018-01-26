/** @file
 *	@brief MAVLink comm protocol generated from ualberta.xml
 *	@see http://mavlink.org
 */
#ifndef MAVLINK_UALBERTA_H
#define MAVLINK_UALBERTA_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_UALBERTA.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{220, 34, 32, 0, 0, 0}, {221, 71, 42, 0, 0, 0}, {222, 15, 3, 0, 0, 0}}
#endif

#ifndef MAVLINK_MESSAGE_INFO
#define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_NAV_FILTER_BIAS, MAVLINK_MESSAGE_INFO_RADIO_CALIBRATION, MAVLINK_MESSAGE_INFO_UALBERTA_SYS_STATUS}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_UALBERTA

// ENUM DEFINITIONS


/** @brief Available autopilot modes for ualberta uav */
#ifndef HAVE_ENUM_UALBERTA_AUTOPILOT_MODE
#define HAVE_ENUM_UALBERTA_AUTOPILOT_MODE
typedef enum UALBERTA_AUTOPILOT_MODE
{
	MODE_MANUAL_DIRECT=1, /* Raw input pulse widts sent to output | */
	MODE_MANUAL_SCALED=2, /* Inputs are normalized using calibration, the converted back to raw pulse widths for output | */
	MODE_AUTO_PID_ATT=3, /*  dfsdfs | */
	MODE_AUTO_PID_VEL=4, /*  dfsfds | */
	MODE_AUTO_PID_POS=5, /*  dfsdfsdfs | */
	UALBERTA_AUTOPILOT_MODE_ENUM_END=6, /*  | */
} UALBERTA_AUTOPILOT_MODE;
#endif

/** @brief Navigation filter mode */
#ifndef HAVE_ENUM_UALBERTA_NAV_MODE
#define HAVE_ENUM_UALBERTA_NAV_MODE
typedef enum UALBERTA_NAV_MODE
{
	NAV_AHRS_INIT=1, /*  | */
	NAV_AHRS=2, /* AHRS mode | */
	NAV_INS_GPS_INIT=3, /* INS/GPS initialization mode | */
	NAV_INS_GPS=4, /* INS/GPS mode | */
	UALBERTA_NAV_MODE_ENUM_END=5, /*  | */
} UALBERTA_NAV_MODE;
#endif

/** @brief Mode currently commanded by pilot */
#ifndef HAVE_ENUM_UALBERTA_PILOT_MODE
#define HAVE_ENUM_UALBERTA_PILOT_MODE
typedef enum UALBERTA_PILOT_MODE
{
	PILOT_MANUAL=1, /*  sdf | */
	PILOT_AUTO=2, /*  dfs | */
	PILOT_ROTO=3, /*  Rotomotion mode  | */
	UALBERTA_PILOT_MODE_ENUM_END=4, /*  | */
} UALBERTA_PILOT_MODE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_nav_filter_bias.h"
#include "./mavlink_msg_radio_calibration.h"
#include "./mavlink_msg_ualberta_sys_status.h"

// base include
#include "../common/common.h"

#if MAVLINK_COMMAND_24BIT
#include "../mavlink_get_info.h"
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_UALBERTA_H
