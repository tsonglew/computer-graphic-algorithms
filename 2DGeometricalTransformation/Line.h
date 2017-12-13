// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__530DD02B_533D_43F0_90A9_2026EC10212F__INCLUDED_)
#define AFX_LINE_H__530DD02B_533D_43F0_90A9_2026EC10212F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"

class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC*, CP2);
	void MoveTo(CDC*, double, double);
	void LineTo(CDC*, CP2);
	void LineTo(CDC*, double, double);
public:
	CP2 P0;
	CP2 P1;
};

#endif // !defined(AFX_LINE_H__530DD02B_533D_43F0_90A9_2026EC10212F__INCLUDED_)
