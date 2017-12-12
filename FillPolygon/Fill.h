// Fill.h: interface for the CFill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILL_H__A4C5AE56_E682_4019_859B_F1FA368C50F0__INCLUDED_)
#define AFX_FILL_H__A4C5AE56_E682_4019_859B_F1FA368C50F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Pi2.h"
#include "AET.h"
#include "Bucket.h"
class CFill  
{
public:
	CFill();
	virtual ~CFill();
	void SetPoint(CPi2* p, int);
	void CreateBucket();
	void CreateEdge();
	void AddET(CAET*);
	void ETOrder();
	void Gouraud(CDC*);
	void ClearMemory();
	void DeleteAETChain(CAET* pAET);
protected:
	int PNum;
	CPi2* P;
	CAET* pHeadE, *pCurrentE, *pEdge;
	CBucket *pHeadB, *pCurrentB;
};

#endif // !defined(AFX_FILL_H__A4C5AE56_E682_4019_859B_F1FA368C50F0__INCLUDED_)
