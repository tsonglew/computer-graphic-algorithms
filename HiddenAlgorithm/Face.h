// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__DB6C4DDC_B937_4E30_A0E4_0309829F115A__INCLUDED_)
#define AFX_FACE_H__DB6C4DDC_B937_4E30_A0E4_0309829F115A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Vector.h"

class CFace  
{
public:
	CFace();
	virtual ~CFace();
	void SetNum(int);
	void SetFaceNormal(CP3, CP3, CP3);
public:
	int vN;
	int* vI;
	CVector fNormal;
};

#endif // !defined(AFX_FACE_H__DB6C4DDC_B937_4E30_A0E4_0309829F115A__INCLUDED_)
