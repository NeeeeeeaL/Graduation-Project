#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_gldemo.h"
#include "childtest.h"
#include "mywidget.h"

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include "qwt3d_surfaceplot.h"
#include "qwt3d_function.h"

typedef Qwt3D::SurfacePlot SurfacePlot; // VC6/moc issue
typedef Qwt3D::Function Function; // VC6/moc issue

using namespace cv;

class GLDemo : public QMainWindow
{
	Q_OBJECT

public:
	GLDemo(QWidget *parent = Q_NULLPTR);
	childTest *myTest;
	MyWidget *widget;

private:
	Ui::GLDemoClass ui;

public slots:
	void on_pushButton_clicked();
	void on_pushButton2_clicked();
	void on_comboBox_activated(int);
		
};


//class Saddle : public Function
//{
//public:
//	Saddle(SurfacePlot& pw)
//		:Function(pw)
//	{
//		setDomain(-2.5, 2.5, -2.5, 2.5);
//		setMaxZ(1.5);
//		setMinZ(-1.5);
//		setMesh(31, 31);
//	}
//
//	double operator()(double x, double y)
//	{
//		return x * y;
//	}
//};
//
//class Hat : public Function
//{
//public:
//
//	Hat(SurfacePlot& pw)
//		:Function(pw)
//	{
//		setDomain(-1.5, 1.5, -1.5, 1.5);
//		setMesh(51, 51);
//	}
//
//	double operator()(double x, double y)
//	{
//		return 1.0 / (x*x + y*y + 0.3);
//	}
//};
//
//class Plot : public SurfacePlot
//{
//	//Q_OBJECT
//
//public:
//	Plot(QWidget* pw, int updateinterval);
//	Plot(QWidget* pw, Mat &m);
//
//public slots:
//	void rotate();
//
//};