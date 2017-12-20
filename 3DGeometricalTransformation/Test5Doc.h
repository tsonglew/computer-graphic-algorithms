// Test5Doc.h : interface of the CTest5Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST5DOC_H__A2518AA9_7FDF_4EE4_BCAF_85B49F214C87__INCLUDED_)
#define AFX_TEST5DOC_H__A2518AA9_7FDF_4EE4_BCAF_85B49F214C87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest5Doc : public CDocument
{
protected: // create from serialization only
	CTest5Doc();
	DECLARE_DYNCREATE(CTest5Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest5Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest5Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST5DOC_H__A2518AA9_7FDF_4EE4_BCAF_85B49F214C87__INCLUDED_)
