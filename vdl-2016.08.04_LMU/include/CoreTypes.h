#ifndef __CORE_TYPES_H_
#define __CORE_TYPES_H_

// IDs for GetParamValue() / IsParamSupported()
#define CORE_PARAM_PING_DURATION				(0)			// seconds (since last ping)
#define	CORE_PARAM_ROAD_SPEED					(1)			// kph
#define CORE_PARAM_ENGINE_RPM					(2)			// rpm
#define CORE_PARAM_FUEL_USED					(3)			// ml
#define CORE_PARAM_FUEL_PER_SEC					(4)			// ml/s
#define CORE_PARAM_ACCELERATION					(5)			// m/s^2
#define CORE_PARAM_DECELERATION					(6)			// m/s^2
#define CORE_PARAM_DIST_TRAVELED				(7)			// m (since last ping)
#define CORE_PARAM_FUEL_LEVEL					(8)			// %
#define CORE_PARAM_ODOMETER						(9)			// km
#define CORE_PARAM_DTC_COUNT					(10)		// number of DTCs
#define CORE_PARAM_MIL_STATUS					(11)		// Bitfield of MIL lamps (J1939, single bit for J1979)
#define CORE_PARAM_SERVICE_DISTANCE				(12)		// distance to next service (km)
#define CORE_PARAM_TACHO_INFO					(13)		// As per J1939 TCO1 first 4 bytes
#define CORE_PARAM_VEHICLE_WEIGHT				(14)		// kg
#define CORE_PARAM_FUEL_CALC_METHOD				(15)		// From FuelCalcStatus enum
#define CORE_PARAM_DIST_CALC_METHOD				(16)		// From FuelCalcStatus enum
#define CORE_PARAM_ACCEL_PED_POS				(17)		// %
#define CORE_PARAM_ENGINE_LOAD					(18)		// %
#define CORE_PARAM_CRUISE_STATUS				(19)		// Bitfield
#define CORE_PARAM_PTO_STATUS					(20)		// Bitfield
#define CORE_PARAM_ENGINE_COOLANT_TEMP			(21)		// degrees Centigrade
#define CORE_PARAM_TORQUE						(22)		// % Mamimum
#if KARLOFF                             	
#define CORE_PARAM_TOTAL_FUEL_ACCUM				(23)		// Total accumulated fuel ml
#define CORE_PARAM_COOLANT_LEVEL				(24)        // coolant level   %
#define CORE_PARAM_OIL_LEVEL					(25)        // oil level         %
#define CORE_PARAM_BATTERY_VOLTAGE				(26)		// battery voltage    v
#define CORE_PARAM_TOTAL_ENGINE_HOUR			(27)		// total engine hour   hour
#define CORE_PARAM_ROAD_SPEED_LIMIT				(28)		// Road Speed Limit    km/h 
#define CORE_PARAM_CRUISESET_SPEED_LIMIT		(29)		//  Cruise Control High Set Limit Speed   km/h 
#define CORE_PARAM_BOOST_PRESSURE				(30)		// Boost Pressure   kPa
#define CORE_PARAM_OIL_PRESSURE					(31)		// Oil Pressure   kPa
#define CORE_PARAM_AIRINLET_PRESSURE			(32)		// Air Inlet Pressure    kPa 
#define CORE_PARAM_EXHAUST_PRESSURE				(33)		//  Exhaust Pressure  kPa
#define CORE_PARAM_FUEL_PRESSURE				(34)		// Fuel Pressure       kPa
#define CORE_PARAM_OIL_TEMP						(35)		//  Oil Temperature   degrees Centigrade
#define CORE_PARAM_FUEL_TEMP					(36)		//  Fuel Temperature   degrees Centigrade
#define CORE_PARAM_EXHAUST_TEMP					(37)		//  Exhaust Temperature  degrees Centigrade
#define CORE_PARAM_AIRINLET_TEMP				(38)		//  Air Inlet Temperature   degrees Centigrade
#define CORE_PARAM_TRANS_FLUID_TEMP				(39)		// Transmission Fluid Temperature  degrees Centigrade
#define CORE_PARAM_TRANS_INPUT_SPEED			(40)		// Transmission Input Speed   RPM
#define CORE_PARAM_TRANS_OUTPUT_SPEED			(41)		//  Transmission Output Speed  RPM

// Range selected by the operator. Characters may include P, Rx, Rx-
// 1...R2, R1, R, Nx, Nx-1...N2, N1, N, D, D1, D2..., Dx, L, L1, L2..., Lx-1, 1, 2, 3,... If only one displayed
// character is required, the second character shall be used and the first character shall be a space (ASCII 32) or
// a control character (ASCII 0 to 31). If the first character is a control character, refer to the manufacturer's
// application document for definition.
#define CORE_PARAM_GEAR_SELECTED				(42)		//  Gear Selected

// Range currently being commanded by the transmission control system.
// Characters may include P, Rx, Rx-1...R2, R1, R, Nx, Nx-1...N2, N1, N, D, D1, D2..., Dx, L, L1, L2..., Lx-1, 1, 2,
// 3,... If only one displayed character is required, the second character shall be used and the first character shall
// be a space (ASCII 32) or a control character (ASCII 0 to 31). If the first character is a control character, refer
// to the manufacturer's application document for definition.
#define CORE_PARAM_GEAR_OBTAINED 				(43)   // Gear Obtained
// CORE_PARAM_LAMP_STATUS
//Byte: 1 bits 7-6 Malfunction Indicator Lamp Status 
//	bits 5-4 Red Stop Lamp Status See 
//	bits 3-2 Amber Warning Lamp Status See 
//	bits 1-0 Protect Lamp Status See 5.7.1.4
//Byte: 2 bits 7-6 Flash Malfunction Indicator Lamp 
//	bits 5-4 Flash Red Stop Lamp 
//	bits 3-2 Flash Amber Warning Lamp 
//	bits 1-0 Flash Protect Lamp 
//Byte: 3 bits 3-2 ABS warning lamp
//	bits 1-0 Parking Break status	
#define CORE_PARAM_LAMP_STATUS 					(44)   // Lamp Status for J1939 & J1587 
// CORE_PARAM_DPF_STATUS 
// Byte 1:
//   bits 1-0 Diesel Particulate Filter Active Regeneration Status
//         00 not active
//         01 active
//         10 regeneration needed - automatically initiated active regeneration imminent
//         11 not available
//   bit2 4-2 Diesel Particulate Filter Status  SPN 3701
//         000 Regeneration not needed
//         001 Regeneration needed - lowest level
//         010 Regeneration needed - moderate level
//         011 Regeneration needed - highest level
//         100 reserved for SAE assignment
//         101 reserved for SAE assignment
//         110 reserved for SAE assignment
//         111 not available
#define CORE_PARAM_DPF_STATUS			(45)  // Diesel Particulate Filter Status, PGN 64892
#define CORE_PARAM_ENGINE_TOTAL_FUEL_USED				(46)			// Liter,  Engine Total Fuel Used, PGN 65257, spn 250, or PID 250
#define CORE_PARAM_TOTAL_ENGINE_PTO_FUEL_USED				(47)			// Liter, Total Engine PTO Governor Fuel Used, PGN 65203 spn 1028 
#define CORE_PARAM_TOTAL_ENGINE_IDLE_FUEL_USED				(48)			// Liter
#define CORE_PARAM_ODOMETER_ESTIMATED			(49)		// Estimated odometer
#define CORE_PARAM_ACCU_DIST_BET_BUS_SAMPLES	(50)		// Estimated odometer
#define CORE_PARAM_SPEED_METHOD					(51)
#define CORE_PARAM_ENG_RUNTIME_METHOD			(52)		// Engine runtime method
#define CORE_PARAM_ESTIMATED_ENG_RUNTIME		(53)		// Estimated runtime in seconds
#define CORE_PARAM_RAW_VEHICLE_SPEED            (54)		// Used for GPS sanity only, use CORE_PARAM_ROAD_SPEED for speed
#define CORE_PARAM_FUEL_USED_SINCE_BOOTUP       (55)        // fuel used since VDL start up, in ml

#define CORE_PARAM_MAX_PARAM					(55)		// Maximum param number

#else
#if defined(__TARGET_AVG660) || defined(__TARGET_TM3000)
#define CORE_PARAM_ACCEL_X              (23)		// G
#define CORE_PARAM_ACCEL_Y              (24)		// G
#define CORE_PARAM_ACCEL_Z              (25)		// G
#define CORE_PARAM_MAX_PARAM			(25)		// Maximum param number
#else
#define CORE_PARAM_MAX_PARAM			(22)		// Maximum param number
#endif
#endif

#define CORE_PARAMS_N_ELEMENTS          (CORE_PARAM_MAX_PARAM + 1)  // Number of array elements, CoreValues

// Bus connection options
#define CP_DONT_CLEAR_DTCS              (false)
#define CP_CLEAR_DTCS                   (true)
#define CP_J1939_START_NORMAL           (false)
#define CP_J1979_START_PASSIVE          (true)
#define CP_CLEAR_GPS_PARAMS             (false)
#define CP_PRESERVE_GPS_PARAMS          (true)

// Status of core parameter value
#define CP_PARAM_INVALID                (false)
#define CP_PARAM_VALID                  (true)

#define CORE_PARAM_UNASSIGNED			255			// MID or method not set (unassigned/auto detect)
#define UNASSIGNED_MID_VALUE            (CORE_PARAM_UNASSIGNED)

#define CORE_INVALID_16_BIT             0xFFFF      // Used as an invalid falg for 16 bit params

#ifdef __INCLUDE_COREPARAMS_DTCS
#define CORE_MAXIMUM_DTCS_STORED        (20)
#endif /* __INCLUDE_COREPARAMS_DTCS */

#define ODOMRES_1000m					(1000.0)		//in meters
#define ODOMRES_1600m					(1609.0)

#ifdef _VDL_GPS_FALLBACK_ENABLE
#define CORE_GPS_FALLBACK_TIME			(5000)		// Fall back to GPS speed if bus speed age is >
#define CORE_GPS_FALLBACK_LOCK_TIME		(120000)	// Stick with GPS speed/odometer if no bus values for this long
#endif

// Estimated runtime calculation definitions
#define ESTIMATED_RUNTIME_RPM_THRESH	400		// Engine running RPM threshold
#define ESTIMATED_RUNTIME_RPM_MAX_AGE	5000	// Age in ms

#define CP_HDV_BUS_ODO_TIMEOUT          (30000)     // 30s timeout for heavy duty odometer

// Broadcast odometer method throttling
#define TIMING_BROADCAST_DELAY		500			// Milliseconds - one broadcast message allowed per interval
#define VIN_INFO_BROADCAST_DELAY    100         // Milliseconds - one broadcast VIN message per this interval

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/
typedef enum
{	
	CoreNotConnected,
	CoreConnectedJ1979,
	CoreConnectedJ1939,
    CoreConnectedJ1587,
	CoreConnectedVauxhallKWP,
	CoreConnectedFordSCP,
	CoreConnectedGpsIgn,
    CoreConnectedJ1939J1587,
	
} CoreStatus;

typedef enum 
{
	FuelCalcNoData,
	FuelCalcFromVehicle,
	FuelCalcPetrolMAF,
	FuelCalcPetrolMAP,
	FuelCalcDieselMAF,
	FuelCalcDieselMAP,
	FuelCalcFromUsedFuel,
	FuelCalcFromUsedTripFuel,
} FuelCalcStatus;

typedef enum 
{
	DistCalcNoData,
	DistCalcFromVehicle,			// Heavy duty high resolution
	DistCalcVehicleSpeed,
	DistCalcGPS,
	DistCalcFromVehicleLowRes,		// Heavy duty low resolution
	DistCalcFordPwm,				// Light duty Ford J1850 PWM
	DistCalcFordCan6182,			// Light duty Ford CAN (Param 6182)	
	DistCalcGmVpw,					// Light duty GM J1850 VPW
	DistCalcChryslerTruckCan,		// Light duty Chrysler CAN (a few trucks)
	DistCalcChryslerCarTruckCan,	// Light duty Chrysler CAN (most cars and trucks)
	DistCalcFordCan404C,			// Light duty Ford CAN (Param 404C)
	DistCalcFordCanDD01PCM,			// Light duty Ford CAN (Param DD01) from PCM
	DistCalcFordCanDD01GEM,			// Light duty Ford CAN (Param DD01) from GEM
	DistCalcFordCan6182LowRes,		// Light duty Ford CAN (param 6182) low resolution
	DistCalcGmCan120,               // Light duty GM CAN 0x120
	DistCalcToyotaCan611,           // Light duty Toyota CAN 0x611
	DistCalcFordCan6180IPC,         // Light duty European Ford CAN, 1/10 km
	DistCalcFordCan6180PCM,         // Light duty European Ford CAN, 1/10 mile
	DistCalcFordCan430_1,           // Light duty Ford CAN, broadcst 0x430 type A
	DistCalcFordCan430_2,           // Light duty Ford CAN, broadcst 0x430 type B
	// ^^ Add new entries above here, be sure to update odoCalcMethodStrings, OdomMethod and methodTypes ^^
	DistCalcMaxMethods,
	DistCalcAutoSelect = 254		// Used to auto detect when multiple methods possible
} DistCalcStatus;

typedef enum
{
	SpeedCalcNoData,
	SpeedCalcVehicleSpeed,
	SpeedCalcGPS
}SpeedCalcStatus;

typedef enum
{
	RuntimeCalcNoData,
	RuntimeCalcDerived,
	RuntimeCalcJ1939,
	RuntimeCalcJ1587,
	RuntimeCalcFordCanF47F_PCM,
	RuntimeCalcFordCanF47F_IPC,
	RuntimeCalcFordCan6103_3Byte,
	RuntimeCalcFordCan6103_4Byte,
	RuntimeCalcJ1979Can7F,
	// ^^ Add new entries above here, be sure to update RuntimeCalcMethodStrings and 
	// VD_PARAM_ENG_RUNTIME_SOURCE_SHORT_STR handler ^^
	RuntimeCalcMaxMethods,
	RuntimeCalcAutoSelect = 254		// Used to auto detect when multiple methods possible	
}RuntimeCalcStatus;

typedef enum
{
	TurboNone,
	TurboEquipped,
	TurboUnknown,
	TurboInvalid
} TurboType;

typedef enum
{
	FuelTypeDiesel,
	FuelTypeGasoline,
	FuelTypeNaturalGas,
	FuelTypeNA,
	FuelTypeInvalid
} FuelTypes;
typedef enum
{
	ParamSourceUnknown = 0,
    ParamSourceGps = 1,
	ParamSourceJ1587 = 2,
	ParamSourceJ1979 = 3,
	ParamSourceJ1939 = 4,
	ParamSourceMax = 5
}ParamSource;

// The type of bus conflicts that might be encountered
typedef enum {
    CONFLICT_STATE_NORMAL,                  // The bus is not in the conflict state
    CONFLICT_STATE_BUS_CONFLICT,            // Bus in conflict state due to scan tool like traffic
    CONFLICT_STATE_DPF_REGEN_CONFLICT       // Bus in conflict state due to a diesel particulate filter regeneration in progress
}teConflictState;

#define     ClearFaultStatusINIT  0  // 0 clear fault request not sent. This is the initialized value.
#define     ClearFaultStatusSENT  1  // 1 clear fault request sent. When the clear fault message is sent to bus, it is set to 1.
#define     ClearFaultStatusACK   2  // 2 ACK received. When an ACK is received, the corresponding fault's clear_status is set to 2.
#define     ClearFaultStatusNACK  3  // 3 NACK received. When a NACK is received, the corresponding fault's clear_status is set to 3. 

#endif
