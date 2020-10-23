/********************************************************************
* File:     $Id: ExtFlash_VehicleInfo.h,v 1.1 2010/10/08 13:20:09 Amiao Exp $
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
*	Provides header file information for module <ExtFlash_VehicleInfo.c>
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
*   $Log: ExtFlash_VehicleInfo.h,v $
*   Revision 1.1  2010/10/08 13:20:09  Amiao
*   TVG660 port on TM3000. Current TVG version 1.5.0.X.29.
*
*   Revision 1.12  2009/03/31 10:33:35  richard
*   Latest Pinpointers stuff
*
*   Revision 1.11  2009/02/13 14:07:57  simon
*   Added functions to _ResetVIN() and _ResetProtocol()
*
*   Revision 1.10  2009/02/12 12:17:28  DBateman
*   Added storage used for the new Trimble/@Road trip fuel measurement code.
*
*   Revision 1.9  2008/12/17 10:56:47  accutest\colin
*   Added SetHiResOdometer()
*
*   Revision 1.8  2008/12/12 10:56:05  accutest\colin
*   Added storage for calculation methods
*
*   Revision 1.7  2008/08/19 09:49:43  ACCUTEST\richard
*   Made CoreParamsJ1979 store total fuel in flash
*
*   Revision 1.6  2008/08/14 15:27:17  ACCUTEST\simon
*   Changed odometer and total fuel to use a 'double' internally and during periodic trip
*    increments to eliminate/reduce rounding errors.
*
*   Revision 1.5  2008/08/14 11:29:37  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.4  2008/08/13 15:11:43  ACCUTEST\richard
*   Added fudge factor to ford module
*   FIxed a few bugs in at commands
*   Now stores fudge factor in flash
*
*   Revision 1.3  2008/08/11 15:26:56  ACCUTEST\simon
*   Moved Total fuel from Fuel to VehicleInfo. The total fuel is now an accumulative stored
*    value accessable via AT$SF? (read) or set via AT$VI=*,*,<value>.
*
*   Revision 1.2  2008/08/08 11:24:48  accutest\colin
*   Added Total Fuel used as a stored variable
*
*   Revision 1.1  2008/07/08 08:35:17  ACCUTEST\simon
*   Implemented a Vehicle Info module to store general
*    non-volatile information about the vehicle
*
*
* Change Log:
*
*********************************************************************
*/

#ifndef EXT_FLASH_VEHICLE_INFO_H
#define EXT_FLASH_VEHICLE_INFO_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

#include "ExtFlash.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* MEMORY MAP (NOTE : DO NOT move addresses once allocated !!!)     */
/*------------------------------------------------------------------*/

// (NOTE : see ExtFlash.h for memory map base address)

#define VI_ODOMETER_ADDRESS     (FLASH_VI_START_ADDRESS)
#define VI_ODOMETER_SIZE        (sizeof(uint32_t))  // 4 bytes
#define VI_PROTOCOL_ADDRESS     (VI_ODOMETER_ADDRESS + VI_ODOMETER_SIZE)
#define VI_PROTOCOL_SIZE        (sizeof(uint8_t))   // 1 bytes
#define VI_VIN_ADDRESS          (VI_PROTOCOL_ADDRESS + VI_PROTOCOL_SIZE)
#define VI_VIN_SIZE             (17)                // 17 bytes
#define VI_TOTAL_FUEL_ADDRESS   (VI_VIN_ADDRESS + VI_VIN_SIZE)
#define VI_TOTAL_FUEL_SIZE      (sizeof(uint32_t))  // 4 bytes
#define VI_FUDGE_FACTOR_ADDRESS (VI_TOTAL_FUEL_ADDRESS + VI_TOTAL_FUEL_SIZE)
#define VI_FUDGE_FACTOR_SIZE    (sizeof(uint32_t))  // 4 bytes
#define VI_ENGINE_SIZE_ADDRESS  (VI_FUDGE_FACTOR_ADDRESS + VI_FUDGE_FACTOR_SIZE)
#define VI_ENGINE_SIZE_SIZE     (sizeof(uint32_t))  // 4 bytes
#define VI_VOLUMETRIC_EFF_ADDRESS (VI_ENGINE_SIZE_ADDRESS + VI_ENGINE_SIZE_SIZE)
#define VI_VOLUMETRIC_EFF_SIZE    (sizeof(uint32_t))  // 4 bytes
#define VI_FUEL_CALC_ADDRESS    (VI_VOLUMETRIC_EFF_ADDRESS + VI_VOLUMETRIC_EFF_SIZE)
#define VI_FUEL_CALC_SIZE       (sizeof(uint8_t))     /* 1 Byte */
#define VI_DIST_CALC_ADDRESS    (VI_FUEL_CALC_ADDRESS + VI_FUEL_CALC_SIZE)
#define VI_DIST_CALC_SIZE       (sizeof(uint8_t))     /* 1 Byte */
#define VI_TURBO_ADDRESS        (VI_DIST_CALC_ADDRESS + VI_DIST_CALC_SIZE)
#define VI_TURBO_SIZE           (sizeof(uint8_t))     /* 1 Byte */
#define VI_FUELTYPE_ADDRESS     (VI_TURBO_ADDRESS + VI_TURBO_SIZE)
#define VI_FUELTYPE_SIZE        (sizeof(uint8_t))     /* 1 Byte */

#define VI_FIXODOMID_ADDRESS        (VI_FUELTYPE_ADDRESS + VI_FUELTYPE_SIZE)
#define VI_FIXODOMID_SIZE           (sizeof(uint8_t))     /* 1 Byte */
#define VI_FIXODOMETHOD_ADDRESS     (VI_FIXODOMID_ADDRESS + VI_FIXODOMID_SIZE)
#define VI_FIXODOMETHOD_SIZE        (sizeof(uint8_t))     /* 1 Byte */

#define VI_FIXFUELMID_ADDRESS       (VI_FIXODOMETHOD_ADDRESS + VI_FIXODOMETHOD_SIZE)
#define VI_FIXFUELMID_SIZE          (sizeof(uint8_t))     /* 1 Byte */
#define VI_FIXFUELMETHOD_ADDRESS    (VI_FIXFUELMID_ADDRESS + VI_FIXFUELMID_SIZE)
#define VI_FIXFUELMETHOD_SIZE       (sizeof(uint8_t))     /* 1 Byte */

#define VI_FIXSPEEDMID_ADDRESS      (VI_FIXFUELMETHOD_ADDRESS + VI_FIXFUELMETHOD_SIZE)
#define VI_FIXSPEEDMID_SIZE         (sizeof(uint8_t))     /* 1 Byte */
#define VI_FIXSPEEDMETHOD_ADDRESS   (VI_FIXSPEEDMID_ADDRESS + VI_FIXSPEEDMID_SIZE)
#define VI_FIXSPEEDMETHOD_SIZE      (sizeof(uint8_t))     /* 1 Byte */
#define VI_DIST_BETWEEN_BUS_SAMPLE_ADDRESS   (VI_FIXSPEEDMETHOD_ADDRESS + VI_FIXSPEEDMETHOD_SIZE)
#define VI_DIST_BETWEEN_BUS_SAMPLE_SIZE      (sizeof(uint32_t))     /* 4 Byte */
#define VI_DIST_EST_ODOM_REFERENCE_ADDRESS   (VI_DIST_BETWEEN_BUS_SAMPLE_ADDRESS + VI_DIST_BETWEEN_BUS_SAMPLE_SIZE)
#define VI_DIST_EST_ODOM_REFERENCE_SIZE      (sizeof(uint32_t))     /* 4 Byte */

#define VI_FIX_RUNTIME_METHOD_ADDRESS 	(VI_DIST_EST_ODOM_REFERENCE_ADDRESS + VI_DIST_EST_ODOM_REFERENCE_SIZE)
#define VI_FIX_RUNTIME_METHOD_SIZE		(sizeof(uint8_t))	/* 1 byte */
#define VI_EST_ENGINE_RUNTIME_ADDRESS	(VI_FIX_RUNTIME_METHOD_ADDRESS + VI_FIX_RUNTIME_METHOD_SIZE)
#define VI_EST_ENGINE_RUNTIME_SIZE		(sizeof(uint32_t))	/* 4 bytes */

#define VI_ODO_BCAST_CANID_ADDRESS		(VI_EST_ENGINE_RUNTIME_ADDRESS + VI_EST_ENGINE_RUNTIME_SIZE)
#define VI_ODO_BCAST_CANID_SIZE			(sizeof(uint32_t)) // 4 byte

#define VI_FIX_RUNTIME_MID_ADDRESS		(VI_ODO_BCAST_CANID_ADDRESS + VI_ODO_BCAST_CANID_SIZE)
#define VI_FIX_RUNTIME_MID_SIZE			(sizeof(uint8_t)) // 1 byte

#ifdef BUILD_ATROAD
#  define VI_TRIP_SEQUENCE_NUMBER_ADDRESS    (VI_DIST_CALC_ADDRESS + VI_DIST_CALC_SIZE)
#  define VI_TRIP_SEQUENCE_NUMBER_SIZE       (sizeof(uint8_t))    // 1 byte

#  define VI_TRIP_START_END_FLAGS_ADDRESS    (VI_TRIP_SEQUENCE_NUMBER_ADDRESS + VI_TRIP_SEQUENCE_NUMBER_SIZE)
#  define VI_TRIP_START_END_FLAGS_SIZE       (sizeof(uint8_t))    // 1 byte

#  define VI_TRIP_FUEL_USED_ADDRESS          (VI_TRIP_START_END_FLAGS_ADDRESS + VI_TRIP_START_END_FLAGS_SIZE)
#  define VI_TRIP_FUEL_USED_SIZE             (sizeof(double))    // 8? bytes

#  define VI_IDLE_FUEL_USED_ADDRESS          (VI_TRIP_FUEL_USED_ADDRESS + VI_TRIP_FUEL_USED_SIZE)
#  define VI_IDLE_FUEL_USED_SIZE             (sizeof(double))    // 8? bytes

#  define VI_PTO_FUEL_USED_ADDRESS           (VI_IDLE_FUEL_USED_ADDRESS + VI_IDLE_FUEL_USED_SIZE)
#  define VI_PTO_FUEL_USED_SIZE              (sizeof(double))    // 8? bytes

#  define VI_TRIP_START_FUEL_MARK_ADDRESS    (VI_PTO_FUEL_USED_ADDRESS + VI_PTO_FUEL_USED_SIZE)
#  define VI_TRIP_START_FUEL_MARK_SIZE       (sizeof(double))    // 8? bytes

#  define VI_IDLE_START_FUEL_MARK_ADDRESS    (VI_TRIP_START_FUEL_MARK_ADDRESS + VI_TRIP_START_FUEL_MARK_SIZE)
#  define VI_IDLE_START_FUEL_MARK_SIZE       (sizeof(double))    // 8? bytes

#  define VI_PTO_START_FUEL_MARK_ADDRESS     (VI_IDLE_START_FUEL_MARK_ADDRESS + VI_IDLE_START_FUEL_MARK_SIZE)
#  define VI_PTO_START_FUEL_MARK_SIZE        (sizeof(double))    // 8? bytes

/* #  define VI_OLD_TRIP_SEQUENCE_NUMBER_ADDRESS    (VI_PTO_START_FUEL_MARK_ADDRESS + VI_PTO_START_FUEL_MARK_SIZE) */
/* #  define VI_OLD_TRIP_SEQUENCE_NUMBER_SIZE       (sizeof(uint8_t))    // 1 byte */

/* #  define VI_OLD_TRIP_FUEL_USED_ADDRESS          (VI_OLD_TRIP_SEQUENCE_NUMBER_ADDRESS + VI_OLD_TRIP_SEQUENCE_NUMBER_SIZE) */
/* #  define VI_OLD_TRIP_FUEL_USED_SIZE             (sizeof(double))    // 8? bytes */

/* #  define VI_OLD_IDLE_FUEL_USED_ADDRESS          (VI_OLD_TRIP_FUEL_USED_ADDRESS + VI_OLD_TRIP_FUEL_USED_SIZE) */
/* #  define VI_OLD_IDLE_FUEL_USED_SIZE             (sizeof(double))    // 8? bytes */

/* #  define VI_OLD_PTO_FUEL_USED_ADDRESS           (VI_OLD_IDLE_FUEL_USED_ADDRESS + VI_OLD_IDLE_FUEL_USED_SIZE) */
/* #  define VI_OLD_PTO_FUEL_USED_SIZE              (sizeof(double))    // 8? bytes */

#endif // BUILD_ATROAD

#define VI_ECU_MAP              FLASH_VI_START_ADDRESS + 128        // Use next free block - note VI starts on a half block boundary!

//fuel factor range
#define FUEL_FACTOR_MIN 200
#define FUEL_FACTOR_MAX 5000

#define ENGINESIZE_MIN  600
#define ENGINESIZE_MAX  15000

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

uint8_t     VehicleInfo_InitModule(void);
uint8_t     VehicleInfo_Reset(void);
void        VehicleInfo_Load(void);
void        VehicleInfo_Save(void);

// parameters
uint32_t    VehicleInfo_GetOdometer(void);                          // KM
uint32_t    VehicleInfo_GetHiResOdometer(void);                     // M
void        VehicleInfo_SetOdometer(uint32_t odometerKilometers);   // KM
void        VehicleInfo_SetHiResOdometer(double odometerMeters);    // M
void        VehicleInfo_IncrementOdometer(double meters);           // M + fraction

const char* VehicleInfo_GetVIN(void);
uint32_t   VehicleInfo_IsVINAvailable(void);
void        VehicleInfo_SetVIN(const char* lpVIN);
void        VehicleInfo_ResetVIN(int1_t bSave);

const char* VehicleInfo_GetBusVIN(void);
uint32_t    VehicleInfo_IsBusVINAvailable(void);
void        VehicleInfo_SetBusVIN(const char* lpVIN);
void        VehicleInfo_ResetBusVIN(void);

uint8_t     VehicleInfo_GetProtocol(void);
void        VehicleInfo_SetProtocol(uint8_t protocol);
void        VehicleInfo_ResetProtocol(int1_t bSave);

uint32_t    VehicleInfo_GetTotalFuel(void);                         // L
uint32_t    VehicleInfo_GetHiResTotalFuel(void);                    // ml
void        VehicleInfo_SetTotalFuel(uint32_t totalFuelLitres);     // L
void        VehicleInfo_SetTotalFuelHiRes(double totalFuelml);      // ml
void        VehicleInfo_IncrementTotalFuel(double millilitres);     // ml + fraction
double      VehicleInfo_GetDblTotalFuel(void);                      // ml + fraction

void        VehicleInfo_SetFudgeFactor(double fudge);
double      VehicleInfo_GetFudgeFactor(void);

void        VehicleInfo_SetEngineSize(double size);
double      VehicleInfo_GetEngineSize(void);

void        VehicleInfo_SetVolumetricEff(double efficiency);
double      VehicleInfo_GetVolumetricEff(void);

void        VehicleInfo_SetTurboType(uint8_t turbo);
uint8_t     VehicleInfo_GetTurboType(void);

void        VehicleInfo_SetFuelType(uint8_t fuelType);
uint8_t     VehicleInfo_GetFuelType(void);


void	VehicleInfo_IncrementDistBetweenBusSamples(double deltaDist, double odomRes);
void	VehicleInfo_ResetDistBetweenBusSamples(void);
double	VehicleInfo_GetDistBetweenBusSamples(void);
double	VehicleInfo_GetEstimatedOdomReference(void);
void 	VehicleInfo_AdjustDistBetweenBusSamples(double deltaDist, double odomRes);

void 		VehicleInfo_IncrementEstimatedRuntime(uint32_t seconds);
void 		VehicleInfo_SetEstimatedRuntime(uint32_t seconds);
uint32_t 	VehicleInfo_GetEstimatedRuntime(void);

#ifdef BUILD_ATROAD
void        VehicleInfo_SetTripSequenceNumber(uint8_t  n);
uint8_t     VehicleInfo_GetTripSequenceNumber(void);

void        VehicleInfo_SetTripStartEndFlags(uint8_t  flags);
uint8_t     VehicleInfo_GetTripStartEndFlags(void);

void        VehicleInfo_SetTripFuelUsed(double  fuel);
double      VehicleInfo_GetTripFuelUsed(void);

void        VehicleInfo_SetIdleFuelUsed(double  fuel);
double      VehicleInfo_GetIdleFuelUsed(void);

void        VehicleInfo_SetPtoFuelUsed(double  fuel);
double      VehicleInfo_GetPtoFuelUsed(void);

void        VehicleInfo_SetTripStartFuelMark(double  fuel);
double      VehicleInfo_GetTripStartFuelMark(void);

void        VehicleInfo_SetIdleStartFuelMark(double  fuel);
double      VehicleInfo_GetIdleStartFuelMark(void);

void        VehicleInfo_SetPtoStartFuelMark(double  fuel);
double      VehicleInfo_GetPtoStartFuelMark(void);

/* void        VehicleInfo_SetOldTripSequenceNumber(uint8_t  n); */
/* uint8_t     VehicleInfo_GetOldTripSequenceNumber(void); */

/* void        VehicleInfo_SetOldTripFuelUsed(double  fuel); */
/* double      VehicleInfo_GetOldTripFuelUsed(void); */

/* void        VehicleInfo_SetOldIdleFuelUsed(double  fuel); */
/* double      VehicleInfo_GetOldIdleFuelUsed(void); */

/* void        VehicleInfo_SetOldPtoFuelUsed(double  fuel); */
/* double      VehicleInfo_GetOldPtoFuelUsed(void); */

#endif // BUILD_ATROAD

int        VehicleInfo_EcuMapLoad(uint8_t *data, uint32_t u32Length);
void        Vehicleinfo_EcuMapSave(uint8_t *data, uint32_t u32Length);

uint8_t     VehicleInfo_GetDistCalcMid(void);
uint8_t     VehicleInfo_GetDistCalcMethod(void);
uint8_t     VehicleInfo_GetFuelMid(void);
uint8_t     VehicleInfo_GetFuelMethod(void);
uint8_t     VehicleInfo_GetSpeedMid(void);
uint8_t     VehicleInfo_GetSpeedMethod(void);
uint8_t		VehicleInfo_GetRuntimeMethod(void);
uint8_t     VehicleInfo_GetRuntimeCalcMid(void);

void        VehicleInfo_SetDistCalcMid(uint8_t u8Mid);
void        VehicleInfo_SetDistCalcMethod(uint8_t u8Method);
void        VehicleInfo_SetFuelMid(uint8_t u8Mid);
void        VehicleInfo_SetFuelMethod(uint8_t u8Method);
void        VehicleInfo_SetSpeedMid(uint8_t u8Mid);
void        VehicleInfo_SetSpeedMethod(uint8_t u8Method);
void		VehicleInfo_SetRuntimeMethod(uint8_t u8Method);
void        VehicleInfo_SetRuntimeCalcMid(uint8_t u8Mid);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif  // EXT_FLASH_VEHICLE_INFO_H

