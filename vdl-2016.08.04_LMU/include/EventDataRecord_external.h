
#ifndef EVENTDATARECORD_EXTERNAL_H__
#define EVENTDATARECORD_EXTERNAL_H__

#ifdef __INCLUDE_EVENTDATARECORD

typedef struct
{
    uint32_t timestamp;

    
    /* bit 0-1: ABS retarder status PID 49  
     * bit 2-3: ABS brake control status-tractor PID 49, SPN 563
             00 - ABS passive but installed
             01 - ABS active
             10 - Reserved
             11 - Not available
     * bit 4-5: ABS warning lamp status-tractor  PID 49  SPN 1438
     * bit 6-7: reserved
     */
    uint8_t ABS_status1;

    /* bit 0-1: ABS brake control status-trailer#1 PID 209 SPN 1836
     * bit 2-3: ABS brake control status-trailer#2 PID 209 SPN 1836
     * bit 4-5: ABS brake control status-trailer#3 PID 209 SPN 1836
     * bit 6-7: reserved
     */
    uint8_t ABS_brake_control_status_trailer;
    
    /* bit 0-1: ABS warning lamp status-trailer#1 PID 209 SPN 1792
     * bit 2-3: ABS warning lamp status-trailer#2 PID 209 SPN 1792
     * bit 4-5: ABS warning lamp status-trailer#3 PID 209 SPN 1792
     * bit 6-7: reserved
     */
    uint8_t ABS_warning_lamp_status_trailer;
        
    /* bit 0-1: Cruise Control Active PID 85 bit 8, SPN 596
     * bit 2-4: Cruise control states SPN 527
     *    000 - Off/Disabled
     *    001 - Hold
     *    010 - Accelerate
     *    011 - Decelerate
     *    100 - Resume
     *    101 - Set
     *    110 - Accelerator Override
     *    111 - Not available
     */
    uint8_t  cruise_control_status;
    
    /* cruise control set-speed,  km/h PID 86, SPN 86*/
    uint16_t  cruise_control_setspeed;
    
    /* for both brake status parking and brake status service 
     * bit 0-1: Two Speed Axle Switch  PID 69, SPN 69
     *  note: the value range in J1587 is different, be careful about this when handling J1587 PID 70 message.
     *    00 - Low speed range 
     *    01 - High speed range
     *    10 - Error           
     *    11 - Not available   
     * bit 2-3: brake status-parking  PID 70, SPN 70
     *     00 - Parking brake not set
     *     01 - Parking brake set    
     *     10 - Error                
     *     11 - Not available        
     * bit 4-5: brake status-service  PID65, SPN 597(?)
     *     00 - Brake pedal released 
     *     01 - Brake pedal depressed
     *     10 - Error                
     *     11 - Not Available        
     * bit 6-7 reserved
     */
    uint8_t  brake_status_axle_switch; 
    
    
    /* brake pedal position. spn 521
     *  bit resolution 0.4%
     *  range: 0-100%
     */
    uint8_t  brake_position;

    /* Accelerator pedal position, PID 91, SPN 91
     * 0-100%
     * bit resolution is 0.4%
     */
    uint8_t  accelerator_pedal_position;
    
    /*  engine retarder percent torque, PID 122, SPN 520
     *   Resolution: 1 %/bit, -125 % offset which means value 0 means -125%
     *  data range: -125% to +125%
     */
    int8_t  engine_retarder_percent_torque;

    /* bit 0-1: engine retarder status  PID 121 bit 8, SPN 571
     *      00 Retarder - brake assist disabled
     *      01 Retarder - brake assist enabled 
     *      10 Error                           
     *      11 Not available                   
     * bit 2-7: reserved
     */
    uint8_t engine_retarder_status;
    
    /* transmission gear, SPN 523, 
     *    Resolution: 1 gear value/bit, -125 offset
     *    Data Range: -125 to 125 Operational Range: -125 to +125, negative values are
     *             reverse gears, positive values are forward gears, zero is neutral. 251(0xFB) is park.
     */
    uint8_t  transmission_gear;

    /* engine speed: PID 190, SPN 190
     *  note: J1939 SPN 190 bit resolution is 0.125 rpm, need to convert.
     *   Bit Resolution: 0.25 rpm
     *   Maximum Range: 0.0 to 16383.75 rpm
     */
    uint16_t engine_speed;

    /* the vehicle speed calculated from vehicle speed sensor. PID 84, SPN 84
     * bit resolution: 0.1 km/h (all vehicle speed in VDL km/h)
     */
    uint16_t vehicle_speed;

    /* SPN 904
     * bit resolution: 0.1 lkm/h (all vehicle speed in VDL km/h)
     */
    uint16_t vehicle_speed_wheel_based;
} __attribute__ ((__packed__)) VDL_EVENTDATA_Record_Item;

typedef struct
{
    
    uint32_t allocated_items;
    uint32_t number_items;
    VDL_EVENTDATA_Record_Item* items;
} VDL_EVENTDATA_Record;

#if defined(__cplusplus)
extern "C" {
#endif

/* to get the latest Event Data buffer
 * param:
 *    start_time: the start system clock of event buffer in ms
 *    end_time:   the end system clock of event buffer  in ms
 *    record:   the EVENTDATA_Record to store event data
 * return value:
 *    0: success
 *    non-zero: failed
 */
extern uint32_t VDL_EVENTDATA_Record_Get(uint32_t start_time, uint32_t end_time, VDL_EVENTDATA_Record* record);

/* clear allocated memory of VDL_EVENTDATA_Record
 */
extern void VDL_EVENTDATA_Record_clear_Record(VDL_EVENTDATA_Record* record);

#if defined(__cplusplus)
}
#endif

#endif // __INCLUDE_EVENTDATARECORD

#endif
