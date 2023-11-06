////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __TYPEDEF_HEADER__
#define __TYPEDEF_HEADER__




#define	MAX_AREANAME		20
#define	MAX_VIEWZFROMSPEED	32		//2005.04.12
#define	MAX_MAP_NUM			5


/*
typedef struct _MV_tagRectS{
	Int16	left;
	Int16	top;
	Int16	right;
	Int16	bottom;
} MV_tagRectS;

typedef struct _MV_tagRectUS{
	UInt16	left;
	UInt16	top;
	UInt16	right;
	UInt16	bottom;
} MV_tagRectUS;

typedef struct _MV_tagAreaCodeName
{
	UInt32				uiCode;
	Int8				strName[MAX_AREANAME];
	DOUBLE_VERTEX	pt;			//��ǥ��ǥ
	Int32				iEyePosZ;	//��ü�� ���� �� �ִ� ��
}MV_tagAreaCodeName;

typedef struct _MV_tagRouteSummObj
{
	UInt8	ucLinkNode;			//��ũ1 ���2
	UInt8	ucImportance;		//�߿䵵
	UInt16	usDist;				//�Ÿ�
	UInt16	usTime;				//�ð�
	Int8*	pstrName;
}MV_tagRouteSummObj;

typedef struct _MV_tagRouteSummary
{
	UInt8	ucNum;
	MV_tagRouteSummObj* pSummary;
}MV_tagRouteSummary;




typedef struct _MV_tagRDetailSObj
{
	Int8				strRoadName[128];
	Int8				strGuide[128];
	Int32				iRmDist;
	Int32				iRmTime;
	DOUBLE_VERTEX	ptMap;
}MV_tagRDetailSObj;

typedef struct _MV_tagRouteDetailSummary
{
	UInt16					ucNum;
	Int32					iTotalDist;		//��ü��� �Ÿ�
	Int32					iTotalTime;		//��ü �ܿ��ð�
	MV_tagRDetailSObj*		pobj;
}MV_tagRouteDetailSummary;

//2005.04.12
typedef struct  {
	Int32	iViewPosZ;
	Int32	iSpeedFrom;
	Int32	iSpeedTo;
}MV_tagVZSpeedObj;

typedef struct  {
	Bool				bUse;
	Int32				nVZspeed;
	MV_tagVZSpeedObj	vzspeed[MAX_VIEWZFROMSPEED];
}MV_tagViewZFromSpeed;

typedef struct  {
	Int8	strDstName[64];		//	��������
	UInt32	TimeDisplay;		//	0: �����ð�ǥ��		,	1: �����ð�ǥ��
	UInt32	AndoService;		//	0: ���				,	1: �̻��
	UInt32	UserSpeed;			//	0: �̻��			,	1~200	����� �Է� �ӵ�
	UInt32	AndoSetting;		//	�ȵ� �ȳ� ���� : ��Ʈ�� �� ����
	UInt32	debugOption1;		//
	UInt32	debugOption2;		//
	UInt32	debugOption3;		//
}MV_tagNaviOption;


typedef struct _MAP_COORD
{
	UInt32			uiIndexX;
	UInt32			uiIndexY;
	UInt8			ucLevel;
	UInt8			ucViewLevel;
	UInt32			uix;
	UInt32			uiy;
	UInt32			uiTilex;
	UInt32			uiTiley;
} MAP_COORD;




typedef struct
{
	GPS_STATE		state;				// GPS���� (GPS_GOOD, GPS_BAD, GPS_ERROR)
	Int16			direction;			// ���ϱ��ذ��� (0 ~ 359)
	Int16			speed;				// �ӵ�(km/h)
	POSITION_TYPE	position;			// ������, ��ǥŸ��
	TIME_INFO		gpsTime;			// �ð�
	Int16			mode;				// mode//�������
	Int16			satelliteNum;		// ���� ��
	Int16			hdop;				// horizontal dilution of precision. X10 �Ǿ� ����.
	KIT_VERSION		kitVersion;			// kit ����
	UInt32			nCount;				//������ ����
	UInt32			size;				// GPS ���� ������
	Int8			*buf;				// GPS ���� ����.
} GPS_INFO1;


typedef struct
{
	Int32			x;					//	������, ��ǥŸ��
	Int32			y;					//	������, ��ǥŸ��
	Int32			gpsTime;			//	�ð� (2003��1��1�Ϻ��� �ʴ���)
	Int16			direction;			//	���ϱ��ذ��� (0 ~ 359)
	Int16			speed;				//	�ӵ�(km/h)
	Int8			satelliteNum;		//	���� ��
	Int8			mode;				//	mode	(�������)
	Int16			hdop;				//	horizontal dilution of precision. X10 �Ǿ� ����.
} GPS_INFO_ONE;


typedef struct
{
	Int8	mapType;
	Int8	highway;
	Int8	destName[128];
	Int32	destDirection;
	Int32	routingOption;
	UInt8	positionByte[8];
	UInt8	POI_ID[10];
	UInt8	MPP_NSL;
} SAVE_ROUTINGINFO;



//#ifdef _WIN32_
typedef struct
{
	DOUBLE_VERTEX ptCrt;
	DOUBLE_VERTEX ptDest;

	Int32	iAngle;
	Int32	iTBT;
	Int32	iNextTBT;
	Int8	strCrossName[128];
	Int8	strDirName[128];
	Int8	strRoadName[128];
	Int8	strAreaName[128];

	Int32	iLastMMState;
	Int32	iRGState;

	Int32	iSafeImg;			//�������� ������
	Int32	iSafeDist;			//��ġ�������� �Ÿ�
	Int32	iSafeImgType;
	Int32	iSafeImgSpeed;


	UInt8	bVoice;
	UInt32	uiVoiceType;
	UInt32	uiVoiceTypeNext;
	UInt8	ucVoiceDist;
	UInt32	uiVoiceOption;

	Int32	iDstlTime;
	Int32	iDstDist;
	Int32	iCrtDist;

	Int32	bHiwayMode;
	MV_tagRestInfo restInfo[MAX_RESTINFO];

	Int32	bComplexCross;
	Int8	pstrCmplxCrossImgFName[64];
	Int32	iCmplxCross;

	UInt8			bLaneInfo;
	TsRGLaneInfo	laneInfo;
	UInt8			bTIInfo;
	TsTIInfo		tiInfo;
	UInt32			uiLinkID;


}MV_tagRGinfo;
//#endif

typedef struct
{
	Int32	iVer;
	Int32	iSize;
}MV_tagFVerSize;//������ ������


typedef struct
{
	Int32	iVerNAVI;
	Int32	iVerM2DAL;

	MV_tagFVerSize	fverMCfg;
	MV_tagFVerSize	fverMmap[MAX_MAP_NUM];
}MV_tagVersionInfoINI;

*/



#define		MCFG_VER								0x00050026


#define MV_ERR_DALLOAD_FAIL			-1
#define MV_ERR_MCFGLOAD_FAIL		-2
#define MV_ERR_MAPLOAD_FAIL			-3
#define MV_ERR_SAFEDATA_LOAD_FAIL	-4
#define MV_ERR_RESDATA_LOAD_FAIL	-5

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#define NULL				0
#define TRUE				1
#define FALSE				0

#ifndef PI
#define PI					3.14159265358979323846f
#endif

#define HALF_PI				1.57079632679489661923f

#define ONE_PER_PI			0.31830988618379067153803535746773f			// (1 / PI)
#define ONE_PER_180			0.0055555555555555555555555555555556f		// (1 / 180)

#define PT_IN_RECT(rc,x,y)	((rc).left <= (x) && (x) <= (rc).right && \
								(rc).top <= (y) && (y) <= (rc).bottom)

#define PT_IN_RECTEX(a,b,c,d,x,y) ((a) <= (x) && (x) <= (c) && \
								(b) <= (y) && (y) <= (d))

#define FILE_E_ERROR		  -1
#define FILE_E_NOENT		  -1
#define FILE_E_BADFILENAME	  -1
#define FILE_E_LONGNAME		  -1
#define FILE_E_INVALID		  -1
#define FILE_E_NOSPACE		  -1
#define FILE_E_ACCESS		  -1
#define FILE_E_DEVCLOSE		  -1

#define FILE_E_BADFD		  -1
#define FILE_E_EOF			  -1
#define FILE_E_BADSEEKPOS	  -1

#ifdef _OS_WIN32
   #define SIZE_MAP_PATH 0xff
   #define SIZE_FILE_PATH 0xff
#else
   #define SIZE_MAP_PATH 128
   #define SIZE_FILE_PATH 128
#endif
#if 0
typedef struct
{
   Int8* map1; // base map
   Int8* map2; // poi map
   Int8* map3; // area map
   Int8* map4; // area idx
   Int8* map5; // area idx2
   Int8* mapcfg; // map config
   Int8* mapcfgcross; // map config ������ Ȯ�뵵��
   Int8* ver; // map version

   Int8* tbt; // s/res1
   Int8* etc; // s/res3
   Int8* snd; // v/res2
   Int8* avtimg; // a/chr_005.avt , default avata
   Int8* avt; // a , only path
   Int8* landmark; // i/res4
   Int8* landmark2; // sktmap/rmap

   Int8* safemap; // ndrive/ndsafe.dat
   Int8* safemapchange; // ndrive/ndsafech.dat
   Int8* safeidx; // ndrive/ndsafe.idx
}DAL_tagPathInfo;

typedef struct  {
	UInt16		usVerx;		//DOUBLE_VERTEX x
	UInt16		usVery;		//DOUBLE_VERTEX y
}MV_tagTrInfoVertex;

typedef struct  {
	UInt16		usVertexNum;	//DOUBLE_VERTEX ����
	UInt32		uiOffset;		//DOUBLE_VERTEX offset
}MV_tagTrInfoRoadEle;

typedef struct  {
	UInt8		ucJam;			//ȥ�⵵
	UInt16		usTime;			//����ð�
	UInt8		ucSpeed;		//��ռӵ�
	UInt8		ucDir;			//RE ���� (��, ��)
	UInt32		uiOffset;		//RE offset
	UInt32		uiStartIndex;	//���ؽ� ���� �ε���
	UInt32		uiVerNum;		//���ؽ� ���� �ε���
}MV_tagTrInfoLink;


typedef struct  {
	Int32 ngp;
	Int32 nlink;
	Int32 nname;
	Int32 nv;
	Int32 nCross;
	Int32 nSub;
	Int32 nAndo;
	Int32 nLaneInfo;
	Int32 nTIInfo;
	Int32 nTGateInfo;
	Int32 nTotalSize;



	void* pMemBase;
	void* pgp;
	void* plink;
	void* pname;
	void* pv;
	void* pCross;
	void* pSub;
	void* pAndo;
	void* pLaneInfo;
	void* pTIInfo;
	void* pTGateInfo;


	Int32 nTvasVer;
	Int32 bUse;
	Int8 pcDestName[256];
	Int32 iStartX;
	Int32 iStartY;
	Int32 iDestX;
	Int32 iDestY;


}MV_tagTvasDataPoint;
#endif









#define DIST_ROUTE_OUT	50		// ��� ��Ī�� ���� �ʰ� GPS ������ ��Ī�ϱ� ���� �Ÿ�

//#define SAVE_ROUTE_MAX	250		// ��� ���� �ִ� ����
#define SAVE_ROUTE_MAX	50

#pragma pack(1)	//--------------------------------------- �������
#if 0
typedef struct
{
	char				posName[64];		//  ��Ī
	DOUBLE_VERTEX	posWpt;				//	��ǥ
	char				rpFlag;				//	RP Flag
	UInt32				iPoiID;				//  POI ID
	UInt16				ByteAlignedPed;		//
} RoutePosition;

typedef struct
{
	char				routeName[64];		//  ���� ��Ī
	Int32				routeOption;		//	Ž�� �ɼ�
	RoutePosition		routePos[5];		//	�����, ������1, ������2, ������3, ������
} RouteList;
#endif
#pragma pack()	//--------------------------------------- �������



#define SWAP(a, b) a^=b^=a^=b

#ifndef __IPHONEOS__
	#define SWAP3(a, b, c) {c = a; a = b; b = c;}
#endif

#ifndef ON
#define ON 1
#endif
#ifndef OFF
#define OFF 0
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif


#define DRAW_RUN_MASK 0x00000001

#if defined(_OS_WINCE) || defined(_OS_WIN32) // Open pointers test.

#pragma warning( disable : 4530 )
#pragma warning( disable : 4996 ) // implicit type casting possible data loss

#endif

#endif // __TYPEDEF_HEADER__
