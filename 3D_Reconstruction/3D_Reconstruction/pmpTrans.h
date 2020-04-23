#pragma once

#include <QMainWindow>
#include "ui_pmpTrans.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;

class PMPTrans : public QMainWindow
{
	Q_OBJECT

public:
	PMPTrans(QWidget *parent = Q_NULLPTR);
	~PMPTrans();


protected:

	void LabelDisplayMat(cv::Mat& mat_img, QLabel* label);

private:
	Ui::PMPTrans ui;

private:
	//判断按钮是否按过标志位
	bool isOpen = false;
	bool isGetP = false;
	bool isUnwrap = false;

public:
	//声明四幅调制光栅图像
	cv::Mat imgSrc1;
	cv::Mat imgSrc2;
	cv::Mat imgSrc3;
	cv::Mat imgSrc4;

	//声明四幅原光栅图像
	cv::Mat imgSrc5;
	cv::Mat imgSrc6;
	cv::Mat imgSrc7;
	cv::Mat imgSrc8;

	//相位
	cv::Mat phaseFG;
	cv::Mat phaseBG;

	cv::Mat wrappedPhase;
	cv::Mat unwrappedPhase;

signals:
	/*
	*信号必须由signals关键字来声明
	*信号没有返回值，但可以有参数
	*信号就是函数的声明，只需声明，无需定义
	*使用方法：emit mysignal();
	*/
	void signalSwitch();
	void signalNotOpen();
	void signalNotGetP();

public slots:

void on_actionFTP_triggered();
void on_actionOpen_triggered();
void on_pushButton1_clicked();
void on_pushButton2_clicked();
void on_pushButton3_clicked();

};
