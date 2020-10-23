/********************************************************************
* File:     $Id: Fuel.h,v 1.14 2008/08/14 11:29:37 ACCUTEST\richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.14 $
* Date:     $Date: 2008/08/14 11:29:37 $
* Author:   $Author: ACCUTEST\richard $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <Fuel.c>
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
*   $Log: Fuel.h,v $
*   Revision 1.14  2008/08/14 11:29:37  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.13  2008/08/13 16:24:35  ACCUTEST\simon
*   Added FUEL_StopMeasurment function.
*
*   Revision 1.12  2008/08/11 16:17:11  ACCUTEST\simon
*   Added FUEL_StartMeasurement function. This is used at ignition ON to reset the last
*    time that valid data in the FUEL module was used. This is needed to prevent the FUEL
*    module from calculating a huge usage or distance because the time from the last measurment
*    was a very long time ago !!!
*
*   Revision 1.11  2008/08/11 15:26:56  ACCUTEST\simon
*   Moved Total fuel from Fuel to VehicleInfo. The total fuel is now an accumulative stored
*    value accessable via AT$SF? (read) or set via AT$VI=*,*,<value>.
*
*   Revision 1.10  2008/08/06 14:46:50  ACCUTEST\simon
*   Added reset function for last tick counter
*
*   Revision 1.9  2008/07/29 16:02:47  ACCUTEST\richard
*   Changes to make Enfora / Webtech / LCD builds use CoreParams
*
*   Revision 1.8  2008/07/15 14:58:00  ACCUTEST\simon
*   Added function prototype
*
*   Revision 1.7  2008/07/14 15:31:14  ACCUTEST\richard
*   Added wrapper functions for rpm, speed and fuel level
*
*   Revision 1.6  2008/07/03 11:24:02  ACCUTEST\simon
*   Added Fuel config to AT Commands and moved FUEL_Init to main.c
*
*   Revision 1.5  2008/06/23 08:52:53  ACCUTEST\richard
*   Added function definition
*
*   Revision 1.4  2008/06/18 10:55:10  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.3  2008/06/13 08:51:20  ACCUTEST\richard
*   Added max accel / decel values
*   Added distance calculations
*   Added ability to get supported PIDs
*   Added Fuel level parameter
*
*   Revision 1.2  2008/05/12 10:14:38  ACCUTEST\simon
*   CMS J1979 V2.3.3.0, plus various bug fixes and fuel rate calculation tweeks.
*
*   Revision 1.1  2008/05/08 09:43:19  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*
*
*********************************************************************
*/

#ifndef FUEL_H
#define FUEL_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"
#include "J1979.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

// Status of fuel parameter value
#define FUEL_PARAM_INVALID                  (false)
#define FUEL_PARAM_VALID                    (true)

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

uint8_t FUEL_InitModule(void);
void    FUEL_SetRequired(int u8Parameter);
int1_t  FUEL_IsSupported(int u8Parameter);
int1_t 	FUEL_IsRequired(int u8Parameter);
void    FUEL_SetValue(int u8Parameter, double fValue, int1_t bAvailable);
double  FUEL_GetValue(int u8Parameter);
void    FUEL_OutputToLCD(void);
int1_t  FUEL_IsValueAvailable(int u8Parameter);
uint32_t FUEL_GetLastRxTime(int u8Parameter);
int1_t FUEL_IsParamFresh(int u8Parameter);

uint8_t FUEL_GetFirstSupportedParameter(void);
uint8_t FUEL_GetNextSupportedParameter(void);

uint8_t FUEL_GetFirstRequiredParameter(void);
uint8_t FUEL_GetNextRequiredParameter(void);

void    FUEL_ProcessJ1979Message(uint8_t pid, uint8_t *pu8Data, uint8_t datalength);
void    FUEL_StartMeasurment(void);
void    FUEL_StopMeasurment(void);

// external parameter access
int1_t  FUEL_IsFuelRateAvailable(void);
double  FUEL_GetLitresPerSecond(void);
void    FUEL_UpdateTotalLitresUsed(void);
double	FUEL_GetDistance(void);
double	FUEL_GetMaxAccel(void);
double	FUEL_GetMaxDecel(void);
void	FUEL_ResetMaxParams(void);
uint8_t FUEL_GetFuelRateCalcType(void);
double	FUEL_GetEngineRPM(void);
double	FUEL_GetVehicleSpeed(void);
double  FUEL_GetFuelLevel(void);
uint32_t Fuel_GetLastSpeedRx(void);
void FUEL_CalculateAccelAndDistance(double fKph, int1_t bUpdateOdometer);

#ifdef _VDL_GPS_FALLBACK_ENABLE
int1_t 	Fuel_HandleGpsSpeedFallback(double fSpeed, int1_t bGpsLock, uint32_t u32Timeout);
#endif

void    FUEL_UpdateConfig(void);
/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif // FUEL_H
