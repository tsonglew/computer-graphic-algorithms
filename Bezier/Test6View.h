// Test6View.h : interface of the CTest6View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST6VIEW_H__5A2B049A_5764_4EC1_B536_64E7B11D71EC__INCLUDED_)
#define AFX_TEST6VIEW_H__5A2B049A_5764_4EC1_B536_64E7B11D71EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define N_MAX_POINT 21

class CTest6View : public CView
{
protected: // create from serialization only
	CTest6View();
	DECLARE_DYNCREATE(CTest6View)

// Attributes
public:
	CTest6Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest6View)
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
	long Fac(int m);
	double Cni(const int &n, const int &i);
	void DrawBezier();
	void DrawCtrlPolygon();
	void OnInitialUpdate();
	virtual ~CTest6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int n;
	int CtrlPointNum;
	bool bFlag;
	CPoint P[N_MAX_POINT];
// Generated message map functions
protected:
	//{{AFX_MSG(CTest6View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawpic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Test6View.cpp
inline CTest6Doc* CTest6View::GetDocument()
   { return (CTest6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST6VIEW_H__5A2B049A_5764_4EC1_B536_64E7B11D71EC__INCLUDED_)
