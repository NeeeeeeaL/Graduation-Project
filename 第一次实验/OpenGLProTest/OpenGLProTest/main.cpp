#include "openglprotest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OpenGLProTest w;
	w.show();
	return a.exec();
}
