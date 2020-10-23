/* ----------------------- Proprietary to Trimble, Inc. --------------------- *
 *
 *         File name: VDL.h
 *   Initial Project: Karloff
 *            Author: ddye
 *        Created on: Feb 1, 2011 - 4:19:35 PM
 *       Description: 
 *
 * ----------------------- Proprietary to Trimble, Inc. --------------------- *
 * Trimble Mobile Resource Management
 * 47071 Bayside Parkway
 * Fremont, CA 94538
 * Tel: 1-877-7AtRoad
 * www.road.com

 * ----------------------- Proprietary to Trimble, Inc. --------------------- *
 * Copyright (c) 2009, At Road a Trimble Company - All Rights Reserved.
 * No part of this file may be reproduced or transmitted in any form
 * by any means electronically, mechanically, by  photocopying, via recording
 * or otherwise outside of Trimble Company without the prior consent of
 * Trimble, Inc.

 * The information in this file constitutes confidential and proprietary
 * information of Trimble, Inc. This file is intended for the use of Trimble
 * employees only.  The disclosure of all or any part of this document to or the
 * use of all or any part of this file by any other party is strictly prohibited
 * without the prior written consent of Trimble, Inc.

 * Trimble Mobile Resource Management solutions, including without limitation its
 * products, software and services, are protected under one or more patents or
 * patents pending in jurisdictions around the world.

 * Trimble patents include without limitation the following:
 * U.S. 5,477,228; 5,694,594; 5,959,577; 5,990,827; 6,459,988; 6,529,159;
 * 6,552,682; 6,594,576; 6,664,922; 6,578,005; 5,963,911; 6,862,524; 6,795,017; 6,882,313;
 * 6,867,733; 6,832,140; 6,922,566; 6,965,665; 6,980,131; 6,980,812; 7,006,820; 7,035,620,
 * 7,043,255 and 7,082,605;
 * Australia patents 682,585 and 722,806;
 * Canada patent 2,183,586;
 * China patents 95,192,287.4 and 97,180,004.9;
 * France, Ireland, Italy, Netherlands, Spain and United Kingdom
 * European Patent No. EP0938714;
 * European Patent No. EP0752136;
 * European Patent No. EP1168863;
 * Germany patents 69,411,744.7; 60,105,094.008; 69,512,040 and 69,703,938;
 * India patent 19,044;
 * United Kingdom patents 705,442 and 2,373,655B.

 * Further information relating to Trimble copyrights, trademarks, patents and patents
 * pending may be found at the Trimble Mobile Resource Management Web site, www.trimble.com
 * and www.road.com.

 * ----------------------- Proprietary to Trimble, Inc. --------------------- *
 */

#ifndef __VDL_H_
#define __VDL_H_

#include <stdbool.h>
#include <stdint.h>

#include "CoreTypes.h"

#ifdef __INCLUDE_EVENTDATARECORD
#include "EventDataRecord_external.h"
#include "EventTrigger_external.h"
#endif

#define VDL_VERSION						"1.0.0.45"	// Vesion of the vehile diagnostics library
#define ENABLE_TRIP_MODE				0			// Trip mode may be needed for hybrid vehicles in the future
#define LOG_DIR_NAME_LEN				100			// Log file directory string max length

#ifdef __INCLUDE_VD_MODULE_INFO
#define VDL_STRING_SIZE					1800
#endif

#define VDL_UNASSIGNED					CORE_PARAM_UNASSIGNED

// Configuration items 
typedef enum {
	ConfigParamFuelFactor,				// Fuel factor 1/1000
#if	ENABLE_TRIP_MODE	
	ConfigParamCrankMode,				// Bits 0-3 - crank mode, bit 4 - smart tech
#endif	
	ConfigParamEngineSize,				// Engine size in liters
	ConfigParamTurboFuelType,			// Bit 0-1 - turbo, bits 8-15 - fuel type
	ConfigParamBusProtocol,				// Set the desired bus protocol to auto or a specific protocol	
	ConfigParamOdometer,				// Set the odometer (m)
	ConfigParamOdometerMethod,			// 0 - NO method, 1-6 for known methods (see eVdlOdoMethods)
	ConfigParamVIN,						// Initialize the stack VIN to prevent J1979 VIN query during connection
	ConfigParamHdvSpeedMid,				// Lock the HDV speed to a speciific MID
	ConfigParamHdvOdometerMid,			// Lock the HDV odometer to a specific MID
	ConfigParamHdvFuelMid,				// Lock the HDV fuel to a specific MID
	ConfigParamHdvFuelMethod,			// Lock the HDV fuel to  a specific method
	ConfigParamSpeedMethod,				// Lock the speed to a specified method
	ConfigToggleSimSpeedCheck,			// Used to override the logic that allows for simulated VD speed
	ConfigParamRuntimeMethod,			// Lock the engine runtime to a specific method
	ConfigParamEstEngineRuntime,		// Set the estimated engine runtime (sec)
	ConfigParamHdvRuntimeMid			// Lock MID for engine runtime calculations
}eVdlSetParamType;

// Protocol type settings
typedef enum {
    BusProtocolAuto         = 0,        // Auto detect J1939, J1708 or one of the J1979 protocols
    BusProtocolIso9141      = 1,        // Light Duty ISO9194 (aka k-line)
    BusProtocolKwp2000Slow  = 2,        // Light Duty ISO14230 with slow sync (k-line)
    BusProtocolKwp2000Fast  = 3,        // Light Duty ISO14230 with fast sync (k-line)
    BusProtocolCan11_250    = 4,        // Light Duty ISO15765 - 250Bbps, 11-bit (baud not applicable to US)
    BusProtocolCan11_500    = 5,        // Light Duty ISO15765 - 500Kbps, 11-bit (baud specified for US)
    BusProtocolCan29_250    = 6,        // Light Duty ISO15765 - 250Kbps, 29-bit (supported but no known use)
    BusProtocolCan29_500    = 7,        // Light Duty ISO15765 - 500Kbps, 29-bit (supported but no known use)
    BusProtocolJ1850Pwm     = 8,        // Light Duty J1850 PWM (Ford)
    BusProtocolJ1850Vpw     = 9,        // Light Duty J1850 VPW (GM)
    BusProtocolJ1939_250    = 10,       // Heavy Duty J1939 - 250Kbps, 29-bit
    BusProtocolJ1587        = 11,       // Heavy Duty J1708/J1587
    BusProtocolJ1939J1587   = 12,       // J1939 and J1587 working simutaneously
    BusProtocolJ1939_500    = 13,       // Heavy Duty J1939 - 500Kbps, 29-bit
    BusProtocolUnknown      = 255       // Bus protocol not known
}eVdlBusProtocol;

// Log file enable bit definitons
typedef enum {
	VdlDebugDisable		= 0x0000,		// Disable VDL logging
	VdlDebugCore		= 0x0001,		// Enable logging for core module
	VdlDebugFuel		= 0x0002,		// Enable logging in the fuel calc module
	VdlDebugJ1587	 	= 0x0004,		// Enable logging in the J1708/J1587 module
	VdlDebugJ1939		= 0x0008,		// Enable logging in the J1939 module
	VdlDebugJ1979		= 0x0010,		// Enable logging in the J1979 module
	VdlDebugInterface	= 0x0020,		// Enable logging in the Buster interface module
	VdlDebugCan		= 0x0040,		// Enable CAN interface logging
	VdlDebugVdl			= 0x0080,		// Enable loggig of VDL calls
	VdlDebugVerbose	= 0x0100,		// Enable verbose logging in parser
	vdlDebugSpeed		= 0x0200,		// Eanble logging of VD speed sanitizer
	vdlDebugEcuMap		= 0x0400,		// Enable logging of EcuMap param updates
	vdlDebugAbnmlData   = 0x0800,       // Enable logging of abnormal data
	vdlDebugObdBcast    = 0x1000,       // Enable logging of bcast data decode
}eVdlDebug;

// Buster log enable
typedef enum {
	BusterDebugMin		= 0,
	BusterDebugDisable 	= 0,			// Disable bus monitoring on /dev/pts/7
	BusterDebugBasic	= 1,			// Enable bus monitoring on /dev/pts/7 for (J1939, J1587 and J1979)
	BusterDebugVerbose 	= 3,			// For J1979, provide diagnostic and run time message monitoring
	// ^^ Add new items above ^^
	BusterDebugInvalid
}eVdlBusterDebug;

typedef struct
{
	bool 			passive;						// true = listen only mode, false = transmissions allowed
	bool 			enable;							// true = Enable vehicle diagnostics, false = disable diagnostics
	eVdlBusProtocol	protocol;						// Desired bus protocol or auto detect
	uint8_t 		odoCalcMethod;					// Method used to calcualte odometer (GPS, vehicle speed or bus odometer)
	uint16_t		speedMethod;					// Method used for speed (GPS or bus based)
	uint16_t		hdvSpeedMid;					// Lock the speed to this MID
	uint16_t		hdvOdometerMid;					// Lock the odometer to this MID
	uint16_t		hdvFuelMid;						// Lock the fuel to this MID
	uint16_t		hdvFuelMethod;					// Lock the fuel to this method
	uint8_t 		turboType;						// Turbo or non-turbo
	uint8_t 		fuelType;						// Diesel, gasoline, natural gas or unknown
	double 			engineSize;						// Engine size in liters
	double 			fuelCalcCompensation;			// Compensation factor used for MAP and MAF based calculation (0-100%)
	double 			initialTotalFuel;				// Last saved value for total fuel (ml)
	double 			initialTotalDist;				// Last saved odometer value (m)
	eVdlBusterDebug	busterLogEnable;				// Buster log enable on /dev/pts/7 (see eBusterDebug)
	eVdlDebug		logEnable;						// Bitmap of modules to log (see eVdlDebug definitons above)
	char			logLocation[LOG_DIR_NAME_LEN];	// Path to log file location, default is /var/log (filename is vdl.log)
	uint32_t		logMaxSize;						// Max size (in bytes) of vdl.log
	bool			squarell;      // true if TVG connects to Squarell device.
	double			distBetweenBusSamples;			//Initial value of accumulated distance from previous trip
	double			estOdomReference;				//Initial value - estimated odom when last time distBetweenBusSamples was updated
	uint8_t			runtimeMethod;					// Lock the engine runtime method
	double			estEngineRuntime;				// Estimated engine runtime (sec)
	uint16_t		hdvRuntimeMid;					//Lock the runtime to this MID
}VDL_CfgParams;

typedef struct
{
	uint32_t 	ttag;					// GPS time tag
	bool 		locked;					// 0 = not locked, 1 = locked
	double		latitude;				// Latitude in (degrees)
	double		longitude;				// Longitude in (degrees)
	double		filteredVelocity;		// Filtered velocity (kmh)
	double		unfilteredVelocity;		// Unfiltered velocity (kmh)
}VDL_Location;

typedef struct
{
	uint32_t 	dtcCode;				// DTC Identifier
	uint8_t		dtcReason;				// DTC reason code
	uint8_t		dtcEcu;					// ECU that reported the DTC
	uint8_t		dtcType;				// Type of bus (CoreConnectedJ1587, CoreConnectedJ1939 or CoreConnectedJ1979)
	uint8_t		dtcOccurence;			// Occurence count
	uint32_t	eventTime;				// System time at DTC detection
	uint32_t	locationTime;			// Location timestamp at DTC detection
	double		latitude;				// Latitude at DTC detection
	double		longitude;				// Longitude at DTC detection
	uint8_t		dtcIsSid;				// For j1587, 1: if DTC is SID, 0: if dtcCode is PID. For J1939, don't care.
	uint32_t	dtcStatus;				// 1-active, 2-preactive,3-cleared.
	uint32_t	deactiveTime;			// timestamp when this DTC is deactived           
	uint32_t	clearedTime;			// timestamp when this DTC is cleared.
}VDL_DtcDetails;

#ifdef __INCLUDE_VD_MODULE_INFO
typedef enum
{
	VdlComponentId,						// J1587/J1939 Component ID strings
	VdlSoftwareId						// J1587/J1939 Software ID strings
}VDL_VehicleStringType;

typedef struct
{
	uint32_t ecu;						// Source of the string MID/ECU
	uint8_t protocol;					// last reported protocol
	int numFields;						// Some strings such as J1939 Software ID indicate
										// number of fields in the string
										// (set to 1 if not supplied inthe message)
	char data[VDL_STRING_SIZE];
}VDL_VehicleString;
#endif

typedef struct
{
    uint8_t ECU;						// ECU for J1939 or MID for J1587
    eVdlBusProtocol protocol;			// J1587 or J1939
    uint32_t fault_code;				// Fault code
    uint8_t   fault_reason;				// Fault Mode Identifier
    uint8_t isSID;						// Only for J1587, is the code PID or SID. 
}VDL_CLEAR_FAULT_ITEM;

#if defined(__cplusplus)
extern "C" {
#endif

// Initialization and connection management
extern int			VDL_Init(VDL_CfgParams *params);						// Must be called once to bring up VDL
extern int 			VDL_ConnectToVehicle(void);								// Initiate an auto detect and attach to the vehicle bus
extern int 			VDL_Disconnect(void);									// Disconnect from the vehicle bus
extern void     	VDL_ClearAll(void);										// Should be called at ignition off to clear DTCs and stale parameters
extern CoreStatus 	VDL_GetConnectionStatus(void);							// Are we connected yet
extern int 			VDL_ProcessData(void);									// Should be called at a 1Hz rate to process the bus data

// VDL input
extern void 		VDL_UpdateLocation(VDL_Location *loc);					// Should be called at 1Hz rate to supply current GPS location/status

// Parameter retrieval
extern bool 		VDL_IsParamAvailable(uint32_t param);					// Determine if a vehicle parameter is available
extern double		VDL_GetParamValue(uint32_t param);						// Retreive the parameter data
extern int			VDL_SetParamValue(uint32_t param, double value);		// Set a parameter value
extern const char* 	VDL_GetParamDesc(uint32_t param);
extern const char*	VDL_GetVin(void);										// Return the vehicle identification number
extern bool            VDL_HaveDtcsChanged(void);						// Has the diagnostic trouble code list changed
extern bool             VDL_CriticalDrivetrainHaveNewFault(void);                            // Does the critical drivetrian have new active  diagnostic trouble code since the last query.
extern uint32_t 	VDL_GetDtcCount(void);									// Number of active diagnostic trouble codes
extern bool			VDL_GetDtcDetails(uint32_t dtcNum, VDL_DtcDetails *dtc);// Returns the details for the specified DTC if it exists
extern void			VDL_ClearClearedDtc(void);								// clear already preactive DTSs have been cleared by DM3 message.
extern int          VDL_GetNumClearedDTC(void);
extern bool			VDL_DtcLock(void);										// Should be called before iterating through the DTCs
extern void 		VDL_DtcUnlock(void);									// Must be called when done with the lock
extern const char* 	VDL_GetProtocolString(void);							// Returns the current protocol as a string
extern eVdlBusProtocol	VDL_GetProtocol(void);								// Returns the current protocol as a number
extern int 			VDL_RequestVIN(void);									// Force a VIN request, J1979 only and only if supported by the vehicle
extern int 			VDL_SetVin(const char* VIN);							// Pre configure the VIN to prevent J1979 VIN request during connect
extern uint32_t		VDL_GetMSTick(void);									// Returns the millisec tick value used within VDL
extern int 			VDL_GetEcuMapString(char *buf);							// Reutrns a descriptive string of an ECU map entry
extern int 			VDL_GetNumberOfEcuMapEntries(void);						// Return number of items in the ECU map
extern int				VDL_SendRequest(uint32_t protocol, uint32_t destination, uint32_t PidPgn); // send PID/PGN request 
extern void			VDL_SetJ1939Filter(bool bEnable); // Disable J1939 filter on buster  
#ifdef __INCLUDE_VD_MODULE_INFO
extern int			VDL_GetVehicleStringCount(VDL_VehicleStringType type);  // Return the number of string entries of a given type
extern int			VDL_GetVehicleString(VDL_VehicleStringType type, int idx,
										VDL_VehicleString *vehStr);			// Returns the requested vehicle string if available 
#endif
extern int 			VDL_SetAutoOdomSelect(char manuCode);					// Sets the list of LD odometer methods to try
extern double		VDL_GetDistBetweenBusSamples(void);						//Get the current accumulated distance between since last odometer sample
extern void			VDL_ResetDistBetweenBusSamples(void);					//Reset accumulated distance
extern double 		VDL_GetEstimatedOdomReference(void);					//Get current reference estimated odometer. This is the checkpoint for last update of accumulated distance  

extern double VDL_OdometerReading(uint8_t index);
extern void VDL_SetOdometerReading(double fOdometer, uint8_t index);
extern void VDL_SetOdoEcuSource(uint8_t u8Src, uint8_t index);
extern uint8_t VDL_GetOdoEcuSource(uint8_t index);
extern void VDL_SetOdometerType(uint8_t type, uint8_t index);
extern uint8_t VDL_GetOdometerType(uint8_t index);

extern const char*	VDL_GetBusVin(void);									// Return the vehicle identification number
extern int 			VDL_RequestVIN2(void);									//This is LD VIN request. Unlike VDL_RequestVIN, it does not modify internal copy of VIN.																		

extern int			VDL_SetAutoRuntimeSelect(char manuCode);

extern DistCalcStatus VDL_GetOdoMethodOverride(void);
extern SpeedCalcStatus VDL_GetSpeedMethodOverride(void);

extern bool VDL_BroadcastVinAvailable(void);

extern int VDL_GetConfigFileVersionString(char *cfgStr);
extern int VDL_GetConflictState(void);
extern bool VDL_GetBroadcastOdoMethod(DistCalcStatus *method);
extern bool VDL_GetVinDerivedEngineSize(uint32_t *size);
extern FuelTypes VDL_GetVinDerivedFuelType(void);

extern int VDL_ClearAllFaults(void);
extern int VDL_ClearFaults(VDL_CLEAR_FAULT_ITEM* faults, uint32_t numberOfFaults);

#if defined(__cplusplus)
}
#endif

#endif
