/********************************************************************
* File:     $Id: version.h,v 1.99 2010/05/05 16:02:22 Amiao Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.99 $
* Date:     $Date: 2010/05/05 16:02:22 $
* Author:   $Author: Amiao $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	This file contains firmware version information.
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
*   $Log: version.h,v $
*   Revision 1.99  2010/05/05 16:02:22  Amiao
*   latest version 1.4.0.5
*
*   Revision 1.98  2010/05/04 11:50:49  Amiao
*   Latest version
*
*
*********************************************************************
*/

#ifndef  _VERSION_H_
#define  _VERSION_H_

/*------------------------------------------------------------------*/
/*                                                                  */
/* NOTE : This file is used by both C and Assembler source files    */
/*        and as such CAN NOT contain ANY C specific definitions !! */
/*                                                                  */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#if defined(__INCLUDE_GEOMANAGER_MODULE) || defined(__INCLUDE_GEOMANAGER_RELTEST)
// Note that GeoManager project follows Trimble versioning system

// firmware version format = <PLATFORM>.<FEATURE>.<SERVICE>.<MODEM = 3>.<BUILD> (3 = GSM)
#ifdef __TARGET_AVG660
#define VERSION_VERSION         1         // Platform 1 = TVG660
#define VERSION_REVISION        7 //5        // incremented for new features
#define VERSION_PATCH           0         // incremented for bug fixes
#define VERSION_BUILD           0 //39       // Incremented for internal releases
#endif
#ifdef __TARGET_TM3000
#define VERSION_VERSION         8         // Platform 8 = TM3000
#define VERSION_REVISION        1         // incremented for new features
#define VERSION_PATCH           0         // incremented for bug fixes
#define VERSION_BUILD           1         // Incremented for internal releases
#endif

#define VERSION_PLATFORM        VERSION_VERSION
#define VERSION_FEATURE         VERSION_REVISION
#define VERSION_SERVICE         VERSION_PATCH
#define VERSION_MODEM_GSM       3
#define VERSION_MODEM_CDMA      6
#define VERSION_MODEM           VERSION_MODEM_GSM		// Needs changing to run time

#endif

//Version for BLU application
#if defined(__INCLUDE_BOOTLOADER_UPGRADE)
#define VERSION_VERSION         1
#define VERSION_REVISION        0
#define VERSION_PATCH           0
#define VERSION_BUILD           2
#endif

/*
// firmware version format = <VERSION>.<REVISION>.<PATCH>.<BUILD>

#define VERSION_VERSION         2
#define VERSION_REVISION        8
#define VERSION_PATCH           0
#define VERSION_BUILD           7
#endif
*/

#ifdef BUILD_TSCAN

#define VERSION_VERSION         2
#define VERSION_REVISION        9  //8
#define VERSION_PATCH           0
#define VERSION_BUILD           27  //26//7

#endif

#ifdef __TARGET_AVG600

#define VERSION_VERSION         1
#define VERSION_REVISION        0  
#define VERSION_PATCH           0
#define VERSION_BUILD           0  

#endif



/*------------------------------------------------------------------*/
/*                                                                  */
/* FIRMWARE ID's                                                    */
/*                                                                  */
/* NOTE:  Used in AVG Build Configurations.                         */
/*                                                                  */
/* USAGE: In the build configuration pre-processor                  */
/*        definition, place the following macro:                    */
/*        __FIRMWARE_ID=xx                                          */
/*                                                                  */
/*------------------------------------------------------------------*/

////////////////////////////////////////////
// CUSTOMER SPECIFIC:
//
// ARM Trimble                  1
// ARM CMS J1587                2
// ARM CMS J1939                3
// ARM CMS J1979                4
// ARM LVDS OBDII               5
// ARM Modec                    6
// ARM Matrix J1979             7
// ARM Microlise FORD           8
// ARM PinPointers J1939        9
// ARM Telematics               10
// ARM WebTech J1587            11
// ARM WebTech J1939            12
// ARM WebTech J1979            13
// ARM PinPointers J1979        14
// ARM PinPointers J1939/J1587  15
// ARM PinPointers J1587        16
//
////////////////////////////////////////////
// T-SCAN:
//
// ARM T-SCAN                   20
// ARM AVG550 T-SCAN            21
//
////////////////////////////////////////////
// LCD:
//
// ARM LCD J1939                30
// ARM LCD J1979                31
//
////////////////////////////////////////////
// Enfora (AVG540 and AVG550):
//
// ARM Enfora J1979             40
// ARM Enfora J1587             41
// ARM Enfora J1939             42
// ARM Enfora J1939 RS232PT     43
//
////////////////////////////////////////////
// AVG540:
//
// ARM AVG540                   60
// ARM AVG540 J1979             61
// ARM AVG540 RDVS              62
//
////////////////////////////////////////////
// AVG550:
//
// ARM AVG550                   80
// ARM AVG550 J1587             81
// ARM AVG550 J1708 Test        82
// ARM AVG550 TrafficMaster     83
// ARM AVG550 Trimble           84
//
////////////////////////////////////////////
// AVG650:
//
// ARM AVG650                   100
// ARM AVG650 J1979             101
// ARM AVG650 J1939             102
// ARM AVG650 Ignition          103
// ARM AVG650 J1939 RS232PT     104
// ARM AVG650 J1979 iButton     105
// ARM AVG650 J1939 iButton     106
// ARM AVG650 Trimble           107
// ARM AVG650 Pinpointers J1979 108
// ARM AVG650 Pinpointers J1939 109
// ARM AVG650- NMEA J1939       110
// ARM AVG550L- NMEA J1939      112
//
////////////////////////////////////////////
// AVG660:
//
// GeoManager J1939             110
// GeomanagerNMEA               111
//
////////////////////////////////////////////
// TM3000:
//
// GeoManager                   150
//
////////////////////////////////////////////
// PRODUCTION TEST:
//
// (ALL PRODUCTS)               255
//
////////////////////////////////////////////

/*------------------------------------------------------------------*/

#endif // _VERSION_H_

/**** End of file ****/
