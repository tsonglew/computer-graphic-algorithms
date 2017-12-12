// RGB.cpp: implementation of the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test4.h"
#include "RGB.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRGB::CRGB()
{
	this->red = 1.0;
	this->green = 1.0;
	this->blue = 1.0;
}

CRGB::CRGB(double r, double g, double b)
{
	this->red = r;
	this->green = g;
	this->blue = b;
}

CRGB::~CRGB()
{
}
