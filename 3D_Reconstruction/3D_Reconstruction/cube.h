#pragma once

#include <QWidget>
#include "ui_cube.h"

class Cube : public QWidget
{
	Q_OBJECT

public:
	Cube(QWidget *parent = Q_NULLPTR);
	~Cube();

private:
	Ui::Cube ui;
};
