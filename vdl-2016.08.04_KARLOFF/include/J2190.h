/********************************************************************
* File:     $Id: J2190.h $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision:$
* Date:     $Date:$
* Author:   $Author:$
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for J2190
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2012 Trimble Navigation Ltd. All rights reserved.
*********************************************************************
*/

#ifndef J2190_H
#define J2190_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

// J2190 Standard Diagnostic Test Modes
#define J2190_MODE_21_REQ                       (0x21)  // Request by offset
#define J2190_MODE_21_RESP                      (0x61)
#define J2190_MODE_22_REQ                       (0x22)  // Request by 2-byte PID
#define J2190_MODE_22_RESP                      (0x62)
#define J2190_MODE_23_REQ                       (0x23)  // Request by address 3-byte
#define J2190_MODE_23_RESP                      (0x63)
#define J2190_MODE_2A_REQ                       (0x2A)  // Request diagnostic data packet
#define J2190_MODE_2A_RESP                      (0x6A)
#define J2190_MODE_2C_REQ                       (0x2C)  // Dynamically define diagnostic data packet
#define J2190_MODE_2C_RESP                      (0x6C)

#define J2190_MODE_22_DLC                       3

#endif // J2190_H







