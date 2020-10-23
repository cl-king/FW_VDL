/********************************************************************
* File:     $Id: J1979.h,v 1.22 2010/04/12 15:28:10 Rharvie Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.22 $
* Date:     $Date: 2010/04/12 15:28:10 $
* Author:   $Author: Rharvie $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <J1979.c>
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2006 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: J1979.h,v $
*   Revision 1.22  2010/04/12 15:28:10  Rharvie
*   New code for multiple ECU support
*
*   Revision 1.21  2010/01/22 14:48:18  richard
*   Build 1.3.0.x.13
*
*   Revision 1.20  2009/11/30 16:57:19  richard
*   Combined all vehicle protocols.
*   Added FIFO test
*
*   Revision 1.19  2009/04/15 16:37:02  simon
*   Added support for interval based TesterPresent messages on KWP2000 protocol.
*
*   Revision 1.18  2009/02/12 12:56:17  DBateman
*   Added STP_instantaneousFuelLitresPerHour to the Globals section.
*
*   Revision 1.17  2008/10/03 11:56:44  simon
*   Added GetProtocolString(protocol) function.
*
*   Revision 1.16  2008/08/06 16:23:27  ACCUTEST\simon
*   Added WaitForECUReset function
*
*   Revision 1.15  2008/08/06 14:47:52  ACCUTEST\simon
*   Added J1979MsgType_SilentStatus
*
*   Revision 1.14  2008/08/06 13:17:28  accutest\colin
*   Excluded J1850 unless specified byt the __INCLUDE_J1850_MODULE build option
*
*   Revision 1.13  2008/07/08 08:35:17  ACCUTEST\simon
*   Implemented a Vehicle Info module to store general
*    non-volatile information about the vehicle
*
*   Revision 1.12  2008/07/07 09:28:15  ACCUTEST\simon
*   Corrected bug when trying to connect to KWP2000-SLOW using an auto protocol detect.
*    Also requests for SID/PID now removes PID when doing
*    a service 3,4 or 7 request.
*
*   Revision 1.11  2008/07/03 15:45:42  ACCUTEST\simon
*   Removed static keyword from structures being posted on a queue. These are automatically
*    copied by the RTOS and not held by reference.
*
*   Revision 1.10  2008/07/02 16:31:05  ACCUTEST\simon
*   Progressed AT Command set and renamed AVG500M to AVG600
*
*   Revision 1.9  2008/05/08 09:43:34  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*   Revision 1.8  2008/04/21 09:11:17  ACCUTEST\richard
*   Added fuel rate PID
*
*   Revision 1.7  2008/03/17 13:19:56  ACCUTEST\simon
*   Added J1979_IsConnecting() function
*
*   Revision 1.6  2008/03/07 14:50:34  ACCUTEST\simon
*   Added internal staus message and corrected CAN_AUTO define value
*
*   Revision 1.5  2008/03/06 14:23:52  ACCUTEST\richard
*   Added Auto Baud function
*
*   Revision 1.4  2008/03/06 13:41:46  ACCUTEST\simon
*   put #define values in brackets
*
*   Revision 1.3  2007/11/30 10:09:48  ACCUTEST\simon
*   corrected coolant #define
*
*   Revision 1.2  2007/10/22 08:46:15  ACCUTEST\peterp
*   AVG500L (NXP LPC2129) and AVG600 (NXP LPC2468) port.
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   2007/09/26 10:58:24  ACCUTEST\simon
*   Various bug fixes and enhancements
*
*   2007/07/05 08:11:33  ACCUTEST\simon
*   Added J1850 (PWM) protocol support. (Uses AVG500L-J1850 expansion board).
*
*   2007/06/21 14:50:30  ACCUTEST\simon
*   Interim development build
*
*   2007/06/04 10:50:47  ACCUTEST\simon
*   Added @Road STP module and added more build configurations to solution in
*    order to better manage specific build targets.
*
*   2007/05/29 08:53:24  ACCUTEST\simon
*   Fixed various issues with all protocols and added multi-message support.
*
*   2007/05/16 10:59:43  ACCUTEST\simon
*   Initial J1979 working code.
*
*   2007/04/20 14:14:28  ACCUTEST\simon
*   J1979 in progress
*
*********************************************************************
*/

#ifndef J1979_H
#define J1979_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Required Modules
#include "ISO9141.h"        // ISO9141-2  (KLINE)  
#include "KWP2000.h"        // KWP2000    (KLINE)
#include "ISO15765.h"       // ISO15765-4 (CAN)
#ifdef __INCLUDE_J1850_MODULE
#include "J1850.h"          // J1850      (PWM/VPW)
#endif // __INCLUDE_J1850_MODULE
#include "CoreTypes.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define J1979_MAX_ECU                           (8)         // J1979 allows for 8 diagnostic ECU addresses
#define J1979_ECU_MASK                          (0x07)      // Mask for the short hand ECU address

#define J1979_MAX_REQUEST_LEN                   (8)
#define J1979_MAX_RESPONSE_LEN                  (64)        // caters for general multiframe data

// Protocol
#define J1979_PROTOCOL_UNKNOWN                  (0x00)
#define J1979_PROTOCOL_ISO9141_2                (0x01)
#define J1979_PROTOCOL_KWP2000_SLOW             (0x02)
#define J1979_PROTOCOL_KWP2000_FAST             (0x03)
#define J1979_PROTOCOL_CAN_11_250               (0x04)
#define J1979_PROTOCOL_CAN_11_500               (0x05)
#define J1979_PROTOCOL_CAN_29_250               (0x06)
#define J1979_PROTOCOL_CAN_29_500               (0x07)
#define J1979_PROTOCOL_J1850_PWM                (0x08)
#define J1979_PROTOCOL_J1850_VPW                (0x09)
#define J1979_PROTOCOL_CAN_AUTO					(0x0A)
#define J1979_PROTOCOL_KWP2000_VAUXHALL			(0x0B)

#define J1979_PROTOCOL_MIN                      (J1979_PROTOCOL_UNKNOWN)            // Lower limit of valid protocol 

#ifdef __INCLUDE_COREPARAMSGENERIC_MODULE		

// Allow J1979 to understand J1939 and J1587 as well if included
#define CP_MODE_INVALID                         (0xFF)
#define CP_MODE_AUTO                            (0x00)
#define CP_MODE_J1979                           (0x00)		// Actually 01-0F
#define CP_MODE_J1939_250                       (0x10)
#define CP_MODE_J1587                           (0x20)
#ifdef _INCLUDE_SUPPORT_J1939J1587
#define CP_MODE_J1939J1587                      (0x30)
#define CP_MODE_J1939_500                       (0x40)
#define CP_MODE_STOP                            (0x50)
#else
#define CP_MODE_J1939_500                       (0x30)
#define CP_MODE_STOP                            (0x40)
#endif
#define J1979_PROTOCOL_MAX                      (CP_MODE_STOP)

#else
#ifdef __INCLUDE_VAUXHALL_MODULE
#define J1979_PROTOCOL_MAX                      (J1979_PROTOCOL_KWP2000_VAUXHALL)   // Upper limit of valid protocol 
#else
#define J1979_PROTOCOL_MAX                      (J1979_PROTOCOL_CAN_AUTO)           // Upper limit of valid protocol 
#endif // __INCLUDE_VAUXHALL_MODULE
#endif //__INCLUDE_COREPARAMSGENERIC_MODULE

#define J1979_END_OF_AUTODETECT                 (0xFF)

// auto detect start and end protocols
#define J1979_PROTOCOL_AUTODETECT               (0)
#define J1979_PROTOCOL_FIRST                    (J1979_PROTOCOL_CAN_AUTO)
#define J1979_PROTOCOL_LAST                     (J1979_PROTOCOL_CAN_29_500)

#define J1979_ERROR                             (0xff)

// start diagnostic options flags
#define J1979_OPTION_KEEPALIVE                  (0x01)    // enable keepalive
#define J1979_OPTION_RECONNECT                  (0x02)    // re-connect if connection lost
#define J1979_OPTION_EXTEND_TIMINGS             (0x04)    // extend timout timings
#define J1979_OPTION_QUIET                      (0x08)    // silent connetion attempts
#define J1979_OPTION_QUIET_CONNECT              (0x10)    // silent connection

// functional or physical
#define J1979_ADDR_FUNCTIONAL                   (0)
#define J1979_ADDR_PHYSICAL                     (1)

// J1979 leg diag addresess
#define J1979_FUNCTIONAL_REQ_ADDRESS			0x7DF
#define J1979_ECU0_REQ_ADDR_7E0					0x7E0
#define J1979_ECU0_RESP_ADDR_7E8				0x7E8

// J1979 Standard service ids (SIDs)
#define J1979_SID_SERVICE_01                    (0x01)
#define J1979_SID_SERVICE_02                    (0x02)
#define J1979_SID_SERVICE_03                    (0x03)
#define J1979_SID_SERVICE_04                    (0x04)
#define J1979_SID_SERVICE_07                    (0x07)
#define J1979_SID_SERVICE_09                    (0x09)

// J1979 Service response IDs
#define J1979_SERVICE_01_RESP					(0X41)
#define J1979_SERVICE_02_RESP					(0X42)
#define J1979_SERVICE_03_RESP					(0X43)
#define J1979_SERVICE_04_RESP					(0X44)
#define J1979_SERVICE_07_RESP					(0X47)
#define J1979_SERVICE_09_RESP					(0X49)

// J1979 Standard parameter ids (PIDs) for all services
#define J1979_PID_SUPPORTED_PIDS_BASE           (0x00)
#define J1979_PID_SUPPORTED_PIDS_01_TO_20       (0x00)
#define J1979_PID_SUPPORTED_PIDS_21_TO_40       (0x20)
#define J1979_PID_SUPPORTED_PIDS_41_TO_60       (0x40)
#define J1979_PID_SUPPORTED_PIDS_61_TO_80       (0x60)
#define J1979_PID_SUPPORTED_PIDS_81_TO_A0       (0x80)
#define J1979_PID_SUPPORTED_PIDS_OFFSETS        (0x20)

// J1979 Standard parameter ids (PIDs) for Service $01  //  A7....A0 B7....B0 C7....C0 D7....D0
#define J1979_PID_VEHICLE_STATUS				(0x01)  //  *....... ........ ........ ........
#define J1979_PID_DTC_OF_FREEZE_FRAME			(0x02)  //  .*...... ........ ........ ........
#define J1979_PID_FUEL_SYSTEM_1_STATUS			(0x03)  //  ..*..... ........ ........ ........
#define J1979_PID_CALCULATED_LOAD				(0x04)  //  ...*.... ........ ........ ........
#define J1979_PID_COOLANT_TEMPERATURE			(0x05)  //  ....*... ........ ........ ........
#define J1979_PID_SHORT_TERM_FUEL_TRIM_BANK1	(0x06)  //  .....*.. ........ ........ ........
#define J1979_PID_LONG_TERM_FUEL_TRIM_BANK1		(0x07)  //  ......*. ........ ........ ........
#define J1979_PID_SHORT_TERM_FUEL_TRIM_BANK2	(0x08)  //  .......* ........ ........ ........
#define J1979_PID_LONG_TERM_FUEL_TRIM_BANK2		(0x09)  //  ........ *....... ........ ........
#define J1979_PID_FUEL_RAIL_PRESSURE_GAGE		(0x0A)  //  ........ .*...... ........ ........
#define J1979_PID_INTAKE_MANIFOLD_PRESSURE		(0x0B)  //  ........ ..*..... ........ ........
#define J1979_PID_ENGINE_RPM					(0x0C)  //  ........ ...*.... ........ ........
#define J1979_PID_VEHICLE_SPEED					(0x0D)  //  ........ ....*... ........ ........
#define J1979_PID_IGNITION_TIMING				(0x0E)  //  ........ .....*.. ........ ........
#define J1979_PID_INTAKE_AIR_TEMPERATURE		(0x0F)  //  ........ ......*. ........ ........
#define J1979_PID_AIR_FLOW_RATE					(0x10)  //  ........ .......* ........ ........
#define J1979_PID_ABSOLUTE_THROTTLE_POSITION	(0x11)  //  ........ ........ *....... ........
#define J1979_PID_OBD_REQUIREMENTS              (0x1C)  //  ........ ........ ........ ...*....
#define J1979_PID_TIME_SINCE_ENGINE_START		(0x1F)  //  ........ ........ ........ ......*.
#define J1979_PID_DISTANCE_MIL_ACTIVE			(0x21)  //  *....... ........ ........ ........
#define J1979_PID_FUEL_RAIL_TO_MANIFOLD_DELTA	(0x22)  //  .*...... ........ ........ ........
#define J1979_PID_FUEL_RAIL_PRESSURE			(0x23)  //  ..*..... ........ ........ ........
#define J1979_PID_FUEL_LEVEL_INPUT				(0x2F)  //  ........ ......*. ........ ........
#define J1979_PID_ENGINE_FUEL_RATE				(0x5E)  //  ........ ........ ........ .....*..
#define J1979_PID_MAF_66                        (0x66)  //  .....*.. ........ ........ ........
#define J1979_PID_ENGINE_RUN_TIME				(0x7F)	//  ........ ........ ........ ......*.
#define J1979_PID_MAP_87                        (0x87)  //  ......*. ........ ........ ........

// J1979 Standard parameter ids (PIDs) for Service $09
#define J1979_PID_VIN_LENGTH                    (0x01)
#define J1979_PID_VIN                           (0x02)

#define J1979_SUPPORTED_PID_MAX_BLOCKS          (5)	///< supported PIDs are reported in 32bit blocks

#define J1979_MAX_RESPONSES			8	// Max number of expected J1979 responders

// CAN IDs for custom responses (manufcturer specific for odometer, runtime and etc)
#define FORD_IPC_RESP_ADDR_728		0x728
#define FORD_GEM_RESP_ADDR_72E		0x72E

// PIDs for custom responses (manufacturer specific odometer, runtime and etc)
#define FORD_ODO_PID_404C			0x404C
#define FORD_ENG_RUNTIME_PID_6103	0x6103
#define FORD_ODO_PID_6182			0x6182
#define FORD_ODO_PID_DD01			0xDD01
#define FORD_ENG_RUNTIME_PID_F47F	0xF47F

typedef enum{
	pidRequestTimeout,
	extPidRequestTimeout,
	rawRequestTimeout,
}eRequestTimeout;

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

uint8_t J1979_InitModule(void);

// external functions
void        J1979_Abort(void);
uint8_t 	J1979_SendEndDiagnostics(void);
void        J1979_EndDiagnostics(void);
void        J1979_DisableKeepalive(void);
void        J1979_SendKeepalivesAtRegularIntervals(int1_t bEnable);
uint8_t     J1979_ConnectToVehicle(uint8_t u8Protocol, int1_t bKeepalive, int1_t bSilentProgress, int1_t bSilentConnect);
int1_t      J1979_IsConnecting(void);
void        J1979_WaitForECUReset(uint8_t u8OldProtocol, uint8_t u8NewProtocol);
uint8_t     J1979_GetActiveProtocol(void);
const char* J1979_GetProtocolString(uint8_t u8Protocol);
const char* J1979_GetActiveProtocolString(void);
uint32_t    J1979_GetSupportedPIDInformation(uint8_t u8Block);
const char* J1979_GetProtocolInformationString(void);
void        J1979_GetResponse(void);
uint8_t     J1979_GetChkSum(uint8_t *pData, uint16_t u16Size);
uint8_t     J1979_IsPIDSupported(uint8_t u8PID);
uint8_t J1979_RequestRaw(uint8_t *pu8Data, 
                             uint8_t u8DataLength, 
                             uint8_t *pu8ResponseData, 
                             uint8_t *pu8ResponseDataLength,
                             uint8_t u8RequestID);

uint8_t J1979_SendRequest(uint8_t *pu8Data, 
                          uint8_t u8DataLength, 
                          uint8_t *pu8ResponseData, 
                          uint8_t *pu8ResponseDataLength,
                          uint8_t u8Ecu,
                          uint8_t u8NumResponses,
                          eRequestTimeout timeoutType);
uint8_t J1979_PhysicalRequestRaw(uint8_t *pu8Data,				
								 uint8_t u8DataLength,			
								 uint8_t *pu8ResponseData,		
								 uint8_t *pu8ResponseDataLength,
								 uint8_t u8Ecu,
								 int1_t  u1FilterReq,			
								 uint32_t u32Filter);
int J1979IfaceSendRawPhysical(uint8_t* pu8Data, 
							  uint8_t u8DataLength, 
							  int1_t u1FilterReq, 
							  uint32_t u32Filter);
void J1979_SendTesterPresent(void);
void J1979_SetCANSupported(int1_t bSupported);
void J1979_SetKLineSupported(int1_t bSupported);
void J1979_SetJ1850Supported(int1_t bSupported);
void J1979_SetLastTimeout(uint32_t u32Timeout);

uint32_t    J1979_GetEcuCount(void);
int1_t      J1979_IsPhysicalSupported(void);
void        J1979_SetPhysicalSupported(int1_t bSupported);
int1_t      J1979_AddEcuToList(uint8_t ECUAddress);
uint8_t     J1979_GetEcuAddress(uint8_t EcuNumber);
int1_t      J1979_SetEcuPids(uint8_t ECUAddress, uint32_t pid_support1, uint32_t pid_support2, uint32_t pid_support3, 
                             uint32_t pid_support4, uint32_t pid_support5, uint32_t Service9PidSupport);
int1_t      J1979_GetEcuString(uint8_t EcuNumber, char* szString);
int1_t      J1979_RequestPID(uint8_t Service, uint8_t PID);
int1_t      J1979_RequestDTCs(void);
int1_t      J1979_ClearDTCs(void);
int1_t      J1979_AddToTxQueue(uint8_t MessageType, uint8_t Dlc, uint8_t *data);
int1_t      J1979_GetEcuAddressFromPid(uint8_t service, uint8_t Pid, uint8_t *lowestEcu, uint8_t *NumResponses);
int1_t      J1979_RequestDTCFromEcu(uint8_t u8EcuAddress);
int1_t      J1979_RequestPIDFromEcu(uint8_t Service, uint8_t PID, uint8_t u8EcuAddress);
int1_t 		J1979_RequestOdometer(DistCalcStatus method);
int 		J1979_SetAutoOdoList(char manuCode);
int1_t 		J1979_ProtocolIsCan(void);
int1_t		J1979_RequestEngineRuntime(RuntimeCalcStatus method);
int 		J1979_SetAutoRuntimeMethodList(char manuCode);
void		J1979_SetAuxFilter(uint32_t canID, uint32_t rate, uint32_t filterIndex);
void        J1979_SetSupportedPidsBlock(uint32_t id, uint8_t *data, uint8_t len);
int1_t      J1979_IsLowestEcuAddress(uint8_t ecu);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

// J1979 message type
typedef enum {
    J1979MsgType_Request            = 0,    // service/pid request from external module
	J1979MsgType_Response           = 1,    // external response
	J1979MsgType_Status             = 2,    // external status report
    J1979MsgType_Information        = 3,    // external information
    J1979MsgType_ResponseRaw        = 4,    // raw request from external module
    J1979MsgType_InternalRequest    = 5,    // service/pid request from internal module
    J1979MsgType_InternalResponse   = 6,    // internal response
    J1979MsgType_InternalStatus     = 7,    // internal status report
	J1979MsgType_SilentStatus       = 8,    // silent status report (notification to a slient operation)
	J1979MsgType_InternalPhysResponseRaw	= 9,		// raw physical request from external module
	J1979MsgType_SetAuxFilter		= 10,	//Set auxillary filter
	J1979MsgType_Broadcast			= 11	//Broadcast message
} teJ1979MsgType;

// J1979 message
typedef struct {
    teJ1979MsgType eJ1979MsgType;
    uint8_t u8Data[J1979_MAX_RESPONSE_LEN];
    uint8_t u8Dlc;
    uint8_t u8ChkSum;
} tsJ1979Msg;

uint8_t J1979_Init(tsJ1979Msg *J1979RequestMsg); //uint8_t u8InitProtocol, uint8_t u8InitOptions, uint8_t u8ExtTimings);

// J1979 Module Task State
typedef enum {
    J1979ModuleState_Idle,
    J1979ModuleState_Initialise,
    J1979ModuleState_Connected,
    J1979ModuleState_Disconnect,
    J1979ModuleState_Request,
    J1979ModuleState_ResponsePending,
    J1979ModuleState_Error
} teJ1979ModuleState;

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

xQueueHandle xJ1979RequestQueue;

extern double  STP_instantaneousFuelLitresPerHour;



#endif // J1979_H







