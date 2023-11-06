// sgl_error.h

// �ۼ��� : ������
// �ۼ��� : 2007.12.27
// ��  �� : ���̺귯������ �������� ����� ���� ����

#ifndef __SGL_ERROR_H
#define __SGL_ERROR_H

#define SGL_SUCCESS(ErrorCode)	(ErrorCode == SGL_ERROR_SUCCESS)
#define SGL_FAIL(ErrorCode)		(ErrorCode != SGL_ERROR_SUCCESS)

enum
{
	SGL_ERROR_SUCCESS = 0,
	SGL_ERROR_UNKNOWN = -1,
	SGL_ERROR_OUTOFMEMORY = -2,
	SGL_ERROR_OUTOFRESOURCE = -3,
	SGL_ERROR_DIVBYZERO = -4,
	SGL_ERROR_OVERFLOW = -5,
	SGL_ERROR_UNDERFLOW = -6	
};

#endif // __SGL_ERROR_H
