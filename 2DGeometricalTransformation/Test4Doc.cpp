// Test4Doc.cpp : implementation of the CTest4Doc class
//

#include "stdafx.h"
#include "Test4.h"

#include "Test4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest4Doc

IMPLEMENT_DYNCREATE(CTest4Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest4Doc, CDocument)
	//{{AFX_MSG_MAP(CTest4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest4Doc construction/destruction

CTest4Doc::CTest4Doc()
{
	// TODO: add one-time construction code here

}

CTest4Doc::~CTest4Doc()
{
}

BOOL CTest4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest4Doc serialization

void CTest4Doc::Serialize(CArchive& ar)
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
// CTest4Doc diagnostics

#ifdef _DEBUG
void CTest4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest4Doc commands
