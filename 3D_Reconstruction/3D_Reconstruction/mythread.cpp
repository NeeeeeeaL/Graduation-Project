#include "mythread.h"
#include "display.h"




MyThread::MyThread(QObject *parent)
	: QThread(parent)
{
}

MyThread::~MyThread()
{
}

void MyThread::run()
{
	//���ӵ����ݴ���
	
	//�������
	emit signalEndPlot();
}
