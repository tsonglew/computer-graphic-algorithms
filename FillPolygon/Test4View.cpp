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
	ON_COMMAND(IDM_DRAWPIC, OnDrawpic)
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
	ReadPoint();
	bFill = FALSE;
	DrawGraph();
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
	P[0].x = 50; P[0].y = 100;
	P[1].x = -150; P[1].y = 300;
	P[2].x = -250; P[2].y = 50;
	P[3].x = -150; P[3].y = -250;
	P[4].x = 0; P[4].y = -50;
	P[5].x = 100; P[5].y = -250;
	P[6].x = 300; P[6].y = 150;
}

void CTest4View::OnDrawpic() 
{
	// TODO: Add your command handler code here
	COLORREF GetClr = RGB(0, 0, 0);
	CColorDialog ccd(GetClr, CC_SOLIDCOLOR);
	if (IDOK == ccd.DoModal())
		GetClr = ccd.GetColor();
	else
		return;
	bRed = GetRValue(GetClr);
	bGreen = GetGValue(GetClr);
	bBlue = GetBValue(GetClr);
	bFill = TRUE;
	DrawGraph();
	Invalidate(FALSE);
}

void CTest4View::DrawGraph()
{
	CRect rect;
	GetClientRect(&rect);
	CDC* pDC = GetDC();
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width()/2, rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2, -rect.Height()/2);
	if (!bFill)
		DrawPolygon(pDC);
	else
		FillPolygon(pDC);
	ReleaseDC(pDC);
}

void CTest4View::DrawPolygon(CDC* pDC)
{
	CLine* line = new CLine;
	CPi2 t;
	for (int i=0; i<7; ++i)
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

void CTest4View::FillPolygon(CDC* pDC)
{
	for (int i=0; i<7; ++i)
	{
		P1[i].x = P[i].x;
		P1[i].y = Round(P[i].y);
		P1[i].c = CRGB(bRed/255.0, bGreen/255.0, bBlue/255.0);
	}
	CFill* fill = new CFill;
	fill->SetPoint(P1, 7);
	fill->CreateBucket();
	fill->CreateEdge();
	fill->Gouraud(pDC);
	delete fill;
}
