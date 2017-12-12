// Pi2.h: interface for the CPi2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PI2_H__688F8524_9809_4CF6_BC1E_3A38BEBADB43__INCLUDED_)
#define AFX_PI2_H__688F8524_9809_4CF6_BC1E_3A38BEBADB43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RGB.h"
#include "math.h"
#define Round(d) int(floor(d+0.5))
class CPi2
{
public:
	CPi2();
	virtual ~CPi2();
	CPi2(double, double);
public:
	double x;
	double y;
	CRGB c;
};

#endif // !defined(AFX_PI2_H__688F8524_9809_4CF6_BC1E_3A38BEBADB43__INCLUDED_)
