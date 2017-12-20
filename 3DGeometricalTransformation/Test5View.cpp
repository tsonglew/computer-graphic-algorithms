// Test5View.cpp : implementation of the CTest5View class
//

#include "stdafx.h"
#include "Test5.h"

#include "Test5Doc.h"
#include "Test5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CTest5View

IMPLEMENT_DYNCREATE(CTest5View, CView)

BEGIN_MESSAGE_MAP(CTest5View, CView)
	//{{AFX_MSG_MAP(CTest5View)
	ON_COMMAND(IDM_LEFT, OnLeft)
	ON_COMMAND(IDM_BACK, OnBack)
	ON_COMMAND(IDM_DECREASE, OnDecrease)
	ON_COMMAND(IDM_DOWN, OnDown)
	ON_COMMAND(IDM_FRONT, OnFront)
	ON_COMMAND(IDM_INCREASE, OnIncrease)
	ON_COMMAND(IDM_RESET, OnReset)
	ON_COMMAND(IDM_RIGHT, OnRight)
	ON_COMMAND(IDM_RXAXIS, OnRxaxis)
	ON_COMMAND(IDM_RXOY, OnRxoy)
	ON_COMMAND(IDM_RYAXIS, OnRyaxis)
	ON_COMMAND(IDM_RYOZ, OnRyoz)
	ON_COMMAND(IDM_RZAXIS, OnRzaxis)
	ON_COMMAND(IDM_SXDIRECTIONPLUS, OnSxdirectionplus)
	ON_COMMAND(IDM_SYDIRECTIONPLUS, OnSydirectionplus)
	ON_COMMAND(IDM_SZDIRECTIONPLUS, OnSzdirectionplus)
	ON_COMMAND(IDM_UP, OnUp)
	ON_COMMAND(IDM_RXOZ, OnRxoz)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest5View construction/destruction

CTest5View::CTest5View()
{
	// TODO: add construction code here

}

CTest5View::~CTest5View()
{
}

BOOL CTest5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View drawing

void CTest5View::OnDraw(CDC* pDC)
{
	CTest5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View printing

BOOL CTest5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest5View diagnostics

#ifdef _DEBUG
void CTest5View::AssertValid() const
{
	CView::AssertValid();
}

void CTest5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest5Doc* CTest5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest5Doc)));
	return (CTest5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest5View message handlers

void CTest5View::ReadPoint()
{
	double a = 100;
	P[0].x = 0; P[0].y = 0; P[0].z = 0;
	P[1].x = a; P[1].y = 0; P[1].z = 0;
	P[2].x = a; P[2].y = a; P[2].z = 0;
	P[3].x = 0; P[3].y = a; P[3].z = 0;
	P[4].x = 0; P[4].y = 0; P[4].z = a;
	P[5].x = a; P[5].y = 0; P[5].z = a;
	P[6].x = a; P[6].y = a; P[6].z = a;
	P[7].x = 0; P[7].y = a; P[7].z = a;
}

void CTest5View::ReadFace()
{
	F[0].SetNum(4); F[0].vI[0] = 4; F[0].vI[1] = 5; F[0].vI[2] = 6; F[0].vI[3] = 7; 
	F[1].SetNum(4); F[1].vI[0] = 0; F[1].vI[1] = 3; F[1].vI[2] = 2; F[1].vI[3] = 1;
	F[2].SetNum(4); F[2].vI[0] = 0; F[2].vI[1] = 4; F[2].vI[2] = 7; F[2].vI[3] = 3;
	F[3].SetNum(4); F[3].vI[0] = 1; F[3].vI[1] = 2; F[3].vI[2] = 6; F[3].vI[3] = 5;
	F[4].SetNum(4); F[4].vI[0] = 2; F[4].vI[1] = 3; F[4].vI[2] = 7; F[4].vI[3] = 6;
	F[5].SetNum(4); F[5].vI[0] = 0; F[5].vI[1] = 1; F[5].vI[2] = 5; F[5].vI[3] = 4;
}

void CTest5View::OnLeft() 
{
	// TODO: Add your command handler code here
	trans.Translate(-10, 0, 0);
	Invalidate(FALSE);
}

void CTest5View::OnBack() 
{
	// TODO: Add your command handler code here
	trans.Translate(0, 0, -10);
	Invalidate(FALSE);
}

void CTest5View::OnDecrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(0.5, 0.5, 0.5);
	Invalidate(FALSE);
}

void CTest5View::OnDown() 
{
	// TODO: Add your command handler code here
	trans.Translate(0, -10, 0);
	Invalidate(FALSE);
}

void CTest5View::OnFront() 
{
	// TODO: Add your command handler code here
	trans.Translate(0, 0, 10);
	Invalidate(FALSE);
}

void CTest5View::OnIncrease() 
{
	// TODO: Add your command handler code here
	trans.Scale(2, 2, 2);
	Invalidate(FALSE);
}

void CTest5View::OnReset() 
{
	// TODO: Add your command handler code here
	ReadPoint();
	Invalidate(FALSE);
}

void CTest5View::OnRight() 
{
	// TODO: Add your command handler code here
	trans.Translate(10, 0, 0);
	Invalidate(FALSE);
}

void CTest5View::OnRxaxis() 
{
	// TODO: Add your command handler code here
	trans.RotateX(30, P[0]);
	Invalidate(FALSE);
}

void CTest5View::OnRxoy() 
{
	// TODO: Add your command handler code here
	trans.ReflectXOY();
	Invalidate(FALSE);
}

void CTest5View::OnRyaxis() 
{
	// TODO: Add your command handler code here
	trans.RotateY(30, P[0]);
	Invalidate(FALSE);
}

void CTest5View::OnRyoz() 
{
	// TODO: Add your command handler code here
	trans.ReflectYOZ();
	Invalidate(FALSE);
}

void CTest5View::OnRxoz() 
{
	// TODO: Add your command handler code here
	trans.ReflectZOX();
	Invalidate(FALSE);
}

void CTest5View::OnRzaxis() 
{
	// TODO: Add your command handler code here
	trans.RotateZ(30, P[0]);
	Invalidate(FALSE);
}

void CTest5View::OnSxdirectionplus() 
{
	// TODO: Add your command handler code here
	trans.ShearX(1, 1);
	Invalidate(FALSE);
}

void CTest5View::OnSydirectionplus() 
{
	// TODO: Add your command handler code here
	trans.ShearY(1, 1);
	Invalidate(FALSE);
}

void CTest5View::OnSzdirectionplus() 
{
	// TODO: Add your command handler code here
	trans.ShearZ(1, 1);
	Invalidate(FALSE);
}

void CTest5View::OnUp() 
{
	// TODO: Add your command handler code here
	trans.Translate(0, 10, 0);
	Invalidate(FALSE);
}

void CTest5View::DoubleBuffer()
{
    CDC* pDC = GetDC();
	GetClientRect(&rect);
	CDC MemDC;
	CBitmap NewBitmap, *pOldBitmap;

	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width()/2, rect.Height()/2);

	MemDC.CreateCompatibleDC(pDC);
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBitmap = MemDC.SelectObject(&NewBitmap);
	MemDC.FillSolidRect(&rect, pDC->GetBkColor());
	MemDC.SetMapMode(MM_ANISOTROPIC);
	MemDC.SetWindowExt(rect.Width(), rect.Height());
	MemDC.SetViewportExt(rect.Width(), -rect.Height());
	MemDC.SetViewportOrg(rect.Width()/2, rect.Height()/2);

	DrawOblique(&MemDC);
	pDC->BitBlt(-rect.Width()/2, -rect.Height()/2, rect.Width(), rect.Height(), &MemDC, -rect.Width()/2, -rect.Height()/2, SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
	ReleaseDC(pDC);
}

CP2 CTest5View::ObliqueProject(CP3 p)
{
	CP2 ScreenP;
	ScreenP.x = p.x - p.z/sqrt(2);
	ScreenP.y = p.y - p.z/sqrt(2);
	return ScreenP;
}

void CTest5View::DrawObject(CDC *pDC, CP3 P[])
{
	for(int nFace=0;nFace<6;nFace++)
	{
		CP2 t;	
		CLine *line=new CLine;
		for(int nVertex=0;nVertex<F[nFace].vN;nVertex++)
		{
			CP2 p0 = ObliqueProject(P[F[nFace].vI[0]]);
			CP2 p1 = ObliqueProject(P[F[nFace].vI[1]]);
			CP2 p2 = ObliqueProject(P[F[nFace].vI[2]]);
			CP2 p3 = ObliqueProject(P[F[nFace].vI[3]]);
			line->MoveTo(pDC, p0.x, p0.y);
			line->LineTo(pDC, p1.x, p1.y);
			line->MoveTo(pDC, p1.x, p1.y);
			line->LineTo(pDC, p2.x, p2.y);
			line->MoveTo(pDC, p2.x, p2.y);
			line->LineTo(pDC, p3.x, p3.y);
		} 
		delete line;		
	}
}

void CTest5View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	ReadPoint();
	ReadFace();
	trans.SetMat(P, 8);
}

void CTest5View::DrawOblique(CDC *pDC)
{
	CLine* line = new CLine;
	line->MoveTo(pDC, 0, 0);
	line->LineTo(pDC, 0, rect.Height()/2);
	line->MoveTo(pDC, 0, 0);
	line->LineTo(pDC, rect.Width()/2, 0);
	line->MoveTo(pDC, 0, 0);
	line->LineTo(pDC, -rect.Height()*sqrt(2), -rect.Height()*sqrt(2));
	delete line;
	DrawObject(pDC,P);
}
