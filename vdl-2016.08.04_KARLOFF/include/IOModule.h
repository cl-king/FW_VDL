/********************************************************************
* File:     $Id: IOModule.h,v 1.6 2009/11/12 16:59:11 simon Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.6 $
* Date:     $Date: 2009/11/12 16:59:11 $
* Author:   $Author: simon $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <IOModule.c>
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
*   $Log: IOModule.h,v $
*   Revision 1.6  2009/11/12 16:59:11  simon
*   Added Ananlog I/O (AVG660) and calibration functions.
*
*   Revision 1.5  2008/07/02 16:31:05  ACCUTEST\simon
*   Progressed AT Command set and renamed AVG500M to AVG600
*
*   Revision 1.4  2008/06/23 08:49:29  ACCUTEST\richard
*   Added function definition
*
*   Revision 1.3  2008/06/20 08:48:07  ACCUTEST\simon
*   Added AT Command interpreter
*
*   Revision 1.2  2007/11/29 17:36:51  ACCUTEST\simon
*   Corrected comment block
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.2  2007/04/20 14:14:27  ACCUTEST\simon
*   J1979 in progress
*
*   Revision 1.1  2007/03/27 15:49:17  ACCUTEST\paull
*   *** empty log message ***
*
*   Revision 1.3  2006/12/21 11:38:43  ACCUTEST\paull
*   style changes
*
*   Revision 1.2  2006/12/01 13:43:54  ACCUTEST\paull
*   Added STP queue message post functionality.
*
*   Revision 1.1  2006/11/29 09:46:43  ACCUTEST\paull
*   First check in of the usb module.
*
*   Revision 1.1  2006/11/27 15:51:56  ACCUTEST\paull
*   Initial checkin of the ARM_AVG module.
*
*
*********************************************************************
*/

#ifndef IOMODULE_H
#define IOMODULE_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#ifdef __TARGET_PROCESSOR_STR710
#define ADC_DEFAULT_GAIN        (float)(1282.8)        // From SDK 2.10
#define ADC_DEFAULT_ZERO_OFFSET (uint16_t)(420)        // From SDK 2.10

/* Ref divisors for analog input 0. This input is tied to either main power
* or battery power lines (selected by a mux). The two power sources have
* different resistor divider circuits.
*/
#define ADC_MAIN_PWR_REF_DIVISOR              21
#define ADC_BATT_PWR_REF_DIVISOR              2

/* Voltage drop due to the diode after the main power input, in mV. */
#define ADC_MAIN_PWR_DIODE_DROP                   753
#endif

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

// External functions
uint8_t     IO_InitModule(void);
uint16_t    IO_ReadInputVoltage(void);
int1_t      IO_VehiclePowerPresent(void);
double      IO_VehicleVoltage(void);

// DIN
int1_t      IO_DigitalInput(uint8_t channel);

// DOUT
void        IO_DigitalOutput(uint8_t channel, int1_t state);
void        IO_PWMOutput(uint8_t channel, uint32_t frequency, double dutycycle, int1_t state);

#ifdef __TARGET_PROCESSOR_STR710
void        IO_SetBackupBattery(int1_t bBackupBatt);
int1_t      IO_GetBackupBattery(void);
#endif

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif // IOMODULE_H







