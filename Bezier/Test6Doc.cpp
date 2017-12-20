// Test6Doc.cpp : implementation of the CTest6Doc class
//

#include "stdafx.h"
#include "Test6.h"

#include "Test6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest6Doc

IMPLEMENT_DYNCREATE(CTest6Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest6Doc, CDocument)
	//{{AFX_MSG_MAP(CTest6Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest6Doc construction/destruction

CTest6Doc::CTest6Doc()
{
	// TODO: add one-time construction code here

}

CTest6Doc::~CTest6Doc()
{
}

BOOL CTest6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest6Doc serialization

void CTest6Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTest6Doc diagnostics

#ifdef _DEBUG
void CTest6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest6Doc commands
