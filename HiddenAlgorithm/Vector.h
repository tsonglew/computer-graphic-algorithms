// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__A99DFE15_39AA_4E68_9E6C_31035492E7FB__INCLUDED_)
#define AFX_VECTOR_H__A99DFE15_39AA_4E68_9E6C_31035492E7FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"

class CVector  
{
public:
	CVector();
	virtual ~CVector();
	CVector(double x, double y, double z);
	CVector(const CP3 &);
	CVector(const CP3 &, const CP3 &);
	double Mag();
	CVector Normalize();
	friend CVector operator + (const CVector &, const CVector &);
	friend CVector operator - (const CVector &, const CVector &);
	friend CVector operator * (const CVector &, double);
	friend CVector operator * (double, const CVector&);
	friend CVector operator / (const CVector &, double);
	friend CVector operator += (CVector &, CVector &);
	friend CVector operator -= (CVector &, CVector &);
	friend CVector operator *= (CVector &, CVector &);
	friend CVector operator /= (CVector &, double);
	friend double Dot (const CVector &, const CVector &);
	friend CVector Cross(const CVector &, const CVector &);
public:
	double x, y, z;
};

#endif // !defined(AFX_VECTOR_H__A99DFE15_39AA_4E68_9E6C_31035492E7FB__INCLUDED_)
