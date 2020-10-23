/* ----------------------- Proprietary to Trimble, Inc. --------------------- *
 *
 *         File name: ModuleInfo.c
 *   Initial Project: Karloff
 *            Author: ddye
 *        Created on: Aug 15, 2011 - 10:03:25 AM
 *       Description: 
 *
 * ----------------------- Proprietary to Trimble, Inc. --------------------- *
 * Trimble Mobile Resource Management
 * 47071 Bayside Parkway
 * Fremont, CA 94538
 * Tel: 1-877-7AtRoad
 * www.road.com

 * ----------------------- Proprietary to Trimble, Inc. --------------------- *
 * Copyright (c) 2009, At Road a Trimble Company - All Rights Reserved.
 * No part of this file may be reproduced or transmitted in any form
 * by any means electronically, mechanically, by  photocopying, via recording
 * or otherwise outside of Trimble Company without the prior consent of
 * Trimble, Inc.

 * The information in this file constitutes confidential and proprietary
 * information of Trimble, Inc. This file is intended for the use of Trimble
 * employees only.  The disclosure of all or any part of this document to or the
 * use of all or any part of this file by any other party is strictly prohibited
 * without the prior written consent of Trimble, Inc.

 * Trimble Mobile Resource Management solutions, including without limitation its
 * products, software and services, are protected under one or more patents or
 * patents pending in jurisdictions around the world.

 * Trimble patents include without limitation the following:
 * U.S. 5,477,228; 5,694,594; 5,959,577; 5,990,827; 6,459,988; 6,529,159;
 * 6,552,682; 6,594,576; 6,664,922; 6,578,005; 5,963,911; 6,862,524; 6,795,017; 6,882,313;
 * 6,867,733; 6,832,140; 6,922,566; 6,965,665; 6,980,131; 6,980,812; 7,006,820; 7,035,620,
 * 7,043,255 and 7,082,605;
 * Australia patents 682,585 and 722,806;
 * Canada patent 2,183,586;
 * China patents 95,192,287.4 and 97,180,004.9;
 * France, Ireland, Italy, Netherlands, Spain and United Kingdom
 * European Patent No. EP0938714;
 * European Patent No. EP0752136;
 * European Patent No. EP1168863;
 * Germany patents 69,411,744.7; 60,105,094.008; 69,512,040 and 69,703,938;
 * India patent 19,044;
 * United Kingdom patents 705,442 and 2,373,655B.

 * Further information relating to Trimble copyrights, trademarks, patents and patents
 * pending may be found at the Trimble Mobile Resource Management Web site, www.trimble.com
 * and www.road.com.

 * ----------------------- Proprietary to Trimble, Inc. --------------------- *
 */

#ifndef __MODULE_INFO_H
#define __MODULE_INFO_H

#ifdef __INCLUDE_VD_MODULE_INFO

typedef enum
{
	MI_ComponentId,						// J1587/J1939 Component ID strings
	MI_SoftwareId						// J1587/J1939 Software ID strings
}MI_StringType;

extern int ModuleInfo_Init(void);
extern uint32_t ModuleInfo_GetCount(MI_StringType type);
extern int1_t ModuleInfo_Update(MI_StringType strType, uint8_t u8BusType, uint32_t u32Ecu, uint16_t u8Length, uint8_t *u8Data);
extern int1_t ModuleInfo_GetString(MI_StringType type, int idx, uint32_t *u32Ecu, uint8_t *u8BusType, int *numFields, char *buf);
extern uint32_t ModuleInfo_TargetedIDsNeedUpdate(uint8_t busType, uint16_t *RequestId, uint8_t *Ecu);

#endif

#endif
