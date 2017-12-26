// Test7Doc.h : interface of the CTest7Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST7DOC_H__9B6E08D6_49A6_417F_8D34_06B640F55C73__INCLUDED_)
#define AFX_TEST7DOC_H__9B6E08D6_49A6_417F_8D34_06B640F55C73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest7Doc : public CDocument
{
protected: // create from serialization only
	CTest7Doc();
	DECLARE_DYNCREATE(CTest7Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest7Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest7Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest7Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST7DOC_H__9B6E08D6_49A6_417F_8D34_06B640F55C73__INCLUDED_)
