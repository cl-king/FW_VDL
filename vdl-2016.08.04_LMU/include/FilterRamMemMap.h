/********************************************************************
* File:     $Id: FilterRamMemMap.h,v 1.2 2009/01/21 12:15:49 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.2 $
* Date:     $Date: 2009/01/21 12:15:49 $
* Author:   $Author: richard $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Allocates large arrays in CAN Filter RAM
*   Note all access must be on 32 bit boundry, BYTE / WORD access
*   will fail
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2006-2009 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: FilterRamMemMap.h,v $
*   Revision 1.2  2009/01/21 12:15:49  richard
*   *** empty log message ***
*
*   Revision 1.1  2009/01/15 16:40:20  richard
*   *** empty log message ***
*
*
*/
#ifndef __FILTERMEMMAP_H__
#define __FILTERMEMMAP_H__

#if KARLOFF
#define ACCEPTANCE_FILTER_SIZE		(0x00000800)
#define AFR_CORE_PARAMS_ADDR		(ACCEPTANCE_FILTER_RAM_ADDR)
#define AFR_VEHICLE_DATA_ADDR		(AFR_CORE_PARAMS_ADDR + 256)
#define AFR_FUEL_DATA_ADDR		    (AFR_VEHICLE_DATA_ADDR + 256)
#define ACCEPTANCE_FILTER_RAM_ADDR	RAM_DATA
#define RAM_DATA_SIZE (ACCEPTANCE_FILTER_SIZE + 512)
#else
#define ACCEPTANCE_FILTER_RAM_ADDR	(0xE0038000)
#define ACCEPTANCE_FILTER_SIZE		(0x00000800)
#define AFR_CORE_PARAMS_ADDR		(ACCEPTANCE_FILTER_RAM_ADDR)
#define AFR_VEHICLE_DATA_ADDR		(AFR_CORE_PARAMS_ADDR + 256)
#define AFR_FUEL_DATA_ADDR		    (AFR_VEHICLE_DATA_ADDR + 256)
#endif

#endif
