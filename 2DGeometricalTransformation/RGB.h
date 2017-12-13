// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__2D62BB33_A526_4189_BD21_06050F4F9FDF__INCLUDED_)
#define AFX_RGB_H__2D62BB33_A526_4189_BD21_06050F4F9FDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	CRGB();
	CRGB(double, double, double);
	virtual ~CRGB();
	friend CRGB operator+ (const CRGB &, const CRGB &);
	friend CRGB operator- (const CRGB &, const CRGB &);
	friend CRGB operator* (const CRGB &, const CRGB &);
	friend CRGB operator* (const CRGB &, double);
	friend CRGB operator* (double, const CRGB &);
	friend CRGB operator/ (const CRGB &, double);
	friend CRGB operator+= (CRGB &, CRGB &);
	friend CRGB operator-= (CRGB &, CRGB &);
	friend CRGB operator*= (CRGB &, CRGB &);
    friend CRGB operator/= (CRGB &, CRGB &);
	void Normalize();
public:
	double red;
	double green;
	double blue;
};

#endif // !defined(AFX_RGB_H__2D62BB33_A526_4189_BD21_06050F4F9FDF__INCLUDED_)
