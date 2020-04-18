#pragma once

#include <QMainWindow>
#include "ui_pmpTrans.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
using namespace std;

class PMPTrans : public QMainWindow
{
	Q_OBJECT

public:
	PMPTrans(QWidget *parent = Q_NULLPTR);
	~PMPTrans();

	void sendSlot();

protected:

	void LabelDisplayMat(Mat& mat_img, QLabel* label);

private:
	Ui::PMPTrans ui;

public:
	//声明四幅调制光栅图像
	Mat imgSrc1;
	Mat imgSrc2;
	Mat imgSrc3;
	Mat imgSrc4;

	//声明四幅原光栅图像
	Mat imgSrc5;
	Mat imgSrc6;
	Mat imgSrc7;
	Mat imgSrc8;

	//相位
	Mat phaseFG;
	Mat phaseBG;

	Mat wrappedPhase;
	Mat unwrappedPhase;

signals:
	/*
	*信号必须由signals关键字来声明
	*信号没有返回值，但可以有参数
	*信号就是函数的声明，只需声明，无需定义
	*使用方法：emit mysignal();
	*/
	void signalSwitch();

public slots:

void on_actionFTP_triggered();
void on_actionOpen_triggered();
void on_pushButton1_clicked();
void on_pushButton2_clicked();

};
