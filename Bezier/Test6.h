// Test6.h : main header file for the TEST6 application
//

#if !defined(AFX_TEST6_H__D12C1D68_36A1_4649_9D7B_77CD0CCA0CC5__INCLUDED_)
#define AFX_TEST6_H__D12C1D68_36A1_4649_9D7B_77CD0CCA0CC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest6App:
// See Test6.cpp for the implementation of this class
//

class CTest6App : public CWinApp
{
public:
	CTest6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest6App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST6_H__D12C1D68_36A1_4649_9D7B_77CD0CCA0CC5__INCLUDED_)
