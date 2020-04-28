#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Reconstruction.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <QSplitter>
#include "mythread.h"
#include "pmpTrans.h"
#include "welcome.h"
#include "datalist.h"

#include <QSqlTableModel>

using namespace std;


class Reconstruction : public QMainWindow
{
	Q_OBJECT

public:
	Reconstruction(QWidget *parent = Q_NULLPTR);

	void dealChild();
	void dealNotOpen();
	void dealNotGetP();
	void dealNotUnwrap();

	//线程相关处理函数
	void dealEndPlot();
	void killThread();
	void dealTransmit();

	DataList* dataWidget;
	QSplitter* spl;

protected:
	//重写绘图事件，虚函数
	//如果在窗口绘图，必须放在绘图事件力实现
	//绘图事件内部自动调用（窗口需要重绘的时候）
	void paintEvent(QPaintEvent *);

	void LabelDisplayMat(cv::Mat& mat_img, QLabel* label);


private:
	Ui::ReconstructionClass ui;

	PMPTrans windowPMP;
	Welcome welcomeW;
	QSqlTableModel *model;

	MyThread *thread;//线程对象

private:
	//判断按钮是否按过标志位
	bool isOpen = false;
	bool isFFT = false;
	bool isFilt = false;
	bool isIFFT = false;
	bool isGetP = false;
	bool isUnwrap = false;


public:
	//尽量避免对全局变量进行操作，可在函数内声明临时变量，
	//对临时变量进行操作，完成后再将值赋给全局变量
	QImage img1, img2;

	cv::Mat imgOriginal_src;
	cv::Mat imgOriginal_fft;
	cv::Mat imgOriginal_filt;
	cv::Mat imgOriginal_ifft;
	cv::Mat imgOriginal_angel;

	cv::Mat imgModulated_src;
	cv::Mat imgModulated_fft;
	cv::Mat imgModulated_filt;
	cv::Mat imgModulated_ifft;
	cv::Mat imgModulated_angel;

	cv::Mat wrappedPhase;
	cv::Mat unwrappedPhase;


public slots:

//图像处理操作按钮槽函数
void on_pushButton_clicked();//傅里叶变换
void on_pushButton_2_clicked();//滤波按钮
void on_pushButton_3_clicked();//傅里叶反变换
void on_pushButton_4_clicked();//求相位
void on_pushButton_5_clicked();//解相位
void on_pushButton_6_clicked();//解相位

//三维重建一步操作
void on_pushButton_7_clicked();//One Step 

//菜单栏操作按钮槽函数
void on_actionOpen_triggered();
void on_actionSave_triggered();
void on_actionPMP_triggered();

//ComboBox 切换
void on_comboBox_activated(int);

};


//class MyThread : public QThread
//{
//	Q_OBJECT
//
//public:
//	MyThread(QObject *parent);
//	~MyThread();
//
//protected:
//	//线程处理函数
//	//只能通过start间接调用，不能直接调用
//	void run();
//
//signals:
//	void signalEndPlot();
//};

