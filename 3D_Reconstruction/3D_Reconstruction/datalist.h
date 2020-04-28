#pragma once

#include <QWidget>
#include "ui_datalist.h"

//���ݿ����
#include "QSqlDatabase"
#include <QSqlQuery>//��SQL����������
#include <QSqlError>
#include <QSqlTableModel>

#include <QMessageBox>
#include <iostream>


class DataList : public QWidget
{
	Q_OBJECT

public:
	DataList(QWidget *parent = Q_NULLPTR);
	~DataList();

private:
	Ui::DataList ui;

	QSqlTableModel *model;
};
