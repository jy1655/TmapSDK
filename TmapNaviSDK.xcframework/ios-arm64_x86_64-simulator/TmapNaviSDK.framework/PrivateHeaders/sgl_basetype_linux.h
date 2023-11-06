// sgl_basetype_linux.h

// �ۼ��� : ������
// �ۼ��� : 2007.12.27
// ��  �� : ���̺귯������ �������� ����� Ÿ�� ����

#ifndef __SGL_BASETYPE_LINUX_H
#define __SGL_BASETYPE_LINUX_H

// Wide char type redefinition

typedef unsigned short		WChar;
typedef unsigned short*		PWChar;

// linux SDK type redefinition
#ifdef NULL
#undef NULL
#endif

#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif

#define WM_USER			0x400

#ifndef __OBJC_BUILD__
#define BOOL			Bool
#endif
#define DWORD			DWord

#define PBYTE			PByte
#define LPBYTE			PByte
#define PDWORD			PDWord

typedef short			SHORT;
typedef void*			PVOID;
typedef void*			LPVOID;
typedef char			TCHAR;
typedef char*			LPTSTR;
typedef const char*		LPCTSTR;

typedef unsigned int	WPARAM;
typedef int				LPARAM;

#endif // __SGL_BASETYPE_LINUX_H
