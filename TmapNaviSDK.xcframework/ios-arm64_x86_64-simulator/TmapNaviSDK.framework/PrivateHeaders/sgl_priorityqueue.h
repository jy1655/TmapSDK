// sgl_priorityqueue.h

// �ۼ��� : ������
// �ۼ��� : 2008.10.14
// ��  �� : �켱���� Queue ��� (���� ���� �켱���� ť ����)

#ifndef __SGL_PRIORITYQUEUE_H
#define __SGL_PRIORITYQUEUE_H

#define SGL_PQUEUE_PARENT_INDEX(index)			((index - 1) >> 1)
#define SGL_PQUEUE_LEFTCHILD_INDEX(index)		(((index) << 1) + 1)
#define SGL_PQUEUE_RIGHTCHILD_INDEX(index)		(((index) << 1) + 2)

enum SGL_PQUEUE_TYPE
{
	SGL_PQUEUE_MAXKEY = 0,
	SGL_PQUEUE_MINKEY
};

typedef struct tagSGL_PQUEUE_ITEM
{
	UInt		nKey;
	void*		pData;
} SGL_PQUEUE_ITEM, *PSGL_PQUEUE_ITEM;

typedef struct tagSGL_PQUEUE_CONTEXT
{
	UInt					nQueueSize;
	UInt					nItemCount;
	SGL_PQUEUE_TYPE			queueType;
	PSGL_PQUEUE_ITEM		pItems;
} SGL_PQUEUE_CONTEXT, *PSGL_PQUEUE_CONTEXT;

PSGL_PQUEUE_CONTEXT sglPQueue_Create(UInt nQueueSize,SGL_PQUEUE_TYPE pQueueType);
void sglPQueue_Destroy(PSGL_PQUEUE_CONTEXT pContext);
UInt sglPQueue_GetCount(PSGL_PQUEUE_CONTEXT pContext);
Bool sglPQueue_Push(PSGL_PQUEUE_CONTEXT pContext,UInt nKey,void* pData);
Bool sglPQueue_Pop(PSGL_PQUEUE_CONTEXT pContext,void** ppData);

#endif // __SGL_PRIORITYQUEUE_H
