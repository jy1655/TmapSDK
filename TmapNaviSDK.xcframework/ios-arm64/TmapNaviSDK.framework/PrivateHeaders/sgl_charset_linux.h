// sgl_charset_linux.h

// �ۼ��� : ������
// �ۼ��� : 2008.03.31
// ��  �� : Character set inline �Լ� ����

#ifndef __SGL_CHARSET_LINUX_H
#define __SGL_CHARSET_LINUX_H

inline
size_t sgl_wcslen(const WChar* wcs)
{
	const WChar*	p = wcs;
	
	while(*p++);
	
	return (size_t)(p - wcs - 1);
}

inline
WChar* sgl_wcschr(const WChar* wcs, WChar ch)
{
	while (*wcs && *wcs != (WChar)ch)
		wcs++;

	if (*wcs == ch)
		return (WChar*)wcs;
	
    return NULL;
}

inline
int sgl_wtoi(const WChar* wcs)
{
	int		nLength;
	char*	mbs;
	
	nLength = (int)sgl_wcslen(wcs);
	if(nLength == 0)
		return 0;
	
	//nLength ũ��� �޸� �Ҵ��ϸ� ���Ƿ� 20ũ����ŭ �߰�(���� �ľ� ���� ����)
	mbs = (char*)sgl_alloca(nLength*2+20);
	sglWideCharToMultiByte((WChar*)wcs,mbs,nLength*2+20);

	return atoi(mbs);
}

inline
WChar* sgl_wcscpy(WChar* dst, const WChar* src)
{
	WChar* cp = dst;

	while( (*cp++ = *src++) != 0);

	return( dst );
}

inline
WChar* sgl_wcsncpy(WChar* dest, const WChar* source, size_t count)
{
	WChar*	start = dest;

	while(count && (*dest++ = *source++))
		count--;

	if(count)
	{
		while (--count)
			*dest++ = 0;
	}
	
	return(start);
}

inline
WChar* sgl_wcscat(WChar* dst, const WChar* src)
{
	WChar* cp = dst;

	while( *cp )
		cp++;

	while( (*cp++ = *src++) != 0 );

	return( dst );
}

inline
int sgl_wcscmp(const WChar* src, const WChar* dst)
{
	int ret = 0 ;

	while(!(ret = (int)(*src - *dst)) && *dst)
	{
		++src, ++dst;
	}

	if ( ret < 0 )
		ret = -1 ;
	else if ( ret > 0 )
		ret = 1 ;

	return( ret );
}

inline
int sgl_wcsncmp (const WChar* first, const WChar* last, size_t count)
{
	if (!count)
		return(0);

	while (--count && *first && *first == *last)
	{
		first++;
		last++;
	}

	return((int)(*first - *last));
}

#endif // __SGL_CHARSET_LINUX_H
