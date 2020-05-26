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
	//�̴߳�����
	//ֻ��ͨ��start��ӵ��ã�����ֱ�ӵ���
	void run();

signals:
	void signalEndPlot();
	void signalTransmitMat(cv::Mat);

};
