#include "openglTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	openglTest w;
	w.show();
	return a.exec();
}
