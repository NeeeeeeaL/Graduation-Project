#include "Reconstruction.h"
#include "imageProcess.h"
#include "unwrap.h"
#include "display.h"
#include <QPainter>
#include <QtWidgets/QApplication>
#include <iostream>
#include <QFile>
#include <QLabel>
#include <QFileDialog>
#include <QDebug>
#include <QGridLayout>
#include <QTextCodec> //ת���ַ�ͷ�ļ�
#include <QMessageBox>
#include <QSplitter>

//���ݿ����
#include "QSqlDatabase"
#include <QSqlQuery>//��SQL����������
#include <QSqlError>
#include <QSqlTableModel>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

QTextCodec *codecParent;

using namespace Qwt3D;
using namespace std;


//�����ڹ��캯��
Reconstruction::Reconstruction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	//��ʼ��codec
	codecParent = QTextCodec::codecForName("GBK");

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


	//��������

	//����ģ��
	model = new QSqlTableModel(this);
	model->setTable("position");//ָ��admin���ݱ�


	//��model����tabview
	ui.tableView->setModel(model);

	//��ʾmodel������
	model->select();


	/***********************��������ʼ������***********************/
	this->setWindowIcon(QIcon("myico.ico"));
	statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // ���ò���ʾlabel�ı߿�
	statusBar()->setSizeGripEnabled(false); //�����Ƿ���ʾ�ұߵĴ�С���Ƶ�
	statusBar()->addWidget(ui.labelStatus, 4);
	ui.statusBar->addWidget(ui.progressBar, 1);
	ui.labelStatus->setText("Ready");
	ui.progressBar->setVisible(true);
	ui.progressBar->setMinimum(0);
	ui.progressBar->setMaximum(100);
	ui.progressBar->reset();


	//�������ƶ������ʵ�λ��
	this->move(120, 40);

	//����TabWidget�ĳ�ʼTab
	ui.tabWidget1->setCurrentIndex(0);
	ui.tabWidget2->setCurrentIndex(0);

	//�޸�toolbox��page����
	ui.toolBox->setItemText(0, codecParent->toUnicode("�ֶ�����"));
	ui.toolBox->setItemText(1, codecParent->toUnicode("�Զ�����"));

	//�����Ӵ����ź�
	connect(&windowPMP, &PMPTrans::signalSwitch, this, &Reconstruction::dealChild);
	connect(&windowPMP, &PMPTrans::signalNotOpen, this, &Reconstruction::dealNotOpen);
	connect(&windowPMP, &PMPTrans::signalNotGetP, this, &Reconstruction::dealNotGetP);

	
}

//�����Ӵ��ڷ��͵���Ϣ
void Reconstruction::dealChild()
{
	windowPMP.hide();
	this->show();
}

//δ��ͼƬ������λ
void Reconstruction::dealNotOpen()
{
	QMessageBox::about(this, codecParent->toUnicode("��ʾ"), codecParent->toUnicode("��δ��ͼƬ��"));

}

void Reconstruction::dealNotGetP()
{
	QMessageBox::about(this, codecParent->toUnicode("��ʾ"), codecParent->toUnicode("��δ����λ��"));

}

//��ͼ�����о�����Ҫ���и��ӵ����ݴ���
//��Ϊ��ͼ�����ᱻƵ������
void Reconstruction::paintEvent(QPaintEvent *)
{
	QPainter p(this);//ָ��welcomeWΪ��ͼ�豸

	//�������ʶ���
	QPen pen;
	pen.setWidth(5);
	pen.setColor(QColor(0, 255, 0));

	//�ѱʽ�������
	p.setPen(pen);

	//��ͼ����
	//������ͼ
	//p.drawPixmap(0, 0, width(), height(), QPixmap("mouse.bmp"));//width(), height()�Զ���ȡ���ڿ�Ⱥ͸߶�
	p.fillRect(rect(), Qt::white);

	//������ˢ����
	QBrush brush;
	brush.setColor(Qt::green);
	brush.setStyle(Qt::Dense1Pattern);

	//�ѻ�ˢ��������
	p.setBrush(brush);	

}

//��QLabel����ʾMatͼ��
void Reconstruction::LabelDisplayMat(cv::Mat & mat_img, QLabel * label)
{
	QImage img;
	if (mat_img.channels() == 3)//RGB image
	{
		cvtColor(mat_img, mat_img, CV_BGR2RGB); //Mat:BGR  //QImage:RGB
		img = QImage((const unsigned char*)(mat_img.data), mat_img.cols, mat_img.rows,
			mat_img.cols * mat_img.channels(), QImage::Format_RGB888);
	}
	else//Gray image
	{
		img = QImage((const unsigned char*)(mat_img.data), mat_img.cols, mat_img.rows,
			mat_img.cols * mat_img.channels(), QImage::Format_Indexed8);
	}
	QPixmap pixmap = QPixmap::fromImage(img);
	//QPixmap fitpixmap = pixmap.scaled(label->width(), label->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); //�������
	QPixmap fitpixmap = pixmap.scaled(label->width(), label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation); //�ȱ������
	label->setPixmap(fitpixmap);
	label->setAlignment(Qt::AlignCenter);//ͼƬ������ʾ
}

//��ɢ����Ҷ�任
void Reconstruction::on_pushButton_clicked()
{
	if (isOpen == true)
	{
		long t1 = cv::getTickCount();

		ui.labelStatus->setText("Start the DFT transformation...");
		ui.progressBar->setValue(10);
		//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked));

		//������ʱ����
		//Mat imgOriTmp = imgOriginal_src.clone();
		//Mat imgMdaTmp = imgModulated_src.clone();
		//Mat imgOrifftTmp;
		//Mat imgMdafftTmp;

		//����Ҷ�任
		imgOriginal_src.convertTo(imgOriginal_src, CV_64F, 1.0 / 255.0);//����Ҷ�任���������б����Ǹ�����
		imgModulated_src.convertTo(imgModulated_src, CV_64F, 1.0 / 255.0);
		//imgOriTmp.convertTo(imgOriTmp, CV_64F, 1.0 / 255.0);//����Ҷ�任���������б����Ǹ�����
		//imgMdaTmp.convertTo(imgMdaTmp, CV_64F, 1.0 / 255.0);

		ui.progressBar->setValue(20);

		ImageProcess imgDft;
		imgDft.fft2(imgOriginal_src, imgOriginal_fft);
		ui.progressBar->setValue(40);
		imgDft.fft2(imgModulated_src, imgModulated_fft);
		//imgDft.fft2(imgOriTmp, imgOrifftTmp);
		//imgDft.fft2(imgMdaTmp, imgMdafftTmp);

		ui.progressBar->setValue(60);

		imgDft.fftshift(imgOriginal_fft);
		ui.progressBar->setValue(70);
		imgDft.fftshift(imgModulated_fft); //CV_64FC2
		//imgDft.fftshift(imgOrifftTmp);
		//imgDft.fftshift(imgMdafftTmp); //CV_64FC2

		ui.progressBar->setValue(80);

		cv::Mat imgDisplay1;
		cv::Mat imgDisplay2;

		imgDft.changeCh(imgOriginal_fft, imgDisplay1);
		imgDft.changeCh(imgModulated_fft, imgDisplay2);
		//imgDft.changeCh(imgOrifftTmp, imgDisplay1);
		//imgDft.changeCh(imgMdafftTmp, imgDisplay2);

		ui.progressBar->setValue(100);

		LabelDisplayMat(imgDisplay1, ui.labelImg1_2);
		LabelDisplayMat(imgDisplay2, ui.labelImg2_2);
	
		ui.tabWidget1->setCurrentIndex(1);
		ui.tabWidget2->setCurrentIndex(1);

		ui.progressBar->reset();

		ui.labelStatus->setText("Ready");

		isFFT = true;

		//����ʱ��������ȫ�ֱ���
		//imgOriginal_src = imgOriTmp.clone();
		//imgModulated_src = imgMdaTmp.clone();
		//imgOriginal_fft = imgOrifftTmp.clone();
		//imgModulated_fft = imgMdafftTmp.clone();

		long t2 = cv::getTickCount();
		cout << "Time of fft :" << (t2 - t1) / 1e7 << "s" << endl;
	}
	else
		QMessageBox::about(this, codecParent->toUnicode("��ʾ"), codecParent->toUnicode("��δ��ͼƬ��"));
}

//�˲�
void Reconstruction::on_pushButton_2_clicked()
{
	if (isFFT == true)
	{
		long t1 = cv::getTickCount();
		ui.labelStatus->setText("Start to filt...");
		ui.progressBar->setValue(10);

		//������ʱ����
		//Mat imgOrifftTmp = imgOriginal_fft.clone();
		//Mat imgMdafftTmp = imgModulated_fft.clone();
		//Mat imgOrifiltTmp;
		//Mat imgMdafiltTmp;

		ImageProcess imgFilt;
		imgFilt.filt(imgOriginal_fft, imgOriginal_filt);
		ui.progressBar->setValue(30);
		imgFilt.filt(imgModulated_fft, imgModulated_filt);
		ui.progressBar->setValue(50);
		//imgFilt.filt(imgOrifftTmp, imgOrifiltTmp);
		//imgFilt.filt(imgMdafftTmp, imgMdafiltTmp);

		cv::Mat imgDisplay1;
		cv::Mat imgDisplay2;

		imgFilt.changeCh(imgOriginal_filt, imgDisplay1);
		ui.progressBar->setValue(70);
		imgFilt.changeCh(imgModulated_filt, imgDisplay2);
		ui.progressBar->setValue(90);
		//imgFilt.changeCh(imgOrifiltTmp, imgDisplay1);
		//imgFilt.changeCh(imgMdafiltTmp, imgDisplay2);

		cout << "imgOriginal_filt.type = " << imgOriginal_filt.type() << endl;

		ui.progressBar->setValue(100);
		LabelDisplayMat(imgDisplay1, ui.labelImg1_3);
		LabelDisplayMat(imgDisplay2, ui.labelImg2_3);

		ui.tabWidget1->setCurrentIndex(2);
		ui.tabWidget2->setCurrentIndex(2);

		ui.progressBar->reset();
		ui.labelStatus->setText("Ready");
		isFilt = true;

		//����ʱ��������ȫ�ֱ���
		//imgOriginal_filt = imgOrifiltTmp.clone();
		//imgModulated_filt = imgMdafiltTmp.clone();

		long t2 = cv::getTickCount();
		cout << "Time of filt :" << (t2 - t1) / 1e7 << "s" << endl;
	}
	else
		QMessageBox::about(this, codecParent->toUnicode("��ʾ"), codecParent->toUnicode("��δ���и���Ҷ�任��"));
}

//����Ҷ���任
void Reconstruction::on_pushButton_3_clicked()
{
	if (isFilt == true)
	{
		long t1 = cv::getTickCount();
		ui.labelStatus->setText("Start the IDFT transformation...");
		ui.progressBar->setValue(10);
		//������ʱ����
		//Mat imgOrifiltTmp = imgOriginal_filt;
		//Mat imgMdafiltTmp = imgModulated_filt;
		//Mat imgOriifftTmp;
		//Mat imgMdaifftTmp;

		ImageProcess imgIfft;

		imgIfft.ifftshift(imgOriginal_filt);
		ui.progressBar->setValue(20);
		imgIfft.ifftshift(imgModulated_filt); //CV_64FC2
		ui.progressBar->setValue(30);
		//imgIfft.ifftshift(imgOrifiltTmp);
		//imgIfft.ifftshift(imgMdafiltTmp); //CV_64FC2

		imgIfft.ifft2(imgOriginal_filt, imgOriginal_ifft);
		ui.progressBar->setValue(40);
		imgIfft.ifft2(imgModulated_filt, imgModulated_ifft); //CV_64FC2
		ui.progressBar->setValue(50);
		//imgIfft.ifft2(imgOrifiltTmp, imgOriifftTmp);
		//imgIfft.ifft2(imgMdafiltTmp, imgMdaifftTmp); //CV_64FC2

		cv::Mat imgDisplay1;
		cv::Mat imgDisplay2;

		vector<cv::Mat> planes1;
		vector<cv::Mat> planes2;

		split(imgOriginal_ifft, planes1);
		//split(imgOriifftTmp, planes1);
		imgDisplay1 = planes1[0];

		split(imgModulated_ifft, planes2);
		//split(imgMdaifftTmp, planes2);
		imgDisplay2 = planes2[0];
		ui.progressBar->setValue(60);

		for (int i = 0; i < imgDisplay1.rows; ++i)
		{
			for (int j = 0; j < imgDisplay1.cols; ++j)
			{
				imgDisplay1.at<double>(i, j) *= 255;
				imgDisplay2.at<double>(i, j) *= 255;
			}

			if( i == imgDisplay1.rows / 2)
				ui.progressBar->setValue(80);
		}

		ui.progressBar->setValue(90);
		imgDisplay1.convertTo(imgDisplay1, CV_8U);
		imgDisplay2.convertTo(imgDisplay2, CV_8U);

		ui.progressBar->setValue(100);
		LabelDisplayMat(imgDisplay1, ui.labelImg1_4);
		LabelDisplayMat(imgDisplay2, ui.labelImg2_4);

		cout << "imgOriginal_ifft.type = " << imgOriginal_ifft.type() << endl;

		ui.tabWidget1->setCurrentIndex(3);
		ui.tabWidget2->setCurrentIndex(3);

		ui.progressBar->reset();
		ui.labelStatus->setText("Ready");
		isIFFT = true;

		//����ʱ��������ȫ�ֱ���
		//imgOriginal_ifft = imgOriifftTmp;
		//imgModulated_ifft = imgMdaifftTmp;

		long t2 = cv::getTickCount();
		cout << "Time of ifft :" << (t2 - t1) / 1e7 << "s" << endl;
	}
	else
		QMessageBox::about(this, codecParent->toUnicode("��ʾ"), codecParent->toUnicode("��δ�˲���"));

}

//����λ
void Reconstruction::on_pushButton_4_clicked()
{
	if (isIFFT == true)
	{
		long t1 = cv::getTickCount();
		ui.labelStatus->setText("Start to obtain the angel...");
		ui.progressBar->setValue(10);

		cv::Mat imgTmp1(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));
		cv::Mat imgTmp2(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));

		//������ʱ����
		//Mat imgOriifftTmp = imgOriginal_ifft.clone();
		//Mat imgMdaifftTmp = imgModulated_ifft.clone();

		//��͵��һ�㶼���У�����ֻ����һ��imgTmp�����������������������������ݻ���ͬ
		imgOriginal_angel = imgTmp1;
		imgModulated_angel = imgTmp2;//��imgModulated_angel����ֵ����������λʱ����

		vector<cv::Mat> planes1;
		vector<cv::Mat> planes2;

		split(imgOriginal_ifft, planes1);
		split(imgModulated_ifft, planes2);
		ui.progressBar->setValue(20);
		//split(imgOriifftTmp, planes1);
		//split(imgMdaifftTmp, planes2);

		for (int i = 0; i < imgOriginal_ifft.rows; ++i)
		{
			for (int j = 0; j < imgOriginal_ifft.cols; ++j)
			{
				imgOriginal_angel.at<double>(i, j) =
					atan2(planes1[1].at<double>(i, j), planes1[0].at<double>(i, j));

				imgModulated_angel.at<double>(i, j) =
					atan2(planes2[1].at<double>(i, j), planes2[0].at<double>(i, j));

				//imgTmp1.at<double>(i, j) =
				//	atan2(planes1[1].at<double>(i, j), planes1[0].at<double>(i, j));

				//imgTmp2.at<double>(i, j) =
				//	atan2(planes2[1].at<double>(i, j), planes2[0].at<double>(i, j));
			}
		}
		ui.progressBar->setValue(30);
		/**************����***************/
		cv::Mat imgTmp3(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));
		cv::Mat imgTmp4(imgModulated_src.rows, imgModulated_src.cols, CV_32F, cv::Scalar(0));
		cv::Mat wrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));
		cv::Mat unwrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_32F, cv::Scalar(0));

		wrappedPhase = imgTmp3;
		unwrappedPhase = imgTmp4;

		for (int i = 0; i < wrappedPhase.rows; ++i)
		{
			for (int j = 0; j < wrappedPhase.cols; ++j)
			{
				wrappedPhase.at<double>(i, j) =
					imgModulated_angel.at<double>(i, j) - imgOriginal_angel.at<double>(i, j);
				//imgTmp3.at<double>(i, j) =
				//	imgTmp2.at<double>(i, j) - imgTmp1.at<double>(i, j);
			}
		}
		ui.progressBar->setValue(50);

		normalize(wrappedPhase, wrappedPhaseNormal, 0, 1, CV_MINMAX);
		//normalize(imgTmp3, wrappedPhaseNormal, 0, 1, CV_MINMAX);

		//namedWindow("wrappedPhase", WINDOW_NORMAL);
		//resizeWindow("wrappedPhase", 700, 500);
		//imshow("wrappedPhase", wrappedPhaseNormal);

		//�����
		unwrap(wrappedPhase, unwrappedPhase);
		ui.progressBar->setValue(70);
		//unwrap(imgTmp3, imgTmp4);

		unwrappedPhase = abs(unwrappedPhase);
		//imgTmp4 = abs(imgTmp4);

		normalize(unwrappedPhase, unwrappedPhaseNormal, 0, 1, CV_MINMAX);
		//normalize(imgTmp4, unwrappedPhaseNormal, 0, 1, CV_MINMAX);

		//namedWindow("unwrappedPhase", WINDOW_NORMAL);
		//resizeWindow("unwrappedPhase", 700, 500);
		//imshow("unwrappedPhase", unwrappedPhaseNormal);

		/****************���Խ���*****************/

		cv::Mat imgDisplay1 = imgOriginal_angel;//CV_64F
		cv::Mat imgDisplay2 = imgModulated_angel;//CV_64F
		//Mat imgDisplay1 = imgTmp1.clone();//CV_64F
		//Mat imgDisplay2 = imgTmp2.clone();//CV_64F

		int type = imgModulated_angel.type();

		cout << "type = " << type;
		ui.progressBar->setValue(90);
		//namedWindow("angel-1", WINDOW_NORMAL);
		//resizeWindow("angel-1", 700, 500);
		//imshow("angel-1", imgDisplay1);

		//namedWindow("angel-2", WINDOW_NORMAL);
		//resizeWindow("angel-2", 700, 500);
		//imshow("angel-2", imgDisplay2);

		for (int i = 0; i < imgDisplay1.rows; ++i)
		{
			for (int j = 0; j < imgDisplay1.cols; ++j)
			{
				imgDisplay1.at<double>(i, j) *= 255.0;
				imgDisplay2.at<double>(i, j) *= 255.0;
			}
		}
		ui.progressBar->setValue(100);
		imgDisplay1.convertTo(imgDisplay1, CV_8U);
		imgDisplay2.convertTo(imgDisplay2, CV_8U);

		LabelDisplayMat(imgDisplay1, ui.labelImg1_5);
		LabelDisplayMat(imgDisplay2, ui.labelImg2_5);

		ui.tabWidget1->setCurrentIndex(4);
		ui.tabWidget2->setCurrentIndex(4);
		ui.progressBar->reset();
		ui.labelStatus->setText("Ready");

		isGetP = true;

		//����ʱ��������ȫ�ֱ���
		//imgOriginal_angel = imgTmp1.clone();
		//imgModulated_angel = imgTmp2.clone();
		//wrappedPhase = imgTmp3.clone();
		//unwrappedPhase = imgTmp4.clone();

		long t2 = cv::getTickCount();
		cout << "Time of getting phase :" << (t2 - t1) / 1e7 << "s" << endl;
	}
	else
		QMessageBox::about(this, codecParent->toUnicode("��ʾ"), codecParent->toUnicode("��δ����Ҷ���任��"));

}

//����λ
void Reconstruction::on_pushButton_5_clicked()
{
	if (isGetP == true)
	{
		ui.labelStatus->setText("Start to unwrap...");
		ui.progressBar->setValue(10);
		//Mat imgTmp1(imgModulated_src.rows, imgModulated_src.cols, CV_64F, Scalar(0));
		//Mat imgTmp2(imgModulated_src.rows, imgModulated_src.cols, CV_32F, Scalar(0));
		//Mat wrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_64F, Scalar(0));
		cv::Mat unwrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_32F, cv::Scalar(0));
		ui.progressBar->setValue(20);
		//wrappedPhase = imgTmp1;
		//unwrappedPhase = imgTmp2;

		//for (int i = 0; i < imgModulated_angel.rows; ++i)
		//{
		//	for (int j = 0; j < imgModulated_angel.cols; ++j)
		//	{
		//		wrappedPhase.at<double>(i, j) =
		//			imgModulated_angel.at<double>(i, j) - imgOriginal_angel.at<double>(i, j);
		//	}
		//}

		//normalize(wrappedPhase, wrappedPhaseNormal, 0, 1, CV_MINMAX);
		////namedWindow("wrappedPhase", WINDOW_NORMAL);
		////resizeWindow("wrappedPhase", 700, 500);
		////imshow("wrappedPhase", wrappedPhaseNormal);

		////�����
		//unwrap(wrappedPhase, unwrappedPhase);

		//unwrappedPhase = abs(unwrappedPhase);

		cout << "unwrappedPhase.type = " << unwrappedPhase.type();
		ui.progressBar->setValue(30);
		normalize(unwrappedPhase, unwrappedPhaseNormal, 0, 1, CV_MINMAX);
		ui.progressBar->setValue(40);
		//namedWindow("unwrappedPhase", WINDOW_NORMAL);
		//resizeWindow("unwrappedPhase", 700, 500);
		//imshow("unwrappedPhase", unwrappedPhaseNormal);

		cv::Mat imgDisplay = unwrappedPhaseNormal;
		ui.progressBar->setValue(50);

		for (int i = 0; i < imgDisplay.rows; ++i)
		{
			for (int j = 0; j < imgDisplay.cols; ++j)
			{
				imgDisplay.at<float>(i, j) *= 255;
			}
			if(i == imgDisplay.rows / 2)
				ui.progressBar->setValue(60);
		}
		ui.progressBar->setValue(80);

		imgDisplay.convertTo(imgDisplay, CV_8U);
		ui.progressBar->setValue(100);

		LabelDisplayMat(imgDisplay, ui.labelImg1_6);
		LabelDisplayMat(imgDisplay, ui.labelImg2_6);

		ui.tabWidget1->setCurrentIndex(5);
		ui.tabWidget2->setCurrentIndex(5);

		ui.progressBar->reset();
		ui.labelStatus->setText("Ready");
		ui.progressBar->setVisible(false);

		isUnwrap = true;
	}
	else
		QMessageBox::about(this, codecParent->toUnicode("��ʾ"), codecParent->toUnicode("��δ����λ��"));

}

//��ά�ؽ�
void Reconstruction::on_pushButton_6_clicked()
{
	cv::Mat imgDisplay(unwrappedPhase.rows, unwrappedPhase.cols, CV_64FC1);
	unwrappedPhase.convertTo(imgDisplay, CV_64FC1);

	for (int i = 0; i < imgDisplay.rows; ++i)
	{
		for (int j = 0; j < imgDisplay.cols; ++j)
		{
			imgDisplay.at<double>(i, j) *= 80.0;
		}
	}

	QSplitter* spl = new QSplitter(Qt::Horizontal, this);
	Plot* plot = new Plot(spl, imgDisplay);

	spl->resize(440, 350);
	spl->move(980, 100);
	spl->show();
}

//One Step
void Reconstruction::on_pushButton_7_clicked()
{
	ui.labelStatus->setText("Only One Step...");
	ui.progressBar->setVisible(true);
	ui.progressBar->setValue(10);

	/***************����Ҷ�任******************/
	imgOriginal_src.convertTo(imgOriginal_src, CV_64F, 1.0 / 255.0);//����Ҷ�任���������б����Ǹ�����
	imgModulated_src.convertTo(imgModulated_src, CV_64F, 1.0 / 255.0);

	ImageProcess imgDft;
	imgDft.fft2(imgOriginal_src, imgOriginal_fft);
	imgDft.fft2(imgModulated_src, imgModulated_fft);

	imgDft.fftshift(imgOriginal_fft);
	imgDft.fftshift(imgModulated_fft); //CV_64FC2

	cv::Mat imgDisplay1_2;
	cv::Mat imgDisplay2_2;

	imgDft.changeCh(imgOriginal_fft, imgDisplay1_2);
	imgDft.changeCh(imgModulated_fft, imgDisplay2_2);

	//namedWindow("imgOriginal_fft", WINDOW_NORMAL);
	//resizeWindow("imgOriginal_fft", 700, 500);
	//imshow("imgOriginal_fft", imgDisplay1_2);


	LabelDisplayMat(imgDisplay1_2, ui.labelImg1_2);
	LabelDisplayMat(imgDisplay2_2, ui.labelImg2_2);
	ui.progressBar->setValue(20);

	ui.tabWidget1->setCurrentIndex(1);
	ui.tabWidget2->setCurrentIndex(1);

	/*******************�˲�********************/
	ImageProcess imgFilt;
	imgFilt.filt(imgOriginal_fft, imgOriginal_filt);
	imgFilt.filt(imgModulated_fft, imgModulated_filt);

	cv::Mat imgDisplay1_3;
	cv::Mat imgDisplay2_3;

	imgFilt.changeCh(imgOriginal_filt, imgDisplay1_3);
	imgFilt.changeCh(imgModulated_filt, imgDisplay2_3);

	LabelDisplayMat(imgDisplay1_3, ui.labelImg1_3);
	LabelDisplayMat(imgDisplay2_3, ui.labelImg2_3);
	ui.progressBar->setValue(30);

	ui.tabWidget1->setCurrentIndex(2);
	ui.tabWidget2->setCurrentIndex(2);

	/*****************����Ҷ���任********************/
	ImageProcess imgIfft;

	imgIfft.ifftshift(imgOriginal_filt);
	imgIfft.ifftshift(imgModulated_filt); //CV_64FC2

	imgIfft.ifft2(imgOriginal_filt, imgOriginal_ifft);
	imgIfft.ifft2(imgModulated_filt, imgModulated_ifft); //CV_64FC2

	cv::Mat imgDisplay1_4;
	cv::Mat imgDisplay2_4;

	vector<cv::Mat> planes1;
	vector<cv::Mat> planes2;

	split(imgOriginal_ifft, planes1);
	imgDisplay1_4 = planes1[0];

	split(imgModulated_ifft, planes2);
	imgDisplay2_4 = planes2[0];

	ui.progressBar->setValue(40);
	for (int i = 0; i < imgDisplay1_4.rows; ++i)
	{
		for (int j = 0; j < imgDisplay1_4.cols; ++j)
		{
			imgDisplay1_4.at<double>(i, j) *= 255;
			imgDisplay2_4.at<double>(i, j) *= 255;
		}
	}
	imgDisplay1_4.convertTo(imgDisplay1_4, CV_8U);
	imgDisplay2_4.convertTo(imgDisplay2_4, CV_8U);

	LabelDisplayMat(imgDisplay1_4, ui.labelImg1_4);
	LabelDisplayMat(imgDisplay2_4, ui.labelImg2_4);
	ui.progressBar->setValue(50);

	ui.tabWidget1->setCurrentIndex(3);
	ui.tabWidget2->setCurrentIndex(3);

	/*****************����λ������λ********************/
	cv::Mat imgTmp1(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));
	cv::Mat imgTmp2(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));

	//��͵��һ�㶼���У�����ֻ����һ��imgTmp�����������������������������ݻ���ͬ
	imgOriginal_angel = imgTmp1;
	imgModulated_angel = imgTmp2;//��imgModulated_angel����ֵ����������λʱ����

	vector<cv::Mat> planes3;
	vector<cv::Mat> planes4;

	split(imgOriginal_ifft, planes3);
	split(imgModulated_ifft, planes4);

	for (int i = 0; i < imgOriginal_ifft.rows; ++i)
	{
		for (int j = 0; j < imgOriginal_ifft.cols; ++j)
		{
			imgOriginal_angel.at<double>(i, j) =
				atan2(planes3[1].at<double>(i, j), planes3[0].at<double>(i, j));

			imgModulated_angel.at<double>(i, j) =
				atan2(planes4[1].at<double>(i, j), planes4[0].at<double>(i, j));

		}
	}
	ui.progressBar->setValue(60);
	cv::Mat imgTmp3(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));
	cv::Mat imgTmp4(imgModulated_src.rows, imgModulated_src.cols, CV_32F, cv::Scalar(0));
	cv::Mat wrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_64F, cv::Scalar(0));
	cv::Mat unwrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_32F, cv::Scalar(0));

	wrappedPhase = imgTmp3;
	unwrappedPhase = imgTmp4;

	for (int i = 0; i < wrappedPhase.rows; ++i)
	{
		for (int j = 0; j < wrappedPhase.cols; ++j)
		{
			wrappedPhase.at<double>(i, j) =
				imgModulated_angel.at<double>(i, j) - imgOriginal_angel.at<double>(i, j);
		}
	}
	ui.progressBar->setValue(70);
	normalize(wrappedPhase, wrappedPhaseNormal, 0, 1, CV_MINMAX);

	//�����
	unwrap(wrappedPhase, unwrappedPhase);

	ui.progressBar->setValue(80);
	unwrappedPhase = abs(unwrappedPhase);

	normalize(unwrappedPhase, unwrappedPhaseNormal, 0, 1, CV_MINMAX);


	cv::Mat imgDisplay1_5 = imgOriginal_angel;//CV_64F
	cv::Mat imgDisplay2_5 = imgModulated_angel;//CV_64F

	int type = imgModulated_angel.type();

	cout << "type = " << type;

	//namedWindow("angel-1", WINDOW_NORMAL);
	//resizeWindow("angel-1", 700, 500);
	//imshow("angel-1", imgDisplay1);

	//namedWindow("angel-2", WINDOW_NORMAL);
	//resizeWindow("angel-2", 700, 500);
	//imshow("angel-2", imgDisplay2);

	for (int i = 0; i < imgDisplay1_5.rows; ++i)
	{
		for (int j = 0; j < imgDisplay1_5.cols; ++j)
		{
			imgDisplay1_5.at<double>(i, j) *= 255.0;
			imgDisplay2_5.at<double>(i, j) *= 255.0;
		}
	}

	imgDisplay1_5.convertTo(imgDisplay1_5, CV_8U);
	imgDisplay2_5.convertTo(imgDisplay2_5, CV_8U);

	LabelDisplayMat(imgDisplay1_5, ui.labelImg1_5);
	LabelDisplayMat(imgDisplay2_5, ui.labelImg2_5);
	ui.progressBar->setValue(90);

	ui.tabWidget1->setCurrentIndex(4);
	ui.tabWidget2->setCurrentIndex(4);

	cv::Mat imgDisplay_6 = unwrappedPhaseNormal;

	for (int i = 0; i < imgDisplay_6.rows; ++i)
	{
		for (int j = 0; j < imgDisplay_6.cols; ++j)
		{
			imgDisplay_6.at<float>(i, j) *= 255;
		}
	}

	imgDisplay_6.convertTo(imgDisplay_6, CV_8U);

	LabelDisplayMat(imgDisplay_6, ui.labelImg1_6);
	LabelDisplayMat(imgDisplay_6, ui.labelImg2_6);
	ui.progressBar->setValue(100);

	ui.tabWidget1->setCurrentIndex(5);
	ui.tabWidget2->setCurrentIndex(5);

	ui.progressBar->reset();
	ui.labelStatus->setText("Ready");
	ui.progressBar->setVisible(false);
}

//��ͼƬ
void Reconstruction::on_actionOpen_triggered()
{
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered));

	//��ԭͼ��
	QStringList pathList = QFileDialog::getOpenFileNames(this, "open", "../");//�������ļ�
	for (int i = 0; i < pathList.size(); ++i)
	{
		if (false == pathList[i].isEmpty())
		{
			//����QFile����
			QFile file(pathList[i]);

			//����QFileInfo���󣬻�ȡ�ļ���
			QFileInfo fileInfo(file);

			QString imgName = fileInfo.fileName();

			//״̬����ʾ
			ui.statusBar->showMessage("Open " + imgName + " successfully! Path: " + fileInfo.path(), 1000);

			if (i == 0)
			{
				imgOriginal_src = cv::imread("..\\image\\" + imgName.toStdString(), 0);
				LabelDisplayMat(imgOriginal_src, ui.labelImg1_1);
				cout << "Read imgOriginal_src successfully!" << endl;
			}
			else
			{
				imgModulated_src = cv::imread("..\\image\\" + imgName.toStdString(), 0);
				LabelDisplayMat(imgModulated_src, ui.labelImg2_1);
				cout << "Read imgModulated_src successfully!" << endl;
			}

		}
	}

	if(!imgOriginal_src.empty() && !imgModulated_src.empty())
		isOpen = true;


	ui.tabWidget1->setCurrentIndex(0);
	ui.tabWidget2->setCurrentIndex(0);
	
}

//����ͼƬ
void Reconstruction::on_actionSave_triggered()
{
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(on_actionSave_triggered));

	QString path = QFileDialog::getSaveFileName(this, "save", "../", "Images(*.png);;Images(*.bmp);;Images(*.jpg)");

	if (false == path.isEmpty())
	{
		QFile file(path);

		bool isOk = file.open(QIODevice::WriteOnly);
		if (true == isOk)
		{
			//QImage img = QImage((const unsigned char*)(mouse1Img.data), mouse1Img.cols, mouse1Img.rows,
			//	mouse1Img.cols * mouse1Img.channels(), QImage::Format_RGB888);
			//QPixmap pixmap = QPixmap::fromImage(img);

			////pixmap.save(path, "png", 0);
			//imwrite(path.toStdString(), mouse1Img);
		}

		file.close();
	}
}

//�л����Ӵ���
void Reconstruction::on_actionPMP_triggered()
{
	windowPMP.show();
	this->hide();
}

