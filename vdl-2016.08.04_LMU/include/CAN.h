/********************************************************************
* File:     $Id: CAN.h,v 1.6 2009/01/14 10:30:13 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.6 $
* Date:     $Date: 2009/01/14 10:30:13 $
* Author:   $Author: richard $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Defines a CAN message structure
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
*   $Log: CAN.h,v $
*   Revision 1.6  2009/01/14 10:30:13  richard
*   Removed timestamp fields when not needed - saves a bit of space
*
*   Revision 1.5  2008/02/14 15:48:18  ACCUTEST\simon
*   Added u16 to message data unions
*
*   Revision 1.4  2007/05/16 11:00:02  ACCUTEST\simon
*   Initial J1979 working code.
*
*   Revision 1.3  2007/04/20 14:14:41  ACCUTEST\simon
*   J1979 in progress
*
*   Revision 1.2  2006/12/15 13:47:59  ACCUTEST\paull
*   Added STP CAN transmit functionality.
*
*   Revision 1.1  2006/11/27 15:51:56  ACCUTEST\paull
*   Initial checkin of the ARM_AVG module.
*
*
*********************************************************************
*/

#ifndef CAN_H
#define CAN_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

#include "types.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*!\brief CAN Message Definition */
/*! Describes a CAN message structure */
typedef struct {
    uint32_t  mId;						/*!< Message identifier */
    uint32_t  mTimeStamp;				/*!< Message Timestamp */
    union {
        uint32_t u32[2];
        uint16_t u16[4];
        uint8_t  u8[8];                /*!< Message Data bytes */
    } mData;
    uint8_t   mPort;					/*!< Message channel */
    uint8_t   mType;					/*!< Message type (XTD / STD) */
    uint8_t   mDlc;						/*!< Message data length code */
} tsCanMsg;

/*!\brief CAN Message Definition */
/*! Describes a CAN message structure */
typedef struct {
    uint32_t  mId;						/*!< Message identifier */
	uint32_t  mTimeStamp;				/*!< Message Timestamp */
	union {
        uint32_t u32[2];
        uint16_t u16[4];
        uint8_t  u8[8];                /*!< Message Data bytes */
    } mData;
    uint8_t   mPort;					/*!< Message channel */
    uint8_t   mType;					/*!< Message type (XTD / STD) */
    uint8_t   mDlc;						/*!< Message data length code */
    uint8_t   mTxRetryCount;			/*!< TX Retry count */
} tsCanMsgV2;

/*!\brief CAN Message Definition */
/*! Describes a CAN message structure */
typedef struct {
    uint32_t  mId;						/*!< Message identifier & bit 31 = message type */
    union {
        uint32_t u32[2];
        uint16_t u16[4];
        uint8_t  u8[8];                 /*!< Message Data bytes */
    } mData;
    uint8_t   mPort;					/*!< Message channel */    
	uint8_t	  mDlc;						/*!< Message data length code */
    uint8_t	  Align1;					/*!< Future expansion */
    uint8_t	  Align2;					/*!< Future expansion*/
} tsStpCanMsg;

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

/*! \brief CAN controller status change types */
typedef enum {
      CAN_ERR_EWARN,
      CAN_ERR_BUSOFF,
      CAN_STAT_BUSON
} teCANStatIds;

/*! \brief CAN data channel error message types */
// These are reported in a tsStpCanMsg, where:
//   mId = 0, 
//   mDlc = 0,
//   and the error message is contained in mData[0].
//   optional data related to the error may appear in mData[1].
typedef enum {
      CAN_OK,                   // No error
      CAN_ERR_PACKET_SIZE,      // STP packet size is incorrect
      CAN_ERR_TX_QUEUE_FULL,    // the transmit buffer is full
      CAN_ERR_NO_HARDWARE       // requested CAN Port is available
} teCANErrors;

#endif /* CAN_H */




