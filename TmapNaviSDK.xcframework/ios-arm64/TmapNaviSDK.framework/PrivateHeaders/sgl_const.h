// sgl_const.h

// �ۼ��� : ������
// �ۼ��� : 2007.12.27
// ��  �� : ���̺귯������ �������� ����� ��� ����

#ifndef _SGL_CONST_H
#define _SGL_CONST_H

/////////////////////////////////////////////////////////////////////////////////////////
// ��� ����

#ifndef TRUE
	#define TRUE                1
#endif

#ifndef FALSE
	#define FALSE               0
#endif

#ifdef __IPHONEOS__
	#define SGL_MAX_PATH			520
#else
	#define SGL_MAX_PATH			260
#endif

#endif // _SGL_CONST_H
