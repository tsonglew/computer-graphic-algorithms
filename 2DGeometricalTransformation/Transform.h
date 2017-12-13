// Transform.h: interface for the CTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORM_H__4F48701D_2023_4304_AC68_74A4D7CF809D__INCLUDED_)
#define AFX_TRANSFORM_H__4F48701D_2023_4304_AC68_74A4D7CF809D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"

class CTransform  
{
public:
	CTransform();
	virtual ~CTransform();
	void SetMat(CP2 *, int);
	void Identity();
	void Translate(double, double);
	void Scale(double, double);
	void Scale(double, double, CP2);
	void Rotate(double);
	void Rotate(double, CP2);
	void ReflectOrg();
	void ReflectX();
	void ReflectY();
	void Shear(double, double);
	void MultiMatrix();
public:
	double T[3][3];
	CP2* POld;
	int num;
};

#endif // !defined(AFX_TRANSFORM_H__4F48701D_2023_4304_AC68_74A4D7CF809D__INCLUDED_)
