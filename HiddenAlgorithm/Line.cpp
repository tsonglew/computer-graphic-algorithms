// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test7.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{

}

CLine::~CLine()
{

}

void CLine::MoveTo(CDC* pDC, CP2 p0)
{
	P0 = p0;
}

void CLine::MoveTo(CDC* pDC, double x0, double y0)
{
	P0 = CP2(x0, y0);
}

void CLine::LineTo(CDC* pDC, CP2 p1)
{
	P1 = p1;
	CP2 p, t;
	CRGB clr = CRGB(0.5, 0.5, 0.5);
	if (fabs(P0.x-P1.x) < 1e-6)
	{
		if (P0.y > P1.y)
		{
			t = P0; P0 = P1; P1 = t;
		}
		for (p = P0; p.y < P1.y; p.y++) {
			pDC->SetPixelV(
				Round(p.x),
				Round(p.y),
				RGB(
				    clr.red * 255,
					clr.green * 255,
					clr.blue * 255
				)
			);
		}
	}
	else 
	{
		double k, d;
		k = (P1.y - P0.y) / (P1.x - P0.x);
		if (k > 1.0)
		{
			if (P0.y > P1.y)
			{
			    t = P0; P0 = P1; P1 = t;
			}
			d = 1 - 0.5*k;
			for (p = P0; p.y < P1.y; p.y++)
			{
				pDC->SetPixelV(
					Round(p.x),
					Round(p.y),
					RGB(
					    clr.red * 255,
						clr.green * 255,
						clr.blue * 255
					)
				);
				if (d >= 0)
				{
					p.x++;
					d += 1-k;
				}
				else
				{
					d += 1;
				}
			}
		}
		if (0.0<=k && k<=1.0)
		{
			if(P0.x > P1.x)
			{
				t=P0; P0=P1; P1=t;
			}
			d = 0.5 - k;
			for (p=P0; p.x<P1.x; p.x++)
			{
				pDC->SetPixelV(
					Round(p.x),
					Round(p.y),
					RGB(
						clr.red * 255,
						clr.green * 255,
						clr.blue * 255
					)
				);
				if (d < 0)
				{
					p.y++;
					d += 1-k;
				}
				else
				{
					d -= k;
				}
			}
		}
		if (k>=-1.0 && k<0.0)
		{
			if (P0.x > P1.x)
			{
				t = P0; P0 = P1; P1 = t;
			}
			d = -0.5 - k;
			for (p=P0; p.x<P1.x; p.x++)
			{
				pDC->SetPixelV(
					Round(p.x),
					Round(p.y),
					RGB(
						clr.red * 255,
						clr.green * 255,
						clr.blue * 255
					)
				);
				if (d > 0)
				{
					p.y--;
					d -= 1+k;
				}
				else
				{
					d -= k;
				}
			}
		}
		if (k < -1.0)
		{
			if(P0.y < P1.y)
			{
		        t = P0; P0 = P1; P1 = t;
			}
			d = -1-0.5*k;
			for (p=P0; p.y>P1.y; p.y--)
			{
				pDC->SetPixelV(
					Round(p.x),
					Round(p.y),
					RGB(
						clr.red * 255,
						clr.green * 255,
						clr.blue * 255
					)
				);
				if (d < 0)
				{
					p.x++;
					d -= 1+k;
				}
				else
				{
					d -= 1;
				}
			}
		}
	}
	P0 = p1;
}
		
void CLine::LineTo(CDC* pDC, double x1, double y1)
{
	LineTo(pDC, CP2(x1, y1));
}
