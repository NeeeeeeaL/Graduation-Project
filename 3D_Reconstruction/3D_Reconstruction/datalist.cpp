#include "datalist.h"

using namespace std;

DataList::DataList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);




	//��ѯ��������

	//QString select_all_sql = "select * from position";

	//QSqlQuery sql_query(db);

	//sql_query.prepare(select_all_sql);//Ԥ����

	//if (!sql_query.exec())

	//{
	//	cout << sql_query.lastError();
	//}

	//else

	//{
	//	while (sql_query.next())

	//	{

	//		QString name = sql_query.value(0).toString();
	//		QString volume = sql_query.value(1).toString();
	//		QString height = sql_query.value(2).toString();
	//		QString x = sql_query.value(3).toString();
	//		QString y = sql_query.value(4).toString();
	//		QString z = sql_query.value(5).toString();
	//		//ui.textEdit->setText(QString("username: %1    password: %2    classification: %3").arg(username).arg(password).arg(classification));
	//		cout << QString("name: %1    volume: %2    volume: %3").arg(name).arg(volume).arg(height);
	//	}

	//}


	


}

//�鿴���ݿ�
void DataList::on_pushButton_clicked()
{

	/*********************���ݿ����Ӽ����ݱ���ʾ********************/
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//ѡ������QMYSQL

	db.setHostName("localhost");
	db.setUserName("root");
	db.setPassword("yjm666");
	db.setDatabaseName("3dreconstruction");
	//Ĭ�ϵĶ˿ڿ��Բ�д
	//db.setPort(3306);

	if (db.open())
		cout << "Connection with database is successful!";
	else
		QMessageBox::warning(this, "Connection is failed!", db.lastError().text());

	//����ģ��
	model = new QSqlTableModel(this);
	model->setTable("position");//ָ��admin���ݱ�


								//��model����tabview
	ui.tableView->setModel(model);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	//��ʾmodel������
	model->select();
}

DataList::~DataList()
{
}
