// Test4View.h : interface of the CTest4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST4VIEW_H__E240BF01_8C3C_42A3_9EF2_950D08437C96__INCLUDED_)
#define AFX_TEST4VIEW_H__E240BF01_8C3C_42A3_9EF2_950D08437C96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Pi2.h"
#include "Line.h"
#include "Fill.h"

class CTest4View : public CView
{
protected: // create from serialization only
	CTest4View();
	DECLARE_DYNCREATE(CTest4View)

// Attributes
public:
	CTest4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest4View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL bFill;
	CPi2 P[7], P1[7];
	double bRed, bGreen, bBlue;
	void ReadPoint();
	void DrawGraph();
	void DrawPolygon(CDC* pDC);
	void FillPolygon(CDC* pDC);
	virtual ~CTest4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest4View)
	afx_msg void OnDrawpic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Test4View.cpp
inline CTest4Doc* CTest4View::GetDocument()
   { return (CTest4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST4VIEW_H__E240BF01_8C3C_42A3_9EF2_950D08437C96__INCLUDED_)
