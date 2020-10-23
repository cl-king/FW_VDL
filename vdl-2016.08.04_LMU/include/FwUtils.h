/********************************************************************
* File:     $Id: FwUtils.h,v 1.7 2010/03/23 14:50:44 Mswain Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.7 $
* Date:     $Date: 2010/03/23 14:50:44 $
* Author:   $Author: Mswain $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	This file contains utility functions header for the
*	Firmware Upgrade facility.
*
*/
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2007 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: FwUtils.h,v $
*   Revision 1.7  2010/03/23 14:50:44  Mswain
*   Updated #defines for GeomanagerInterface.
*
*   Revision 1.6  2009/11/30 16:57:19  richard
*   Combined all vehicle protocols.
*   Added FIFO test
*
*   Revision 1.5  2008/07/02 16:31:05  ACCUTEST\simon
*   Progressed AT Command set and renamed AVG500M to AVG600
*
*   Revision 1.4  2008/06/25 12:05:52  ACCUTEST\simon
*   Changed function prototype of Create_Task
*
*   Revision 1.3  2008/01/03 17:31:25  ACCUTEST\peterp
*   *** empty log message ***
*
*   Revision 1.2  2007/10/22 08:46:15  ACCUTEST\peterp
*   AVG500L (NXP LPC2129) and AVG600 (NXP LPC2468) port.
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   2007/09/28 08:20:49  ACCUTEST\simon
*   Various fixes and enhancements
*
*   2007/08/30 15:03:22  ACCUTEST\peterp
*   FW Utils reorganised.
*
*   2007/08/22 11:32:29  ACCUTEST\peterp
*   Added FwUtils modules.
*
*********************************************************************
*/
#ifndef  _FW_UTILS_H_
#define  _FW_UTILS_H_

// AVG specific definitions
#include "AvgDefines.h"

//#define IRQ_RAM_ADDR        0x40000018
//#define FIQ_RAM_ADDR        0x4000001C
//#define IRQ_RAM_FUNC_ADDR   0x40000038
//#define FIQ_RAM_FUNC_ADDR   0x4000003C

#ifdef __TARGET_PROCESSOR_LPC2129
#undef MAX_TASKS
#define MAX_TASKS           (15)
#endif

#ifdef __TARGET_PROCESSOR_LPC2468
#undef MAX_TASKS
#define MAX_TASKS           (20)
#endif

#if defined(__INCLUDE_GEOMANAGER_MODULE) || defined(__INCLUDE_GMI)
#define Create_Task(a,b,c,d,e,f)	xTaskCreate(a,(const signed portCHAR * const)b,c,d,e,f)		// Allow it to build without fwutils.c
#else

typedef struct _SECTORGEOMETRY
{
    int32_t size;
    int32_t qty;
} SECTORGEOMETRY;


void *  FW_memset(void * dst,  int32_t ch, int32_t length);
void *  FW_memcpy(void * s1, const void *s2, int32_t n);
int32_t FW_get_sector_number(uint32_t in_addr);
uint8_t FW_CalcCheckSum(uint8_t *pu8CheckSumData, uint16_t u16NumOfBytes);
uint8_t FW_InitTaskList(void);
void    FW_FreeTaskResources(void);

#ifdef __TARGET_RTOS
signed portBASE_TYPE Create_Task (pdTASK_CODE pvTaskCode,
                                  const char* lpszName,
                                  unsigned portSHORT usStackDepth,
                                  void *pvParameters,
                                  unsigned portBASE_TYPE uxPriority,
                                  xTaskHandle *pxCreatedTask);

void Delete_Task (xTaskHandle pxTaskToDelete);
#endif // __TARGET_RTOS
#endif // __INCLUDE_GEOMANAGER_MODULE
#endif // _FW_UTILS_H_

/**** End of file ****/
