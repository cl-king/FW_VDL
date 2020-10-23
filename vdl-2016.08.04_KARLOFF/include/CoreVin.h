#ifndef _CORE_VIN_H_
#define _CORE_VIN_H_

//------------------------------------------------------------------------------
// INCLUDES                                                         
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// DEFINES                                                         
//------------------------------------------------------------------------------

// VIN WMI definitions
#define VIN_WMI_OFFSET                      0       // Starting location of the VIN WMI characters 
#define VIN_WMI_LENGTH                      3       // Length of the VIN WMI
#define VIN_CHECK_DIGIT_OFFSET              8       // VIN check digit, may not be valid outside North America
#define VIN_US_MODEL_YEAR_OFFSET            9       // Year code for North American vehicles (UK is different)
#define VIN_US_MIN_MODEL_YEAR               2008

#define CORE_VIN_SIZE                       17

// VIN year codes
#define VIN_US_MODEL_YEAR_2008              ('8')
#define VIN_US_MODEL_YEAR_2009              ('9')
#define VIN_US_MODEL_YEAR_2010              ('A')
#define VIN_US_MODEL_YEAR_2011              ('B')
#define VIN_US_MODEL_YEAR_2012              ('C')
#define VIN_US_MODEL_YEAR_2013              ('D')
#define VIN_US_MODEL_YEAR_2014              ('E')
#define VIN_US_MODEL_YEAR_2015              ('F')
#define VIN_US_MODEL_YEAR_2016              ('G')
#define VIN_US_MODEL_YEAR_2017              ('H')
#define VIN_US_MODEL_YEAR_2018              ('J')
#define VIN_US_MODEL_YEAR_2019              ('K')
#define VIN_US_MODEL_YEAR_2020              ('L')
#define VIN_US_MODEL_YEAR_2021              ('M')
#define VIN_US_MODEL_YEAR_2022              ('N')
#define VIN_US_MODEL_YEAR_2023              ('P')
#define VIN_US_MODEL_YEAR_2024              ('R')
#define VIN_US_MODEL_YEAR_2025              ('S')
#define VIN_US_MODEL_YEAR_2026              ('T')
#define VIN_US_MODEL_YEAR_2027              ('V')
#define VIN_US_MODEL_YEAR_2028              ('W')
#define VIN_US_MODEL_YEAR_2029              ('X')
#define VIN_US_MODEL_YEAR_2030              ('Y')

#define UNKNOWN_MODEL_YEAR                  0

//----------------------------------------------------------------------------------------
// Chrysler vehicle codes
//
#define CHRYSLER_VEHICLE_TYPE_VIN_OFFSET    4
#define CHRYSLER_VEHICLE_TYPE_VIN_LENGTH    2
#define RAM_PROMASTER                       ("RV")

//----------------------------------------------------------------------------------------
// Fiat vehicle codes
//
#define FIAT_WMI                            ("ZFA") // WMI assigned to Fiat
#define FIAT_VEHICLE_TYPE_VIN_OFFSET        3       // Vehicle type offset within the VIN
#define FIAT_VEHICLE_TYPE_VIN_LENGTH        3       // Characters to check for VIN type
#define FIAT_DOBLO_GEN1                     ("223") // Fiat Doblo 1.3L
#define FIAT_DOBLO_GEN2                     ("263") // Fiat Doblo 1.6L
#define FIAT_DUCATO                         ("250") // Fiat Ducato

//----------------------------------------------------------------------------------------
// Ford vehicle definitions
//
#define FORD_EF_SERIES_INCOMPLETE_VEH_WMI   ("1FD") // Could be an E or F series incomplete vehicle (i.e. cutaway van or truck cab with bare chassis)
#define FORD_EF_SERIES_COMPLETE_VEH_WMI     ("1FT") // Could be an E or F series complete vehicle (i.e. Econoline van or F-x50 truck

#define FORD_EF_SERIES_CHASSIS_TYPE_OFFSET  4       // VIN offset for the chassis code
#define FORD_E_SERIES_REGULAR               ('E')   // Regular length Econoline van
#define FORD_F_SERIES_REG_CAB               ('F')   // Regular cab F series truck
#define FORD_E_SERIES_EXTENDED              ('S')   // Extended length Econoline van
#define FORD_F_SERIES_SUPER_CREW            ('W')   // Super Crew F series truck
#define FORD_F_SERIES_SUPER_CAB             ('X')   // Super Cab F series truck

#define FORD_TRUCK_CLASS_OFFSET             5       // VIN offset for the truck class code
#define FORD_TRUCK_CLASS_150                ('1')   // Ford 150
#define FORD_TRUCK_CLASS_250                ('2')   // Ford 250
#define FORD_TRUCK_CLASS_350                ('3')   // Ford 350
#define FORD_TRUCK_CLASS_450                ('4')   // Ford 450
#define FORD_TRUCK_CLASS_550                ('5')   // Ford 550

#define FORD_TRUCK_ENGINE_CODE_OFFSET       7       // VIN offset for the engine code

// E-series engine codes
#define FORD_E_SERIES_ENGINE_4600_GAS       ('W')   // 2008-2014
#define FORD_E_SERIES_ENGINE_5400_GAS       ('L')   // 2008-2016
#define FORD_E_SERIES_ENGINE_6000_DIESEL    ('P')   // 2008-2009
#define FORD_E_SERIES_ENGINE_6800_GAS       ('S')   // 2008-2016

// F-150 engine codes
#define FORD_F150_ENGINE_2700_GAS           ('P')   // 2015
#define FORD_F150_ENGINE_3500_G_GAS         ('G')   // 2015
#define FORD_F150_ENGINE_3500_T_GAS         ('T')   // 2011-2014
#define FORD_F150_ENGINE_3500_8_GAS         ('8')   // 2015
#define FORD_F150_ENGINE_3700_GAS           ('M')   // 2011-2014
#define FORD_F150_ENGINE_4200_GAS           ('2')   // 2008
#define FORD_F150_ENGINE_4600_W_GAS         ('W')   // 2008-2010
#define FORD_F150_ENGINE_4600_8_GAS         ('8')   // 2009-2010
#define FORD_F150_ENGINE_5000_GAS           ('F')   // 2011-2016
#define FORD_F150_ENGINE_5400_5_GAS         ('5')   // 2008
#define FORD_F150_ENGINE_5400_GAS           ('V')   // 2008-2010
#define FORD_F150_ENGINE_6200_GAS           ('6')   // 2010-2014

// F-250 engine codes
#define FORD_F250_ENGINE_5400_GAS           ('5')   // 2008-2010
#define FORD_F250_ENGINE_6200_GAS           ('6')   // 2011-2016
#define FORD_F250_ENGINE_6400_DIESEL        ('R')   // 2008-2010
#define FORD_F250_ENGINE_6700_DIESEL        ('T')   // 2011-2016
#define FORD_F250_ENGINE_6800_GAS           ('Y')   // 2008-2010

// F-350 engine codes
#define FORD_F350_ENGINE_5400_GAS           ('5')   // 2008-2010
#define FORD_F350_ENGINE_6200_GAS           ('6')   // 2011-2016
#define FORD_F350_ENGINE_6400_DIESEL        ('R')   // 2008-2010
#define FORD_F350_ENGINE_6700_DIESEL        ('T')   // 2011-2016
#define FORD_F350_ENGINE_6800_GAS           ('Y')   // 2008-2010

// F-450 engine codes
#define FORD_F450_ENGINE_5400_GAS           ('5')   // 2008-2010
#define FORD_F450_ENGINE_6400_DIESEL        ('R')   // 2008-2010
#define FORD_F450_ENGINE_6700_DIESEL        ('T')   // 2011-2016
#define FORD_F450_ENGINE_6800_GAS           ('Y')   // 2008-2016

// F-550 engine codes
#define FORD_F550_ENGINE_5400_GAS           ('5')   // 2008-2010
#define FORD_F550_ENGINE_6400_DIESEL        ('R')   // 2008-2010
#define FORD_F450_ENGINE_6700_DIESEL        ('T')   // 2011-2016
#define FORD_F550_ENGINE_6800_GAS           ('Y')   // 2008-2016

//----------------------------------------------------------------------------------------
// Peugeot vehicle codes
//
#define PEUGEOT_VEHICLE_TYPE_VIN_OFFSET     3       // Vehicle type offset within the VIN
#define PEUGEOT_EXPERT                      'X'     // Examples VF3XU9H..., VF3XVAH...
#define PEUGEOT_PARTNER                     '7'     // Example VF37A9HN0..... 

//------------------------------------------------------------------------------
// TYPEDEFS                                                         
//------------------------------------------------------------------------------

typedef enum
{
    unknownVehicle,
    fiatDobloGen1,                   // Doblo First Gen 2000 - 2009
    fiatDobloGen2,                   // Doblo Second Gen 2010+
    fiatDucato,
    fordESeries,
    fordFSeries,
    fordTransitConnectT200,
    fordTransitTdci,
    gmcAcadia,
    peugeotExpert,
    peugeotPartner,
    ramPromaster,
    vwCaddy
}eVehicleType;

typedef enum
{
    mfgUnknown,
    mfgChrysler,
    mfgFiat,
    mfgFord,
    mfgGeneralMotors,
    mfgMazda,
    mfgPeugeot,
    mfgToyota,
    mfgVolkswagen
}eVehicleManufacturer;

typedef struct
{
    eVehicleManufacturer make;
    eVehicleType model;
    uint32_t class;
    uint32_t engine;
    uint16_t year;
    char vin[CORE_VIN_SIZE + 1];
}sVehicleInfo;

//------------------------------------------------------------------------------
// PROTOTYPES                                                         
//------------------------------------------------------------------------------

int1_t CORE_VWCaddyVinDetection(void);
void CORE_VinUpdateVehicleType(void);
void CORE_VinGetVehicleInfo(sVehicleInfo *vehicleInfo);
int1_t CORE_VinIsValid(void);
int1_t CORE_VinSegmentIsValid(const char *vinSeg, int vinSegLen);
void CORE_VinUpdateBusVin(char *busVin);
int1_t CORE_VinBroadcastVinAvailable(void);
int1_t CORE_VinIsCheckDigitValid(char *vin);

#endif
