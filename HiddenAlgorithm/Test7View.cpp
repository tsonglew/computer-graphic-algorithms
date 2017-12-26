// Test7View.cpp : implementation of the CTest7View class
//

#include "stdafx.h"
#include "Test7.h"

#include "Test7Doc.h"
#include "Test7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest7View

IMPLEMENT_DYNCREATE(CTest7View, CView)

BEGIN_MESSAGE_MAP(CTest7View, CView)
	//{{AFX_MSG_MAP(CTest7View)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	ON_COMMAND(IDM_PLAY, OnPlay)
	ON_UPDATE_COMMAND_UI(IDM_PLAY, OnUpdatePlay)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest7View construction/destruction

CTest7View::CTest7View()
{
	// TODO: add construction code here
	bPlay = FALSE;
	R = 800.0; d = 1000; Phi = 90.0; Theta = 0.0;
	Alpha = 0.0; Beta = 0.0;
}

CTest7View::~CTest7View()
{
}

BOOL CTest7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest7View drawing

void CTest7View::OnDraw(CDC* pDC)
{
	CTest7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DoubleBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// CTest7View printing

BOOL CTest7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest7View diagnostics

#ifdef _DEBUG
void CTest7View::AssertValid() const
{
	CView::AssertValid();
}

void CTest7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest7Doc* CTest7View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest7Doc)));
	return (CTest7Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest7View message handlers
void CTest7View::DoubleBuffer()
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

	DrawObject(&MemDC);
	pDC->BitBlt(-rect.Width()/2, -rect.Height()/2, rect.Width(), rect.Height(), &MemDC, -rect.Width()/2, -rect.Height()/2, SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	NewBitmap.DeleteObject();
	ReleaseDC(pDC);
}

void CTest7View::ReadVertex() {
	const double Golden_Section = (sqrt(5.0)-1.0)/2.0;
	double a = 160;
	double b = a * Golden_Section;
	V[0].x = 0; V[0].y = a; V[0].z = b;
	V[1].x = 0; V[1].y = a; V[1].z = -b;
	V[2].x = a; V[2].y = b; V[2].z = 0;
	V[3].x = a; V[3].y = -b; V[3].z = 0;
	V[4].x = 0; V[4].y = -a; V[4].z = -b;
	V[5].x = 0; V[5].y = -a; V[5].z = b;
	V[6].x = b; V[6].y = 0; V[6].z = a;
	V[7].x = -b; V[7].y = 0; V[7].z = a;
	V[8].x = b; V[8].y = 0; V[8].z = -a;
	V[9].x = -b; V[9].y = 0; V[9].z = -a;
	V[10].x = -a; V[10].y = b; V[10].z = 0;
	V[11].x = -a; V[11].y = -b; V[11].z = 0;
}

void CTest7View::ReadFace() {
	F[0].SetNum(3); F[0].vI[0] = 0; F[0].vI[1] = 6; F[0].vI[2] = 2;
	F[1].SetNum(3); F[1].vI[0] = 2; F[1].vI[1] = 6; F[1].vI[2] = 3;
	F[2].SetNum(3); F[2].vI[0] = 3; F[2].vI[1] = 6; F[2].vI[2] = 5;
	F[3].SetNum(3); F[3].vI[0] = 5; F[3].vI[1] = 6; F[3].vI[2] = 7;
	F[4].SetNum(3); F[4].vI[0] = 0; F[4].vI[1] = 7; F[4].vI[2] = 6;
	F[5].SetNum(3); F[5].vI[0] = 2; F[5].vI[1] = 3; F[5].vI[2] = 8;
	F[6].SetNum(3); F[6].vI[0] = 1; F[6].vI[1] = 2; F[6].vI[2] = 8;
	F[7].SetNum(3); F[7].vI[0] = 0; F[7].vI[1] = 2; F[7].vI[2] = 1;
	F[8].SetNum(3); F[8].vI[0] = 0; F[8].vI[1] = 1; F[8].vI[2] = 10;
	F[9].SetNum(3); F[9].vI[0] = 1; F[9].vI[1] = 9; F[9].vI[2] = 10;
	F[10].SetNum(3); F[10].vI[0] = 1; F[10].vI[1] = 8; F[10].vI[2] = 9;
	F[11].SetNum(3); F[11].vI[0] = 3; F[11].vI[1] = 4; F[11].vI[2] = 8;
	F[12].SetNum(3); F[12].vI[0] = 3; F[12].vI[1] = 5; F[12].vI[2] = 4;
	F[13].SetNum(3); F[13].vI[0] = 4; F[13].vI[1] = 5; F[13].vI[2] = 11;
	F[14].SetNum(3); F[14].vI[0] = 7; F[14].vI[1] = 10; F[14].vI[2] = 11;
	F[15].SetNum(3); F[15].vI[0] = 0; F[15].vI[1] = 10; F[15].vI[2] = 7;
	F[16].SetNum(3); F[16].vI[0] = 4; F[16].vI[1] = 11; F[16].vI[2] = 9;
	F[17].SetNum(3); F[17].vI[0] = 4; F[17].vI[1] = 9; F[17].vI[2] = 8;
	F[18].SetNum(3); F[18].vI[0] = 5; F[18].vI[1] = 7; F[18].vI[2] = 11;
	F[19].SetNum(3); F[19].vI[0] = 9; F[19].vI[1] = 11; F[19].vI[2] = 10;
}

void CTest7View::InitParameter() {
	k[1] = sin(PI*Theta/180);
	k[2] = sin(PI*Phi/180);
	k[3] = cos(PI*Theta/180);
	k[4] = cos(PI*Phi/180);
	k[5] = k[2] * k[3];
	k[6] = k[2] * k[1];
	k[7] = k[4] * k[3];
	k[8] = k[4] * k[1];
	ViewPoint.x = R*k[6];
	ViewPoint.y = R*k[4];
	ViewPoint.z = R*k[5];
}

void CTest7View::PerProject(CP3 P) {
	CP3 ViewP;
	ViewP.x = P.x*k[3] - P.z*k[1];
	ViewP.y = P.x*k[8] + P.y*k[2] - P.z*k[7];
	ViewP.z = P.x*k[6] - P.y*k[4] - P.z*k[5] + R;
	ScreenP.x = d * ViewP.x / ViewP.z;
	ScreenP.y = d * ViewP.y / ViewP.z;
}

void CTest7View::DrawObject(CDC* pDC) {
	for (int nFace=0; nFace<20; ++nFace) {
		CVector ViewVector(V[F[nFace].vI[0]], ViewPoint);
		ViewVector = ViewVector.Normalize();
		F[nFace].SetFaceNormal(V[F[nFace].vI[0]], V[F[nFace].vI[1]], V[F[nFace].vI[2]]);
		F[nFace].fNormal.Normalize();
		if (Dot(ViewVector, F[nFace].fNormal) >= 0) {
			CP2 t;
			CLine* line = new CLine;
			for (int nVertex=0; nVertex<F[nFace].vN; ++nVertex) {
				PerProject(V[F[nFace].vI[nVertex]]);
				if (0==nVertex) {
					line->MoveTo(pDC, ScreenP);
					t = ScreenP;
				} else {
					line->LineTo(pDC, ScreenP);
				}
			}
			line->LineTo(pDC, t);
			delete line;
		}
	}
}

void CTest7View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	ReadVertex();
	ReadFace();
	trans.SetMat(V, 12);
	InitParameter();
}

void CTest7View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Alpha = 5;
	Beta = 5;
	trans.RotateX(Alpha);
	trans.RotateY(Beta);
	Invalidate(FALSE);
	CView::OnTimer(nIDEvent);
}

void CTest7View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	R = R + 100;
	InitParameter();
	Invalidate(FALSE);
	CView::OnLButtonDown(nFlags, point);
}

void CTest7View::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	R = R - 100;
	InitParameter();
	Invalidate(FALSE);
	CView::OnRButtonDblClk(nFlags, point);
}

void CTest7View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if (!bPlay) {
		switch (nChar) {
		case VK_UP:
			Alpha = -5;
			trans.RotateX(Alpha);
			break;
		case VK_DOWN:
			Alpha = 5;
			trans.RotateX(Alpha);
			break;
		case VK_LEFT:
			Beta = -5;
			trans.RotateY(Beta);
			break;
		case VK_RIGHT:
			Beta = 5;
			trans.RotateY(Beta);
			break;
		default:
			break;
		}
		Invalidate(FALSE);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CTest7View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
}

void CTest7View::OnPlay() 
{
	// TODO: Add your command handler code here
	bPlay = bPlay?FALSE:TRUE;
	if (bPlay)
		SetTimer(1, 150, NULL);
	else
		KillTimer(1);
}

void CTest7View::OnUpdatePlay(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (bPlay) {
		pCmdUI->SetCheck(TRUE);
		pCmdUI->SetText("Stop");
	} else {
		pCmdUI->SetCheck(FALSE);
		pCmdUI->SetText("Play");
	}
}
