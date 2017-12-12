// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__2CB16A31_C4DE_48BB_8620_9D32725E8C70__INCLUDED_)
#define AFX_RGB_H__2CB16A31_C4DE_48BB_8620_9D32725E8C70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	double red;
	double green;
	double blue;
public:
	CRGB();
	CRGB(double, double, double);
	virtual ~CRGB();
};
#endif // !defined(AFX_RGB_H__2CB16A31_C4DE_48BB_8620_9D32725E8C70__INCLUDED_)
