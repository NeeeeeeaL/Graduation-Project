#pragma once

#include <QWidget>
#include "ui_welcome.h"

class Welcome : public QWidget
{
	Q_OBJECT

public:
	Welcome(QWidget *parent = Q_NULLPTR);
	~Welcome();

protected:
	//重写绘图事件，虚函数
	//如果在窗口绘图，必须放在绘图事件力实现
	//绘图事件内部自动调用（窗口需要重绘的时候）
	void paintEvent(QPaintEvent *);

private:
	Ui::Welcome ui;
};
