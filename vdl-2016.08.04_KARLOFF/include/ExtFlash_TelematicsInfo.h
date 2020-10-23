/********************************************************************
* File:     $Id: ExtFlash_TelematicsInfo.h,v 1.1 2010/10/08 13:20:09 Amiao Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.1 $
* Date:     $Date: 2010/10/08 13:20:09 $
* Author:   $Author: Amiao $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <ExtFlash_TelematicsInfo.c>
*/
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2008 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: ExtFlash_TelematicsInfo.h,v $
*   Revision 1.1  2010/10/08 13:20:09  Amiao
*   TVG660 port on TM3000. Current TVG version 1.5.0.X.29.
*
*   Revision 1.36  2010/05/26 14:37:56  Amiao
*   Merged from 1.4
*
*   Revision 1.35.2.1  2010/05/18 15:46:41  Amiao
*   Merged code from FW1.3.
*   Added logging driver out on private and set to public on login.
*
*   Revision 1.35  2010/04/14 14:32:53  Amiao
*   Changed FLASH to include more space for exceptions.
*
*   Revision 1.34  2010/04/12 16:04:09  Amiao
*   Added ifdef for NMEA specific functions to save space.
*
*   Revision 1.33  2010/03/29 13:51:29  Mswain
*   *** empty log message ***
*
*   Revision 1.32  2010/03/23 14:50:44  Mswain
*   Updated #defines for GeomanagerInterface.
*
*   Revision 1.31  2010/02/19 14:55:28  Amiao
*   Added Driver ID and Privacy features
*
*   Revision 1.30  2010/01/21 10:41:01  alanm
*   Added #ifdef for GMI code
*
*   Revision 1.29  2009/10/27 11:07:47  colin
*   Pinpointers require new NMEA messages for the AVG650
*
*   Revision 1.28  2009/10/19 16:16:02  richard
*   Changes for reltest2 and 8Mbit flash
*
*   Revision 1.27  2009/10/06 09:43:56  richard
*   *** empty log message ***
*
*   Revision 1.26  2009/09/23 16:24:42  richard
*   Build 36 with added PPP goodies
*
*   Revision 1.25  2009/08/11 17:25:55  richard
*   Build 16
*
*   Revision 1.24  2009/08/10 18:13:34  richard
*   GeoManager build 15
*
*   Revision 1.23  2009/07/29 08:05:27  richard
*   Fixes for GeoManager Build 6 bugs
*
*   Revision 1.22  2009/07/23 12:58:31  richard
*   Extended memmap for GeoManager. Added default GeoManager IP address
*
*   Revision 1.21  2009/07/16 12:25:57  richard
*   *** empty log message ***
*
*   Revision 1.20  2009/07/06 09:48:54  richard
*   Size is now calculated rather than using a variable for the FIFO.
*
*   Revision 1.19  2009/07/02 14:35:57  richard
*   Extra bit for GeoManager
*
*   Revision 1.18  2009/06/22 09:19:51  richard
*   Added Reset Command for resetting the Enfora.
*   Committed on the Free edition of March Hare Software CVSNT Server.
*   Upgrade to CVS Suite for more features and support:
*   http://march-hare.com/cvsnt/
*
*   Revision 1.17  2009/05/26 12:54:02  richard
*   Added extra funtionality required for GeoManager
*
*   Revision 1.16  2009/05/12 14:24:10  accutest\colin
*   Set default IP and port to Accutest Server
*
*   Revision 1.15  2009/04/06 15:17:37  accutest\colin
*   Added limit for excessive idling trigger
*
*   Revision 1.14  2009/03/12 16:46:34  accutest\colin
*   Reshuffled PAESE limits and now returning doubles
*
*   Revision 1.13  2009/03/12 12:04:26  accutest\colin
*   Added control of the limits used in the PAESE message and changed the address of the licence by correcting the macro definition
*
*   Revision 1.12  2009/02/25 09:51:21  simon
*   Added GetIPAddress() and GetPort() functions
*
*   Revision 1.11  2009/02/19 09:47:39  simon
*   Changed License setting function
*
*   Revision 1.10  2009/02/11 17:05:46  simon
*   Version 2.4.10.0 : Added hardware ignition for AVG600 targets, fixed a few casts and
*    reduced watchdog task stack requirements.
*
*   Revision 1.9  2009/02/06 13:40:01  richard
*   Latest changes for 2.4.9.5
*
*   Revision 1.8  2009/01/28 15:34:16  richard
*   Tweaked PAESE message
*   Added build conditionals for Enfora clone
*
*   Revision 1.7  2009/01/27 16:22:38  richard
*   Added Passive mode switches for J1939.
*   Added License keys for turning stuff on and off
*
*   Revision 1.6  2009/01/22 15:29:39  richard
*   Now stores tracking server IP address, port and ping time
*
*   Revision 1.5  2009/01/15 16:24:16  simon
*   Added support for storing GPS position.
*
*   Revision 1.4  2009/01/13 12:52:15  simon
*   Added AT$RESETMODEM command and added locking and unlocking of the SPI bus, plus an
*    SPI transfer no longer blocks indefinitly waiting for an SPI transfer to signal completion.
*
*   Revision 1.3  2008/12/24 11:54:40  richard
*   Changs made to get instant GPS on AVG650
*
*   Revision 1.2  2008/12/17 14:59:50  simon
*   Added support for saving buffer information (i.e. head,tail,size,etc)
*
*   Revision 1.1  2008/11/21 11:47:47  simon
*   New module
*
*
* Change Log:
*
*********************************************************************
*/

#ifndef EXT_FLASH_TELEMATICS_INFO_H
#define EXT_FLASH_TELEMATICS_INFO_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

#include "ExtFlash.h"
#include "canLPC2000.h"	// required for CAN enum

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/
#define CRANK_BITS_STOP_START           (0x10)

#ifndef KARLOFF
/*------------------------------------------------------------------*/
/* MEMORY MAP (NOTE : DO NOT move addresses once allocated !!!)     */
/*------------------------------------------------------------------*/

// (NOTE : see ExtFlash.h for memory map base address)

// GEOMANAGER ONLY - must be on 256 byte boundries as it uses block writes - max 9.5KB
#if defined(__INCLUDE_GEOMANAGER_MODULE) || defined(__INCLUDE_GMI)
#include "GeoManager.h"

#define GM_SYSTEM_ADDRESS               (FLASH_GEOMANAGER_START_ADDRESS)		// must be on 256 boundry
#define GM_SYSTEM_SIZE                  (256)                                   // Matched to size of flash chip sector

#define GM_COUNTS_ADDRESS               (GM_SYSTEM_ADDRESS + GM_SYSTEM_SIZE)    // must be on 256 boundry
#define GM_COUNTS_SIZE                  (512)                                   // Matched to size of flash chip sector

#define GM_EXCEPTIONS_ADDRESS           (GM_COUNTS_ADDRESS + GM_COUNTS_SIZE)    // must be on 256 boundry
#define GM_EXCEPTIONS_SIZE              (2304)                                  // Matched to size of flash chip sector

#define GM_CONFIG_ADDRESS               (GM_EXCEPTIONS_ADDRESS + GM_EXCEPTIONS_SIZE)
#define GM_CONFIG_SIZE                  (512)

#define GM_DRIVERID_ADDRESS             (GM_CONFIG_ADDRESS + GM_CONFIG_SIZE)
#define GM_DRIVERID_SIZE                (256)

#define GM_LOGIOINFO_ADDRESS            (GM_DRIVERID_ADDRESS + GM_DRIVERID_SIZE)
#define GM_LOGIOINDO_SIZE               (256)

#define GM_PRIVACY_ADDRESS              (GM_LOGIOINFO_ADDRESS + GM_LOGIOINDO_SIZE)
#define GM_PRIVACY_SIZE                 (256)

#define GM_DRIVERSAFETY_ADDRESS         (GM_PRIVACY_ADDRESS +  GM_PRIVACY_SIZE)
#define GM_DRIVERSAFETY_SIZE            (512)

#define GM_TOTAL_SIZE                   (GM_DRIVERSAFETY_ADDRESS + GM_DRIVERSAFETY_SIZE - FLASH_GEOMANAGER_START_ADDRESS)

// TOTAL = 4 KB

#endif

#define TI_IP_ADDRESS_ADDRESS           (FLASH_TELEMATICS_START_ADDRESS)
#define TI_IP_ADDRESS_SIZE              (sizeof(uint32_t))  // 4 bytes
#define TI_PORT_ADDRESS                 (TI_IP_ADDRESS_ADDRESS + TI_IP_ADDRESS_SIZE)
#define TI_PORT_SIZE                    (sizeof(uint16_t))  // 2 bytes
#define TI_PING_ADDRESS                 (TI_PORT_ADDRESS + TI_PORT_SIZE)
#define TI_PING_SIZE                    (sizeof(uint16_t))  // 2 bytes

#define TI_BUFFER_HEAD_ADDRESS          (TI_PING_ADDRESS + TI_PING_SIZE)
#define TI_BUFFER_HEAD_SIZE             (sizeof(uint32_t))  // 4 bytes
#define TI_BUFFER_TAIL_ADDRESS          (TI_BUFFER_HEAD_ADDRESS + TI_BUFFER_HEAD_SIZE)
#define TI_BUFFER_TAIL_SIZE             (sizeof(uint32_t))  // 4 bytes
#define TI_BUFFER_SIZE_ADDRESS          (TI_BUFFER_TAIL_ADDRESS + TI_BUFFER_TAIL_SIZE)
#define TI_BUFFER_SIZE_SIZE             (sizeof(uint32_t))  // 4 bytes
#define TI_BUFFER_CHECKSUM_ADDRESS      (TI_BUFFER_SIZE_ADDRESS + TI_BUFFER_SIZE_SIZE)
#define TI_BUFFER_CHECKSUM_SIZE         (sizeof(uint8_t))  // 1 bytes

#define TI_IMEI_ADDRESS                 (TI_BUFFER_CHECKSUM_ADDRESS + TI_BUFFER_CHECKSUM_SIZE)
#define TI_IMEI_SIZE                    (16)

#define TI_RESET_MODEM_ADDRESS          (TI_IMEI_ADDRESS + TI_IMEI_SIZE)
#define TI_RESET_MODEM_SIZE             (1)

#define TI_GPS_LATITUDE_ADDRESS         (TI_RESET_MODEM_ADDRESS + TI_RESET_MODEM_SIZE)
#define TI_GPS_LATITUDE_SIZE            (sizeof(double))  // 8 bytes
#define TI_GPS_LONGITUDE_ADDRESS        (TI_GPS_LATITUDE_ADDRESS + TI_GPS_LATITUDE_SIZE)
#define TI_GPS_LONGITUDE_SIZE           (sizeof(double))  // 8 bytes

#define TI_CAN_MODE_ADDRESS				(TI_GPS_LONGITUDE_ADDRESS + TI_GPS_LONGITUDE_SIZE)
#define TI_CAN_MODE_SIZE				(2)

#define TI_LICENSE_ADDRESS				(TI_CAN_MODE_ADDRESS + TI_CAN_MODE_SIZE)
#define TI_LICENSE_SIZE					(sizeof(uint32_t))  // 4 bytes

#define TI_HARSH_DECELERATION_ADDRESS	(TI_LICENSE_ADDRESS + TI_LICENSE_SIZE)
#define TI_HARSH_DECELERATION_SIZE		(sizeof(uint8_t)) /* 0 -> 31.75 m/s/s */
#define TI_HARSH_DECELERATION_INDEX		(1u)
#define TI_HARSH_DECELERATION_SCALE		(0.125f)

#define TI_INCIDENT_ADDRESS	            (TI_HARSH_DECELERATION_ADDRESS + TI_HARSH_DECELERATION_SIZE)
#define TI_INCIDENT_SIZE		        (sizeof(uint8_t)) /* 0 -> 31.75 m/s/s */
#define TI_INCIDENT_INDEX		        (2u)
#define TI_INCIDENT_SCALE		        (0.125f)

#define TI_OVER_SPEED_ADDRESS	        (TI_INCIDENT_ADDRESS + TI_INCIDENT_SIZE)
#define TI_OVER_SPEED_SIZE				(sizeof(uint8_t)) /* 0 -> 254 km/h */
#define TI_OVER_SPEED_INDEX				(3u)
#define TI_OVER_SPEED_SCALE				(1.0f)

#define TI_HARSH_ACCELERATION_ADDRESS	(TI_OVER_SPEED_ADDRESS + TI_OVER_SPEED_SIZE)
#define TI_HARSH_ACCELERATION_SIZE		(sizeof(uint8_t)) /* 0 -> 31.75 m/s/s */
#define TI_HARSH_ACCELERATION_INDEX		(4u)
#define TI_HARSH_ACCELERATION_SCALE		(0.125f)

#define TI_OVER_RPM_ADDRESS	     		(TI_HARSH_ACCELERATION_ADDRESS + TI_HARSH_ACCELERATION_SIZE)
#define TI_OVER_RPM_SIZE				(sizeof(uint8_t)) /* 0 -> 5080 rpm */
#define TI_OVER_RPM_INDEX				(5u)
#define TI_OVER_RPM_SCALE				(20.0f)

#define TI_HEAVY_FOOT_ADDRESS			(TI_OVER_RPM_ADDRESS + TI_OVER_RPM_SIZE)
#define TI_HEAVY_FOOT_SIZE				(sizeof(uint8_t)) /* 0 -> 101.6 % */
#define TI_HEAVY_FOOT_INDEX				(6u)
#define TI_HEAVY_FOOT_SCALE				(0.4f)

#define TI_EXCESSIVE_IDLE_ADDRESS		(TI_HEAVY_FOOT_ADDRESS + TI_HEAVY_FOOT_SIZE)
#define TI_EXCESSIVE_IDLE_SIZE			(sizeof(uint8_t)) /* 0 -> 1270 s */
#define TI_EXCESSIVE_IDLE_INDEX			(8u)
#define TI_EXCESSIVE_IDLE_SCALE			(5.0f)

#define TI_ENF_RST_TYPE_ADDRESS         (TI_EXCESSIVE_IDLE_ADDRESS + TI_EXCESSIVE_IDLE_SIZE)
#define TI_ENF_RST_TYPE_SIZE            (sizeof(uint8_t))  // 1 byte

#define TI_ENF_RST_PERIOD_ADDRESS       (TI_ENF_RST_TYPE_ADDRESS + TI_ENF_RST_TYPE_SIZE)
#define TI_ENF_RST_PERIOD_SIZE          (sizeof(uint16_t))  // 2 bytes

#define TI_ENF_RST_MULTI_ADDRESS        (TI_ENF_RST_PERIOD_ADDRESS + TI_ENF_RST_PERIOD_SIZE)
#define TI_ENF_RST_MULTI_SIZE           (sizeof(uint8_t))  // 1 byte

#define TI_ENF_RETRY_PERIOD_ADDRESS     (TI_ENF_RST_MULTI_ADDRESS + TI_ENF_RST_MULTI_SIZE)
#define TI_ENF_RETRY_PERIOD_SIZE        (sizeof(uint16_t))  // 2 bytes

#define GM_CONFIG_LENGTH_ADDRESS        (TI_ENF_RETRY_PERIOD_ADDRESS + TI_ENF_RETRY_PERIOD_SIZE)
#define GM_CONFIG_LENGTH_SIZE           (sizeof(uint32_t))	// 4 bytes

#define GM_CRANK_DETECT_ADDRESS			(GM_CONFIG_LENGTH_ADDRESS + GM_CONFIG_LENGTH_SIZE)
#define GM_CRANK_DETECT_SIZE			(sizeof(uint8_t))	// 1 bytes

#define GM_CONFIG_OTAP_REQ_IP_ADDRESS	(GM_CRANK_DETECT_ADDRESS + GM_CRANK_DETECT_SIZE)
#define GM_CONFIG_OTAP_REQ_IP_SIZE		(sizeof(uint32_t))	// 4 bytes

#define TI_PINPOINTERS_RPM_BAND_ADDRESS (GM_CONFIG_OTAP_REQ_IP_ADDRESS + GM_CONFIG_OTAP_REQ_IP_SIZE)
#define TI_PINPOINTERS_RPM_BAND_SIZE    (sizeof(uint8_t))   // 1 byte

#define TI_TOTAL_SIZE                   (TI_PINPOINTERS_RPM_BAND_ADDRESS + TI_PINPOINTERS_RPM_BAND_SIZE - FLASH_TELEMATICS_START_ADDRESS)

#define	PING_GPS_POLL					(5)				// How often we get GPS data
#define DEFAULT_PING					(12)			// How many GPS co-ords per ping (12 = 1 min)

#define ACCUTEST_SERVER_IP_ADDRESS      (0x576ae15a)    // telematics.accutest.co.uk (87.106.225.90)
#define ACCUTEST_SERVER_PORT            (16724)         // telematics.accutest.co.uk
#define GEOMANAGER_SERVER_IP_ADDRESS    (0x3FFB6D0D)    // 63.251.109.13 (Release stack)
#define GEOMANAGER_SERVER_PORT          (9000)          

//#ifdef	DEBUG
#ifdef __INCLUDE_GEOMANAGER_MODULE
#define DEFAULT_IPADDR					(GEOMANAGER_SERVER_IP_ADDRESS)
#define DEFAULT_PORT					(GEOMANAGER_SERVER_PORT)

#else
#define DEFAULT_IPADDR					(ACCUTEST_SERVER_IP_ADDRESS)
#define DEFAULT_PORT					(ACCUTEST_SERVER_PORT)
#endif

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

uint8_t     TelematicsInfo_InitModule(void);

// connection info
uint8_t     TelematicsInfo_GetConnectionType(void);
void        TelematicsInfo_SetConnectionType(uint8_t connectionType);
uint8_t     TelematicsInfo_GetConnectionIndex(const char* str);

uint32_t    TelematicsInfo_GetIPAddress(void);
const char* TelematicsInfo_GetIPAddressString(void);
int8_t      TelematicsInfo_SetIPAddressString(const char* str);
void        TelematicsInfo_SetIPAddress(uint32_t ipaddress);
const char* TelematicsInfo_GetPortString(void);
uint16_t    TelematicsInfo_GetPort(void);
void        TelematicsInfo_SetPort(uint16_t port);
uint16_t	TelematicsInfo_GetPing(void);
int8_t		TelematicsInfo_SetPing(uint16_t ping);
uint8_t     TelematicsInfo_GetEnforaResetType(void);
uint16_t	TelematicsInfo_GetEnforaResetPeriod(void);
uint8_t     TelematicsInfo_GetEnforaResetMultiplier(void);
uint16_t	TelematicsInfo_GetEnforaRetryPeriod(void);
int8_t		TelematicsInfo_SetEnforaResetPeriod(uint8_t resetType, uint16_t resetPeriod, uint8_t multiplier, uint16_t retryPeriod);

// data buffer info
void        TelematicsInfo_SetBufferInfo(uint32_t head, uint32_t tail);
int1_t      TelematicsInfo_GetBufferInfo(uint32_t* phead, uint32_t* ptail);

// IMEI
void        TelematicsInfo_SetIMEI(const char* szIMEI);
int1_t      TelematicsInfo_GetIMIE(char* szIMEI, uint8_t length);
const char* TelematicsInfo_GetIMIEString(void);

// Modem Reset
void        TelematicsInfo_SetModemReset(int1_t bValue);
int1_t      TelematicsInfo_GetModemReset(void);

// GPS information
void        TelematicsInfo_SetLatitude(double value);
double      TelematicsInfo_GetLatitude(void);
void        TelematicsInfo_SetLongitude(double value);
double      TelematicsInfo_GetLongitude(void);

void        TelematicsInfo_Load(void);
void        TelematicsInfo_Save(void);
#endif  // KARLOFF

// Passive mode
int1_t		TelematicsInfo_SetCANMode(teCanPorts eCanPort, int1_t bPassive);
int1_t		TelematicsInfo_IsCANModePassive(teCanPorts eCanPort);
// Is TVG connected to Squarell device
int1_t		TelematicsInfo_SetSquarell(bool b);
bool		TelematicsInfo_IsConnectToSquarell(void);

#ifndef KARLOFF
// License
int1_t		TelematicsInfo_SetLicense(const char* key, uint32_t data);
uint32_t	TelematicsInfo_GetLicense(void);

// Set $PAESE limits
#ifdef __INCLUDE_NEW_NMEA_ENGINE
int1_t      TelematicsInfo_SetPAESELimits(uint8_t u8Index_, double fValue_);
int1_t		TelematicsInfo_GetPAESEDecelerationLimit(double *pDeceleration_);
int1_t		TelematicsInfo_GetPAESEIncidentLimit(double *pDeceleration_);
int1_t		TelematicsInfo_GetPAESEOverSpeedLimit(double *pOverSpeed_);
int1_t		TelematicsInfo_GetPAESEAccelerationLimit(double *pAcceleration_);
int1_t		TelematicsInfo_GetPAESEOverRPMLimit(double *pOverRPM_);
int1_t		TelematicsInfo_GetPAESEHeavyFootLimit(double *pHeavyFoot_);
int1_t		TelematicsInfo_GetPAESEExcessiveIdleLimit(double *pIdleTime_);
#endif  // __INCLUDE_NEW_NMEA_ENGINE
void		TelematicsInfo_SetRPMBand(uint8_t u8Configuration_);
uint8_t		TelematicsInfo_GetRPMBand(void);
int1_t      TelematicsInfo_LimitsChanged(void);

#if defined(__INCLUDE_GEOMANAGER_MODULE) || defined(__INCLUDE_GMI)
void        TelematicsInfo_WriteGeoManagerConfig(gmConfig *config);
int1_t      TelematicsInfo_ReadGeoManagerConfig(gmConfig *config);
void        TelematicsInfo_WriteGeoManagerSystem(gmSystem *config);
int1_t      TelematicsInfo_ReadGeoManagerSystem(gmSystem *config);
void        TelematicsInfo_WriteGeoManagerDataCounts(gmExtraCounts *counts);
int1_t      TelematicsInfo_ReadGeoManagerDataCounts(gmExtraCounts *counts);
void        TelematicsInfo_WriteGeoManagerExceptions(gmConfigExceptions *exceptions);
int1_t      TelematicsInfo_ReadGeoManagerExceptions(gmConfigExceptions *exceptions);
void		TelematicsInfo_InvalidateGeoManagerConfig(void);
void		TelematicsInfo_SetCrankDetect(uint8_t mode);
uint8_t		TelematicsInfo_GetCrankDetect(void);
void		TelematicsInfo_SetOtapRequesterIP(uint32_t u32IpAddress);
uint32_t	TelematicsInfo_GetOtapRequesterIP(void);

#ifdef __INCLUDE_DRIVERID_MODULE
void        TelematicsInfo_WriteDriverID(void *driverID);
int1_t      TelematicsInfo_ReadDriverID(void *driverID);
void        TelematicsInfo_WriteLogIO(void *logIO);
int1_t      TelematicsInfo_ReadLogIO(void *logIO);
#endif // __INCLUDE_DRIVERID_MODULE

#ifdef __INCLUDE_PRIVACY_MODULE
void        TelematicsInfo_WritePrivacy(void *privacy);
int1_t      TelematicsInfo_ReadPrivacy(void *privacy);
#endif // __INCLUDE_PRIVACY_MODULE

#ifdef __INCLUDE_DRIVERSAFETY_MODULE
uint8_t     TelematicsInfo_ReadDriverSafety(void *pDriverSafetyBlock);
void        TelematicsInfo_WriteDriverSafety(void *pDriverSafetyBlock);
#endif

#endif // __INCLUDE_GEOMANAGER_MODULE || __INCLUDE_GMI
#endif // KARLOFF

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif  // EXT_FLASH_TELEMATICS_INFO_H

