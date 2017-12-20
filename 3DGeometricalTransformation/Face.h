// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__09693600_D7E4_46B6_80DD_EC7F1B4B9540__INCLUDED_)
#define AFX_FACE_H__09693600_D7E4_46B6_80DD_EC7F1B4B9540__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFace  
{
public:
	CFace();
	virtual ~CFace();
	void SetNum(int);
public:
	int vN;
	int* vI;
};

#endif // !defined(AFX_FACE_H__09693600_D7E4_46B6_80DD_EC7F1B4B9540__INCLUDED_)
