// AET.h: interface for the CAET class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AET_H__88ACADB6_2CB7_4245_A9F7_5FEEAD3F185B__INCLUDED_)
#define AFX_AET_H__88ACADB6_2CB7_4245_A9F7_5FEEAD3F185B__INCLUDED_
#include "Pi2.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAET  
{
public:
	CAET();
	virtual ~CAET();
public:
	double x;
	int yMax;
	double k;
	CPi2 ps;
	CPi2 pe;
	CAET *pNext;
};

#endif // !defined(AFX_AET_H__88ACADB6_2CB7_4245_A9F7_5FEEAD3F185B__INCLUDED_)
