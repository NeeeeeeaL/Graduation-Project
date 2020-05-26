#pragma once

#include <QThread>

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>



//extern cv::Mat imgPlot;

class MyThread : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject *parent);
	~MyThread();

protected:
	//线程处理函数
	//只能通过start间接调用，不能直接调用
	void run();

signals:
	void signalEndPlot();
	void signalTransmitMat(cv::Mat);

};
