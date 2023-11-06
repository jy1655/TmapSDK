#ifndef __SGL_GPSRECEIVER_H__
#define __SGL_GPSRECEIVER_H__

#include "sgl_base.h"
#include "sgl_common.h"
#include "gpsdef.h"

class CSglGpsParser;
class CSglGpsReceiver
{
	NOT_COPYABLE(CSglGpsReceiver)
private:
	CSglGpsReceiver();
	virtual ~CSglGpsReceiver(void);

public:

	/// GPS�� �ʱ�ȭ �Ѵ�.
	/**
		@param eGpsType			[IN] GPS Ÿ��
		@param fGpsPreTime		[IN] GPS ��ǥ �̵��� �̸� ���� ��Ų��. (����, ��)
		@param lpfnCallback		[IN] GPS �����͸� ���� �ݹ� �ռ�
		@param pSerialPort		[IN] �ø��� ��Ʈ ���� (GPS Ÿ���� eGpsTypeWinWaitcomm, eGpsTypeWinPoling �϶� �� ��ȿ��)
		@param bThreadStart		[IN] Window �϶� GPS �����带 �ٷ� �������� ����
		@return					TRUE:����, FALSE:����
	**/
	Bool Init(NeGpsType eGpsType, Float fGpsPreTime, LPCALL_RECEIVEGPS lpfnCallback, PSERIAL_PORT pSerialPort = NULL, Bool bThreadStart = FALSE);

	/// GPS �����͸� �Է� �޴´�. (�ȵ���̵�)
	/**
		@param szNmea			[IN] NMEA �ؽ�Ʈ
		@param nSize			[IN] NMEA �ؽ�Ʈ ũ��
		@param bPosition		[OUT] �Է°��� GPS���� �����ϱ� ���� �ʿ��� �ּ����� �����Ͱ� �����ϴ��� ���� (�̵� ��ǥ ���� ����)
		@return					�ʸ�Ī ����(TRUE�̸� ����)
	**/
	Bool InputGpsData(Char *szNmea, Int32 nSize, Bool &bPosition);

	/// NMEA �Ľ̵� �����͸� ��´�.
	/**
		@return					NMEA*
	**/
	NMEA* GetNmeaData();

#if defined(_WIN32) && !defined(_WIN32_PHONE) && !defined(__MINGW32__)
	/// GPS �ø��� �� ���� �Ѵ�.
	/**
		@param pSerialPort		[IN] �ø��� ��Ʈ ���� (GPS Ÿ���� eGpsTypeWinWaitcomm, eGpsTypeWinPoling �϶� �� ��ȿ��)
		@return
	**/
	void SetSerialPort(PSERIAL_PORT pSerialPort);

	/// GPS �ø��� ��Ʈ�� �����͸� Write �Ѵ�.
	void SerialWrite(Byte *pBuf, Int32 nSize);

	/// GPS �����带 ���� �Ѵ�.
	/**
		@return					TRUE:����, FALSE:����
	**/
	Bool StartThread();

	/// GPS �����带 ���� �Ѵ�.
	void StopThread();
#endif

	void SetSaveLog(Bool bSave) {m_bSaveLog = bSave;};

private:
	NeGpsType m_eGpsType;
	Float m_fGpsPreTime;

public:
	CSglGpsParser*	m_pGPSParser;

	// GPS ������ Update Callback �Լ�
	LPCALL_RECEIVEGPS GPSUpdate;

	static Bool DataParser(Byte *pData, Int32 nSize, NMEA_ID &eNmeaID);
	
	static Bool CheckChar(Char c);

	// GPS Read ����
	Char m_szDollerLine[GPS_READ_SIZE+1];
	Int32 m_nLen, m_nComma;

	Bool m_bSaveLog;
	FILE *m_pFile;

#if defined(_WIN32) && !defined(_WIN32_PHONE) && !defined(__MINGW32__)

public:
	// GPS ������
	static DWORD WINAPI ReceiveProc_File(LPVOID lParam);
	static DWORD WINAPI ReceiveProc_Waitcomm(LPVOID lParam);
	static DWORD WINAPI ReceiveProc_Poling(LPVOID lParam);


	// GPS����� Open �������� üũ�Ѵ�.
	Bool IsOpenPort();

	// GPS �ø��� ��Ʈ �ڵ��� ��´�.
	HANDLE GetPortHandle();

private:
	// GPS �ø��� ��Ʈ�� ����.
	Bool OpenPort();

	// GPS �ø��� ��Ʈ�� �ݴ´�.
	void ClosePort();

	// GPS �ø��� ��Ʈ���� �����͸� �д´�.
	Int32 ReadGPS(PByte pBuffer, DWord dwMaxLength);

	// GPS ���� ������ �ڵ�
	HANDLE m_hReceiveThread;
	//������ ���� ��ų �÷���
	Bool m_bEndThread;

	//Com Port �ڵ�
	HANDLE m_hPort;
	SERIAL_PORT m_sSerialPort;


#endif

	DECLARE_SINGLETON(CSglGpsReceiver);
};


#endif // __SGL_GPSRECEIVER_H__
