#pragma once

#include <QWidget>
#include "ui_calibration.h"

class Calibration : public QWidget
{
	Q_OBJECT

public:
	Calibration(QWidget *parent = Q_NULLPTR);
	~Calibration();

private:
	Ui::Calibration ui;
};
