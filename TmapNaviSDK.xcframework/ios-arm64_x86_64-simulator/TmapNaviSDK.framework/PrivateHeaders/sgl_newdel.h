// sgl_newdel.h

// �ۼ��� : ������
// �ۼ��� : 2007.12.27
// ��  �� : ���� new, delete ������ ������

#ifndef __SGL_NEWDEL_H
#define __SGL_NEWDEL_H

#if !(defined(_DEBUG) && (_SGL_CHECK_MEMORYLEAK))

inline
void* __cdecl operator new(size_t size)
{
	return _sgl_malloc(size);
}

inline
void* __cdecl operator new[](size_t size)
{
	return _sgl_malloc(size);
}

inline
void __cdecl operator delete(void* ptr)
{
	_sgl_free(ptr);
}

inline
void __cdecl operator delete[](void* ptr)
{
	_sgl_free(ptr);
}

#endif // !(defined(_DEBUG) && (_SGL_CHECK_MEMORYLEAK))

#endif // __SGL_NEWDEL_H
