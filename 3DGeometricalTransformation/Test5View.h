// Test5View.h : interface of the CTest5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST5VIEW_H__6CB3C7F7_6FAF_4D15_A905_5F9390658BFB__INCLUDED_)
#define AFX_TEST5VIEW_H__6CB3C7F7_6FAF_4D15_A905_5F9390658BFB__INCLUDED_

#include "Transform.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Transform.h"
#include "Face.h"
#include "P3.h"
#include "Line.h"

class CTest5View : public CView
{
protected: // create from serialization only
	CTest5View();
	DECLARE_DYNCREATE(CTest5View)

// Attributes
public:
	CTest5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest5View)
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
	void DrawObject(CDC* pDC);
	void DoubleBuffer();
	void DrawObject(CDC *,CP3 []);
	void DrawOblique(CDC *pDC);
	CP2 ObliqueProject(CP3 p);
	void ReadFace();
	void ReadPoint();
	virtual ~CTest5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:	
	CP3 P[8];
	CFace F[6];
	CRect rect;
    CTransform trans;
	double T[4][4];
// Generated message map functions
protected:
	//{{AFX_MSG(CTest5View)
	afx_msg void OnLeft();
	afx_msg void OnBack();
	afx_msg void OnDecrease();
	afx_msg void OnDown();
	afx_msg void OnFront();
	afx_msg void OnIncrease();
	afx_msg void OnReset();
	afx_msg void OnRight();
	afx_msg void OnRxaxis();
	afx_msg void OnRxoy();
	afx_msg void OnRyaxis();
	afx_msg void OnRyoz();
	afx_msg void OnRzaxis();
	afx_msg void OnSxdirectionplus();
	afx_msg void OnSydirectionplus();
	afx_msg void OnSzdirectionplus();
	afx_msg void OnUp();
	afx_msg void OnRxoz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Test5View.cpp
inline CTest5Doc* CTest5View::GetDocument()
   { return (CTest5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST5VIEW_H__6CB3C7F7_6FAF_4D15_A905_5F9390658BFB__INCLUDED_)
