/********************************************************************
* File:     $Id: license.h,v 1.4 2009/10/27 11:12:46 colin Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.4 $
* Date:     $Date: 2009/10/27 11:12:46 $
* Author:   $Author: colin $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for license information
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2009 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: license.h,v $
*   Revision 1.4  2009/10/27 11:12:46  colin
*   Pinpointers require new NMEA messages for the AVG650
*
*   Revision 1.3  2009/04/20 09:35:00  accutest\colin
*   Corrected macro error so PAESV message can be disabled
*
*   Revision 1.2  2009/03/30 11:58:55  accutest\colin
*   Added flexibility to enable/disable NMEA sentences
*
*   Revision 1.1  2009/02/19 09:58:25  simon
*   Added license.h
*
*
*********************************************************************
*/

#ifndef LICENSE_H
#define LICENSE_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define LICENSE_DISABLE_ALL             (0)

// NOTE : Bit 31 is unavailable

#define LICENSE_ENABLE_TRACKING         (30)
#define LICENSE_ENABLE_NMEA             (29)

#define LICENSE_ENABLE_DIAGNOSTICS_BIT  (28) /* Enables the A, B and G */
#define LICENSE_ENABLE_CONSTANT_BIT     (27) /* Enables the C */
#define LICENSE_ENABLE_DTC_BIT          (26) /* Enables the D */
#define LICENSE_ENABLE_ECONOMY_BIT      (25) /* Enables the E */
#define LICENSE_ENABLE_FUEL_BIT         (24) /* Enables the F */
#define LICENSE_ENABLE_TRIGGER_BIT      (23) /* Enables the T */
#define LICENSE_ENABLE_VEHICLE_BIT      (22) /* Enables the V */
#define LICENSE_ENABLE_PEDAL_BAND_BIT   (21) /* Enables the P */
#define LICENSE_ENABLE_RPM_BAND_BIT     (20) /* Enables the R */

#define LICENSE_ENABLE_PAESA            LICENSE_ENABLE_DIAGNOSTICS_BIT
#define LICENSE_ENABLE_PAESB            LICENSE_ENABLE_DIAGNOSTICS_BIT
#define LICENSE_ENABLE_PAESC            LICENSE_ENABLE_CONSTANT_BIT
#define LICENSE_ENABLE_PAESD            LICENSE_ENABLE_DTC_BIT
#define LICENSE_ENABLE_PAESE            LICENSE_ENABLE_ECONOMY_BIT
#define LICENSE_ENABLE_PAESF            LICENSE_ENABLE_FUEL_BIT
#define LICENSE_ENABLE_PAESG            LICENSE_ENABLE_DIAGNOSTICS_BIT
#define LICENSE_ENABLE_PAESP            LICENSE_ENABLE_PEDAL_BAND_BIT
#define LICENSE_ENABLE_PAESR            LICENSE_ENABLE_RPM_BAND_BIT
#define LICENSE_ENABLE_PAEST            LICENSE_ENABLE_TRIGGER_BIT
#define LICENSE_ENABLE_PAESV            LICENSE_ENABLE_VEHICLE_BIT

//
// NOTE : Bits 0 to 7 are customer driven customisation
//
#define LICENSE_CUSTOMER_MASK           (255u)
#define LICENSE_CUSTOMER_TRIMBLE        (0u)
#define LICENSE_CUSTOMER_DHL            (1u)
#define LICENSE_CUSTOMER_PINPOINTERS    (2u)

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

void LICENSE_SetOptions(int32_t i32LicenseKey_);

int1_t LICENSE_IsOptionEnabled(uint32_t u32Option_);

uint8_t LICENSE_GetCustomisation(void);

void LICENSE_EnableCusomisation(int1_t bEnable_);

#endif // LICENSE_H

/*****************************************************************************
**                            End Of File: license.h
******************************************************************************/
