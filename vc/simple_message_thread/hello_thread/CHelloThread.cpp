
#include "CHelloThread.h"
#include <iostream>

IMPLEMENT_DYNCREATE(CHelloThread, CWinThread);

BEGIN_MESSAGE_MAP(CHelloThread, CWinThread) //����Message_Map

	ON_THREAD_MESSAGE(WM_TEST, On_Message_Test)   //������Ϣ����Ϣ������

END_MESSAGE_MAP()

BOOL CHelloThread::InitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	CWinThread::InitInstance();
	return true;//ͨ�� return����Ϊworker�̶߳���UI�߳�
}

void CHelloThread::On_Message_Test(WPARAM wParam, LPARAM lParam) //�Զ������Ϣ������
{
	// TODO: �ڴ˴����ʵ�ִ���.
	std::cout <<"received message "<< wParam << "," << lParam <<"\n";
	
}
