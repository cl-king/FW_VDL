/********************************************************************
* File:     $Id: Gendefs.h,v 1.18 2009/03/18 11:28:15 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.18 $
* Date:     $Date: 2009/03/18 11:28:15 $
* Author:   $Author: richard $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides general definitions for the AVG 500 project
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2006-2007 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: Gendefs.h,v $
*   Revision 1.18  2009/03/18 11:28:15  richard
*   Changed a sleep to delay in the REBOOT macro so it will work out of RTOS
*
*   Revision 1.17  2009/03/04 12:28:06  simon
*   Added ASCII_ESC definition
*
*   Revision 1.16  2009/01/23 13:21:57  simon
*   Removed ENTER_BOOTLOADER macro
*
*   Revision 1.15  2008/11/03 09:38:47  simon
*   Moved standard definitions (ie. TRUE, FALSE,etc) to types.
*
*   Revision 1.14  2008/07/02 16:31:05  ACCUTEST\simon
*   Progressed AT Command set and renamed AVG500M to AVG600
*
*   Revision 1.13  2008/06/30 13:34:48  ACCUTEST\simon
*   Version 2.3.3.6, Added firmware name to build configuration, progressed AT Command
*    parser.
*
*   Revision 1.12  2008/06/06 09:29:28  ACCUTEST\richard
*   Added REBOOT debug message to LCD display.
*
*   Revision 1.11  2008/05/12 10:14:38  ACCUTEST\simon
*   CMS J1979 V2.3.3.0, plus various bug fixes and fuel rate calculation tweeks.
*
*   Revision 1.10  2008/05/08 09:43:19  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*   Revision 1.9  2008/03/17 13:19:30  ACCUTEST\simon
*   Added ASCII_SPACE
*
*   Revision 1.8  2008/01/21 12:25:08  ACCUTEST\simon
*   Intermediate dev build
*
*   Revision 1.7  2007/11/29 17:36:27  ACCUTEST\simon
*   Added modular trace macro
*
*   Revision 1.6  2007/11/01 16:21:50  ACCUTEST\peterp
*   Added initialisation support for CAN, USB/UART0, UART1/LIN/K-LINE, UART2/RS232, UART3/RS232/RS485.
*
*   Revision 1.5  2007/10/24 13:06:58  ACCUTEST\peterp
*   More LPC2468 configuration.
*
*   Revision 1.4  2007/10/22 16:15:42  ACCUTEST\peterp
*   Added some definitions.
*
*   Revision 1.3  2007/10/22 11:40:22  ACCUTEST\peterp
*   Added LCD_TRACE facility for AVG600 build.
*
*   Revision 1.2  2007/10/18 11:33:05  ACCUTEST\peterp
*   LPC2468 port from LPC2129 modifications.
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   2007/09/28 08:16:21  ACCUTEST\simon
*   Various fixes and enhancements
*
*   2007/07/13 10:49:50  ACCUTEST\simon
*   Added External UART and MODEC STP modules.
*
*   2007/05/29 08:53:24  ACCUTEST\simon
*   Fixed various issues with all protocols and added multi-message support.
*
*   2007/05/16 10:59:43  ACCUTEST\simon
*   Initial J1979 working code.
*
*   2007/04/20 14:14:27  ACCUTEST\simon
*   J1979 in progress
*
*   2006/12/01 13:44:21  ACCUTEST\paull
*   general updates
*
*   2006/11/27 15:51:56  ACCUTEST\paull
*   Initial checkin of the ARM_AVG module.
*
*********************************************************************
*/

#ifndef HDR_GENDEFS
#define HDR_GENDEFS

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define ASCII_NULL      (0x00)          // NULL char
#define ASCII_ETX       (0x03)          // ETX char
#define ASCII_LF        (0x0A)          // LF char
#define ASCII_CR        (0x0D)          // CR char
#define ASCII_DLE       (0x10)          // DLE char
#define ASCII_ESC       (0x1B)          // ESC char
#define ASCII_SPACE     (0x20)          // SPACE char

#ifndef KARLOFF
#ifdef DEBUG
#define TRACE(...)  debug_printf(__VA_ARGS__)
#else
#define TRACE(...) 
#endif
#endif

#ifndef KARLOFF
#ifdef DEBUG
#define MODULE_TRACE(x, ...)  /*debug_printf(x); debug_printf(": ");*/ debug_printf(__VA_ARGS__)
#else
#define MODULE_TRACE(x, ...) 
#endif
#else
#define MODULE_TRACE(x, ...) debug_trace(x, __VA_ARGS__)
#endif

#ifndef KARLOFF
#ifdef DEBUG
#ifdef __AVG600_DEV_BOARD
#define LCD_SPIN_DISP_POSX       (0)
#define LCD_TEXT_DISP_POSX      (10)
#define LCD_TRACE(x, y, str)                    \
{                                               \
    lcd_putString(x, y, (unsigned char *)str);  \
}
#else
#define LCD_TRACE(x, y, str)
#endif  // __AVG600_DEV_BOARD
#else
#define LCD_TRACE(x, y, str)
#endif  // DEBUG
#endif

#define MS_TO_TICKS(x)  ((x) / portTICK_RATE_MS)
#define TICKS_TO_MS(x)  ((x) * portTICK_RATE_MS)

#ifndef KARLOFF
// reboot using watchdog
#define REBOOT                          \
{                                       \
    CRITICAL_TRACE("REBOOTING...\n");   \
    LCD_CLEAR();                        \
    LCD_TRACE0("Rebooting...   ");      \
    Delay_MS(1);                        \
    Hardware_Reboot();                  \
}
#endif

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

// bit field definitions
typedef struct
{
	unsigned int _0 :1;		// Bit 0
	unsigned int _1 :1;		// Bit 1
	unsigned int _2 :1;		// Bit 2
	unsigned int _3 :1;		// Bit 3
	unsigned int _4 :1;		// Bit 4
	unsigned int _5 :1;		// Bit 5
	unsigned int _6 :1;		// Bit 6
	unsigned int _7 :1;		// Bit 7
	unsigned int _8 :1;		// Bit 8
	unsigned int _9 :1;		// Bit 9
	unsigned int _10 :1;		// Bit 10
	unsigned int _11 :1;		// Bit 11
	unsigned int _12 :1;		// Bit 12
	unsigned int _13 :1;		// Bit 13
	unsigned int _14 :1;		// Bit 14
	unsigned int _15 :1;		// Bit 15
} bit_def;

/* Unsigned long, double word, quad char definitions */

typedef struct
{
	volatile unsigned char	lbyte_lword;
	volatile unsigned char	hbyte_lword;
	volatile unsigned char	lbyte_hword;
	volatile unsigned char	hbyte_hword;

} quad_byte;

typedef struct
{
	volatile unsigned int	lword;
	volatile unsigned int	hword;

} double_word;

typedef union
{
	volatile unsigned long	ulong;
	double_word		dword;
	quad_byte		qbyte;

} long_word_byte;

typedef struct
{
	volatile unsigned char	low;
	volatile unsigned char	high;

} double_byte;

typedef union
{
	double_byte		dbyte;
	volatile unsigned int	uint;

} word_dbyte;

typedef union
{
	bit_def bits;			// address individual bits
	double_byte bytes;		// address individual bytes
	volatile unsigned int words;	// access whole word

} bits_bytes_word;	

#endif /* HDR_GENDEFS */



