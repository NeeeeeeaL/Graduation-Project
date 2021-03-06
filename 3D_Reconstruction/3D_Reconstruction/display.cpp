#include "display.h"

using namespace Qwt3D;

Display::Display(QWidget *parent)
	: QWidget(parent)
{
}

Display::~Display()
{
}

Plot::Plot(QWidget* pw, cv::Mat & m)
	:SurfacePlot(pw)
{
	setTitle("3D Reconstruction");
	QFont font;
	font.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
	setFont(font);

	coordinates()->axes[X1].setLabelString("x-axis");
	coordinates()->axes[Y1].setLabelString("y-axis");

	//相位-高度转换
	//for (int i = 0; i < m.rows; ++i)
	//{
	//	for (int j = 0; j < m.cols; ++j)
	//	{
	//		m.at<double>(i, j) /= 18.0;
	//	}
	//}

	double *imgData = (double *)m.data;
	double **p2 = new double *[m.rows];
	for (int i = 0; i < m.rows; i++)
	{
		p2[i] = imgData  + i*m.cols;
	}

	loadFromData(p2, m.rows, m.cols, 0, m.rows, 0, m.cols);

	setRotation(30, 0, 15);
	setScale(1, 1, 1);
	setShift(0.15, 0, 0);
	setZoom(0.9);
	setMeshColor(RGBA(33. / 255, 64. / 255, 102. / 255));
	setBackgroundColor(RGBA(214. / 255, 219. /255, 233. / 255));
	setCoordinateStyle(FRAME);
	setPlotStyle(Qwt3D::POINTS);
	setFloorStyle(NOFLOOR);
	setCoordinateStyle(FRAME);

	updateData();
	updateGL();
}
