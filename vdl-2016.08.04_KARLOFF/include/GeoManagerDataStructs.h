/********************************************************************
* File:     $Id: GeoManagerDataStructs.h,v 1.31 2010/05/26 14:37:56 Amiao Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.31 $
* Date:     $Date: 2010/05/26 14:37:56 $
* Author:   $Author: Amiao $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*   This file contains all the structs used for communications
*   with GeoManager
*/
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2008 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: GeoManagerDataStructs.h,v $
*   Revision 1.31  2010/05/26 14:37:56  Amiao
*   Merged from 1.4
*
*   Revision 1.30.2.2  2010/05/25 13:01:39  Amiao
*   Added BiBBLE config param.
*
*   Revision 1.30.2.1  2010/05/18 15:46:41  Amiao
*   Merged code from FW1.3.
*   Added logging driver out on private and set to public on login.
*
*   Revision 1.30  2010/05/05 11:32:58  Mswain
*   [Bug 34280] Non-hardwired Ignition
*
*   Revision 1.29  2010/04/29 09:44:33  Amiao
*   Added privacy feature config param.
*
*   Revision 1.28  2010/04/12 16:05:05  Amiao
*   Added automatic logout timeout config.
*   Added unauthorized usage exception packets.
*
*   Revision 1.27  2010/03/11 15:28:04  Rharvie
*   Added definitions for latest packet description and system variables
*
*   Revision 1.26  2010/02/26 14:59:40  Rharvie
*   V1.2.3 bug fixes ported back to V1.3 code.
*
*   Revision 1.25  2010/02/19 14:55:28  Amiao
*   Added Driver ID and Privacy features
*
*   Revision 1.24  2010/01/28 16:20:30  richard
*   Fixed data counts (now use raw data from PPP stack)
*   Fixed tab / space formatting issues
*
*   Revision 1.23  2010/01/28 15:57:26  alanm
*   Always keep wakeup time
*
*   Revision 1.22  2010/01/21 11:46:40  alanm
*   Added header comments log up to Revision 1.15
*
*   Revision 1.21  2010/01/21 10:41:02  alanm
*   Added #ifdef for GMI code
*
*   Revision 1.20  2010/01/21 02:08:00  vgundu
*   Added  code to download PRL data for Q26 CDMA modem once in a month
*
*   Revision 1.19  2010/01/20 09:14:00  alanm
*   Fixed GMI wakeup time
*
*   Revision 1.18  2010/01/18 17:23:00  richard
*   *** empty log message ***
*
*   Revision 1.17  2009/12/07 15:55:00  richard
*   Fixed no-distance proble on GPS fallback in CoreParamsGeneric
*   Syncronised vehicle data and debug to GPS
*
*   Revision 1.16  2009/12/01 22:39:00  vgundu
*   some fixes for CDMA modem interface
*
*   Revision 1.15  2009/11/04 15:08:00  richard
*   *** empty log message ***
*
*
*********************************************************************
*/

#if defined(__INCLUDE_GEOMANAGER_MODULE) || defined(__INCLUDE_GEOMANAGER_RELTEST) || defined(__INCLUDE_GMI)

// CONFIG DATA - as sent by GeoManager Server. Only 1st 35 entries used.
typedef struct
{
    int16_t Move2StopSpeed;                             // 0
    int16_t Stop2ParkTimeout;                           // 1
    int16_t ParkTimer1;                                 // 2
    int16_t ParkTimer2;                                 // 3
    int16_t ParkTimer3;                                 // 4
    int16_t ParkTimer4;                                 // 5
    int16_t ParkTimer5;                                 // 6
    int16_t MoveQualifier;                              // 7
    int16_t PvtQueueRate;                               // 8
    int16_t unused_09;                                  // 9
    int16_t unused_10;                                  // 10
    int16_t MessageRetryRate;                           // 11
    int16_t PvtTxRate;                                  // 12
    int16_t TxQueueSizeLimit;                           // 13
    int16_t TxQueueIdleLimit;                           // 14
    int16_t PvtAgeLimit;                                // 15
    int16_t NumPvtRetries;                              // 16
    int16_t PvtRetryTimeOut;                            // 17
    int16_t ServerDownRecheck;                          // 18
    int16_t ServerDownNakLimit;                         // 19
    int16_t DataIdleTimeout;                            // 20
    int16_t MaxDataSessionTime;                         // 21
    int16_t ModemPowerDownTimeout;                      // 22
    int16_t GpsPowerOffTimeout;                         // 23
    int16_t IlmPowerOffTimeout;                         // 24
    int16_t BatteryLowLimit;                            // 25
    int16_t AuxField1;                                  // 26
    int16_t AuxField2;                                  // 27
    int16_t AuxField3;                                  // 28
    int16_t AuxField4;                                  // 29
    int16_t AuxField5;                                  // 30
    int16_t AuxField6;                                  // 31
    int16_t AuxField7;                                  // 32
    int16_t AuxField8;                                  // 33
    int16_t AuxField9;                                  // 34
    int16_t AuxField10;                                 // 35
    uint16_t DailyWakeUpMSW;                            // 36
    uint16_t DailyWakeUpLSW;                            // 37
    int16_t DhcIdleTime;                                // 38
    int16_t DhcHealthInfo;                              // 39
    int16_t DhcFwInfoInterval;                          // 40
    int16_t DhcDataUsageInterval;                       // 41
    uint16_t ScEarliestTimeInMSW;                       // 42
    uint16_t ScEarliestTimeInLSW;                       // 43
    int16_t ScCompanyID;                                // 44
    int16_t ScRepeatCardHoldoff;                        // 45
    int16_t Data2PortFunction;                          // 46
    int16_t Data2PortLineParam;                         // 47
    int16_t PvtqDumpAge;                                // 48
    int16_t DistanceUnitPvt;                            // 49
    int16_t PvtPacketType;                              // 50
    int16_t DistanceParkToMove;                         // 51
    int16_t TimeParkToMove;                             // 52
    int16_t GpsAlarmTime;                               // 53
    int16_t GpsAlarmDistance;                           // 54
    int16_t unknown55;                                  
    int16_t unknown56;                                  
    int16_t PTO_SW3_Settings;                           // 57 Bits 0-7: Switch mode, Bits 8-15:Debounce time
    int16_t PTO_SW4_Settings;                           // 58 Bits 0-7: Switch mode, Bits 8-15:Debounce time
    int16_t DgpsMode;                                   // 59
    int16_t SchoolBusMode;                              // 60
    int16_t GmtOffset;                                  // 61
    int16_t DstOffset;                                  // 62
    int16_t ResetPvtTimer;                              // 63
    int16_t GpsSampleRate;                              // 64
    int16_t GmpeMessaging;                              // 65
    int16_t MaxGpsAge;                                  // 66
    int16_t MaxGpsDistance;                             // 67
    int16_t QncCallFreq;                                // 68
    int16_t QncCallQueueSize;                           // 69
    int16_t TrailerUnitEnabled;                         // 70

    // IMPORTANT - if you add any config values below here, be sure to 
    // edit GM_Modem_Report0x35() and change MAX_0x35_PARAMS

    int16_t dot_features;                               // 71
    int16_t MR3_Feature;
    int16_t iDT_features;                               // 73
    int16_t unknown74;
    int16_t unknown75;
    int16_t unknown76;
    int16_t unknown77;
    int16_t unknown78;
    int16_t unknown79;
    int16_t Data1PortFunction;                         // 80
    int16_t Data1PortLineParam;                        //81
    int16_t unknown82;
    int16_t unknown83;
    int16_t unknown84;
    int16_t unknown85;
    int16_t unknown86;
    int16_t unknown87;
    int16_t unknown88;
    int16_t unknown89;
    int16_t unknown90;
    int16_t DriverAuthEnabled;                          // 91
    int16_t unknown92;
    int16_t Dot_Canadian;                               // 93
    int16_t unknown94;
    int16_t unknown95;
    int16_t unknown96;
    int16_t unknown97;
    int16_t unknown98;
    int16_t unknown99;
    int16_t unknown100;
    int16_t unknown101;
    int16_t unknown102;
    int16_t unknown103;
    int16_t unknown104;
    int16_t unknown105;
    int16_t unknown106;
    int16_t unknown107;
    int16_t unknown108;
    int16_t DriverSafetyDevicePortUsage;                // 109
    int16_t unknown110;
    int16_t unknown111;
    int16_t unknown112;
    int16_t unknown113;
    int16_t unknown114;
    int16_t unknown115;
    int16_t unknown116;
    int16_t unknown117;
    int16_t unknown118;
    int16_t unknown119;
    int16_t unknown120;
    int16_t unknown121;
    int16_t unknown122;
    int16_t unknown123;
    int16_t unknown124;
    int16_t unknown125;
    int16_t unknown126;
    int16_t unknown127;
    int16_t unknown128;
    int16_t unknown129;
    int16_t unknown130;
    int16_t unknown131;
    int16_t unknown132;
    int16_t unknown133;
    int16_t unknown134;
    int16_t unknown135;
    int16_t unknown136;
    int16_t unknown137;
    int16_t unknown138;
    int16_t unknown139;
    int16_t unknown140;
    int16_t unknown141;
    int16_t unknown142;
    int16_t unknown143;
    int16_t unknown144;
    int16_t unknown145;
    int16_t unknown146;
    int16_t unknown147;
    int16_t unknown148;
    int16_t unknown149;
    int16_t unknown150;
    int16_t DriverIDConfig1;                            // 151
    int16_t DriverIDConfig2;                            // 152
    int16_t unknown153;
    int16_t unknown154;
    int16_t unknown155;
    int16_t unknown156;
    int16_t unknown157;
    int16_t unknown158;
    int16_t unknown159;
    int16_t unknown160;
    int16_t SerialPort1Config;                          // 161
    int16_t SerialPort2Config;                          // 162
    int16_t unknown163;
    int16_t FuelCalibrationDoNotUse;                    // 164
    int16_t CrankDetectDoNotUse;                        // 165
    int16_t EngineSizeDoNotUse;                         // 166
    int16_t EngineFuelType;                             // 167
    int16_t unknown168;
    int16_t unknown169;
    int16_t unknown170;
    int16_t NmeaOutParams;                              // 171
    int16_t DriverSafetyFeatureEnabled;                 // 172
    int16_t unknown173;
    int16_t unknown174;
    int16_t unknown175;
    int16_t unknown176;
    int16_t unknown177;
    int16_t unknown178;
    int16_t unknown179;
    int16_t AutomaticLogout;                            // 180
    int16_t unknown181;
    int16_t PrivacyFeature;                             // 182
    int16_t unknown183;
    int16_t unknown184;
    int16_t unknown185;
    int16_t unknown186;
    int16_t unknown187;
    int16_t unknown188;
    int16_t unknown189;
    int16_t unknown190;
    int16_t unknown191;
    int16_t unknown192;
    int16_t unknown193;
    int16_t unknown194;
    int16_t unknown195;
    int16_t unknown196;
    int16_t unknown197;
    int16_t unknown198;
    int16_t unknown199;
    int16_t unknown200;
    int16_t unknown201;
    int16_t unknown202;
    int16_t unknown203;
    int16_t unknown204;
    int16_t unknown205;
    int16_t unknown206;
    int16_t unknown207;
    int16_t unknown208;
    int16_t unknown209;
    int16_t unknown210;
    int16_t unknown211;
    int16_t unknown212;
    int16_t unknown213;
    int16_t unknown214;
    int16_t unknown215;
    int16_t unknown216;
    int16_t unknown217;
    int16_t unknown218;
    int16_t unknown219;
    int16_t unknown220;
    int16_t unknown221;
    int16_t unknown222;
    int16_t unknown223;
    int16_t unknown224;
    int16_t unknown225;
    int16_t unknown226;
    int16_t unknown227;
    int16_t unknown228;
    int16_t unknown229;
    int16_t unknown230;
    int16_t unknown231;
    int16_t unknown232;
    int16_t unknown233;
    int16_t unknown234;
    int16_t unknown235;
    int16_t unknown236;
    int16_t unknown237;
    int16_t unknown238;
    int16_t unknown239;
    int16_t unknown240;
    int16_t unknown241;
    int16_t unknown242;
    int16_t unknown243;
    int16_t unknown244;
    int16_t unknown245;
    int16_t unknown246;
    int16_t unknown247;
    int16_t unknown248;
    int16_t unknown249;
    int16_t unknown250;
    int16_t unknown251;
    int16_t unknown252;
    int16_t unknown253;
    int16_t unknown254;
    int16_t unknown255;
} gmConfig;

// System data - all config and status data that needs to be backed up to flash
// All variables must be 32 bit, as they live in RTC ram which is 32 bit access only

// ALWAYS add variables at end, and do not use #ifdef etc (exception for efficient fifo)

// Finally - add to GM_Ext_ShowSystemVariables() for debug

typedef struct
{
    uint32_t Size;
#ifdef __INCLUDE_EFFICIENT_FLASH_FIFO
    // Efficient FIFO Stuff
    uint32_t EfficientPvtFifoRead;
    uint32_t EfficientPvtFifoTail;
    uint32_t EfficientPvtFifoWrite;
    uint32_t EfficientMsgFifoRead;
    uint32_t EfficientMsgFifoTail;
    uint32_t EfficientMsgFifoWrite;
#else
    // FIFO stuff
    uint32_t PvtFifoHead;
    uint32_t PvtFifoTail;
    uint32_t PvtFifoSize;
    uint32_t MsgFifoHead;
    uint32_t MsgFifoTail;
    uint32_t MsgFifoSize;
#endif
    // PVT stuff
    uint32_t Sequence;
    uint32_t LastStopTime;
    uint32_t PvtCount;

    // Hardware Versions
    uint32_t ModemVersion;       // decimal encoded
    uint32_t GPSVersion;         // hibyte = major, lobyte = minor

    // Data counts
    uint32_t RxDataRaw;
    uint32_t TxDataRaw;
    uint32_t RxData;
    uint32_t TxData;
    uint32_t RequestedPings;
    uint32_t RxDataPvt;
    uint32_t TxDataPvt;

    // Position
    uint32_t StartTime;
    uint32_t StartLat;
    uint32_t StartLon;
    uint32_t CurTime;
    uint32_t CurLat;
    uint32_t CurLon;
    uint32_t GpsSatCount;
    uint32_t GpsStatus;

    // State machines
    uint32_t CurrentState;
    uint32_t pvtqState;

    // Vehicle
    uint32_t StartOdoM;       //m
    uint32_t CurrentOdoM;     //km

    // iLM stuff
    uint32_t DeviceId;
    uint32_t IsLocal;
    int32_t Temperature;
    uint32_t RealTimeClock;

    // Modem
    int32_t Rssi;
    uint32_t CellId;
    uint32_t NetworkRegistration;

    // Reset / Bootloader
    uint32_t ResetType;
    uint32_t SleepTime;

    // Unit info
    uint32_t FirmwareVersion;
    uint32_t IPAddress;
    uint32_t DailyHealth;

    uint32_t StartTimeRTC;
    uint32_t LastIgnTime;

    // CDMA Modem stuff
    uint32_t Channel;
    uint32_t ModemProvDayCounter;

    // GPS count
    uint32_t GpsPingCount;

    // Accelerometer calibration
    uint32_t xAccelRot;
    uint32_t yAccelRot;
    uint32_t zAccelRot;

    // Packet 0x84 stuff
    int32_t MinTemp;
    int32_t MaxTemp;
    uint32_t IgnitionOnTime;

    // Sleep Stuff
    uint32_t GmiWakeUpTime;
    uint32_t ReasonForSleep;

    // Network PLMN
    uint32_t NetworkPLMN;

    uint32_t DOTLastVehMode; //Used in DOT Module

    //Configuration downloaded time
    time_t Config_Down_time;
   

    // Handle case where new 0x31 packet needs sending
    uint32_t ForcePacket;

    // hibyte = SW3, lowbyte = SW4
    uint32_t PTO_SW_NegativeHoldOff; 

    // hibyte = SW3, lowbyte = SW4
    uint32_t PTO_SW_FunctionCode;

        // VBat
    uint32_t FilteredVbat;      // vbat * 1000 to remove decimal point.

} gmSystem;


// Storage for hourly counts;

typedef struct
{
    uint32_t u32StackRxCount;
    uint32_t u32StackTxCount;
    uint32_t u32MovingNonPvtRxCount;
    uint32_t u32MovingNonPvtTxCount;
    uint32_t u32StoppedNonPvtRxCount;
    uint32_t u32StoppedNonPvtTxCount;
} gmHourlyDataCount;

typedef struct
{
    uint32_t u32Size;
    gmHourlyDataCount currentCount;
    gmHourlyDataCount hourlyCount[GM_HOURLYCOUNT];
} gmExtraCounts; // 604 bytes long

// More config information

typedef struct
{
    uint16_t u16StartMin1;
    uint16_t u16EndMin1;
    uint16_t u16StartMin2;
    uint16_t u16EndMin2;
} gmDaySchedule;

typedef struct
{
    uint32_t u32LandmarkID;
    uint32_t u32LandMarkType;
    uint32_t u32Latitude;
    uint32_t u32Longitude;
    uint16_t u16Radius;
    uint32_t u32MinDuration;
    uint32_t u32CurrentDuration;
} gmLandmarkConfig;

typedef struct
{
    uint32_t u32StartTime;
    gmDaySchedule schedule[GM_WEEKDAYS];
    uint8_t u8Weeks;
    uint8_t u8MaxExceptions;
    uint8_t u8CurrentExceptions;
    uint8_t u8MaxSpeed;
    uint32_t u32OverSpeedDuration;
    uint32_t u32CurrentOverSpeedDuration;
    uint8_t u8CurrentMaxSpeed;
    uint32_t u32OverspeedStartTime;
    int32_t i32StartLatitude;
    int32_t i32StartLongitude;
    uint8_t u8StartHeading;
} gmSpeedException;

typedef struct
{
    uint32_t u32StartTime;
    gmDaySchedule schedule[GM_WEEKDAYS];
    uint8_t u8Weeks;
    uint8_t u8MaxExceptions;
    uint8_t u8CurrentExceptions;
    uint32_t u32MaxIdleDuration;
    uint32_t u32CurrentIdleDuration;
    uint32_t u32IdleStartTime;
    int32_t i32StartLatitude;
    int32_t i32StartLongitude;
} gmIdleException;

typedef struct
{
    uint32_t u32StartTime;
    gmDaySchedule schedule[GM_WEEKDAYS];
    uint8_t u8Weeks;
    uint8_t u8MaxExceptions;
    uint8_t u8CurrentExceptions;
    gmLandmarkConfig landmarks[GM_MAX_LANDMARK];
} gmLandmarkException;

typedef struct
{
    uint32_t u32StartTime;
    gmDaySchedule schedule[GM_WEEKDAYS];
    uint8_t u8Weeks;
    uint8_t u8MaxExceptions;
    uint8_t u8CurrentExceptions;
    uint32_t u32MinStopDuration;      
}gmStopException;

typedef struct
{
    uint32_t u32StartTime;
    gmDaySchedule schedule[GM_WEEKDAYS];
    uint8_t u8Weeks;
    uint8_t u8MaxExceptions;
		int16_t MinTemp;
		int16_t MaxTemp;
		int16_t Time_Range;
}gmTempSensorException;
typedef struct
{
    uint32_t u32StartTime;
    gmDaySchedule schedule[GM_WEEKDAYS];
    uint8_t u8Weeks;
    uint8_t u8MaxExceptions;
    uint8_t u8CurrentExceptions;
    uint8_t u8DtcCode;
} gmDtcScheduleException;

typedef struct
{
    uint32_t u32StartTime;
    gmDaySchedule schedule[GM_WEEKDAYS];
    uint8_t u8Weeks;
    uint8_t u8MaxExceptions;
    uint8_t u8CurrentExceptions;
    uint16_t u16TimeAfterMove;
    uint32_t u32CurrentUnauthorizedDuration;
    uint32_t u32UnauthorizedStartTime;
    uint8_t u8Heading;
    int32_t i32StartLatitude;
    int32_t i32StartLongitude;
} gmUnauthorizedUsageException;

//typedef struct
//{
//    uint32_t u32DtcTime;
//    int32_t i32Latitude;
//    int32_t i32Longitude;
//    uint16_t u16Dtc;
//    uint16_t u16DtcData;
//    uint16_t u16DtcEcu;
//    uint16_t u16Duration;
//} gmDtcHolder;
//
//typedef struct
//{
//    uint32_t u32Count;
//    gmDtcHolder dtcs[GM_MAX_DTCS];
//} gmDtcException;

typedef struct
{
    uint32_t u32Size;
    gmSpeedException speed;
    gmIdleException idle;
    gmLandmarkException landmark;
    //gmDtcException dtc;
    gmStopException stop;
    gmDtcScheduleException dtcSchedule;
    gmUnauthorizedUsageException unauthorized;
#ifdef __INCLUDE_TEMP_SENSOR
		gmTempSensorException TempSensor;
#endif
} gmConfigExceptions; // 2024 bytes long
#endif
