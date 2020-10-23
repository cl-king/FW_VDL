/********************************************************************
* File:     $Id: CoreParams.h,v 1.15 2010/03/29 09:00:35 Rharvie Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.15 $
* Date:     $Date: 2010/03/29 09:00:35 $
* Author:   $Author: Rharvie $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for modules <CoreParams_XXX.c>
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2006-2008 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: CoreParams.h,v $
*   Revision 1.15  2010/03/29 09:00:35  Rharvie
*   Improved new DTC detection.
*
*   Revision 1.14  2010/03/26 11:54:20  Rharvie
*   New DTC code handling
*
*   Revision 1.13  2010/01/22 14:48:18  richard
*   Build 1.3.0.x.13
*
*   Revision 1.12  2009/11/30 16:57:19  richard
*   Combined all vehicle protocols.
*   Added FIFO test
*
*   Revision 1.11  2009/08/19 16:43:49  richard
*   Build 24 changes
*
*   Revision 1.10  2009/07/16 12:25:57  richard
*   *** empty log message ***
*
*   Revision 1.9  2009/04/20 10:57:30  accutest\colin
*   Added torque as a Core Parameter
*
*   Revision 1.8  2009/02/27 11:48:55  richard
*   Added support for Cruise Control and PTO
*
*   Revision 1.7  2009/02/19 11:18:15  accutest\colin
*   Restored arrays to Acceptance Filter RAM
*
*   Revision 1.6  2009/02/18 16:45:19  accutest\colin
*   Added build specific to put arrays back in main RAM
*
*   Revision 1.5  2009/01/27 16:21:22  richard
*   Moved some of CoreParams to it's own file.
*
*   Revision 1.4  2008/12/17 08:37:40  accutest\colin
*   Add DTC capability to the Trafficmaster project
*
*   Revision 1.3  2008/12/12 10:55:14  accutest\colin
*   Added additional parameters used by CMS for the J1587 version
*
*   Revision 1.2  2008/10/27 09:11:14  accutest\colin
*   Changed J1708 to J1587 to reflect diagnostic protocol name
*
*   Revision 1.1  2008/07/18 12:42:09  ACCUTEST\richard
*   API requried for all CORE_XXXX C files
*
*
*
*********************************************************************
*/

#ifndef COREPARAMS_H
#define COREPARAMS_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"
#include "CoreTypes.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#if (CORE_DEBUG == 1)
#define CORE_TRACE(...)  MODULE_TRACE("CORE", __VA_ARGS__)
#define SPEED_TRACE(...) MODULE_TRACE("SPEED", __VA_ARGS__)
#define BCAST_TRACE(...)  MODULE_TRACE("BCAST", __VA_ARGS__)
#else
#define CORE_TRACE(...) 
#define SPEED_TRACE(...)
#endif

#define GPS_MIN_SPEED_THRESHOLD		(5.0)		// Min GPS speed in km/h that will result in a GPS based odometer update

//fuel factor range
#define CP_FUEL_FACTOR_MIN          200
#define CP_FUEL_FACTOR_MAX          5000
#define CP_FUEL_FACTOR_DEFAULT      1000

// Engine size range (ml)
#define CP_ENGINESIZE_MIN           600
#define CP_ENGINESIZE_MAX           15000
#define CP_ENGINESIZE_DEFAULT       2000

// Turbo range and mask
#define CP_TURBO_TYPE_MAX           2
#define CP_TURBO_TYPE_DEFAULT       0

// Fuel type range, mask and shift
#define CP_FUEL_TYPE_MAX            3
#define CP_FUEL_TYPE_DEFAULT        1

// Abnormal data logging thresholds
#define CP_ABNORMAL_ROAD_SPEED_THRESH	(120.0)		// Values above this are logged as abnorml, speed in km/h
#define CP_ABNORMAL_ENGINE_SPEED_THRESH (7000.0)	// RPM above this value is logged as abnormal
#define CP_ABNORMAL_BATT_VOLTAGE_THRESH	(30.0)		// Battery voltage above this level will be logged as abnormal

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/



// Core functions
uint8_t CORE_InitModule(void);							// Initialises CORE and FUEL module
uint8_t CORE_ConnectToVehicle(void);					// Connects to vehicle for connection based protocols
uint8_t CORE_Disconnect(void);							// Disconnects to vehicle for connection based protocols
void	CORE_SetAutoConnect(int1_t bEnable);			// Enables automatic connection
uint8_t CORE_GetConnectionStatus(void);					// Returns connection status (see enum)
uint8_t	CORE_ProcessData(void);							// Call every second to process data from vehicle.
const char* CORE_GetProtocolInformationString(void);


// Core data 
int CORE_SetParamValue(ParamSource src, uint8_t u8Param, double value, bool avail);	// Set a parameter
int CORE_SetSupport(uint8_t u8Param, bool avail);					// Set support available
double	CORE_GetParamValue(uint8_t u8Param);						// Request the current value of a certain param
int1_t  CORE_IsParamAvailable(uint8_t u8Param);						// TRUE if param is available and valid
void	CORE_ClearAll(int1_t bPreserveGpsParams);						// Set param true to preserve GPS based speed and distance
uint8_t CORE_RequestVIN(void);										// Force a J1979 VIN request but only if supported
void CORE_ResetLastReceivedOdoMethod(void);							// Used to allow LD odometer to use a new method if it was locked onto an old method
ParamSource CORE_GetParamSource(uint8_t u8Param);					// Source is J1939, J1587 and etc
void CORE_ResetLastReceivedRuntimeMethod(void);

void CORE_Calculate_FuelUsedSinceBootup(ParamSource src, double fuelRate, uint32_t timestamp); 

#ifdef __INCLUDE_COREPARAMS_DTCS

/* Core Paramter DTC Support */
#ifdef KARLOFF
int CORE_Init(void);
void CORE_ParamTiming_Check(void);
#endif
uint32_t CORE_GetDTCCount(void);                         /* Same as CORE_GetParamValue(CORE_PARAM_DTC_COUNT); */
uint32_t CORE_GetNextDTC(int1_t bNext_);                 /* False if the first DTC is desired */
int1_t   CORE_DtcLock(uint32_t lockId);                  /* Allows locking of DTC data by calling function */
void     CORE_DtcUnlock(void);                               /* Unlocks DTC data */
int1_t CORE_GetDTCDetails(uint32_t dtcNum, uint32_t* DtcCode, uint8_t* DtcReason, uint8_t *DtcEcu, uint8_t *DtcType, uint8_t *DtcOcc, uint8_t *DtcIsSid); // returns false if dtcNum is not valid
int1_t CORE_AddDtcToList(uint32_t DtcCode, uint8_t DtcReason, uint8_t DtcEcu, uint8_t DtcType, uint8_t DtcOcc, uint8_t isSid); // returns true if added, false if already exists
int1_t CORE_ClearDtcFromList(uint32_t DtcCode, uint8_t DtcReason, uint8_t DtcEcu, uint8_t DtcType, uint8_t isSID); // returns true if status changed, false if doesn't exist
void  CORE_UpdateDtcStatus(void);
void CORE_AddLampStatus(uint8_t dtcEcu, uint8_t lampType,uint32_t lampStatus);
#ifndef _DISABLE_DTC_DEACTIVATION
int1_t CORE_DeactiveDtcInList(uint32_t DtcCode, uint8_t DtcReason, uint8_t DtcEcu, uint8_t DtcType, uint8_t DtcOcc, uint8_t isSID); // returns true if added, false if already exists
#endif
int1_t CORE_SetClearTimeInDtcList(uint8_t DtcEcu, uint8_t DtcType, uint32_t DtcCode, uint8_t DtcReason, uint8_t isSID, uint32_t clearAllDtcFromEcu);
void CORE_ClearClearedDtc(void);
uint8_t CORE_GetNumClearedDTC(void);
int1_t CORE_DeleteDtcFromList(uint32_t DtcCode, uint8_t DtcReason, uint8_t DtcEcu, uint8_t isSid); // true if deleted, false if not there
int1_t CORE_ClearDtcsFromAll(void);
int1_t CORE_ClearDtcsFromEcu(uint32_t DtcEcu);
int1_t CORE_FlushDtcsFromAll(void);
int1_t CORE_FlushDtcsFromEcu(uint32_t DtcEcu);
int1_t CORE_HadDtcsChanged(void);		// returns true if DTCs have changed since last queried
int1_t CORE_CriticalECUHasFault(void);	// return true if DTCs for critical drivetrain have changed since last queried.
char*  CORE_GetNextDTCString(int1_t bNext_);
int1_t CORE_GetDtcEventDetails(uint32_t dtcNum, uint32_t *eventTime, uint32_t *locationTime, uint32_t *lattitude, uint32_t *longitude);
int1_t CORE_GetDtcActivityDetails(uint32_t dtcNum, uint32_t *status, uint32_t *deactiveTime, uint32_t *clearedTime);
double CORE_SanitiseRoadSpeed(double dInputRoadSpeed);
void CORE_cleareLampStatus(void);
uint32_t CORE_getLampStatus(void);

int1_t CORE_IsOdoMethodValid(uint8_t u8Ecu, DistCalcStatus method);
int1_t CORE_IsFuelMethodValid(uint8_t u8Ecu, FuelCalcStatus method);
int1_t CORE_IsSpeedMethodValid(uint8_t u8Ecu, SpeedCalcStatus method);
int1_t CORE_IsRuntimeMethodValid(uint8_t u8Ecu, RuntimeCalcStatus method);

#ifdef _VDL_GPS_FALLBACK_ENABLE
void CORE_OverrideSpeedMethod(uint8_t u8Method);
void CORE_ResetSpeedOverrideTimer(void);
int CORE_GetSpeedOverrideTimer(void);
void CORE_ResetSpeedOverride(void);
void CORE_SaveSpeedMethod(SpeedCalcStatus method);
SpeedCalcStatus CORE_GetSpeedMethodOverride(void);

void CORE_OverrideOdodMethod(uint8_t u8Method);
void CORE_ResetOdoOverride(void);
int CORE_GetOdoOverrideTimer(void);
void CORE_SaveDistCalcMethod(DistCalcStatus method);
DistCalcStatus CORE_GetOdoMethodOverride(void);
#endif
void CORE_ToggleSimSpeedCheck(void);

int1_t CORE_IsOdometerVehicleBased(void);
int1_t CORE_IsLowResBusOdometer(double *resoultion);
void CORE_EnableSpeedDebug(int1_t enable);

void CORE_GetTargetedVINRequestJ1939(uint8_t * ecu, uint16_t* pgn);
void CORE_GetTargetedVINRequestJ1587(uint8_t * mid, uint16_t* pid);

double CORE_OdometerReading(uint8_t index);
void CORE_SetOdometerReading(double fOdometer, uint8_t index);
void CORE_SetOdoEcuSource(uint8_t u8Src, uint8_t index);
uint8_t CORE_GetOdoEcuSource(uint8_t index);
void CORE_SetOdometerType(uint8_t type, uint8_t index);
uint8_t CORE_GetOdometerType(uint8_t index);

uint8_t CORE_RequestVIN2(void);

// J1979 Odometer support
uint32_t CORE_GetInt(uint8_t* u8Data, int numBytes);
void CORE_J1979UpdateOdometer(double fOdometer, DistCalcStatus method);

#endif /* __INCLUDE_COREPARAMS_DTCS */

int1_t Core_SendJ1939ClearAllFaultsRequest(void);
	
int1_t Core_SendJ1587ClearAllFaultRequest(void);

void Core_SetClearFaultStatus(uint32_t ackType, 
                              uint32_t DtcCode, 
                              uint8_t DtcReason, 
                              uint8_t DtcEcu, 
                              uint8_t protocol, 
                              uint8_t isSID);
void Core_SetClearStatusForEcu(uint8_t protocol, uint32_t ackType, uint8_t DtcEcu);
int1_t Core_SendJ1587ClearFaultRequest(uint8_t mid, uint32_t code, uint8_t fmi, uint8_t sidORpid);
int1_t Core_SendJ1939ClearFaultRequest(uint8_t ecu, uint32_t pgn, uint8_t fmi,uint8_t active);

#ifdef __INCLUDE_COREPARAMSGENERIC_MODULE
void CORE_AllowDiagnostics(int1_t bEnable);				/* Enabled / disable vehicle diagnostics */
#endif

int1_t J1979CORE_IsBusOdoStale(void);
#ifdef DECOUPLE_VD_SPEED_ODO_METHOD
int1_t J1979CORE_IsBusSpeedStale(void);
int1_t J1939CORE_IsBusOdoStale(void);
int1_t J1939CORE_IsBusSpeedStale(void);
int1_t J1587CORE_IsBusOdoStale(void);
int1_t J1587CORE_IsBusSpeedStale(void);
int1_t CORE_IsBusOdoStale(void);
int1_t CORE_IsBusSpeedStale(void);
int1_t CORE_IsConfiguredOdometerVehicleBased(void);
#endif

void CORE_UpdateRpmStats(void);
int CORE_GetFordOdoPriority(DistCalcStatus method);
void Core_RecordBusOdoReading(DistCalcStatus type, double value);

// Bus conflict functions
void CORE_SetConflictState(teConflictState conflictState);
teConflictState CORE_GetConflictState(void);

// From CoreParamsJ1587.c
void CORE_gJ1587Task(void);
uint32_t CORE_J1587MessagesWaiting(void);
uint8_t J1587CORE_InitModule(void);
uint8_t J1587CORE_ConnectToVehicle(void);
uint8_t J1587CORE_Disconnect(void);
uint8_t J1587CORE_ProcessData(void);
int1_t J1587CORE_IsPIDDataInvalid(uint8_t *u8Data, uint32_t u32Length, uint32_t u32Offset);

// From CoreParamsJ1939.c
uint8_t J1939CORE_ConnectToVehicle(int1_t bJ1939Passive, uint32_t bitRate);
uint8_t J1939CORE_Disconnect(void);
uint8_t J1939CORE_ProcessData(void);
void J1939CORE_ProcessCanMessage(tsCanMsgV2 *pMsg);
void J1939CORE_ConnectCleanUp(void);
uint8_t J1939CORE_GetConnectionStatus(void);
#ifdef J1939_STANDALONE
uint8_t J1939CORE_InitModule(void);
#endif
void J1939CORE_SetAutoConnect(int1_t bEnable);
void J1939CORE_VIMessgeHandler(uint32_t u32Length_, uint8_t *pData_);
void J1939CORE_PopulateFuelFromMAF(double fMaf, uint32_t u32MafMode);

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/
#ifdef __CORE_USE_FILTER_MEM
extern double *CoreValues;
extern int32_t *CoreSupport;
#else
#ifndef KARLOFF
extern double      CoreValues[CORE_PARAMS_N_ELEMENTS];		// Holder for data
extern int1_t      CoreSupport[CORE_PARAMS_N_ELEMENTS];		// Supported data
#endif
#endif
#endif // COREPARAMS_H
