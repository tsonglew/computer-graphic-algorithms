// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__DAF4AE9E_9E87_436E_B26F_4B9B830C8F72__INCLUDED_)
#define AFX_LINE_H__DAF4AE9E_9E87_436E_B26F_4B9B830C8F72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pi2.h"

class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC*, CPi2);
	void MoveTo(CDC*, double, double);
	void LineTo(CDC*, CPi2);
	void LineTo(CDC*, double, double);
public:
	CPi2 P0;
	CPi2 P1;
};

#endif // !defined(AFX_LINE_H__DAF4AE9E_9E87_436E_B26F_4B9B830C8F72__INCLUDED_)
