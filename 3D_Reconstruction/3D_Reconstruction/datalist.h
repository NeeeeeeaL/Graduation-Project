#pragma once

#include <QWidget>
#include "ui_datalist.h"

//数据库相关
#include "QSqlDatabase"
#include <QSqlQuery>//用SQL语句操作的类
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>

#include <QMessageBox>
#include <iostream>


class DataList : public QWidget
{
	Q_OBJECT

public:
	DataList(QWidget *parent = Q_NULLPTR);
	~DataList();

public slots:
void on_pushButton_clicked();


private:
	Ui::DataList ui;

	QSqlTableModel *model;
};
