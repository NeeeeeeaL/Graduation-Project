#include "play.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
	QGuiApplication a(argc, argv);
	Play w;
	w.resize(QSize(1280, 720));
	//QPushButton ptn(&w);

	w.show();
	return a.exec();
}
