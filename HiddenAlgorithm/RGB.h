// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__9F4BF186_E509_4D59_8D68_C9EF9019B855__INCLUDED_)
#define AFX_RGB_H__9F4BF186_E509_4D59_8D68_C9EF9019B855__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	CRGB();
	virtual ~CRGB();
	CRGB(double, double, double);
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

#endif // !defined(AFX_RGB_H__9F4BF186_E509_4D59_8D68_C9EF9019B855__INCLUDED_)
