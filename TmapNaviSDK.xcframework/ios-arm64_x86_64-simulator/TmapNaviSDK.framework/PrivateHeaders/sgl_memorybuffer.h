// sgl_memorybuffer.h

// �ۼ��� : 
// �ۼ��� : 
// ��  �� : �޸𸮸� �ݺ������� ���� ���� �Ҷ� ���� �޸𸮸� ��Ȱ�� Ŭ����

#ifndef __SGL_MEMORY_BUFFER_H__
#define __SGL_MEMORY_BUFFER_H__

class CSglMemoryBuffer
{
public:
	CSglMemoryBuffer();
	virtual ~CSglMemoryBuffer();

	Bool SetSize(UInt32 nSize, UInt32 nBase = 1024);
	UInt32 GetSize();

	const BYTE* GetBuffer()			{ return m_pBuffer; }
	const BYTE* GetAt(UInt32 nIdx)	{ return ( nIdx < m_nMaxSize ) ? &m_pBuffer[nIdx] : NULL; }
	
private:
	BYTE*		m_pBuffer;
	UInt32		m_nMaxSize;
};

#endif	// __SGL_MEMORY_BUFFER_H__
