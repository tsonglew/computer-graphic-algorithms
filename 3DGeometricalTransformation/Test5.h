// Test5.h : main header file for the TEST5 application
//

#if !defined(AFX_TEST5_H__F8E1EC58_A0B3_490B_B55B_246E3D313819__INCLUDED_)
#define AFX_TEST5_H__F8E1EC58_A0B3_490B_B55B_246E3D313819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest5App:
// See Test5.cpp for the implementation of this class
//

class CTest5App : public CWinApp
{
public:
	CTest5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest5App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST5_H__F8E1EC58_A0B3_490B_B55B_246E3D313819__INCLUDED_)
