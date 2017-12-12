// Test4.h : main header file for the TEST4 application
//

#if !defined(AFX_TEST4_H__452BC4A3_FDFE_4D4A_914D_7F6F5BC03D98__INCLUDED_)
#define AFX_TEST4_H__452BC4A3_FDFE_4D4A_914D_7F6F5BC03D98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest4App:
// See Test4.cpp for the implementation of this class
//

class CTest4App : public CWinApp
{
public:
	CTest4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST4_H__452BC4A3_FDFE_4D4A_914D_7F6F5BC03D98__INCLUDED_)
