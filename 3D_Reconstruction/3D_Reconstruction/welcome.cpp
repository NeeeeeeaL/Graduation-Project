#include "welcome.h"
#include <QPainter>
#include <QMovie>

Welcome::Welcome(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	setAttribute(Qt::WA_TranslucentBackground);

	//�������ƶ������ʵ�λ��
	this->move(200, 100);


}

Welcome::~Welcome()
{
}

void Welcome::paintEvent(QPaintEvent *)
{
	//QPainter p(this);//ָ��welcomeWΪ��ͼ�豸
	//p.drawPixmap(0, 0, QPixmap("..\\image\\sunny.png"));

}
