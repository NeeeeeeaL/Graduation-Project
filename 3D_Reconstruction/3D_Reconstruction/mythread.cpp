#include "mythread.h"
#include "display.h"
#include "Reconstruction.h"
#include <QSplitter>




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
