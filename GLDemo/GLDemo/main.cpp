#include "gldemo.h"
#include <qsplitter.h>
#include <qtimer.h>
#include <QtWidgets/QApplication>

using namespace Qwt3D;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GLDemo w;
	w.resize(QSize(800, 400));
	w.show();

	Mat m = imread("mouse.png", 0);
	Mat m2(m.rows, m.cols, CV_64FC1);
	m.convertTo(m2, CV_64FC1);

	Plot w2(m2);
	w2.show();

	return a.exec();
}
