/********************************************************************
* File:     $Id: ConversionFactors.h,v 1.1 2008/10/23 11:40:13 simon Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.1 $
* Date:     $Date: 2008/10/23 11:40:13 $
* Author:   $Author: simon $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides macros for standard conversion factors
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
*   $Log: ConversionFactors.h,v $
*   Revision 1.1  2008/10/23 11:40:13  simon
*   New file. Added the standard conversion factors that we currently use.
*
*
*
*********************************************************************
*/

#ifndef CONVERSION_FACTORS_H
#define CONVERSION_FACTORS_H

/*------------------------------------------------------------------*/
/*                                                                  */
/* NOTE : Where possible use values to at least                     */
/*        11 or 12 decimal places in order to preserve accuracy !!  */
/*                                                                  */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* DISTANCES                                                        */
/*------------------------------------------------------------------*/

// Statue Miles
#define MILES_TO_KILOMETERS(x)   ((double)(x) * 1.609344)        // -> Kilometers
#define MILES_TO_METERS(x)       ((double)(x) * 1609.344)        // -> Meters

// Kilometers
#define KILOMETERS_TO_MILES(x)  ((double)(x) * 0.62137119224)   // -> Statute Miles
#define METERS_TO_MILES(x)      ((double)(x) * 0.00062137119224)   // -> Statute Miles

/*------------------------------------------------------------------*/
/* VELOCITIES                                                       */
/*------------------------------------------------------------------*/

// Status Miles Per Hour
#define MPH_TO_KPH(x)           ((double)(x) * 1.609344)        // -> Kilometers Per Hour
#define MPH_TO_KNOTS(x)         ((double)(x) * 0.868976242)     // -> Knots
#define MPH_TO_MPS(x)           ((double)(x) * 0.44704)         // -> Metres Per Second
#define MPH_TO_FPS(x)           ((double)(x) * 1.46666666667)   // -> Feet Per Second

// Kilometers Per Hour
#define KPH_TO_MPH(x)           ((double)(x) * 0.62137119224)   // -> Statute Miles Per Hour
#define KPH_TO_KNOTS(x)         ((double)(x) * 0.539956803)     // -> Knots
#define KPH_TO_MPS(x)           ((double)(x) * 0.27777777777)   // -> Metres Per Second
#define KPH_TO_FPS(x)           ((double)(x) * 0.911344415)     // -> Feet Per Second

// Knots
#define KNOTS_TO_KPH(x)         ((double)(x) * 1.852)           // -> Kilometers Per Hour
#define KNOTS_TO_MPH(x)         ((double)(x) * 1.15077945)      // -> Statute Miles Per Hour
#define KNOTS_TO_MPS(x)         ((double)(x) * 0.514444444)     // -> Metres Per Second
#define KNOTS_TO_FPS(x)         ((double)(x) * 1.68780986)      // -> Feet Per Second

// Meters Per Second
#define MPS_TO_KPH(x)           ((double)(x) * 3.6)             // -> Kilometers Per Hour
       
/*------------------------------------------------------------------*/
/* QUANTITIES                                                       */
/*------------------------------------------------------------------*/

// Litres
#define LITRES_TO_IMPGALS(x)    ((double)(x) * 0.219969157)     // -> Imperial Gallons (UK)
#define LITRES_TO_USGALS(x)     ((double)(x) * 0.264172052)     // -> Gallons (US)

// Imperial Gallons (UK)
#define IMPGALS_TO_LITRES(x)    ((double)(x) * 4.54609188)      // -> Litres
#define IMPGALS_TO_USGALS(x)    ((double)(x) * 1.20095042)      // -> Gallons (US)

// Gallons (US)
#define USGALS_TO_LITRES(x)     ((double)(x) * 3.78541178)      // -> Litres
#define USGALS_TO_IMPGALS(x)    ((double)(x) * 0.83267384)      // -> Imperial Gallons (UK)

/*------------------------------------------------------------------*/
/* FUEL                                                             */
/*------------------------------------------------------------------*/

// Kilometers Per Litre
#define KPL_TO_IMPMPG(x)        ((double)(x) * 2.82481053)      // -> Miles Per Imperial Gallons (UK)
#define KPL_TO_USMPG(x)         ((double)(x) * 2.35214583)      // -> Miles Per Gallons (US)

// Milliliters Per Second
#define MLPS_TO_GPH(x)			((double)(x) * 0.95101939)		// -> Gallons Per Hour (US)

/*------------------------------------------------------------------*/
/* WEIGHTS                                                          */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* TEMPERATURE                                                      */
/*------------------------------------------------------------------*/

// Celsius
#define C_TO_F(x)               (((double)(x) * (9.0 / 5.0)) + 32.0)    // -> Fahrenheit       
#define C_TO_K(x)               ((double)(x) + 273.15)                  // -> Kelvin        

// Fahrenheit
#define F_TO_C(x)               (((double)(x) - 32.0) * (5.0 / 9.0))    // -> Celsius       
#define F_TO_K(x)               (F_TO_C(x) + 273.15)                    // -> Kelvin        

// Kelvin
#define K_TO_C(x)               ((double)(x) - 273.15)                  // -> Celsius       
#define K_TO_F(x)               (C_TO_F(K_TO_C(x)))                     // -> Fahrenheit        

#endif // CONVERSION_FACTORS_H
