#pragma once

#include <QWidget>
#include "ui_calibration.h"
#include "QDebug"

//相机标定用头文件
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

class Calibration : public QWidget
{
	Q_OBJECT

public:
	Calibration(QWidget *parent = Q_NULLPTR);
	~Calibration();

	cv::Mat imgSrc1;
	cv::Mat imgSrc2;
	cv::Mat imgSrc3;
	cv::Mat imgSrc4;
	cv::Mat imgSrc5;
	cv::Mat imgSrc6;
	cv::Mat imgSrc7;
	cv::Mat imgSrc8;
	cv::Mat imgSrc9;
	cv::Mat imgSrc10;
	cv::Mat imgSrc11;
	cv::Mat imgSrc12;

	//定义保存图像的容器
	vector<cv::Mat> calibImg;

	void dealLoadCalibImg();

public slots:
	void on_pushButton1_clicked();
	void on_pushButton2_clicked();

private:
	Ui::Calibration ui;
	//Reconstruction reconWindow;

protected:
	void LabelDisplayMat(cv::Mat& mat_img, QLabel* label);
};
