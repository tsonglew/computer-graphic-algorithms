// Bucket.h: interface for the CBucket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUCKET_H__9879F30E_2778_4C81_AD1B_7A539F2EF0A2__INCLUDED_)
#define AFX_BUCKET_H__9879F30E_2778_4C81_AD1B_7A539F2EF0A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AET.h"
class CBucket  
{
public:
	CBucket();
	virtual ~CBucket();
public:
	int ScanLine;
	CAET* pET;
	CBucket* pNext;
};

#endif // !defined(AFX_BUCKET_H__9879F30E_2778_4C81_AD1B_7A539F2EF0A2__INCLUDED_)
