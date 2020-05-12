#include "differtest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DifferTest w;
	w.show();
	return a.exec();
}
