#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Reconstruction.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include "pmpTrans.h"
#include "welcome.h"

#include <QSqlTableModel>

using namespace cv;
using namespace std;


class Reconstruction : public QMainWindow
{
	Q_OBJECT

public:
	Reconstruction(QWidget *parent = Q_NULLPTR);

	void dealChild();

protected:
	//重写绘图事件，虚函数
	//如果在窗口绘图，必须放在绘图事件力实现
	//绘图事件内部自动调用（窗口需要重绘的时候）
	void paintEvent(QPaintEvent *);

	void LabelDisplayMat(Mat& mat_img, QLabel* label);

private:
	Ui::ReconstructionClass ui;

	PMPTrans windowPMP;
	Welcome welcomeW;
	QSqlTableModel *model;


public:
	//尽量避免对全局变量进行操作，可在函数内声明临时变量，
	//对临时变量进行操作，完成后再将值赋给全局变量
	QImage img1, img2;

	Mat imgOriginal_src;
	Mat imgOriginal_fft;
	Mat imgOriginal_filt;
	Mat imgOriginal_ifft;
	Mat imgOriginal_angel;

	Mat imgModulated_src;
	Mat imgModulated_fft;
	Mat imgModulated_filt;
	Mat imgModulated_ifft;
	Mat imgModulated_angel;

	Mat wrappedPhase;
	Mat unwrappedPhase;

public slots:

//图像处理操作按钮槽函数
void on_pushButton_clicked();//傅里叶变换
void on_pushButton_2_clicked();//滤波按钮
void on_pushButton_3_clicked();//傅里叶反变换
void on_pushButton_4_clicked();//求相位
void on_pushButton_5_clicked();//解相位

//三维重建一步操作
void on_pushButton_7_clicked();//One Step 

//菜单栏操作按钮槽函数
void on_actionOpen_triggered();
void on_actionSave_triggered();
void on_actionPMP_triggered();

};
