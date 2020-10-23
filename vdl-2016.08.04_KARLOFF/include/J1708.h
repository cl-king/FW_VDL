/********************************************************************
* File:     $Id: J1708.h,v 1.5 2009/07/22 09:13:00 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.5 $
* Date:     $Date: 2009/07/22 09:13:00 $
* Author:   $Author: richard $
*
********************************************************************
*
* Description:
* ============
*/
/*! @defgroup j1708_module J1708
 *	Provides the raw message handling for the J1708 interface
 *  implemented on the ATMEL microprocessor.
*/
/*! @{ */
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2008 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: J1708.h,v $
*   Revision 1.5  2009/07/22 09:13:00  richard
*   *** empty log message ***
*
*   Revision 1.4  2008/10/27 09:17:41  accutest\colin
*   Updated header to reflect new J1708 gateway structure implemented in the ATMEL
*
*   Revision 1.3  2008/08/19 10:27:28  accutest\colin
*   Updated to cater for new J1708 and J1587 gateway code for the atmel
*
*   Revision 1.2  2008/08/06 13:16:48  accutest\colin
*   Removed RTOS aspect of module
*
*   Revision 1.1  2008/08/01 07:54:36  accutest\colin
*   First version of the J1708 Gateway driver
*
*
*********************************************************************
*/

#ifndef _J1708_MODULE_H_
#define _J1708_MODULE_H_

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Required modules

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define J1708_MAX_MESSAGE_LENGTH          (21u)

// J1708 message priorities, lowest number is highest priority
#define J1708_PRIORITY_1                  (1)
#define J1708_PRIORITY_2                  (2)
#define J1708_PRIORITY_3                  (3)
#define J1708_PRIORITY_4                  (4)
#define J1708_PRIORITY_5                  (5)
#define J1708_PRIORITY_6                  (6)
#define J1708_PRIORITY_7                  (7)
#define J1708_PRIORITY_8                  (8)

#define J1708_PRODUCT_CODE                (0x04u)
#define J1708_SPI_DELAY                   (50u) /* us delay */

/* SPI commands to the ATMEL J1708 interface */
#define CMD_GET_VERSION                   (0x05)

#define CMD_FLUSH                         (0x20)
#define CMD_SET_J1708_STATE               (0x21)
#define CMD_SEND_J1708_MSG                (0x22)
#define CMD_GET_J1708_MSG                 (0x23)
#define CMD_GET_J1708_MSG_AND_TIME        (0x24)
#define CMD_GET_TEMPERATURE_ADC           (0x30)

/* States for ATMEL J1708 interface */
#define J1708_STATE_DISABLED              (0x00)
#define J1708_STATE_READ_ONLY             (0x01)
#define J1708_STATE_ENABLED               (0x02)
#define J1708_STATE_RESET                 (0x03)

/* This may be configured else where */
#ifndef J1708_HARDWARE_RX_BUFFER_SIZE
#define J1708_HARDWARE_RX_BUFFER_SIZE     (16u)
#endif

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*! @brief Initialise the module and check the hardware is
 *   configured correctly
 *  @return The error code for the function
 */
uint8_t J1708_InitModule(void);

/*! @brief Terminate the J1708 module */
void J1708_TerminateModule(void);

/*! @brief Start monitoring messages on the bus */
void J1708_StartMonitoringBus(void);

/*! @brief Start monitoring and allow writing to bus */
void J1708_StartFullAccessToBus(void);

/*! @brief Stop monitoring messages on the bus */
void J1708_StopMonitoringBus(void);

/*! @breif Empty the receive buffer in the J1708 interface */
void J1708_ResetInterface(void);

/*! @brief Tests that the ATMEL chip is still responding to the ARM
 *  @return The failure state of the connectivity (true = failure detected)
 */
int1_t J1708_TestConnectivity(void);

/*! @brief Attempts to regain connectivity to the ATMEL chip but flushing
 *   erroneous data from the SPI interface
 *  @return The failure state of the connectivity (true = failure detected)
 */
int1_t J1708_EstablishConnectivity(void);

/*! @brief Get the number of messages waiting for processing
 *  @return The number of messages in the receive buffer
 */
uint32_t J1708_MessagesWaiting(void);

/*! @brief Get a raw message from the J1708 bus
 *  @param pLength Pointer for the length of the data
 *  @param pData Pointer for the data
 *  @param pTimeStamp The Timestamp at the start of the message (1 ms)
 */
void J1708_GetTimeStampedMessage(uint8_t *pLength_,
                                 uint8_t *pData_,
                                 uint32_t *pTimeStamp_);

/*! @brief Send a raw message on the J1708 bus
 *  @param u8Priority The priority of the message
 *  @param u8Length The length of the data
 *  @param pData Pointer for the data
 */
void J1708_SendMessage(uint8_t u8Priority_,
                       uint8_t u8Length_,
                       uint8_t *pData_);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif /* _J1708_MODULE_H_ */

/*! @{ */
