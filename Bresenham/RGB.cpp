// RGB.cpp: implementation of the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test2.h"
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
	red = 1.0;
	green = 1.0;
	blue = 1.0;
}

CRGB::CRGB(double r, double g, double b)
{
	red = r;
	green = g;
	blue = b;
}

CRGB::~CRGB()
{
}

CRGB operator + (const CRGB &c1, const CRGB &c2)
{
	CRGB c;
	c.red = c1.red + c2.red;
	c.green = c1.green + c2.green;
	c.blue = c1.blue + c2.blue;
	return c;
}

CRGB operator - (const CRGB &c1, const CRGB &c2)
{
	CRGB c;
	c.red = c1.red - c2.red;
	c.green = c1.green - c2.green;
	c.blue = c1.blue - c2.blue;
	return c;
}

CRGB operator * (const CRGB &c1, const CRGB &c2)
{
	CRGB c;
	c.red = c1.red * c2.red;
	c.green = c1.green * c2.green;
	c.blue = c1.blue * c2.blue;
	return c;
}

CRGB operator * (const CRGB &c1, double k)
{
	CRGB c;
	c.red = c1.red * k;
	c.green = c1.green * k;
	c.blue = c1.blue * k;
	return c;
}

CRGB operator * (double k, const CRGB &c1)
{
	CRGB c;
	c.red = c1.red * k;
	c.green = c1.green * k;
	c.blue = c1.blue * k;
	return c;
}

CRGB operator / (const CRGB &c1, double k)
{
	CRGB c;
	c.red = c1.red / k;
	c.green = c1.green / k;
	c.blue = c1.blue / k;
	return c;
}

CRGB operator += (CRGB &c1, CRGB &c2)
{
	c1.red = c1.red + c2.red;
	c1.green = c1.green + c2.green;
	c1.blue = c1.blue + c2.blue;
	return c1;
}

CRGB operator -= (CRGB &c1, CRGB &c2)
{
	c1.red = c1.red - c2.red;
	c1.green = c1.green - c2.green;
	c1.blue = c1.blue - c2.blue;
	return c1;
}

CRGB operator *= (CRGB &c1, CRGB &c2)
{
	c1.red = c1.red * c2.red;
	c1.green = c1.green * c2.green;
	c1.blue = c1.blue * c2.blue;
	return c1;
}

CRGB operator / (CRGB &c1, double k)
{
	c1.red = c1.red / k;
	c1.green = c1.green / k;
	c1.blue = c1.blue / k;
	return c1;
}

void CRGB::Normalize()
{
	red = (red<1.0)?0.0: ((red>1.0)? 1.0:red);
	green = (green<1.0)?0.0: ((green>1.0)? 1.0:green);
	blue = (blue<1.0)?0.0: ((blue>1.0)? 1.0:blue);
}
