/********************************************************************
* File:     $Id: J1587.h,v 1.3 2008/12/12 10:57:12 accutest\colin Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.3 $
* Date:     $Date: 2008/12/12 10:57:12 $
* Author:   $Author: accutest\colin $
*
********************************************************************
*
* Description:
* ============
*/
/*! @defgroup j1587_module J1587
 *	Provides the message decoding for the J1587 messages
 *  received on the J1708 interface
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
*   $Log: J1587.h,v $
*   Revision 1.3  2008/12/12 10:57:12  accutest\colin
*   Decreased number of PIDs monitored to save memory
*
*   Revision 1.2  2008/11/13 15:29:10  accutest\colin
*   Updated to include ignition callback and to send raw messages over the J1708 bus
*
*   Revision 1.1  2008/10/27 09:18:44  accutest\colin
*   First version of J1587 module
*
*
*********************************************************************
*/

#ifndef _J1587_MODULE_H_
#define _J1587_MODULE_H_

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Required modules

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define J1587_PID_HEAP_SIZE               (80u)
#define J1587_MAX_STORED_PIDS             (20u)

#define J1587_CONNECTION_TIMEOUT          (2000u)

#define J1587_NULL_PID                    (0xFF)
#define J1587_EXTENDED_PID_FLAG           (0xFF)
#define J1587_EXPANSION_PID_OFFSET        (0x100)

/* Mode for the J1587 interface */
#define J1587_MODE_OFF                    (0x00)
#define J1587_MODE_RAW_VIEW               (0x01)
#define J1587_MODE_DECODE                 (0x02)
#define J1587_MODE_DECODE_WITH_TRANSMIT   (0x03)
#define J1587_MODE_INAVLID                (0x04)

#define J1587_MAX_LENGTH                  (239)
#define J1587_INVALID_BYTE                (0xFF)

#define J1587_MID_START                   (128)       // lowest valid J1587 MID

// J1587 MID assignments
#define J1587_ENGINE_1_MID                (128)
#define J1587_TRANSMISSION_MID            (130)
#define J1587_BRAKES_MID                  (136)
#define J1587_BRAKES_TRAILER_1_MID        (137)
#define J1587_BRAKES_TRAILER_2_MID        (138)
#define J1587_BRAKES_TRAILER_3_MID        (139)
#define J1587_INSTRUMENT_CLUSTER_MID      (140)
#define J1587_VEHICLE_MGMT_SYS_MID        (142)
#define J1587_DIAGNOSTICS_PORT_1          (172)
#define J1587_DIAGNOSTICS_PORT_2          (180)

// MID used by the Trimble device
#define J1587_DIAGNOSTICS_PORT            J1587_DIAGNOSTICS_PORT_1

// J1587 PID definitions
#define CORE_J1587_LAMP_STATUS                  (0x2C)
#define CORE_J1587_ABS_CONTROL_STATUS           (0x31)
#define CORE_J1587_PARKBREAK_STATUS             (0x46)
#define CORE_J1587_PID_ROAD_SPEED_LIMIT         (0x4A)
#define CORE_J1587_PID_ROAD_SPEED               (0x54)
#define CORE_J1587_CRUISE_CONTROL_STATUS        (0x55)
#define CORE_J1587_CRUISE_CONTROL_SET_SPEED     (0x56)
#define CORE_J1587_PID_CRUISESET_SPEED_LIMIT    (0x57)
#define CORE_J1587_PTO_STATUS                   (0x59)
#define CORE_J1587_ACCELERATOR_POSITION         (0x5B)
#define CORE_J1587_PID_ENGINE_LOAD              (0x5C)
#define CORE_J1587_PID_FUEL_PRESSURE            (0x5E)
#define CORE_J1587_PID_FUEL_LEVEL               (0x60)
#define CORE_J1587_PID_OIL_LEVEL                (0x62)
#define CORE_J1587_PID_OIL_PRESSURE             (0x64)
#define CORE_J1587_PID_BOOST_PRESSURE           (0x66)
#define CORE_J1587_PID_AIR_INTAKE_TEMP          (0x69)
#define CORE_J1587_PID_MAP                      (0x6A)        // air inlet pressure
#define CORE_J1587_ENGINE_COOLANT_TEMP          (0x6E)
#define CORE_J1587_PID_COOLANT_LEVEL            (0x6F)
#define CORE_J1587_PID_ENGINE_RETARD_STATUS     (0x79)
#define CORE_J1587_PID_ENGINE_RETARD_PERCENT    (0x7A)
#define CORE_J1587_PID_EXHAUST_PRESSURE         (0x83)
#define CORE_J1587_PID_MAF                      (0x84)
#define CORE_J1587_PID_TRANS_INPUT_SPEED        (0xA1)
#define CORE_J1587_PID_GEAR_SELECTED            (0xA2)
#define CORE_J1587_PID_GEAR_OBTAINED            (0xA3)
#define CORE_J1587_PID_BATTERY_VOLTAGE          (0xA8)
#define CORE_J1587_PID_AIRINLET_TEMP            (0xAC)
#define CORE_J1587_PID_EXHAUST_TEMP             (0xAD)
#define CORE_J1587_PID_FUEL_TEMP                (0xAE)
#define CORE_J1587_PID_OIL_TEMP                 (0xAF)
#define CORE_J1587_PID_TRANS_FLUID_TEMP         (0xB1)
#define CORE_J1587_PID_TRIP_FUEL_USED           (0xB6)
#define CORE_J1587_PID_FUEL_RATE                (0xB7)
#define CORE_J1587_PID_ENGINE_SPEED             (0xBE)
#define CORE_J1587_PID_TRANS_OUTPUT_SPEED       (0xBF)
#define CORE_J1587_DTC                          (0xC2)
#define CORE_J1587_DTC_CLEAR_REQUEST            (0xC3)
#define CORE_J1587_DTC_CLEAR_RESPONSE           (0xC4)
#define CORE_J1587_ABS_CONTROL_STATUS_TRAILER   (0xD1)
#define CORE_J1587_SOFTWARE_ID                  (0xEA)
#define CORE_J1587_TOTAL_IDLE_FUEL              (0xEC)
#define CORE_J1587_VIN                          (0xED)
#define CORE_J1587_COMPONENT_ID                 (0xF3)
#define CORE_J1587_PID_TOTAL_DISTANCE           (0xF5)
#define CORE_J1587_PID_TOTAL_ENGINE_HOUR        (0xF7)
#define CORE_J1587_TOTAL_FUEL                   (0xFA)
#define CORE_J1587_DATALINK_ESCAPE              (0xFE)
#define CORE_J1587_VEHICLE_ACCE                 (0x17F)
#define CORE_J1587_SRS_TRIGGER_STATUS           (0x195)

/*------------------------------------------------------------
 J1587 Engine speed, (PID 190, $BE) bit definitions

 PID Data
 405 a a
 a: Engine speed, 0.25 RPM resolution
*/

// Byte offsets
#define J1587_ENGINE_SPEED_INDEX        (0)

// Engine speed definitions
#define J1587_ENGINE_SPEED_LENGTH       (2)         // Bytes
#define J1587_ENGINE_SPEED_MASK         (0xFFFF)    // Bit mask
#define J1587_ENGINE_SPEED_SHIFT        (0)         // Bit shift
#define J1587_ENGINE_SPEED_RES          (0.25L)     // 1/4 RPM resolution
// Technically the J1587 max value is 16383.5 but this implementation
// uses the J1939 limit to be consistent across bus types
#define J1587_ENGINE_SPEED_VALID_LIMIT  (8031.875L)

//--- End PID 190

/*------------------------------------------------------------
 J1587 Diagnostic Data/Count Clear Request, (PID 195, $C3) definitions

 PID Data
 195 n a b c 
 n: Byte count of data = 3
 a: MID of device to which request is directed
 b: SID or PID of a standard diagnostic code
 c: Diagnostic code character
     Bits 8-7:
         00 - Request an ASCII descriptive message for the SID/PID
         01 - Request count to be cleared for the given diagnostic code
         10 - Request all counts to be cleared for this device
         11 - Request additional diagnostic information
     Bit 6:
         1 = Standard diagnostic code
         0 = Expansion diagnostic code (PID or SID is from page 2)
     Bit 5:
         1 = Low character is subsystem identifier (SID)
         0 = Low character is parameter identifier (PID)
     Bits 4-1:
         Failure mode identifier
*/

// Message byte index definitions
#define J1587_DIAG_DATA_REQ_LEN_INDEX       (0)
#define J1587_DIAG_DATA_REQ_MID_INDEX       (1)
#define J1587_DIAG_DATA_REQ_PID_INDEX       (2)
#define J1587_DIAG_DATA_REQ_CODE_INDEX      (3)
#define J1587_DIAG_DATA_REQ_PID_LENGTH      (3)

// Diagnostic code character definitions
#define J1587_DIAG_DATA_REQ_FMI_MASK        (0x0F)
#define J1587_DIAG_DATA_REQ_FMI_SHIFT       (0)
#define J1587_DIAG_DATA_REQ_FMI(n, fmi)     ((n) |= ((fmi) & J1587_DIAG_DATA_REQ_FMI_MASK))
#define J1587_DIAG_DATA_REQ_SID_PID_MASK    (0x10)
#define J1587_DIAG_DATA_REQ_SID_PID_SHIFT   (4)
#define J1587_DIAG_DATA_REQ_IS_SID(n)       ((n) |= J1587_DIAG_DATA_REQ_SID_PID_MASK)
#define J1587_DIAG_DATA_REQ_STD_MASK        (0x20)
#define J1587_DIAG_DATA_REQ_STD_SHIFT       (5)
#define J1587_DIAG_DATA_REQ_IS_STD(n)       ((n) |= J1587_DIAG_DATA_REQ_STD_MASK)
#define J1587_DIAG_DATA_REQ_CODE_MASK       (0xC0)
#define J1587_DIAG_DATA_REQ_CODE_SHIFT      (6)

// Diagnostic code character defintions
#define J1587_DIAG_CODE_REQ_DESC            (0)
#define J1587_DIAG_CODE_REQ_CLEAR           (1)
#define J1587_DIAG_CODE_REQ_ALL_CLEAR       (2)
#define J1587_DIAG_CODE_REQ_ADDTNL_INFO     (3)
#define J1587_DIAG_DATA_REQ_CLEAR(n)        ((n) |= (J1587_DIAG_CODE_REQ_CLEAR << J1587_DIAG_DATA_REQ_CODE_SHIFT))
#define J1587_DIAG_DATA_REQ_ALL_CLEAR(n)    ((n) |= (J1587_DIAG_CODE_REQ_ALL_CLEAR << J1587_DIAG_DATA_REQ_CODE_SHIFT))

//--- End PID 195

/*------------------------------------------------------------
 J1587 Diagnostic Data/Count Clear Response, (PID 196, $C4) definitions

 PID Data
 196 n a b c c c c... 
 n: Byte count of data
 a: SID or PID
 b: Diagnostic code character
     Bits 8-7:
         00 - Message is an ASCII descriptive message for the SID/PID
         01 - The count has been cleared for the given dianostic code
         10 - All clearable diagnostic counts have been cleared for this device
         11 - Message is additional diagnostic information
     Bit 6:
         1 = Standard diagnostic code
         0 = Expansion diagnostic code (PID or SID is from page 2)
     Bit 5:
         1 = Low character is subsystem identifier (SID)
         0 = Low character is parameter identifier (PID)
     Bits 4-1:
         Failure mode identifier
 c: If bits 7 and 8 are (00), the data in field C is an ASCII string, which
    describes the SID or PID. If bits 7 and 8 are (11), the data in field C
    are defined by the manufacturer's application document with the exception
    that the first five characters of the data define the make of the componenet,
    which is respinding. Data type c would be omitted if bits 7 and 8 of character
    b are either (01) or (10) or if no data of the type requested is available.
*/

// Diagnostic code character definitions
#define J1587_DIAG_DATA_RSP_FMI_MASK        (0x0F)
#define J1587_DIAG_DATA_RSP_FMI_SHIFT       (0)
#define J1587_DIAG_DATA_RSP_FMI(n)          (((n) & J1587_DIAG_DATA_RSP_FMI_MASK) >> J1587_DIAG_DATA_RSP_FMI_SHIFT)
#define J1587_DIAG_DATA_RSP_SID_PID_MASK    (0x10)
#define J1587_DIAG_DATA_RSP_SID_PID_SHIFT   (4)
#define J1587_DIAG_DATA_RSP_IS_SID(n)       (((n) & J1587_DIAG_DATA_RSP_SID_PID_MASK) >> J1587_DIAG_DATA_RSP_SID_PID_SHIFT)
#define J1587_DIAG_DATA_RSP_STD_MASK        (0x20)
#define J1587_DIAG_DATA_RSP_STD_SHIFT       (5)
#define J1587_DIAG_DATA_RSP_IS_STD(n)       (((n) & J1587_DIAG_DATA_RSP_STD_MASK) >> J1587_DIAG_DATA_RSP_STD_SHIFT)
#define J1587_DIAG_DATA_RSP_CODE_MASK       (0xC0)
#define J1587_DIAG_DATA_RSP_CODE_SHIFT      (6)
#define J1587_DIAG_DATA_RSP_CODE(n)         (((n) & J1587_DIAG_DATA_RSP_CODE_MASK) >> J1587_DIAG_DATA_RSP_CODE_SHIFT)

// Diagnostic code character defintions
#define J1587_DIAG_CODE_DESC                (0)
#define J1587_DIAG_CODE_CLEAR               (1)
#define J1587_DIAG_CODE_ALL_CLEAR           (2)
#define J1587_DIAG_CODE_ADDTNL_INFO         (3)

//--- End PID 196

/*------------------------------------------------------------
 J1587 ABS Control Status, Trailer (PID 209, $D1) bit definitions

 PID Data
 209 n a b c
 n: Number of paramater data characters
 a: ABS Control status, trailer
        Bits 8-7: ABS brake control status, trailer #1
        Bits 6-5: ABS warningn lamp, trailer #1
        Bits 4-3: Trailer ABS control status
        Bits 2-1: Tractor mounted trailer ABS lamp
 b: ABS control status, trailer
        Bits 8-7: ABS brake control status, trailer #3
        Bits 6-5: ABS warning lamp, trailer #3
        Bits 4-3: ABS brake control status, trailer #2
        Bits 2-1: ABS warning lamp, trailer #2
 c: ABS control status, trailer
        Bits 8-7: ABS brake control status, trailer #5
        Bits 6-5: ABS warning lamp, trailer #5
        Bits 4-3: ABS brake control status, trailer #4
        Bits 2-1: ABS warning lamp, trailer #4
        
 NOTE: Each status will be described using the following nomenclature:
        00 Off/Not Active
        01 On/Active
        10 Error condition
        11 Not available        
*/
// Byte offsets
#define J1587_ABS_TRAILER_LENGTH_INDEX  (0)
#define J1587_ABS_STAT_TRAILER1_INDEX   (1)
#define J1587_ABS_STAT_TRAILER2_INDEX   (2)
#define J1587_ABS_STAT_TRAILER3_INDEX   (2)
#define J1587_ABS_STAT_TRAILER4_INDEX   (3)
#define J1587_ABS_STAT_TRAILER5_INDEX   (3)

// Byte 1 definitions
#define J1587_ABS_LAMP_TRAILER1_MASK    (0x30)
#define J1587_ABS_LAMP_TRAILER1_SHIFT   (4)
#define J1587_ABS_STAT_TRAILER1_MASK    (0xC0)
#define J1587_ABS_STAT_TRAILER1_SHIFT   (6)

// Byte 2 masks
#define J1587_ABS_LAMP_TRAILER2_MASK    (0x03)
#define J1587_ABS_LAMP_TRAILER2_SHIFT   (0)
#define J1587_ABS_STAT_TRAILER2_MASK    (0x0C)
#define J1587_ABS_STAT_TRAILER2_SHIFT   (2)
#define J1587_ABS_LAMP_TRAILER3_MASK    (0x30)
#define J1587_ABS_LAMP_TRAILER3_SHIFT   (4)
#define J1587_ABS_STAT_TRAILER3_MASK    (0xC0)
#define J1587_ABS_STAT_TRAILER3_SHIFT   (6)

// Byte 3 masks
#define J1587_ABS_LAMP_TRAILER4_MASK    (0x03)
#define J1587_ABS_LAMP_TRAILER4_SHIFT   (0)
#define J1587_ABS_STAT_TRAILER4_MASK    (0x0C)
#define J1587_ABS_STAT_TRAILER4_SHIFT   (2)
#define J1587_ABS_LAMP_TRAILER5_MASK    (0x30)
#define J1587_ABS_LAMP_TRAILER5_SHIFT   (4)
#define J1587_ABS_STAT_TRAILER5_MASK    (0xC0)
#define J1587_ABS_STAT_TRAILER5_SHIFT   (6)

// Status bit definitions
#define J1587_ABS_OFF_NOT_ACTIVE        (0)
#define J1587_ABS_ON_ACTIVE             (1)
#define J1587_ABS_ERROR                 (2)
#define J1587_ABS_NOT_AVAILABLE         (3)

//--- End PID 209

/*------------------------------------------------------------
 J1587 Safety restraint system trigger status, (PID 405, $195) bit definitions

 PID Data
 405 a b
 a: SRS trigger status #1
         Bits 8-7: Right side rollover trigger
         Bits 6-5: Left side impact trigger
         Bits 4-3: Right side impact trigger
         Bits 2-1: Frontal impact trigger
 b: SRS trigger status #2
         Bits 8-3: Reserved: all bits set to 1
         Bits 2-1: Left side rollover trigger
 NOTE: Each status will be described using the following nomenclature:
         00 No trigger
         01 Trigger
         10 Error condition
         11 Not available
*/
// Byte offsets
#define J1587_SRS_TRIG_STATUS_1_INDEX   (0)
#define J1587_SRS_TRIG_STATUS_2_INDEX   (1)

// Status 1 definitions
#define J1587_SRS1_FRONTAL_IMPACT_MASK  (0x03)
#define J1587_SRS1_FRONTAL_IMPACT_SHIFT (0)
#define J1587_SRS1_FRONTAL_IMPACT(n)    (((n) & J1587_SRS1_FRONTAL_IMPACT_MASK) >> J1587_SRS1_FRONTAL_IMPACT_SHIFT)
#define J1587_SRS1_RIGHT_IMPACT_MASK    (0x0C)
#define J1587_SRS1_RIGHT_IMPACT_SHIFT   (2)
#define J1587_SRS1_RIGHT_IMPACT(n)      (((n) & J1587_SRS1_RIGHT_IMPACT_MASK) >> J1587_SRS1_RIGHT_IMPACT_SHIFT)
#define J1587_SRS1_LEFT_IMPACT_MASK     (0x30)
#define J1587_SRS1_LEFT_IMPACT_SHIFT    (4)
#define J1587_SRS1_LEFT_IMPACT(n)       (((n) & J1587_SRS1_LEFT_IMPACT_MASK) >> J1587_SRS1_LEFT_IMPACT_SHIFT)
#define J1587_SRS1_RIGHT_ROLL_MASK      (0xC0)
#define J1587_SRS1_RIGHT_ROLL_SHIFT     (6)
#define J1587_SRS1_RIGHT_ROLL(n)        (((n) & J1587_SRS1_RIGHT_ROLL_MASK) >> J1587_SRS1_RIGHT_ROLL_SHIFT)

// Status 2 definitions
#define J1587_SRS2_LEFT_ROLL_MASK       (0x03)
#define J1587_SRS2_LEFT_ROLL_SHIFT      (0)
#define J1587_SRS2_LEFT_ROLL(n)         (((n) & J1587_SRS2_LEFT_ROLL_MASK) >> J1587_SRS2_LEFT_ROLL_SHIFT)

// Staus bit definitions
#define J1587_SRS_NO_TRIGGER            (0)
#define J1587_SRS_TRIGGER               (1)
#define J1587_SRS_ERROR_CONDITION       (2)
#define J1587_SRS_NOT_AVAILABLE         (3)

//--- End PID 405

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

typedef void (*J1587_CONNECTIONSTATECHANGED)(int1_t);
typedef void (*J1587_IGNITIONSTATECHANGED)(int1_t);
typedef void (*J1587_RECEIVEDMESSAGE)(uint32_t, uint8_t*, uint32_t);

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*! @brief Initialise the module, the queue and check the hardware is
 *   configured correctly
 *  @return The error code for the function
 */
uint8_t J1587_InitModule(void);

/*! @brief Terminate the tasks and queues for the J1587 module */
void J1587_TerminateModule(void);

/*! @brief Sets the callback for a received J1708 message (Raw View Mode Only)
 *  @param cbFunction The function to call
 */
void J1587_RegisterReceivedMessageCallback(J1587_RECEIVEDMESSAGE cbFunction_);

/*! @brief Sets the operation mode of the stack
 *  @param u32Mode The desired mode for the stack
 */
void J1587_SetOperationMode(uint32_t u32Mode_);

/*! @brief Set the bus silence time before assuming diconnection
 *  @param u32Milliseconds The timout (default = 2000)
 */
void J1587_SetConnectionTimeout(uint32_t u32Milliseconds_);

/*! @brief Sets the callback for a change in connection status
 *  @param cbFunction The function to call
 */
void J1587_RegisterConnectionStateChangedCallback(J1587_CONNECTIONSTATECHANGED cbFunction_);

/*! @brief Sets the callback for a change in connection status
 *  @return The connection state (true = connected)
 */
int1_t J1587_GetConnectionState(void);

/*! @brief Sets the callback for a change in igntion state
 *  @param cbFunction The function to call
 */
void J1587_RegisterIgnitionStateChangedCallback(J1587_IGNITIONSTATECHANGED cbFunction_);

/*! @brief Adds a PID to monitor to the stack 
 *  @param u32PID The PID to add
 *  @return The success of the pre-emption (true = PID added)
 */
int1_t J1587_PreEmptPID(uint32_t u32PID_);

/*! @brief Get a PID by its index within the module
 *  @param u32Index The index
 *  @param pPID A pointer for the PID
 *  @return The validity of the returned PID (true = PID is valid)
 */
int1_t J1587_GetPIDByIndex(uint32_t u32Index_, uint32_t *pPID_);

/*! @brief Tests if PID data is available
 *  @param u32PID The PID to test
 *  @return The availablity of the PID data (true = PID data available)
 */
int1_t J1587_IsPIDAvailable(uint32_t u32PID_);

/*! @brief Converts the PID value to a double
 *  @param u32PID The PID to convert
 *  @param fScale The scalar for the PID value
 *  @param fOffset The offset for the PID value
 *  @return The transformed PID data as a double
 */
double J1587_PIDToDouble(uint32_t u32PID_,
                         double fScale_,
                         double fOffset_);

/*! @brief Converts the PID value to an integer
 *  @param u32PID The PID to convert
 *  @param u32Mask The mask for the PID value
 *  @param u32Shift The right shift for the PID value
 *  @return The transformed PID data as an unsigned integer
 */
uint32_t J1587_PIDToInteger(uint32_t u32PID_,
                            uint32_t u32Mask_,
                            uint32_t u32Shift_);

/*! @brief Send a raw message on the J1708 bus
 *  @param u8Priority The priority of the message
 *  @param u8Length The length of the data
 *  @param pData Pointer for the data
 */
void J1587_SendMessage(uint8_t u8Priority_,
                       uint8_t u8Length_,
                       uint8_t *pData_);

/*! @brief Converts a PID to array
 *  @param u32PID The PID to convert
 *  @param u32Length pointer to recieve length
 *  @return The transformed PID data as an unsigned integer
 */
uint8_t* J1587_PIDToArray(uint32_t u32PID_, 
                          uint32_t *u32Length);

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif /* _J1587_MODULE_H_ */

/*! @{ */
