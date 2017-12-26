// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__393E404F_B843_44FB_AD9B_7DFB078889C9__INCLUDED_)
#define AFX_LINE_H__393E404F_B843_44FB_AD9B_7DFB078889C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"
#include "RGB.h"
#include <math.h>
#define Round(x) int(floor(x+0.5))

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

#endif // !defined(AFX_LINE_H__393E404F_B843_44FB_AD9B_7DFB078889C9__INCLUDED_)
