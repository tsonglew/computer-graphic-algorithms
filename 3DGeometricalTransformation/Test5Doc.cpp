// Test5Doc.cpp : implementation of the CTest5Doc class
//

#include "stdafx.h"
#include "Test5.h"

#include "Test5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest5Doc

IMPLEMENT_DYNCREATE(CTest5Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest5Doc, CDocument)
	//{{AFX_MSG_MAP(CTest5Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest5Doc construction/destruction

CTest5Doc::CTest5Doc()
{
	// TODO: add one-time construction code here

}

CTest5Doc::~CTest5Doc()
{
}

BOOL CTest5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest5Doc serialization

void CTest5Doc::Serialize(CArchive& ar)
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
// CTest5Doc diagnostics

#ifdef _DEBUG
void CTest5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest5Doc commands
