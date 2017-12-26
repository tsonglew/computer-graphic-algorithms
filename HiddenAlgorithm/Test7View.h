// Test7View.h : interface of the CTest7View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST7VIEW_H__5D68BD5A_2B1E_4240_B53C_D4DF0374442F__INCLUDED_)
#define AFX_TEST7VIEW_H__5D68BD5A_2B1E_4240_B53C_D4DF0374442F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Vector.h"
#include "Face.h"
#include "Transform.h"
#include "Line.h"

class CTest7View : public CView
{
protected: // create from serialization only
	CTest7View();
	DECLARE_DYNCREATE(CTest7View)

// Attributes
public:
	CTest7Doc* GetDocument();

// Operations
public:
	void ReadVertex();
	void ReadFace();
	void InitParameter();
	void PerProject(CP3);
	void DoubleBuffer();
	void DrawObject(CDC*);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest7View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CRect rect;
	CP3 V[12];
	CFace F[20];
	double R, Theta, Phi, d;
	double k[9];
	CP3 ViewPoint;
	CP2 ScreenP;
	BOOL bPlay;
	double Alpha, Beta;
	CTransform trans;
// Generated message map functions
protected:
	//{{AFX_MSG(CTest7View)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPlay();
	afx_msg void OnUpdatePlay(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Test7View.cpp
inline CTest7Doc* CTest7View::GetDocument()
   { return (CTest7Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST7VIEW_H__5D68BD5A_2B1E_4240_B53C_D4DF0374442F__INCLUDED_)
