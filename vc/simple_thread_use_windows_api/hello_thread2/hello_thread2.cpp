// hello_thread2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "windows.h"
#include <vector>
using namespace std;
//定义线程函数

//首先我们用互斥体实现线程的互斥
HANDLE g_hMutex = NULL;
DWORD WINAPI threadfunc(LPVOID param)
{
	int threadno = (int)param;
	WaitForSingleObject(g_hMutex, INFINITE); //获取互斥体mutex
	cout << "thread: " << threadno << " is running" << endl; //如果不对临界区做控制，这里会打印混乱，因此需要用到 互斥体 mutex这个东西 g_hMutex做互斥
	ReleaseMutex(g_hMutex); //释放互斥体mutex
	return 0;
}

void test_thread1()
{	
	DWORD threadid;
	g_hMutex =CreateMutex(NULL, FALSE, NULL);
	for (int i = 0; i < 5; i++)
	{
		HANDLE hThread = CreateThread(NULL, 0, threadfunc, (LPVOID)i, CREATE_SUSPENDED, &threadid); //第4个参数可以给线程函数传一个struct数据块过去，这里只传了个i
		ResumeThread(hThread);//执行线程
	}
	Sleep(1000);
	CloseHandle(g_hMutex);
}

//下面我们不用mutex，用sempore来实现互斥, 当然sempore的更大用途是实现线程同步

HANDLE g_hSemaphore = NULL;
DWORD WINAPI threadfunc2(LPVOID param)
{
	int threadno = (int)param;
	WaitForSingleObject(g_hSemaphore, INFINITE); //获取信号量
	cout << "thread: " << threadno << " is running" << endl; //如果不对临界区做控制，这里会打印混乱，因此需要用到 互斥体 mutex这个东西 g_hMutex做互斥
	ReleaseSemaphore(g_hSemaphore,1,NULL); //释放信号量，这里的第2个参数1表示一次性释放的值，一般都为1
	return 0;
}

void test_thread2()
{
	DWORD threadid;
	g_hSemaphore =  CreateSemaphore(NULL, 1, 1, NULL); //第2个参数1表示信号量的初始值，设置为1等同于mutex, 第3个参数指信号量的最大值
	if (NULL == g_hSemaphore) { cout << "create semaphore failed" << endl; }
	for (int i = 0; i < 5; i++)
	{
		HANDLE hThread = CreateThread(NULL, 0, threadfunc2, (LPVOID)i, CREATE_SUSPENDED, &threadid); //第4个参数可以给线程函数传一个struct数据块过去，这里只传了个i
		ResumeThread(hThread);//执行线程
	}
	Sleep(1000);
	CloseHandle(g_hSemaphore);
}

int main()
{//线程就这么简单
	test_thread1();
	test_thread2();
	return 0;
}