// sgl_bsearch.h

// �ۼ��� : ������
// �ۼ��� : 2008.05.20
// ��  �� : bsearch ���

#ifndef __SGL_BSEARCH_H
#define __SGL_BSEARCH_H

void* SGLCALL sglBSearch(const void* pKey,const void* pBase,
	UInt nElementCount,UInt nElementSize,
	Int (SGLCALL *pfnCompare)(const void*,const void*));

#endif // __SGL_BSEARCH_H
