// Test4Doc.h : interface of the CTest4Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST4DOC_H__570BD8D0_F82A_4FFA_A53A_F74B49A90239__INCLUDED_)
#define AFX_TEST4DOC_H__570BD8D0_F82A_4FFA_A53A_F74B49A90239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest4Doc : public CDocument
{
protected: // create from serialization only
	CTest4Doc();
	DECLARE_DYNCREATE(CTest4Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest4Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest4Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST4DOC_H__570BD8D0_F82A_4FFA_A53A_F74B49A90239__INCLUDED_)
