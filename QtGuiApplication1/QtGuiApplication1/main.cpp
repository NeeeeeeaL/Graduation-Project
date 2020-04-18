#include "qtguiapplication1.h"
#include "testmwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiApplication1 w;
	w.show();

	TestMWindow w1;
	w1.show();
	return a.exec();
}
