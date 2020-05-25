#include "welcome.h"
#include <QPainter>
#include <QMovie>

Welcome::Welcome(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	setAttribute(Qt::WA_TranslucentBackground);

	//将窗口移动到合适的位置
	this->move(200, 100);


}

Welcome::~Welcome()
{
}

void Welcome::paintEvent(QPaintEvent *)
{
	//QPainter p(this);//指定welcomeW为绘图设备
	//p.drawPixmap(0, 0, QPixmap("..\\image\\sunny.png"));

}
