// Test6Doc.h : interface of the CTest6Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST6DOC_H__279463EE_4EE9_42A8_8921_D5E3C600902C__INCLUDED_)
#define AFX_TEST6DOC_H__279463EE_4EE9_42A8_8921_D5E3C600902C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest6Doc : public CDocument
{
protected: // create from serialization only
	CTest6Doc();
	DECLARE_DYNCREATE(CTest6Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest6Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest6Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST6DOC_H__279463EE_4EE9_42A8_8921_D5E3C600902C__INCLUDED_)
