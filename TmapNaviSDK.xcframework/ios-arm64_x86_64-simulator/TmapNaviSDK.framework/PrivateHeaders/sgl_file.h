// sgl_file.h

// �ۼ��� : ������
// �ۼ��� : 2008.01.15
// ��  �� : File Handling Ŭ����

#ifndef __SGL_FILE_H
#define __SGL_FILE_H

enum SGL_FILEMODE
{
	SGL_FILEMODE_READ =				0x00000001,
	SGL_FILEMODE_WRITE =			0x00000002,	
	SGL_FILEMODE_SHARE_READ =		0x00000010,
	SGL_FILEMODE_SHARE_WRITE =		0x00000020,
	SGL_FILEMODE_CREATE =			0x00000100,
	SGL_FILEMODE_NOTRUNCATE =		0x00000200
};

enum SGL_SEEK_POSITION
{
	SGL_SEEK_BEGIN = 0x0,
	SGL_SEEK_CURRENT = 0x1,
	SGL_SEEK_END = 0x2
};

class CSglFile
{
public :
	CSglFile();
	~CSglFile();

	Bool IsOpen() { return (m_hFile != SGL_INVALID_FILE_HANDLE); }
	Bool Open(const Char* lpszFileName,DWord dwFlags);
#ifndef _WIN32
	Bool Open(Int32 nFileDescriptor, Int32 nDefaultOffset, Int32 nSize);
#endif

	void Close();

	UInt32 GetSize();

	Bool Seek(UInt32 nOffset,UInt32 nFrom);
	UInt32 Read(void* pBuffer,UInt32 nCount);
	UInt32 Write(const void* pBuffer,UInt32 nCount);

private :
	SGL_FILE_HANDLE		m_hFile;
#ifdef _WIN32_PHONE
	Char m_szName[_MAX_PATH];
#endif
#ifndef _WIN32
	Bool				m_bAssetsFile;		//�ȵ���̵忡�� APK�� ��ϵ� ���ҽ� ���� ���� ����
	Int32				m_nFileDescriptor;
	Int32				m_nDefaultOffset;	//�ȵ���̵忡�� APK�� ��ϵ� ���ҽ� ������ ������ �⺻ offset�� 0�� �ƴϴ�.
	Int32				m_nSize;			//�ȵ���̵忡�� APK�� ��ϵ� ���ҽ� ������ ������ ũ�⸦ �˼� �����Ƿ� JAVA���� ���� �޴´�.
#endif
};
#endif // __SGL_FILE_H
