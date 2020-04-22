#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_openglprotest.h"

class OpenGLProTest : public QMainWindow
{
	Q_OBJECT

public:
	OpenGLProTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::OpenGLProTestClass ui;
};
