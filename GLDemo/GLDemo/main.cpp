#include "gldemo.h"
#include <qsplitter.h>
#include <qtimer.h>
#include <QtWidgets/QApplication>

using namespace Qwt3D;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GLDemo w;
	w.show();

#if QT_VERSION < 0x040000
	QSplitter* spl = new QSplitter(QSplitter::Horizontal);
#else
	QSplitter* spl = new QSplitter(Qt::Horizontal);
#endif
	Plot* plot1 = new Plot(spl, 30);
	plot1->setFloorStyle(FLOORISO);
	plot1->setCoordinateStyle(BOX);
	Saddle saddle(*plot1);
	saddle.create();
	plot1->setTitle("Autoswitching axes");
	plot1->setBackgroundColor(RGBA(1, 1, 157. / 255));
	plot1->makeCurrent();
	plot1->updateData();
	plot1->updateGL();


	Plot* plot2 = new Plot(spl, 80);
	plot2->setZoom(0.8);
	Hat hat(*plot2);
	hat.create();
	plot2->setPlotStyle(HIDDENLINE);
	plot2->setFloorStyle(FLOORDATA);
	plot2->setCoordinateStyle(FRAME);
	plot2->setBackgroundColor(RGBA(1, 1, 157. / 255));
	plot2->makeCurrent();
	plot2->updateData();
	plot2->updateGL();


#if QT_VERSION < 0x040000
	a.setMainWidget(spl);
#endif
	spl->resize(800, 400);
	spl->show();
	return a.exec();
}
