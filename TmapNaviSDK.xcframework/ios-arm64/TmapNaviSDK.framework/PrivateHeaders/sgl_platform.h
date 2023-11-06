// sgl_platform.h

// �ۼ��� : ������
// �ۼ��� : 2008.01.07
// ��  �� : SGL(Speed Good Library) ���̺귯�� common ��� ���� ���

#ifndef __SGL_PLATFORM_H
#define __SGL_PLATFORM_H

#include "../src/platform/sgl_interface_platform.h"

#if defined(_WIN32) && !defined(_WIN32_PHONE)
	#include "../src/platform/win32/sgl_win32_platform.h"
#elif defined(__ANDROID__)
#elif defined(__IPHONEOS__)
#endif

#endif // __SGL_PLATFORM_H
