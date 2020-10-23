/********************************************************************
* File:     $Id: types.h,v 1.6 2010/03/23 16:35:00 Cbarret Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.6 $
* Date:     $Date: 2010/03/23 16:35:00 $
* Author:   $Author: Cbarret $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <Main.c>	
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
*   $Log: types.h,v $
*   Revision 1.6  2010/03/23 16:35:00  Cbarret
*   Proteus Kernel Light added to GeoManager (First Version)
*
*   Revision 1.5  2009/01/15 16:34:10  simon
*   Added VARIANT for doing byte access of other types
*
*   Revision 1.4  2008/11/03 09:38:49  simon
*   Moved standard definitions (ie. TRUE, FALSE,etc) to types.
*
*   Revision 1.3  2008/10/03 09:00:05  simon
*   Added _MAX and _MIN values for types.
*
*   Revision 1.2  2007/12/04 11:34:16  ACCUTEST\simon
*   Added unions for accessing portions of large data types
*
*   Revision 1.1  2006/11/27 15:51:56  ACCUTEST\paull
*   Initial checkin of the ARM_AVG module.
*
*
*********************************************************************
*/

#ifndef TYPES_H
#define TYPES_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/
#include <stdint.h>

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

typedef _Bool				int1_t;		/*!< 1 bit quantity */
//typedef signed char			int8_t;		/*!< Signed 8 bit quantity */
//typedef unsigned char	    uint8_t;	/*!< Unsigned 8 bit quantity */
//typedef short				int16_t;	/*!< Signed 16 bit quantity */
//typedef unsigned short	    uint16_t;	/*!< Unsigned 16 bit quantity */
//typedef signed int			int32_t;	/*!< Signed 32 bit quantity */
//typedef unsigned int	    uint32_t;	/*!< Unsigned 32 bit quantity */
//typedef long long			int64_t;	/*!< Signed 64 bit quantity */
//typedef unsigned long long  uint64_t;	/*!< Unsigned 64 bit quantity */

// byte and word accessors for larger data types
typedef union  {
    uint16_t u16;
    uint8_t u8[2];
} WORD;

typedef union  {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
} DWORD;

typedef union {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
} QWORD;

// this can be used for memory operations (i.e. storing doubles in SPI flash, etc.)
// NOTE : It is not to be used for data conversion !!!!
typedef union  {
    double d;
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
} VARIANT;

#pragma pack(1)
struct _cPKL_CANMESSAGEINFO
{
    uint8_t u8Channel;
    uint8_t u8DLC;
    uint8_t u8Unused;
    uint8_t u8Error;
};
#pragma pack()
typedef struct _cPKL_CANMESSAGEINFO     cPKL_CANMESSAGEINFO;

union _cPKL_CANDATA
{
    uint8_t u8Byte[8];
    uint16_t u16Short[4];
    uint32_t u32Word[2];
};
typedef union _cPKL_CANDATA             cPKL_CANDATA;

struct _cPKL_CANMESSAGE
{
    uint32_t u32ID;
    cPKL_CANMESSAGEINFO sInfo;
    cPKL_CANDATA uData;
};
typedef struct _cPKL_CANMESSAGE         cPKL_CANMESSAGE;

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define INT1_MIN        (0)
#define INT1_MAX        (1)
#define UINT8_MIN       (0)
//#define UINT8_MAX       (255)
#define UINT16_MIN      (0)
//#define UINT16_MAX      (65535)

#define	STOP            (1)
#define	GO              (0)

#define	ON              (1)
#define	OFF             (0)


#define	TRUE            (int1_t)(1)
#define	FALSE           (int1_t)(0)

#ifdef KARLOFF
#include <stdbool.h>
#else
#define	true            (int1_t)(1)	 
#define	false           (int1_t)(0)
#endif

#ifndef NULL
#define NULL            ((void*)0)
#endif

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif
