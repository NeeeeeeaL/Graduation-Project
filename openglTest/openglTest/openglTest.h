#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_openglTest.h"

class openglTest : public QMainWindow
{
	Q_OBJECT

public:
	openglTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::openglTestClass ui;
};
