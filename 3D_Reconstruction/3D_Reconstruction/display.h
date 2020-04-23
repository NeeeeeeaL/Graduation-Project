#pragma once

#include <QWidget>

#include "qwt3d_surfaceplot.h"
#include "qwt3d_function.h"

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

typedef Qwt3D::SurfacePlot SurfacePlot; // VC6/moc issue
typedef Qwt3D::Function Function; // VC6/moc issue


class Display : public QWidget
{
	//Q_OBJECT

public:
	Display(QWidget *parent);
	~Display();
};


class Plot : public SurfacePlot
{
	//Q_OBJECT

public:
	Plot(QWidget* pw, cv::Mat &m);

};
