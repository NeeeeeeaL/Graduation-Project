#pragma once

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include "ui_learngl.h"

class LearnGL : public QOpenGLWindow
{
	Q_OBJECT

public:
	LearnGL(QWidget *parent = Q_NULLPTR);

private:
	Ui::LearnGLClass ui;
};
