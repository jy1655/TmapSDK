#ifndef _sgl_interface_platform_h
#define _sgl_interface_platform_h

#include <stdio.h>
#include "sgl_base.h"
#include "sgl_begin_code.h"

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
extern "C" {
	/* *INDENT-ON* */
#endif

/////////////////////////////////////////////////////////////
// �÷��� ���� �Լ� ȣ��
/////////////////////////////////////////////////////////////

//Native �����ڵ�
typedef enum
{
	NATIVE_ERROR_NOTMAPDB				= -1, //Map DB�� �������� ����
	NATIVE_ERROR_RESOLUTION				= -2, //ȭ�� �ػ󵵰� ���� ����
	NATIVE_ERROR_UNSUPPORTED_DEVICE		= -3, //�������� �ʴ� �ܸ���
}eNativeErrorCode;

//Native �޼��� �ڵ�
typedef enum
{
	NATIVE_MSG_WPCM_CONNECT			= 1,	//���� ����� ���(��ϵ� AP ����)
	NATIVE_MSG_WPCM_DISCONNECT,				//���� ����
	NATIVE_MSG_WPCM_EXIT,					//WPCM ����
}eNativeMsgCode;

//�� ��ȣ ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetPhoneNumber(char *szPhoneNumber, int nSize);
//�ܸ��� ID ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceID(char *szDeviceID, int nSize);
//�ܸ��� �̸� ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceName(char *szDeviceName, int nSize);
//��Ʈ��ũ �� ��巹�� ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetNetworkMacAddress(char *szNetworkMacAddress, int nSize);
//������� �� ��巹�� ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetBluetoothMacAddress(char *szBluetoothMacAddress, int nSize);

//�ܸ��� ��Ʈ �н� ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetRootPath(char *szPath, int nSize);

//�ܸ��� �ػ� �� ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceWidth(int *nWidth);
//�ܸ��� �ػ� ���� ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceHeight(int *nHeight);

//�ܸ��� Sound Mute ���� ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetSoundMute(int *bMute);
//�ܸ��� Sound �ִ� ������ ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetSoundMaxVolume(int *nMaxVolume);
//�ܸ��� Sound ������ ���
extern SGL_DECLSPEC int SGLCALL SGL_IGetSoundVolume(int *nVolume);

//�ܸ��� Sound ������ ����
extern SGL_DECLSPEC int SGLCALL SGL_ISetSoundVolume(int nVolume, unsigned char bShowUI);

//Native Code �ʱ�ȭ �Ϸ��(�̺�Ʈ ���� �غ� ����)
extern SGL_DECLSPEC int SGLCALL SGL_INativeInitDone();

//Native Code ������ �߻��� �˸�
extern SGL_DECLSPEC int SGLCALL SGL_INativeError(eNativeErrorCode eErrorCode);

//APK ���Ͽ� ���ԵǾ� �ִ� ������ �ε��Ѵ�.
extern SGL_DECLSPEC int SGLCALL SGL_ILoadAssetsFile(const char *szFileName, int *pFileDescriptor, long *pOffset, long *pLength);

//�ٸ� Activity�� ����Ʈ �޼����� ������.
extern SGL_DECLSPEC int SGLCALL SGL_IPostMessageDevice(eNativeMsgCode eMsg);

/////////////////////////////////////////////////////////////

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif
#include "sgl_close_code.h"

#endif /* _sgl_interface_platform_h */
