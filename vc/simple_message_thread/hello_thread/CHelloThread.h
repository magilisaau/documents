#pragma once
#define _AFXDLL
#include <afxwin.h>
#define WM_TEST     WM_USER+10
class CHelloThread :public CWinThread
{
public:
	DECLARE_DYNCREATE(CHelloThread)
	virtual BOOL InitInstance();
	afx_msg void On_Message_Test(WPARAM wParam, LPARAM lParam);
protected:
	DECLARE_MESSAGE_MAP()
};

