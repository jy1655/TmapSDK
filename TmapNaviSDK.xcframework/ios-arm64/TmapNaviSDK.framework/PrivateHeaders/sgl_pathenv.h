// sgl_pathenv.h

#ifndef __SGL_PATHENV_H
#define __SGL_PATHENV_H

#include "sgl.h"

typedef struct tagSglPath
{
	Char		szPath[SGL_MAX_PATH];			// DB���� �����
	Int32		nCacheSize;			// ĳ�� ũ��
	Int32		nCacheBlockSize;	// ĳ�� �� ũ��
}SGL_PATH, *PSGL_PATH;

class CSglPathEnv
{
public:
	CSglPathEnv();
	~CSglPathEnv();

public:

	/// ���� �н� ������ �ʱ�ȭ �Ѵ�.
	/**
		@param szRootPath	[IN] Root �н�
		@param nPath		[IN] ���� �н� ����
		@param pPath		[IN] ���� �н� ������
		@return
	**/
	void InitPath(PChar szRootPath, Int32 nPath, PSGL_PATH pPath);

	/// Root �н��� ��´�. (DB �н�)
	/**
		@return		Root �н�
	**/
	PChar GetRootPath();
	PTChar GetRootPathT();

	/// �н��� ��´�.
	/**
		@param nIdxFile			[IN] ���� �ε���(���Ժ� �ε��� 0 ���� ���)
		@param szPath			[IN] Ǯ �н��� ����� ����
		@param pCacheSize		[OUT] ������ ĳ���� ����� ��ü ũ�� (NULL �̸� ���� �������� �ʴ´�.)
		@param pCacheBlockSize	[OUT] ������ ĳ�� �� 1�� ũ�� (NULL �̸� ���� �������� �ʴ´�.)
		@return					szPath �� ���ϰ����� �Ѵ�. (���н� NULL)
	**/
	Char* GetPath(Int32 nIdxFile, PChar szPath, Int32 *pCacheSize=NULL, Int32 *pCacheBlockSize=NULL);
	TChar* GetPathT(Int32 nIdxFile, PTChar szPath, Int32 *pCacheSize=NULL, Int32 *pCacheBlockSize=NULL);

private:	
	Char			m_szRootPath[SGL_MAX_PATH];	// ���� DB �н�
	Int32			m_nPath;
	PSGL_PATH		m_pPath;
};

#endif // __SGL_PATHENV_H
