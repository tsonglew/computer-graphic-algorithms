// Test4View.cpp : implementation of the CTest4View class
//

#include "stdafx.h"
#include "Test4.h"

#include "Test4Doc.h"
#include "Test4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest4View

IMPLEMENT_DYNCREATE(CTest4View, CView)

BEGIN_MESSAGE_MAP(CTest4View, CView)
	//{{AFX_MSG_MAP(CTest4View)
	ON_COMMAND(IDM_INCREASE, OnIncrease)
	ON_COMMAND(IDM_DECREASE, OnDecrease)
	ON_COMMAND(IDM_CLOCKWISE, OnClockwise)
	ON_COMMAND(IDM_ANTICLOCKWISE, OnAntiClockwise)
	ON_COMMAND(IDM_XAXIS, OnXaxis)
	ON_COMMAND(IDM_YAXIS, OnYaxis)
	ON_COMMAND(IDM_ORG, OnOrg)
	ON_COMMAND(IDM_XDIRECTIONNEG, OnXDirectionNeg)
	ON_COMMAND(IDM_XDIRECTIONPLUS, OnXDirectionPlus)
	ON_COMMAND(IDM_YDIRECTIONNEG, OnYDirectionNeg)
	ON_COMMAND(IDM_YDIRECTIONPLUS, OnYDirectionPlus)
	ON_COMMAND(IDM_RESET, OnReset)
	ON_COMMAND(IDM_UP, OnUp)
	ON_COMMAND(IDM_RIGHT, OnRight)
	ON_COMMAND(IDM_LEFT, OnLeft)
	ON_COMMAND(IDM_DOWN, OnDown)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest4View construction/destruction

CTest4View::CTest4View()
{
	// TODO: add construction code here

}

CTest4View::~CTest4View()
{
}

BOOL CTest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest4View drawing

void CTest4View::OnDraw(CDC* pDC)
{
	CTest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CTest4View printing

BOOL CTest4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest4View diagnostics

#ifdef _DEBUG
void CTest4View::AssertValid() const
{
	CView::AssertValid();
}

void CTest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest4Doc* CTest4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest4Doc)));
	return (CTest4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest4View message handlers

void CTest4View::ReadPoint()
{
	P[0].x = -150; P[0].y = -100;
	P[1].x = 150; P[1].y = -100;
	P[2].x = 150; P[2].y = 100;
	P[3].x = -150; P[3].y = 100;
}

void CTest4View::OnIncrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(1.5, 1.5);
	Invalidate(FALSE);
}

void CTest4View::OnDecrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(0.5, 0.5);
	Invalidate(FALSE);
}

void CTest4View::OnClockwise() 
{
	// TODO: Add your command handler code here
	CP2 p = (P[0]+P[2]) / 2;
	trans.Rotate(-30, p);
	Invalidate(FALSE);
}

void CTest4View::OnAntiClockwise() 
{
	// TODO: Add your command handler code here
	CP2 p = (P[0]+P[2]) / 2;
	trans.Rotate(30, p);
	Invalidate(FALSE);
}

void CTest4View::OnXaxis() 
{
	// TODO: Add your command handler code here
	trans.ReflectX();
	Invalidate(FALSE);
}

void CTest4View::OnYaxis() 
{
	// TODO: Add your command handler code here
	trans.ReflectY();
	Invalidate(FALSE);
}

void CTest4View::OnOrg() 
{
	// TODO: Add your command handler code here
	trans.ReflectOrg();
	Invalidate(FALSE);
}

void CTest4View::OnXDirectionPlus() 
{
	// TODO: Add your command handler code here
	trans.Shear(0, 1);
	Invalidate(FALSE);
}

void CTest4View::OnXDirectionNeg() 
{
	// TODO: Add your command handler code here
	trans.Shear(0, -1);
	Invalidate(FALSE);
}

void CTest4View::OnYDirectionPlus() 
{
	// TODO: Add your command handler code here
	trans.Shear(1, 0);
	Invalidate(FALSE);
}

void CTest4View::OnYDirectionNeg() 
{
	// TODO: Add your command handler code here
	trans.Shear(-1, 0);
	Invalidate(FALSE);
}

void CTest4View::DoubleBuffer()
{
	CDC* pDC = GetDC();
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width()/2, rect.Height()/2);
	CDC MemDC;
	CBitmap NewBitmap, *pOldBitmap;
	MemDC.CreateCompatibleDC(pDC);
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBitmap = MemDC.SelectObject(&NewBitmap);
	MemDC.FillSolidRect(&rect, pDC->GetBkColor());
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(rect.Width(), rect.Height());
	MemDC.SetViewportExt(rect.Width(), -rect.Height());
	MemDC.SetViewportOrg(rect.Width()/2, rect.Height()/2);
	DrawObject(&MemDC);
	pDC->BitBlt(-rect.Width()/2, -rect.Height()/2, rect.Width(), rect.Height(), &MemDC, -rect.Width()/2, -rect.Height()/2, SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
	ReleaseDC(pDC);
}

void CTest4View::DrawObject(CDC* pDC)
{
	CLine *line = new CLine;
	line->MoveTo(pDC, 0, -rect.Height()/2);
	line->LineTo(pDC, 0, rect.Height()/2);
	line->MoveTo(pDC, -rect.Width()/2, 0);
	line->LineTo(pDC, rect.Width()/2, 0);
	DrawPolygon(pDC);
	delete line;
}

void CTest4View::DrawPolygon(CDC* pDC)
{
	CLine* line = new CLine;
	CP2 t;
	for (int i=0; i<4; ++i)
	{
		if (i == 0)
		{
			line->MoveTo(pDC, P[i]);
			t = P[i];
		}
		else
		{
			line->LineTo(pDC, P[i]);
		}
	}
	line->LineTo(pDC, t);
	delete line;
}


void CTest4View::OnReset() 
{
	// TODO: Add your command handler code here
	ReadPoint();
	Invalidate(FALSE);
}


void CTest4View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	ReadPoint();
	trans.SetMat(P, 4);
}

void CTest4View::OnUp() 
{
	// TODO: Add your command handler code here
	trans.Translate(0, 10);
	Invalidate(FALSE);
}

void CTest4View::OnRight() 
{
	// TODO: Add your command handler code here
	trans.Translate(10, 0);
	Invalidate(FALSE);
}

void CTest4View::OnLeft() 
{
	// TODO: Add your command handler code here
	trans.Translate(-10, 0);
	Invalidate(FALSE);
}

void CTest4View::OnDown() 
{
	// TODO: Add your command handler code here
	trans.Translate(0, -10);
	Invalidate(FALSE);
}
