// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__C882FEC5_41D9_47F4_BFD7_52E5CE7B00A6__INCLUDED_)
#define AFX_LINE_H__C882FEC5_41D9_47F4_BFD7_52E5CE7B00A6__INCLUDED_

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

#endif // !defined(AFX_LINE_H__C882FEC5_41D9_47F4_BFD7_52E5CE7B00A6__INCLUDED_)
