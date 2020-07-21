
#include "CHelloThread.h"
#include <iostream>

IMPLEMENT_DYNCREATE(CHelloThread, CWinThread);

BEGIN_MESSAGE_MAP(CHelloThread, CWinThread) //定义Message_Map

	ON_THREAD_MESSAGE(WM_TEST, On_Message_Test)   //关联消息和消息处理函数

END_MESSAGE_MAP()

BOOL CHelloThread::InitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	CWinThread::InitInstance();
	return true;//通过 return设置为worker线程而非UI线程
}

void CHelloThread::On_Message_Test(WPARAM wParam, LPARAM lParam) //自定义的消息处理函数
{
	// TODO: 在此处添加实现代码.
	std::cout <<"received message "<< wParam << "," << lParam <<"\n";
	
}
