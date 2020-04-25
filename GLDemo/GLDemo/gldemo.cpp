#include "gldemo.h"

#include <qapplication.h>
#include <qsplitter.h>
#include <qtimer.h>

using namespace Qwt3D;
using namespace cv;

GLDemo::GLDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	widget = new MyWidget(this);
	widget->hide();
//
//#if QT_VERSION < 0x040000
//	QSplitter* spl = new QSplitter(QSplitter::Horizontal);
//#else
//	QSplitter* spl = new QSplitter(Qt::Horizontal);
//#endif
//	Plot* plot1 = new Plot(spl, 130);
//	//Plot* plot1 = new Plot(ui.widget, 30);
//	plot1->setFloorStyle(FLOORDATA);
//	plot1->setCoordinateStyle(BOX);
//	Saddle saddle(*plot1);
//	saddle.create();
//	plot1->setTitle("Autoswitching axes");
//	plot1->setBackgroundColor(RGBA(1, 1, 157. / 255));
//	plot1->makeCurrent();
//	plot1->updateData();
//	plot1->updateGL();
//
//
//	Plot* plot2 = new Plot(spl, 80);
//	plot2->setZoom(0.8);
//	Hat hat(*plot2);
//	hat.create();
//	plot2->setPlotStyle(HIDDENLINE);
//	plot2->setFloorStyle(FLOORDATA);
//	plot2->setCoordinateStyle(FRAME);
//	plot2->setBackgroundColor(RGBA(1, 1, 157. / 255));
//	plot2->makeCurrent();
//	plot2->updateData();
//	plot2->updateGL();
//
//
//#if QT_VERSION < 0x040000
//	a.setMainWidget(spl);
//#endif
//	spl->resize(800, 400);
//	//spl->move(50, 50);
//	spl->show();
//
//	Mat m = imread("mouse.png", 0);
//	Mat m2(m.rows, m.cols, CV_64FC1);
//	m.convertTo(m2, CV_64FC1);
//
//	QSplitter* spl1 = new QSplitter(Qt::Horizontal, this);
//	Plot* plot3 = new Plot(spl1, m2);
//
//	spl1->resize(800, 400);
//	//Plot w2(spl1, m2);
//	//w2.show();
//	spl1->show();

}

void GLDemo::on_pushButton_clicked()
{
	//myTest = new childTest(this);

	//myTest->show();

	
	widget->move(50, 50);
	widget->show();
	ui.calendarWidget->hide();
}

void GLDemo::on_pushButton2_clicked()
{
	widget->hide();
	ui.calendarWidget->show();
}

void GLDemo::on_comboBox_activated(int index)
{

	if (index == 1)
	{
		widget->move(50, 50);
		widget->show();
		ui.calendarWidget->hide();
	}
	else if (index == 0)
	{
		widget->hide();
		ui.calendarWidget->show();
	}
}

//Plot::Plot(QWidget* pw, int updateinterval)
//	:SurfacePlot(pw)
//{
//	setRotation(30, 0, 15);
//	setShift(0.1, 0, 0);
//	setZoom(0.8);
//	coordinates()->setNumberFont("Courier", 8);
//
//	for (unsigned i = 0; i != coordinates()->axes.size(); ++i)
//	{
//		coordinates()->axes[i].setMajors(7);
//		coordinates()->axes[i].setMinors(4);
//	}
//
//
//	coordinates()->axes[Qwt3D::X1].setLabelString("x");
//	coordinates()->axes[Y1].setLabelString("y");
//	coordinates()->axes[Z1].setLabelString("z");
//	coordinates()->axes[X2].setLabelString("x");
//	coordinates()->axes[Y2].setLabelString("y");
//	coordinates()->axes[Z2].setLabelString("z");
//	coordinates()->axes[X3].setLabelString("x");
//	coordinates()->axes[Y3].setLabelString("y");
//	coordinates()->axes[Z3].setLabelString("z");
//	coordinates()->axes[X4].setLabelString("x");
//	coordinates()->axes[Y4].setLabelString("y");
//	coordinates()->axes[Z4].setLabelString("z");
//
//
//	QTimer* timer = new QTimer(this);
//	connect(timer, SIGNAL(timeout()), this, SLOT(rotate()));
//
//	timer->start(updateinterval);
//
//}
//
////Mat×ªÈýÎ¬
//Plot::Plot(QWidget* pw, Mat & m)
//	:SurfacePlot(pw)
//{
//	setTitle("A Simple SurfacePlot Demonstration");
//
//	coordinates()->axes[X1].setLabelString("x-axis");
//	coordinates()->axes[Y1].setLabelString("y-axis");
//
//	double *imgData = (double *)m.data;
//	double **p2 = new double *[m.rows];
//	for (int i = 0; i < m.rows; i++)
//	{
//		p2[i] = imgData + i*m.cols;
//	}
//
//	loadFromData(p2, m.rows, m.cols, 0, m.rows, 0, m.cols);
//
//	setRotation(30, 0, 15);
//	setScale(1, 1, 1);
//	setShift(0.15, 0, 0);
//	setZoom(0.9);
//	setMeshColor(RGBA(0.1, 0.5, 1));
//	setBackgroundColor(RGBA(1, 1, 157. / 255));
//	setCoordinateStyle(FRAME);
//	setPlotStyle(Qwt3D::POINTS);
//	setFloorStyle(NOFLOOR);
//	setCoordinateStyle(FRAME);
//
//	updateData();
//	updateGL();
//}
//
//void Plot::rotate()
//{
//	int prec = 3;
//
//	setRotation(
//		(int(prec*xRotation() + 2) % (360 * prec)) / double(prec),
//		(int(prec*yRotation() + 2) % (360 * prec)) / double(prec),
//		(int(prec*zRotation() + 2) % (360 * prec)) / double(prec)
//	);
//}


