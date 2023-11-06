//////////////////////////////////////////////////////////////////////////
// RGServiceConfig.h

#ifndef _RGSERVICECONFIG_H_
#define _RGSERVICECONFIG_H_

#include "sgl_inc.h"
#include "rgdata_def.h"

#define 	UI_DEFAULT_SET			0				// ȯ�� ���� Default Value	

#define		UI_POI_CNT				15				// ǥ���� POI ����
#define		UI_CAMERA_CNT			12				// ī�޶� ���� �ȳ� ����
#define		UI_GUIDE_CNT			12				// �Ϲ� ���� �ȳ� ���� 
#define		UI_ETC_GUIDE_CNT		21				// ��Ÿ ���� �ȳ� ����

class CRGServiceConfig
{
	NOT_COPYABLE(CRGServiceConfig)
private:
	CRGServiceConfig();
	virtual ~CRGServiceConfig();

public:
	// ��� �ȳ� ȯ�氪�� ��´�.
	RG_CONFIG& GetConfig();

	// ��� �ȳ� ȯ�氪�� �����Ѵ�.
	void SetConfig(PRG_CONFIG pConfig);

private:
	// ���Ͽ��� ��� �ȳ� ȯ�氪 �д´�.
	Bool FileReadDefaultConfig();

	// ��� �ȳ� ȯ�氪�� ���Ͽ� �����Ѵ�. (������Ʈ�� �⺻ �ȳ� ������ �����ø� ���)
	Bool FileWriteDefaultConfig();

	// ��Ī���� ȯ�氪 ������ ã�� �����Ѵ�.
	Bool SetValue(Char *szName, Byte *pValue, Int32 nSize);


	RG_CONFIG m_sData;

	DECLARE_SINGLETON(CRGServiceConfig)
};

#endif // _RGSERVICECONFIG_H_
