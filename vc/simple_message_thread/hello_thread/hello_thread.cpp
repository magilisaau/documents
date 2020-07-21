// hello_thread.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#define _AFXDLL
#include "afxwin.h"
#include "CHelloThread.h"

int main()
{
    //std::cout << "Hello World!\n";
	//创建一个线程
	CHelloThread* pThread = (CHelloThread*)AfxBeginThread(RUNTIME_CLASS(CHelloThread));
	Sleep(50);
	//测试向线程发送一个消息
	pThread->PostThreadMessageW(WM_TEST, 0, 0);
	pThread->PostThreadMessageW(WM_TEST, 1, 0);
	pThread->PostThreadMessageW(WM_TEST, 1, 2);
	while (1); //主线程不退出,否则会把子线程一起杀了
}
