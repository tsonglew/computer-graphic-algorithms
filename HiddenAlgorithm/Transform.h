// Transform.h: interface for the CTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORM_H__6E666FDD_6200_435F_AD27_7C481075B68E__INCLUDED_)
#define AFX_TRANSFORM_H__6E666FDD_6200_435F_AD27_7C481075B68E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"
#include <math.h>
#define PI 3.1415

class CTransform  
{
public:
	CTransform();
	virtual ~CTransform();
	void SetMat(CP3* , int);
	void Identity();
	void Translate(double, double, double);
	void Scale(double, double, double);
	void Scale(double, double, double, CP3);
	void RotateX(double);
	void RotateX(double, CP3);
	void RotateY(double);
	void RotateY(double, CP3);
	void RotateZ(double);
	void RotateZ(double, CP3);
	void ReflectX();
	void ReflectY();
	void ReflectZ();
	void ReflectXOY();
	void ReflectYOZ();
	void ReflectZOX();
	void ShearX(double, double);
	void ShearY(double, double);
	void ShearZ(double, double);
	void MultiMatrix();
public:
	double T[4][4];
	CP3* POld;
	int num;
};

#endif // !defined(AFX_TRANSFORM_H__6E666FDD_6200_435F_AD27_7C481075B68E__INCLUDED_)
