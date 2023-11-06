#ifndef __GPSDEF_H__
#define __GPSDEF_H__

#define MAX_BEFORE_SPEED_CNT	 1
#define MAX_BEFORE_HEADING_CNT	 1

#ifndef RADIAN
#define		RADIAN  0.017453288
#endif
#define KM_PER_HOUR_TO_METER  0.2777777777777778  //    Km/h  ->  m/s

#define GPS_VALIDE_SIGNAL_VALUES	50

//////////////////////////////////////////////////////////////////////////
// ����ü ����
//////////////////////////////////////////////////////////////////////////

//======================================================================
// sentence id
//======================================================================
typedef enum
{
	NMEA_GPGLL = 0,
	NMEA_GPRMC,
	NMEA_GPGSA,
	NMEA_GPGGA,
	NMEA_GPGSV,
	NMEA_GPVTG,
	NMEA_MIGDR,			// 2011.08.23 Microinfinity DR/GPS Infomation
	NMEA_MSPOS,			// M&Service Position ����(Nmea ���� ��ü��)
	NMEA_NOT_USE,
	NMEA_BAD,
	NMEA_CHECKSUM_BAD,
	NMEA_MAX,
} NMEA_ID;

typedef enum
{
	NMEA_UPDATE = 0,
	NMEA_KEEP_ANGLE,
	NMEA_KEEP_ANGLE_SPEED,		// Hdop, Position ������Ʈ
	NMEA_STANDSTILL,
} NMEA_update_mode;

typedef enum
{
	WGS84,
	BESSEL
} coord_unit;

//////////////////////////////////////////////////////////////////////////

typedef struct
{
	int             year;
	int             month;
	int             day;
	int             hour;
	int             min;
	int             sec;
    int             msec;
} NMEA_DateTime;


//////////////////////////////////////////////////////////////////////////


#define	MAX_SVINFO					12

typedef struct
{
	int		nmessage;
	int		messageid;
	int		nSV;
	int		SVid[12];
	int		elevation[12];
	int		azimuth[12];
	int		db[12];
} NMEA_GSV;

typedef struct
{
	DOUBLE_VERTEX	wp;

	int		time;
	Float	latitude;
	char	NorS;
	Float	longitude;
	char	EorW;
	int		fix;
	int		nSatellite;
	Float	hdop;
	Float	altitude;
	char	unit;
	Float	altitudeofwgs84;
	char	unit2;
	Float	dgpsupdatetime;
	int		stationid;
} NMEA_GGA;

typedef struct
{
    char	mode1;  // 'M'=Manual, forced to operate in 2D or 3D, 'A'=Automatic, 3D/2D
	int		mode2;  // 1=Fix not available, 2=2D, 3=3D
	int		usedsv[12];
	Float	pdop;
	Float	hdop;
	Float	vdop;
} NMEA_GSA;

typedef struct
{
	DOUBLE_VERTEX	wp;

	int		time;
	int		datestamp;

	char	valid;
	char	NorS;
	char	EorW;
	char	EorW2;

	Float	latitude;
	Float	longitude;
	Float	speed;
	Float	angle;
	Float	variation;
} NMEA_RMC;

typedef struct
{
	int		timeType;

	char	NorS;
	char	EorW;
	char	time[20];

	Float	latitude;
	Float	longitude;
	Float	speed;
	Float	angle;
	Float	altitude;
	Float	accuracy;
    
    Int32   gpsmode;    // 1: Phone GPS 2:DRGPS

	NMEA_DateTime	dateTime;
} stNMEA_MSPOS;

typedef struct
{
	int			nTime;			// **  UTC time					140047.000					HrMinSec
	int			nSateliteCnt;	// **  Number of satellite 
	int			nFixQuality;	// **  Fix Quality				1							0 Solution Invalid, 1 Position Fix
	int			nMode2;			// **  Mode 2					3							1 Solution Invalid, 2 GPS 2D Fix, 3 GPS 3D Fix
	DOUBLE_VERTEX	wpGPS;			// **  GPS Latitude				37.5026988		dd.ddddd	WGS84(North = +, South = -)
	char		cNorS;			// **  N/S Indicator			N							N=north or S=south
	// **  GPS Longitude			127.01113420	ddd.ddddd	WGS84(East = +, West = -)
	char		cEorW;			// **  E/W Indicator			E							E=east or W=west
	DOUBLE_VERTEX	wpDR;			// **  DR/GPS Latitude			37.5026489		dd.ddddd	WGS84(North = +, South = -)
	char		cNorS_DR;		// **  N/S Indicator			N							N=north or S=south
	// **  DR/GPS Longitude			127.01112128	ddd.ddddd	WGS84(East = +, West = -)
	char		cEorW_DR;		// **  E/W Indicator			E							E=east or W=west
	Float		fAngleGPS;		// **  GPS Course				123.08			degree
	Float		fSpeedGPS;		// **  GPS Speed				004.06			m/s
	Float		fAngleDR;		// **  DR/GPS Course			133.48			degree
	Float		fSpeedDR;		// **  DR/GPS Speed				005.13			m/s
	Float		fPDOP;			// **  PDOP						04.1						Position dilution of Precision
	Float		fHDOP;			// **  HDOP						01.6						Horizontal Dilution of Precision
	int			nGyroErrorFlag;	// **  Gyro Error Flag			0							0 : Normal -> DR/GPS Mode, 1 : Error -> GPS Mode
	int			nOdometerErrorFlag;	// **  Odometer Error Flag		0							Same to Gyro Error Flag
	Float		fDRParam1;		// **  DR Parameter 1			100.23
	Float		fMeanGyroOutput;// **  Mean Gyro Output			-04.22			deg/sec
	Float		fDRParam2;		// **  DR Parameter 2			-294.06
	int			nOdometerSF;	// **  Odometer SF				02594			pulse/Km
	int			nOdometerPulse;	// **  Odometer Pulse			014							Number of pulse in the second
} stNMEA_MIGDR;

typedef struct
{
	DOUBLE_VERTEX		wp;

	int				tvas_time;		// tvas�� �ð�
	int				week;           //(1:��~7:��)
	Bool			IsNight;
	int				state;          // GPS ����
	int				extend;         // GPS Ȯ�� ���
	int				speed;	
	int				angle;
	Float			hdop;			// HDOP

	Float			fAngle;			// �������� ���� ����
    Bool            IsDRGps;        //
} NMEA_ParsedData;


typedef struct
{
	int				total_speed;
	int				sub_speed;
} NMEA_avg;

typedef struct
{
	int				hour;
	int				min;
} NMEA_suntime;

typedef struct
{
	int		daylen;
	int		morning_twilight;
	int		sunrise;
	int		noontime;
	int		sunset;
	int		evening_twilight;
} NMEA_sun;

typedef struct
{
	NMEA_ParsedData	data;
	NMEA_DateTime	datetime;
	NMEA_sun		sun;
	NMEA_avg		avg;

	NMEA_GSV		gsv;
	NMEA_GGA		gga;
	NMEA_GSA		gsa;
	NMEA_RMC		rmc;
	stNMEA_MSPOS	mspos;
	stNMEA_MIGDR    migdr;
} NMEA;

//GPS ����
typedef enum
{
	GPS_NONE = 0,               // �ʱⰪ
	GPS_PORT_UNAVAILABLE,       // port open ����
	GPS_PORT_REOPEN,            // port reopen ��
	GPS_SIGNAL_NONE,            // ��ȣ�� ���� ����
	GPS_SIGNAL_IN_BAD,          // rmc�� valid���� bad�� ���
	GPS_SIGNAL_IN_GOOD,         // rmc�� valid���� good�� ���
} NeStatusGps;

typedef enum
{
	GPS_EXTRND_NONE			= 0,
	GPS_EXTRND_OBD			= 0x0001,	// OBD ��� ����
} NeExtendGPSFlag;


//=============================================================
// 3. GPS ���� ������ �ʿ��� struct define
//=============================================================

// 3.1	���� ���� ����
typedef struct tagSVInfo
{
	Int32	nSVId;				//id
	Int32	nSVdb;				//���İ���
	Int32	nElevation;			//����
	Int32	nAzimuth;			//���Ⱒ
} SVINFO;


// 3.2	��¥.
typedef struct tagGpsDate
{
	Int32	y;	//��
	Int32	m;	//��
	Int32	d;	//��
} GPSDATE;


// 3.3 �ð�.
typedef struct tagGpsTime
{
	Int32	h;	//��
	Int32	m;	//��
	Int32	s;	//��
}GPSTIME;

// 3.4 ������.
typedef struct tagCoordWpt
{
	Int32	d;	//��
	Int32	m;	//��
	Float	s;	//��
} COORDWPT;


// 3.5 GPS ������ ����
typedef struct tagGpsSatelliteInfo
{
	NeStatusGps		eGpsState;				//GPS ���� ����
	Int32			nSVCnt;					//���� ���� ����
	SVINFO			sSVInfo[MAX_SVINFO];	//���� ���� ����
	GPSDATE			sDate;					//��¥
	GPSTIME			sTime;					//���� �ð�
	DOUBLE_VERTEX		wp;						//����ġ ��ǥ
	COORDWPT		wpCPX;					//����ġ X ��ǥ(������ ����)
	COORDWPT		wpCPY;					//����ġ Y ��ǥ
	Int32			nMode;					//�������
	Int32			nSpeed;					//�ӵ�
	Int32			nAngle;					//���� ����
	double			nAltitude;				//��
	double			dHdop;					//HDOP
} GPSSATELLITEINFO;

#if defined(_WIN32) && !defined(_WIN32_PHONE)
#define GPS_THREAD_TERMINATE_TIME 2000	// GPS ������ ����� �ִ� ��� �ð�
#define GPS_LINE_MAX_SIZE			90
#define COMM_TIMEOUT_MIN 5000
#define COMM_TIMEOUT_MAX 20000
#endif
#define GPS_READ_SIZE				4096

// GPS ���� Ÿ��
typedef enum
{
    eGpsTypeNone = 0,			// �̼���
    eGpsTypeFile,				// GPS �����带 �����Ͽ� GPS ���Ͽ��� ���� GPS ������(NMEA)�� �д´�.
    eGpsTypeWinWaitcomm,		// GPS �����带 �����Ͽ� WaitCommEvent �Լ��� �̿��Ͽ� �̺�Ʈ�� GPS ������(NMEA)�� �����Ѵ�. (�ø��� ��Ʈ ���)
    eGpsTypeWinPoling,			// GPS �����带 �����Ͽ� GPS ��Ʈ���� GPS ������(NMEA)�� Poling �Ѵ�. (�ø��� ��Ʈ ���)
    eGpsTypeInput,				// GPS �����带 �������� �ʰ� �ܺο��� GPS ������(NMEA �Ǵ� ����ü)�� �޴´�.
}NeGpsType;

// �ø��� ��Ʈ ����
typedef struct tagSerialPort
{
    Int32	nPort;
    Int32	nBaudrate;
    Bool	bEnableDTR;
}SERIAL_PORT, *PSERIAL_PORT;

// ������ GPS ������
typedef struct tagIPhoneGpsData
{
    Bool			bGood;				// ����Ƽ ����(TRUE:����, FALSE:����)
    struct NMEA_DateTimesDateTime;			// ���� ��¥, �ð�
    Double			dLatitude;			// WGS84 Degree ���� (��, 37.895231)
    Char			cLatitudeType;		// ���� 'N', ���� 'S'
    Double			dLongitude;			// WGS84 Degree ���� (��, 126.794521)
    Char			cLongitudeType;		// ���� 'E', ���� 'W'
    Float			fSpeed;				// �̵��ӵ� Km/h
    Float			fHeading;			// �̵����� 0~359
}IPHONE_GPSDATA, *PIPHONE_GPSDATA;

// GPS ���� Callback �Լ� ������
typedef Bool (*LPCALL_RECEIVEGPS)(NMEA *nmea, NMEA_ID id);

#endif //__GPSDEF_H__
