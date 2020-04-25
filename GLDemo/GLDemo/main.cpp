#include "gldemo.h"
#include <qsplitter.h>
#include <qtimer.h>
#include <QtWidgets/QApplication>

using namespace Qwt3D;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GLDemo w;
	//w.resize(QSize(800, 400));
	w.show();

	

	return a.exec();
}
