#ifndef __RES_FORMAT_DITHER_H__
#define __RES_FORMAT_DITHER_H__

// writer : ramoo
// last update : 2012-07-12

//crossimg.idx format
typedef struct tagCrossImageIndexHeader
{
	unsigned int	nMaxIndex;			// �ε��� �� ����
	unsigned int*	pResOffsetByIndex;	// �̹����� offset �迭
}CROSSIMAGEINDEXHDEADER, *LPCROSSIMAGEINDEXHDEADER;

//crossimg.bdb header
typedef struct tagCrossImageDBHeader
{
	unsigned int	nMaxImageCount;		// �̹��� �� ����
//	unsigned int	nMaxSizeImage;		// ����ū �̹��� ������ ? (��?) �ϴ� ������ �־ ����
//										// �ƹ��� ���� �ʿ� ���� ���� ������
}CROSSIMAGEDBHDEADER, *LPCROSSIMAGEDBHDEADER;

//crossimg.bdb data
typedef struct tagCrossImageInfo
{
	unsigned int	nImageType;			// �̹��� ���� (5650, 4444, 5551)
	unsigned short	nwidth;				
	unsigned short	nheight;
	unsigned int	nOriginalSize;		// �̹��� ����	 ũ��
	unsigned int	nCompressSize;		// �̹��� ����� ũ��
	unsigned char*	pBit;				// ����� �̹��� ����
}CROSSIMAGEINFO, *LPCROSSIMAGEINFO;

#endif
