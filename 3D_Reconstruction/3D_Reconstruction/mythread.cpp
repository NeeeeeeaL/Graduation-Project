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
	//复杂的数据处理

	//处理完成
	emit signalEndPlot();
}
