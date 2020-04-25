#pragma once

#include <QWidget>
#include "ui_childtest.h"

class childTest : public QMainWindow
{
	Q_OBJECT

public:
	childTest(QWidget *parent = Q_NULLPTR);
	~childTest();

private:
	Ui::childTest ui;
};
