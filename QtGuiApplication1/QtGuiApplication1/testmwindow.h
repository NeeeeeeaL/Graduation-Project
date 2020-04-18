#pragma once

#include <QMainWindow>
#include "ui_testmwindow.h"

class TestMWindow : public QMainWindow
{
	Q_OBJECT

public:
	TestMWindow(QWidget *parent = Q_NULLPTR);
	~TestMWindow();

private:
	Ui::TestMWindow ui;
};
