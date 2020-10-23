#ifndef SERIALTRANSPORTIDS_H
#define SERIALTRANSPORTIDS_H

/*!
   \file serialtransportids.hpp
   \brief Serial Transport Protocol IDs
*/

/** \addtogroup STP Serial Transport Protocol
 */
/**@{*/

/// Namespace for all Stp-related ids
//namespace SerialTransportID  {
    enum FunctionIDs {
        DISABLED = 0x00,

        ACK = 0x01,
        NAK,
        Connect,
        Disconnect,
        ReadVersion,
        ReadConfig,
        WriteConfig,
        Abort,

        // CAN  
        RequestMsgs = 0x09,
        SendMsgs,
        StartPeriodic,
        StopPeriodic,
        CreateFilter,
        DeleteFilter,
        Message,

        // J1979
        StartDiagnostics = 0x10,    // initialise a J1979 session
        RequestPending,             // outstanding request is pending
        RequestPID,                 // functional request PID from vehicle
        Request,                    // functional request from vehicle
        ReadProtocol,               // get the current session protocol
        EndDiagnostics,             // end an active J1979 session
        PhysRequestPID,             // physical request PID from vehicle
        PhysRequest,                // physical request from vehicle
        RequestRaw,                 // raw functional request from vehicle
        PhysRequestRaw,             // raw physical request from vehicle

        // Firmware Update
        FirmwareUpgrade = 0x1A,     // Firmware Upgrade command
        
        // CMS
        CMSIgnitionStatus = 0x20,   // Ignition status from the CMS box
        CMSRequest,                 // Request for data by the CMS box
        CMSSetup,                   // Used during initial vehicle installation

        // More J1979
        RequestFromEcu,             // Request PID from a set ECU
        RequestVIN,					// Request the VIN
   };

   enum ErrorCodes {
        OK,
        BadCRC
   };

   enum VersionItems {
        FirmwareVersion             = 0,
        FirmwareVariantName,
        HardwareSerialNum,
        HardwareBuildDate,
        HardwareRevisionNum,
        HardwareConfigurationNum    = 5,
        FirmwareBuildDate,
        HardwareTime,
        SoftwareReset,
        ModuleList,
        DeviceID                    = 10
   };

   enum UpgradeItems {
        UpgradeInactive = 0,
        UpgradeStart,
        UpgradeNextBlock,
        UpgradeAllBlocksIn,
        UpgradeStatusRequest,
        UpgradeCommit,
        UpgradeAbort,
        UpgradeDone,
   };

   enum UpgradeResponseCodes {
        UpgradeAck = 0,
        UpgradeNak,
        UpgradeBusy,
        UpgradeHuh,
    };

    enum ModecCommand {
        modecStartCommunication = 0,
        modecStopCommunication,
        modecSendData,
        modecToggleProgPort,
    };

    enum ModecStatus {
        modecRX_DATA = 0,
        modecTX_BUFFER_IN_USE,
        modecTX_BUFFER_FREE
    };

    enum TelematicsCommand {
		StartTelematics,
		StartTelematicsByGpsDistance,
		StartTelematicsByRoadDistance,
        RequestTelematicsSingleShot,
		StopTelematics,
		TelematicsDataTimed,
        TelematicsDataDistance,
        TelematicsDataSingleShot,
		TelematicsDataIgnOn,
		TelematicsDataIgnOff,
        TelematicsDataObdConnected
    };
//};

//namespace Components {
    enum ComponentIDs {
        Avg                 = 0,
        Can,      
        CanRx, // Not used
        KLine,
        Kwp2000,
        Lin                 = 5,
        Debug,
        CFCR,
        MGMT,
        Milcan,
        OBF                 = 10,
        Trigger,
        Snapshot,
        IO,
        PT,
        SigGW_MsgEncoder    = 15,
        Matrix,
        Modec,
        J1979,
        Upgrader,
        CMS                 = 20,
		Telematics,
		J1708,

        MaxComponentID
    };

    enum DataChannelIDs {
        CanReceive = 0,    

        MaxDataChannelID
    };

   // NOW REMEMBER TO UPDATE THE szComponentNames ARRAY IN SerialTransportIds.cpp
	extern   char* szComponentNames[];
//};

//namespace Devices {
    enum DeviceIDs {
        deviceGeneric = 0,    // Generic Device

        deviceAVG500  = 50,   // AVG500L Series
        deviceAVG540  = 54,   // AVG540
        deviceAVG550  = 55,   // AVG550

        deviceAVG600  = 60,   // AVG600 Series 
        deviceAVG650  = 65,   // AVG650 
        deviceAVG660  = 66,   // AVG660 

        deviceAVG700  = 70,   // AVG700 Series 
};
//};
/**@}*/

#endif
