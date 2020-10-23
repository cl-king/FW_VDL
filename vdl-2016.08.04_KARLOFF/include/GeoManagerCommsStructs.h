/********************************************************************
* File:     $Id: GeoManagerCommsStructs.h,v 1.32 2010/05/27 14:19:33 Amiao Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.32 $
* Date:     $Date: 2010/05/27 14:19:33 $
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
*   $Log: GeoManagerCommsStructs.h,v $
*   Revision 1.32  2010/05/27 14:19:33  Amiao
*   Merged from 1.4
*
*   Revision 1.31  2010/05/26 14:37:56  Amiao
*   Merged from 1.4
*
*   Revision 1.30.2.1  2010/05/25 13:01:03  Amiao
*   Increased formal version data size.
*
*   Revision 1.30  2010/05/06 10:54:01  Amiao
*   Increased report 0x35 and 0x32 limits
*
*   Revision 1.29  2010/04/29 09:44:05  Amiao
*   Fixed unauthorized vehicle usage exception packet structure.
*
*   Revision 1.28  2010/04/22 09:02:41  Amiao
*   Changed data types for several trip data.
*
*   Revision 1.27  2010/04/19 15:51:06  Amiao
*   Added padding to packet 0x4B.
*
*   Revision 1.26  2010/04/14 14:26:14  Mswain
*   Increased lenth of AT commands for use with sms
*
*   Revision 1.25  2010/04/14 09:27:13  Rharvie
*   Changes brought forward from v1.3 branch
*
*   Revision 1.24  2010/04/12 16:06:04  Amiao
*   Fixed driver ID distance.
*   Added unauthorized usage exception packets.
*
*   Revision 1.23  2010/03/11 15:28:04  Rharvie
*   Added definitions for latest packet description and system variables
*
*   Revision 1.22  2010/03/09 17:26:06  Amiao
*   Added driver packet type due to bug
*
*   Revision 1.21  2010/03/02 11:15:46  Amiao
*   Added new 0x48 trip report packet structure
*
*   Revision 1.20  2010/01/28 16:20:30  richard
*   Fixed data counts (now use raw data from PPP stack)
*   Fixed tab / space formatting issues
*
*   Revision 1.19  2010/01/21 12:03:06  alanm
*   Added header comments log up to Revision 1.15
*
*   Revision 1.18  2010/01/21 10:41:02  alanm
*   Added #ifdef for GMI code
*
*   Revision 1.17  2010/01/18 17:23:00  richard
*   *** empty log message ***
*
*   Revision 1.16  2009/10/19 17:16:00  richard
*   Changes for reltest2 and 8Mbit flash
*
*   Revision 1.15  2009/09/23 17:24:00  richard
*   Build 36 with added PPP goodies
*
*
*********************************************************************
*/
#if defined(__INCLUDE_GEOMANAGER_MODULE) || defined(__INCLUDE_GEOMANAGER_RELTEST) || defined(__INCLUDE_GMI)
#ifndef __INCLUDE_IDT_MODULE
#include "types.h"
#endif

#pragma pack(1)
typedef struct
{
    uint32_t DestAddress;
    uint16_t DestPort;
    uint16_t RecPort;
    uint32_t RecTime;
} __attribute__ ((__packed__)) gmIP;

typedef struct
{
    gmIP ip;
    // 16 bytes
    uint16_t HeaderSync;
    uint8_t PacketID;
    uint8_t PacketLen;
    int32_t Sequence;
    int32_t UID;
} __attribute__ ((__packed__)) gmHeader;

typedef struct
{
    uint32_t EventTimeTag;
    uint32_t LocationTimeTag;
    uint8_t Speed;
    uint8_t Heading;
    int32_t Latitude;
    int32_t Longitude;
    uint8_t Status;
    uint8_t TotalDistMsb;
    uint8_t TotalDistMid;
    uint8_t TotalDistLsb;
    uint16_t LastStopDuration;
    uint16_t InvokeCode;
    int16_t AuxCode1;
    int16_t AuxCode2;
    int16_t AuxCode3;
    int16_t AuxCode4;
    int16_t AuxCode5;
    int16_t AuxCode6;
    int16_t AuxCode7;
    int16_t AuxCode8;
    int16_t AuxCode9;
    int16_t AuxCode10;
} __attribute__ ((__packed__)) gmPVT6_sub;

typedef struct
{
    gmHeader Header;
    uint32_t StartEventTimeTag;
    uint32_t StartLocationTimeTag;
    int32_t StartLatitude;
    int32_t StartLongitude;
    uint8_t StartOdoMsb;
    uint8_t StartOdoMid;
    uint8_t StartOdoLsb;
    uint32_t EndEventTimeTag;       // Check alignment
    uint32_t EndLocationTimeTag;
    int32_t EndLatitude;
    int32_t EndLongitude;
    uint8_t EndOdoMsb;
    uint8_t EndOdoMid;
    uint8_t EndOdoLsb;
    uint32_t TripFuel;
    uint16_t TripDrivingTime;
    uint32_t IdleFuel;              // Speed < 3, RPM > 200
    uint16_t IdleTime;
    uint16_t PtoDuration;
    uint32_t PtoFuel;
    uint16_t PtoDistance;
    uint16_t DistanceInTopGear;         // Not Used
    uint8_t NumAccelerations;
    uint8_t NumDecelerations;
    uint8_t NumBrake;
    uint8_t MaxSpeed;
    uint8_t NumStops;
    uint8_t GpsStatus;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmVehicleDiagnostics;     // allows non algined data

#define TRIP_REPORT_VERSION 1
typedef struct
{
    gmHeader Header;
    uint8_t PacketVersion;
    uint8_t Reserved;
    uint8_t PID;        // 1 = TVG
    uint8_t TripFlag;   // 1-VD only, 2-DS only, 3-VD & DS
    uint8_t NumberOfTrips;
    uint8_t OperationMode;  // 0-Public, 1-Private
    uint8_t CardID[20];     // Driver ID

    uint32_t TripStartEventTime;

    uint8_t StartOdoMsb;
    uint8_t StartOdoMid;
    uint8_t StartOdoLsb;
    uint32_t StartEventTimeTag;
    uint32_t StartLocationTimeTag;
    int32_t StartLatitude;
    int32_t StartLongitude;

    uint32_t TripEndEventTime;

    uint8_t EndOdoMsb;
    uint8_t EndOdoMid;
    uint8_t EndOdoLsb;
    uint32_t EndEventTimeTag;       // Check alignment
    uint32_t EndLocationTimeTag;
    int32_t EndLatitude;
    int32_t EndLongitude;

    uint8_t GpsStatus;

    uint32_t BeforeTripFuel;

    int32_t TripFuel;
    uint16_t TripDrivingTime;
    int32_t IdleFuel;              // Speed < 3, RPM > 200
    uint16_t IdleTime;
    int32_t PtoFuel;
    uint16_t PtoDuration;
    uint16_t PtoDistance;

    uint8_t MaxSpeed;
    uint16_t MaxRPM;

    int16_t DistanceInTopGear;         // Not Used
    int8_t NumAccelerations;
    int8_t NumDecelerations;
    int8_t NumBrake;
    uint8_t NumStops;

    uint8_t TurnMinCode;
    uint8_t TurnMaxCode;
    uint16_t TurnManeuverBinGroups[20];
    uint8_t AccelMinCode;
    uint8_t AccelMaxCode;
    uint16_t AccelManeuverBinGroups[20];
    uint8_t DecelMinCode;
    uint8_t DecelMaxCode;
    uint16_t DecelManeuverBinGroups[20];
    uint8_t TurnManeuverDynamics;
    uint8_t AccelManeuverDynamics;
    uint8_t DecelManeuverDynamics;

    uint8_t Pad;

    uint16_t Checksum;
} __attribute__ ((__packed__)) gmTripReport;     // allows non algined data

#ifdef __INCLUDE_DRIVERID_MODULE
typedef struct
{
    gmHeader        Header;
    uint8_t         PacketVersion;
    uint8_t         Reserved;
    uint8_t         EventType;      // 1 = Login, 2 = logout
    uint8_t         LogSource;      // see t_SourceType
    uint32_t        QueuedTimeTag;
    uint32_t        QueuedLocationTimeTag;
    uint8_t         Speed;
    uint8_t         Heading;
    int32_t         Latitude;
    int32_t         Longitude;
    uint8_t         TimerStatus;
    uint8_t         TotalDistMsb;
    uint8_t         TotalDistMid;
    uint8_t         TotalDistLsb;
    int16_t         LastStopDuration;
    uint32_t        LogTimeTag;
    uint8_t         driver_id[20];	// 20 bytes, Driver ID
    int16_t         Checksum;
} __attribute__ ((__packed__)) gmDriverID;
#endif

typedef struct
{
    gmHeader Header;
    gmPVT6_sub Data;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmPVT6;

#define MAX_PVTS    5
typedef struct
{
    gmHeader Header;
    gmPVT6_sub Data[MAX_PVTS];      // Variable length packet
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmPVT6Full;


typedef struct
{
    gmHeader Header;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmACK;

typedef struct
{
    gmHeader Header;
    uint8_t RequestCode;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmReqPvt;

typedef struct
{
    gmHeader Header;
    uint8_t PlatformID;
    uint16_t VersionNumber;
    uint16_t ServiceRelease;
    uint8_t ModemType;
    uint16_t BuildNumber;
    uint16_t AddOnOptions;
    uint8_t HardwareID;
    uint32_t ServerAddress;
    uint16_t ServerPort;
    int16_t UpdateRate;
    uint8_t SVsVisable;
    uint8_t SVsTracking;
    uint16_t GpsStatus;
    int16_t LoFreqOffset;
    uint8_t SupplyVoltage;
    uint16_t UnitTemp;
    uint16_t UnitMinTemp;
    uint16_t UnitMaxTemp;
    uint8_t Mode;
    uint16_t PvtQueueSize;
    uint8_t Chan1PRN;
    uint8_t Chan1SNR;
    uint8_t Chan2PRN;
    uint8_t Chan2SNR;
    uint8_t Chan3PRN;
    uint8_t Chan3SNR;
    uint8_t Chan4PRN;
    uint8_t Chan4SNR;
    uint8_t Chan5PRN;
    uint8_t Chan5SNR;
    uint8_t Chan6PRN;
    uint8_t Chan6SNR;
    uint8_t Chan7PRN;
    uint8_t Chan7SNR;
    uint8_t Chan8PRN;
    uint8_t Chan8SNR;
    uint8_t GpsCurrentSpeed;
    uint8_t Move2StopSpeed;
    uint16_t Stop2ParkElapseTime;
    uint16_t StopTimer1;
    uint16_t StopTimer2;
    uint16_t StopTimer3;
    uint16_t StopTimer4;
    uint16_t StopTimer5;
    int8_t GmtOffset;
    uint16_t TxRetryRate;
    uint8_t Park2MoveVoltage;
    uint8_t Stop2ParkVoltage;
    uint8_t MoveQualifier;
    uint16_t CpdpSleepTimeout;
    uint16_t GpsSleepTimeout;
    uint32_t TotalTxBytes;
    uint32_t TotalRxBytes;
    uint16_t TotalPingRequests;
    uint16_t TotalTxRetries;

    uint32_t TotalDrivenDistance;
    uint32_t TotalIgnitionOnTime;
    uint8_t SwitchStatus;

    uint8_t AuxFieldSetting;
    uint16_t GpsFilterMaxDist;
    uint8_t GpsFilterSlowSpdAccel;
    uint8_t GpsFilterHighSpdAccel;

    uint16_t TransmissionRate;
    uint16_t IlmPowerOffTimer;
    uint16_t IlmLowBatteryLimit;
    uint16_t CpdcCellId;
    uint16_t CpdcChannel;
    uint8_t CpdpRSSI;
    uint8_t AuxField1;
    uint8_t AuxField2;
    uint8_t AuxField3;
    uint8_t AuxField4;
    uint8_t AuxField5;
    uint8_t AuxField6;
    uint8_t AuxField7;
    uint8_t AuxField8;
    uint8_t AuxField9;
    uint8_t AuxField10;

    uint16_t GpsAntennaVoltage;
    uint8_t IdtFwVersionMajor;
    uint8_t IdtFwVersionMinor;

    uint8_t GpsVersionMajor;
    uint8_t GpsVersionMinor;

    uint8_t BootBlockVersion;
    uint8_t Data2portFunctionCode;
    uint32_t u32TotalMovingTime;

    uint8_t Imei[8];
    uint8_t PVTtxEngineState;
    uint32_t BackUpServerIp;
    uint16_t BackUpServerPort;

    uint16_t GpsMaxTemp;
    uint16_t GpsMinTemp;
    uint8_t RamSize;
    uint8_t FlashSize;

    uint16_t Checksum;
} __attribute__ ((__packed__)) gmStatusInfo;

typedef struct
{
    gmHeader Header;
    uint8_t cmdByte1;
    uint8_t cmdByte2;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmStatusInfoRequest;

typedef struct
{
    gmHeader Header;
    uint16_t reserved;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmFormalVersionRequest;

#define MAX_FORMAL_VERSION_DATA 300
typedef struct
{
    gmHeader Header;
    char Data[MAX_FORMAL_VERSION_DATA];
    // variable length packet, no checksum
} __attribute__ ((__packed__)) gmFormalVersion;


#define MAX_PARAMS 60
typedef struct
{
    uint16_t ParamID;
    uint16_t ParamValue;
} __attribute__ ((__packed__)) gmParamType;

typedef struct
{
    gmHeader Header;
    uint8_t ResetType;
    uint8_t NumberParams;
    gmParamType ParamPairs[MAX_PARAMS];
    // No checksum as packet is variable length
} __attribute__ ((__packed__)) gmConfigPacket;

#define MAX_AUX_FIELDS 10

typedef struct
{
    gmHeader Header;
    uint8_t AuxField[MAX_AUX_FIELDS];
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmAuxFieldPacket;

typedef struct
{
	gmHeader Headr;
	uint8_t u8Data[50];
	uint16_t Checksum;
}__attribute__ ((__packed__)) gmPacket0x9A;

#define INTERVAL_REPORTS 24
#define INTERVAL_DURATION (60 * 60)
typedef struct
{
    uint8_t UDPRxCountMsb;
    uint8_t UDPRxCountMid;
    uint8_t UDPRxCountLsb;
    uint8_t UDPTxCountMsb;
    uint8_t UDPTxCountMid;
    uint8_t UDPTxCountLsb;
    uint8_t MovingRxCountMsb;
    uint8_t MovingRxCountMid;
    uint8_t MovingRxCountLsb;
    uint8_t MovingTxCountMsb;
    uint8_t MovingTxCountMid;
    uint8_t MovingTxCountLsb;
    uint8_t StoppedRxCountMsb;
    uint8_t StoppedRxCountMid;
    uint8_t StoppedRxCountLsb;
    uint8_t StoppedTxCountMsb;
    uint8_t StoppedTxCountMid;
    uint8_t StoppedTxCountLsb;
} __attribute__ ((__packed__)) gmHourlyUsage;     // allows non algined data

typedef struct
{
    gmHeader Header;
    uint8_t Version;
    uint8_t NumIntervalReports;
    uint32_t FirstIntervalTime;
    uint16_t IntervalDuration;
    uint32_t ModemRecieved;
    uint32_t ModemTransmitted;
    uint32_t UDPRecieved;
    uint32_t UDPTransmitted;
    uint32_t SatRecieved;
    uint32_t SatTransmitted;
    uint32_t TCPRecieved;
    uint32_t TCPTransmitted;
    gmHourlyUsage HourlyUsage[INTERVAL_REPORTS];
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmDataUsage;     // allows non algined data

typedef struct
{
    gmHeader Header;
    int8_t i8GmtOffset;
    int8_t i8TimeFlag;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmGmtOffset;


typedef struct
{
    uint32_t u32Schedule1;
    uint32_t u32Schedule2;
} __attribute__ ((__packed__)) gmDailySchedule;

typedef struct
{
    uint32_t u32LandmarkID;
    uint8_t u8LandmarkType;
    int32_t i32Latitude;
    int32_t i32Longitude;
    uint16_t u16Radius;
    uint16_t u16Duration;
} __attribute__ ((__packed__)) gmLandmark;

typedef struct
{
    gmHeader Header;
    uint16_t u16StartWeekNumber;
    gmDailySchedule schedule[GM_WEEKDAYS];
    uint8_t u8RecurringCount;
    uint8_t u8MaxExceptions;
    uint16_t u16IdleDuration;
    uint16_t Checksum;
} __attribute__ ((__packed__)) IdleExceptionConfig;


typedef struct
{
    gmHeader Header;
    uint16_t u16StartWeekNumber;
    gmDailySchedule schedule[GM_WEEKDAYS];
    uint8_t u8RecurringCount;
    uint8_t u8MaxExceptions;
    uint8_t u8DtcCode;
    uint8_t pad;
    uint16_t Checksum;
} __attribute__ ((__packed__)) DtcExceptionConfig;

typedef struct
{
    gmHeader Header;
    uint16_t u16StartWeekNumber;
    gmDailySchedule schedule[GM_WEEKDAYS];
    uint8_t u8RecurringCount;
    uint8_t u8MaxExceptions;
    uint8_t u8MaxSpeed;
    uint8_t u8DurationAtMaxSpeed;
    uint16_t Checksum;
} __attribute__ ((__packed__)) SpeedExceptionConfig;

typedef struct
{
    gmHeader Header;
    uint16_t u16StartWeekNumber;
    gmDailySchedule schedule[GM_WEEKDAYS];
    uint8_t u8RecurringCount;
    uint8_t u8MaxExceptions;
	int16_t Min_Temp;
	int16_t Max_Temp;
	int16_t Time_Range;
	uint16_t Checksum;
}__attribute__ ((__packed__)) TempSensorExceptionConfig;

typedef struct
{
    gmHeader Header;
    uint16_t u16StartWeekNumber;
    gmDailySchedule schedule[GM_WEEKDAYS];
    uint8_t u8RecurringCount;
    uint8_t u8MaxExceptions;
    uint8_t u8LandmarkActionType;
    gmLandmark landmark[GM_MAX_LANDMARK];
    uint16_t Checksum;
} __attribute__ ((__packed__)) LandmarkExceptionConfig;

typedef struct
{
    gmHeader Header;
    uint16_t u16StartWeekNumber;
    gmDailySchedule schedule[GM_WEEKDAYS];
    uint8_t u8RecurringCount;
    uint8_t u8MaxExceptions;
    uint16_t u16TimeAfterMove;
    uint16_t u16Reserved;
    uint16_t Checksum;
} __attribute__ ((__packed__)) UnauthorizedUsageExceptionConfig;

typedef struct
{
    gmHeader Header;
    uint8_t TargetSpeed;
    uint8_t DurationSetting;
    uint32_t EventTimeTag;
    uint16_t Duration;
    uint32_t LocationTimeTag;
    uint8_t HighestSpeed;
    uint8_t Heading;
    int32_t Latitude;
    int32_t Longitude;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmSpeedExceptionMessage;


typedef struct
{
    gmHeader Header;
    uint16_t DurationSetting;
    uint32_t EventTimeTag;
    uint16_t Duration;
    uint32_t LocationTimeTag;
    int32_t Latitude;
    int32_t Longitude;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmIdleExceptionMessage;

typedef struct
{
    gmHeader Header;
    uint32_t EventTimeTag;
    uint32_t LandmarkID;
    uint8_t Violation;
    uint16_t Duration;
    int32_t Latitude;
    int32_t Longitude;
    uint8_t Padding;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmLandmarkExceptionMessage;

#define DTC_DATA_COUNT 18

typedef struct
{
    uint32_t EventTimeTag;
    uint32_t LocationTimeTag;
    int32_t Latitude;
    int32_t Longitude;
    uint16_t Mid;
    uint16_t Pid;
    uint16_t Fmi;
    uint8_t DiagnosticsRawData[DTC_DATA_COUNT];
    uint16_t FaultDuration;
} __attribute__ ((__packed__)) gmDiagnosticsDtcHolder; //42 bytes

typedef struct
{
    gmHeader Header;
  int16_t  Min_Temp;
  int16_t  Max_Temp;
	int16_t  Time_Range;
	uint32_t EventTimeTag;
	int16_t  Duration_Time_Range;
	uint32_t Location_Time;
	int32_t Latitude;
	int32_t Longitude;
  int16_t Recorded_Temp;
	uint16_t Checksum;
}__attribute__ ((__packed__)) gmTempSensorExceptionMessage;
typedef struct
{
    gmHeader Header;
    //uint8_t NumDtcs;
    gmDiagnosticsDtcHolder dtcs[GM_MAX_DTCS];
    //uint8_t Pad;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmDiagnosticsDtcMessage;

typedef struct
{
    gmHeader Header;
    uint8_t UnauthorizedVehicleUsage;
    uint16_t Reserved;
    uint32_t EventTimeTag;
    uint32_t LocationTimeTag;
    int32_t Latitude;
    int32_t Longitude;
    uint8_t Padding;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmUnauthorizedUsageExceptionMessage;

typedef struct
{
    gmHeader Header;
    uint8_t u8ResetCmd;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmResetPacket;

typedef struct
{
    gmHeader Header;
    uint8_t u8Action;
    uint32_t u32TotalDistance;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmTotalDistancePacket;

typedef struct
{
    gmHeader Header;
    uint32_t u32PrimaryAddress;
    uint16_t u16PrimaryPort;
    uint32_t u32SecondaryAddress;
    uint16_t u16SecondaryPort;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmServerAddress;

typedef struct
{
    gmHeader Header;
    int32_t i32TotalDrivenDistance;
    int32_t i32HourMeter;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmOdoHourMeter;

#define FTP_FILE_SIZE 20
typedef struct
{
    gmHeader Header;
    uint32_t u32FtpAddress;
    uint8_t szFileName[FTP_FILE_SIZE];
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmOtapFile;

typedef struct
{
    gmHeader Header;
    uint32_t u32FtpAddress;
    uint8_t szFileName[FTP_FILE_SIZE];
    uint8_t u8ResultCode;
    uint8_t u8Retries;
    uint32_t u32BytesRecv;
    uint32_t u32BytesTrans;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmOtapComplete;
typedef struct
{
    gmHeader Header;
    uint8_t RequestType;
    uint8_t NumParams;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmReqReportConfig;

#ifdef __INCLUDE_DRIVERSAFETY_MODULE
#define MAX_0x35_PARAMS 92
#else
#define MAX_0x35_PARAMS 83
#endif

typedef struct
{
    uint16_t ParamId;
    uint16_t ParamValue;
} __attribute__ ((__packed__)) gmParamHolder;

typedef struct
{
    gmHeader Header;
    uint8_t RequestType;
    uint8_t NumParams;
    gmParamHolder params[MAX_0x35_PARAMS];
    uint16_t Checksum;
} __attribute__ ((__packed__)) gm0x35ReportConfig;

#ifdef __INCLUDE_DRIVERSAFETY_MODULE
#define MAX_0x32_PARAMS 28
#else
#define MAX_0x32_PARAMS 25
#endif

typedef struct
{
    uint8_t IcId;
    uint8_t IcValue;
} __attribute__ ((__packed__)) gmIcHolder;

typedef struct
{
    gmHeader Header;
    uint8_t RequestType;
    uint8_t NumParams;
    gmIcHolder params[MAX_0x32_PARAMS];
    uint16_t Checksum;
} __attribute__ ((__packed__)) gm0x32ReportConfig;

#ifdef __INCLUDE_DRIVERSAFETY_MODULE

typedef struct
{
    gmHeader  Header;
    uint8_t   pktVersion;
    uint8_t   diagCode;
    uint8_t   driverID[21];
    uint32_t  ttag;
    float     MD_Avg_Xs[3];
} __attribute__ ((__packed__))gmManeuverDynamicsConfig;

typedef struct
{
    gmHeader  Header;
    uint8_t   pktVersion;
    uint8_t   diagCode;
    uint8_t   u8TurnThresholdDegree;
    uint8_t   u8SettlingThresholdDegree;
    uint8_t   u8MinHdgSpdMPH; 
    uint8_t   u8MinHdgChgDeg;
    uint8_t   u8SpdSlow;
    uint8_t   u8SpdFast;
    uint8_t   u8MaxENAccelMPHPS;
    uint8_t   u8MonitorSize;
    uint8_t   u8SettlingWindow;
    uint8_t   u8SmWindow;
    uint8_t   u8StartSamples;
} __attribute__ ((__packed__))gmDfltConfigReq;

typedef struct
{
    gmHeader  Header;
    uint8_t   pktVersion;
    uint8_t   diagCode;
    uint8_t   gmData[498]; //GM_MAX_PKT_PAYLOAD_SIZE(500) - 2 (i.e sizeof(pktVersion) + sizeof(diagCode) )
} __attribute__ ((__packed__)) gmDriverSafety_GenericPkt;
#endif

typedef struct
{
    // IP
    uint8_t versionLength;
    uint8_t TypeOfService;
    uint16_t LengthOfIpPacket;
    uint16_t PacketNumber;
    uint16_t FragmentationOffset;
    uint8_t TTL;
    uint8_t Protocol;
    uint16_t HeaderCS;
    uint32_t SourceAddress;
    uint32_t DestAddress;
    // UDP
    uint16_t SourcePort;
    uint16_t DestPort;
    uint16_t UdpLength;
    uint16_t UdpCS;
    // Data
} __attribute__ ((__packed__)) UDP_Header;

typedef struct
{
    // IP
    uint8_t versionLength;
    uint8_t TypeOfService;
    uint16_t LengthOfIpPacket;
    uint16_t PacketNumber;
    uint16_t FragmentationOffset;
    uint8_t TTL;
    uint8_t Protocol;
    uint16_t HeaderCS;
    uint32_t SourceAddress;
    uint32_t DestAddress;
    // ICMP
    uint8_t IcmpType;
    uint8_t IcmpCode;
    uint16_t IcmpChecksum;
    uint16_t IcmpID;
    uint16_t IcmpSeq;
    // Data
} __attribute__ ((__packed__)) ICMP_Header;

#define AT_COMMAND_MAX_LEN  64

typedef struct
{
    uint16_t ApiNumber;
    uint8_t CommandType;
    uint8_t OptHeaderSize;
    char AtCommand[AT_COMMAND_MAX_LEN];
} __attribute__ ((__packed__)) ATCmd_Header;

typedef struct
{
	gmHeader Header;              //12
	uint32_t EventTimeTag;        //16
    uint32_t LocationTimeTag;     //20
    uint8_t Speed;               //21
    uint8_t Heading;             //22
    int32_t Latitude;            //26
    int32_t Longitude;           //30
    uint8_t Status;              //31
	uint32_t Reserved;           //35
	char   Installer_Id[20];   //55
	char   SR_Number[20];      //75
	uint16_t ComponentIDs;       //77
	uint16_t DPF_Code;           //79
	int16_t Error_Code;         //81
}__attribute__ ((__packed__))gmPacket38Header;

typedef struct
{
	gmPacket38Header gmPacket_38Header;
	char RequestParams[512-sizeof(gmPacket38Header)];
}__attribute__ ((__packed__))gmPacket38;

typedef struct
{
	gmHeader Header;        
	uint16_t Requestor;
	uint16_t ResourceID;
	uint8_t  Count;
}__attribute__ ((__packed__))gmPacket39_Header;	

typedef struct
{
	gmPacket39_Header gmPacket39_header;
	char RequestParams[526-sizeof(gmPacket39_Header)];
}gmPacket39;

/*

Geomanager Packet Format [ Derived based on max packet data in 0xCF12 ]

---------------------------
Total Bytes          514
---------------------------

*/

#define GM_MAX_PKT_PAYLOAD_SIZE (500) // [ 508 - 8(Sequence Number(4) + Device ID (4)]

typedef struct
{
    gmIP ip;

//  Geomanager Header
    uint16_t HeaderSync;
    uint8_t  PacketID;
    uint8_t  PacketLen;
    int32_t  Sequence;
    int32_t  MobileDevID;

//  Geomanager Payload
    uint8_t  gmData[GM_MAX_PKT_PAYLOAD_SIZE];

//  Checksum
    uint16_t Checksum;

} __attribute__ ((__packed__)) gmGenericPkt;


/********* Vehicle CALIBARATION PARAMS *****************
    
    1: FuelFactor;             //Default = 1000
    2: CrankModeAndSmartTech   //Default = 0
                                    //LSB: 0:normal; 1:wait for vbat; 2-7:reserved 
                                    //MSB: Enable/disable start/stop technology
    3: EngineSize;
    4: TurboAndFuelType        //LSB: 0:non turbo; 1:turbo; 2:unknown;
    							//MSB: Fuel type
*/

typedef struct
{
    gmHeader   Header;
    uint32_t   EventTimeTag;            //16
    uint32_t   LocationTimeTag;         //20
    uint8_t    Speed;                   //21
    uint8_t    Heading;                 //22
    int32_t    Latitude;                //26
    int32_t    Longitude;               //30
    uint8_t    Status;                  //31
    uint8_t    NumOfvehicleParams;         //33
} __attribute__ ((__packed__)) gmVehicleParamsPktHeader;

typedef struct
{
    uint16_t                   id;
    uint16_t                   value;
} __attribute__ ((__packed__)) gmVehicleParamsFieldType;

#define MAX_FUEL_PARAMS      (512-sizeof(gmVehicleParamsPktHeader))/4

typedef struct
{
    gmVehicleParamsPktHeader vehicleParamsPktHeader;
    gmVehicleParamsFieldType vehicleParams[MAX_FUEL_PARAMS];
} __attribute__ ((__packed__)) gmVehicleParamsPkt;


typedef struct
{
    gmHeader Header;
    uint8_t  Version;
	uint8_t  Reserved;
	uint32_t PktBitMask[8];
	uint8_t  NumOfFeatureMasks;
	uint8_t  DriverLogFeatureMask;
	uint8_t  EatonFeatureMask;
	uint8_t  MiscFeatureMask;
    uint8_t  Padding;
    uint16_t Checksum;
} __attribute__ ((__packed__)) gmFWCapMatrixPacket;

#pragma pack()

#endif
