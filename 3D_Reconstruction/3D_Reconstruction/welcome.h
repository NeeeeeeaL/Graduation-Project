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
	//��д��ͼ�¼����麯��
	//����ڴ��ڻ�ͼ��������ڻ�ͼ�¼���ʵ��
	//��ͼ�¼��ڲ��Զ����ã�������Ҫ�ػ��ʱ��
	void paintEvent(QPaintEvent *);

private:
	Ui::Welcome ui;
};
