// Test7Doc.cpp : implementation of the CTest7Doc class
//

#include "stdafx.h"
#include "Test7.h"

#include "Test7Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest7Doc

IMPLEMENT_DYNCREATE(CTest7Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest7Doc, CDocument)
	//{{AFX_MSG_MAP(CTest7Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest7Doc construction/destruction

CTest7Doc::CTest7Doc()
{
	// TODO: add one-time construction code here

}

CTest7Doc::~CTest7Doc()
{
}

BOOL CTest7Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest7Doc serialization

void CTest7Doc::Serialize(CArchive& ar)
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
// CTest7Doc diagnostics

#ifdef _DEBUG
void CTest7Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest7Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest7Doc commands
