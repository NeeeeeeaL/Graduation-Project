#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_differtest.h"

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

class DifferTest : public QMainWindow
{
	Q_OBJECT

public:
	DifferTest(QWidget *parent = Q_NULLPTR);

	void fft2(const cv::Mat & src, cv::Mat & Fourier);
	void circshift(cv::Mat &out, const cv::Point &delta);
	void fftshift(cv::Mat &out);

private:
	Ui::DifferTestClass ui;
};
