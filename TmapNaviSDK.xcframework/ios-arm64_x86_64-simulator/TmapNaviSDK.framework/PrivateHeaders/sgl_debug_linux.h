// sgl_debug_linux.h

// �ۼ��� : ������
// �ۼ��� : 2008.03.31
// ��  �� : ����� inlne �Լ� ����

#ifndef __SGL_DEBUG_LINUX_H
#define __SGL_DEBUG_LINUX_H

#include <stdarg.h>
#ifdef __ANDROID__
	#include <android/log.h>
#endif

extern Int	g_nDebugPrintId;

void sglSetDebugPrintId(Int nId);
Int sglGetDebugPrintId();

#define SGL_DBGPRINT_BUFFER_SIZE		4096

#if (defined(_DEBUG) && defined(_SGL_DEBUG_ROUTINES)) || defined(_NATIVE_DEBUG_PRINT)
inline
void __cdecl sglDebugPrintA(const char* format,...)
{
    char		szBuffer[SGL_DBGPRINT_BUFFER_SIZE] ={0,};
	va_list		args;

	va_start(args,format);
	vsnprintf(szBuffer,SGL_DBGPRINT_BUFFER_SIZE-1,format,args);
#ifndef __ANDROID__
    printf("VSM %s", szBuffer);
#else
	__android_log_write(ANDROID_LOG_INFO, "VSM", szBuffer);
#endif
	va_end(args);
}

#define sglDebugBreak()			((void)0)

#else

#define sglDbgPrintA(x)			((void)0)
#define sglDebugBreak()			((void)0)

#endif

#endif // __SGL_DEBUG_WIN32_H
