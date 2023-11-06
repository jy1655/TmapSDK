// sgl_pftype.h

// �ۼ��� : ������
// �ۼ��� : 2008.01.14
// ��  �� : �÷��� ������ Ÿ�� ������

#ifndef __SGL_PFTYPE_H
#define __SGL_PFTYPE_H

#if defined(_WIN32)

#if defined(__GNUC__) && !defined(__MINGW32__)

typedef FILE*	SGL_FILE_HANDLE;

#define SGL_INVALID_FILE_HANDLE		NULL

#else

typedef HANDLE	SGL_FILE_HANDLE;

#define SGL_INVALID_FILE_HANDLE		INVALID_HANDLE_VALUE

#endif //defined(__GNUC__)

#elif defined(__MACOSX__)

typedef void*	HANDLE;
typedef void*	SGL_HANDLE;
typedef FILE*	SGL_FILE_HANDLE;

#define INVALID_HANDLE_VALUE		((HANDLE)-1)
#define SGL_INVALID_HANDLE_VALUE	((HANDLE)-1)
#define SGL_INVALID_FILE_HANDLE		NULL

#elif defined(_LINUX) || defined(__IPHONEOS__)

typedef void*	HANDLE;
typedef void*	SGL_HANDLE;
typedef FILE*	SGL_FILE_HANDLE;

#define INVALID_HANDLE_VALUE		((HANDLE)-1)
#define SGL_INVALID_HANDLE_VALUE	((HANDLE)-1)
#define SGL_INVALID_FILE_HANDLE		NULL

#endif

#endif // __SGL_PFTYPE_H
