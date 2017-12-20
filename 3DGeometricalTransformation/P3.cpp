// P3.cpp: implementation of the CP3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test5.h"
#include "P3.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CP3::CP3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 1;
}

CP3::~CP3()
{

}

CP3::CP3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 1;
}
