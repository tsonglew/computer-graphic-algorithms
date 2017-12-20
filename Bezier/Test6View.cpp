// Test6View.cpp : implementation of the CTest6View class
//

#include "stdafx.h"
#include "Test6.h"

#include "Test6Doc.h"
#include "Test6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "Help.h"
#include <math.h>
#define Round(x) int(floor(x+0.5))

/////////////////////////////////////////////////////////////////////////////
// CTest6View

IMPLEMENT_DYNCREATE(CTest6View, CView)

BEGIN_MESSAGE_MAP(CTest6View, CView)
	//{{AFX_MSG_MAP(CTest6View)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_DRAWPIC, OnDrawpic)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest6View construction/destruction

CTest6View::CTest6View()
{
	// TODO: add construction code here

}

CTest6View::~CTest6View()
{
}

BOOL CTest6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest6View drawing

void CTest6View::OnDraw(CDC* pDC)
{
	CTest6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

}

/////////////////////////////////////////////////////////////////////////////
// CTest6View printing

BOOL CTest6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest6View diagnostics

#ifdef _DEBUG
void CTest6View::AssertValid() const
{
	CView::AssertValid();
}

void CTest6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest6Doc* CTest6View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest6Doc)));
	return (CTest6Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest6View message handlers

void CTest6View::DrawCtrlPolygon()
{
	CDC* pDC = GetDC();
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pOldPen = pDC->SelectObject(&NewPen);
	CBrush NewBrush, *pOldBrush;
	pOldBrush = (CBrush*)pDC->SelectStockObject(GRAY_BRUSH);
	for (int i=0; i<CtrlPointNum; ++i)
	{
		if (i == 0)
		{
			pDC->MoveTo(P[i]);
			pDC->Ellipse(P[i].x-2, P[i].y-2, P[i].x+2, P[i].y+2);
		}
		else
		{
			pDC->LineTo(P[i]);
			pDC->Ellipse(P[i].x-2, P[i].y-2, P[i].x+2, P[i].y+2);
		}
	}
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
	ReleaseDC(pDC);
}

void CTest6View::DrawBezier()
{
	CDC* pDC = GetDC();
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(P[0]);
	for (double t=0.0; t<=1.0; t+=0.001)
	{
		double x=0, y=0;
		for (int i=0; i<=n; ++i)
		{
			x += P[i].x*Cni(n, i)*pow(t, i)*pow(1-t, n-i);
			y += P[i].y*Cni(n, i)*pow(t, i)*pow(1-t, n-i);
		}
		pDC->LineTo(Round(x), Round(y));
	}	
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
	ReleaseDC(pDC);
}

double CTest6View::Cni(const int &n, const int &i)
{
	return double(Fac(n))/(Fac(i)*Fac(n-i));
}

long CTest6View::Fac(int m)
{
	long f;
	if (m==0 || m==1)
		f = 1;
	else
		f = m*Fac(m-1);
	return f;
}


void CTest6View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (bFlag)
	{
		P[CtrlPointNum].x = point.x;
		P[CtrlPointNum].y = point.y;
		if (CtrlPointNum < N_MAX_POINT-1)
			CtrlPointNum++;
		else
			bFlag = FALSE;
		n = CtrlPointNum - 1;
		DrawCtrlPolygon();
	}
	CView::OnLButtonDown(nFlags, point);
}

void CTest6View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	bFlag = FALSE;
	if (CtrlPointNum != 0)
		DrawBezier();
	CView::OnRButtonDown(nFlags, point);
}

void CTest6View::OnDrawpic() 
{
	// TODO: Add your command handler code here
	bFlag = TRUE;
	CtrlPointNum = 0;
	CHelp dlg;
	dlg.DoModal();
	Invalidate(TRUE);
}

void CTest6View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	bFlag = FALSE;
}
