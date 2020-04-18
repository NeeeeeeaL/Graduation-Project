#include "learngl.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LearnGL w;
	w.show();
	return a.exec();
}
