#include "Reconstruction.h"
#include "welcome.h"
#include "datalist.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QMovie>
#include <QTime>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//欢迎界面
	QPixmap pixmap("..\\image\\sunny.png");
	//QMovie myMovie("..\\image\\JNU.gif");
	//QSplashScreen splash(pixmap);
	//splash.show();

	QMovie *myMovie = new QMovie("..\\image\\JNU.gif");
	QLabel *label = new QLabel("", 0);
	label->setMovie(myMovie);
	myMovie->start();

	label->setWindowFlags(Qt::FramelessWindowHint);//隐藏边框
	//将窗口移动到合适的位置
	label->move(120, 80);
	label->show();

	QTime t;
	t.start();
	while (t.elapsed() < 3500)
	{
		a.processEvents();
	}

	label->hide();
	//myMovie->start();

	//显示FTP窗口
	Reconstruction w;
	w.show();

	//Welcome w;
	//w.show();

	//splash.finish(&w);

	//DataList list;
	//list.show();
	
	return a.exec();
}
