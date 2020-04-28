#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Reconstruction.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <QSplitter>
#include "mythread.h"
#include "pmpTrans.h"
#include "welcome.h"
#include "datalist.h"

#include <QSqlTableModel>

using namespace std;


class Reconstruction : public QMainWindow
{
	Q_OBJECT

public:
	Reconstruction(QWidget *parent = Q_NULLPTR);

	void dealChild();
	void dealNotOpen();
	void dealNotGetP();
	void dealNotUnwrap();

	//�߳���ش�����
	void dealEndPlot();
	void killThread();
	void dealTransmit();

	DataList* dataWidget;
	QSplitter* spl;

protected:
	//��д��ͼ�¼����麯��
	//����ڴ��ڻ�ͼ��������ڻ�ͼ�¼���ʵ��
	//��ͼ�¼��ڲ��Զ����ã�������Ҫ�ػ��ʱ��
	void paintEvent(QPaintEvent *);

	void LabelDisplayMat(cv::Mat& mat_img, QLabel* label);


private:
	Ui::ReconstructionClass ui;

	PMPTrans windowPMP;
	Welcome welcomeW;
	QSqlTableModel *model;

	MyThread *thread;//�̶߳���

private:
	//�жϰ�ť�Ƿ񰴹���־λ
	bool isOpen = false;
	bool isFFT = false;
	bool isFilt = false;
	bool isIFFT = false;
	bool isGetP = false;
	bool isUnwrap = false;


public:
	//���������ȫ�ֱ������в��������ں�����������ʱ������
	//����ʱ�������в�������ɺ��ٽ�ֵ����ȫ�ֱ���
	QImage img1, img2;

	cv::Mat imgOriginal_src;
	cv::Mat imgOriginal_fft;
	cv::Mat imgOriginal_filt;
	cv::Mat imgOriginal_ifft;
	cv::Mat imgOriginal_angel;

	cv::Mat imgModulated_src;
	cv::Mat imgModulated_fft;
	cv::Mat imgModulated_filt;
	cv::Mat imgModulated_ifft;
	cv::Mat imgModulated_angel;

	cv::Mat wrappedPhase;
	cv::Mat unwrappedPhase;


public slots:

//ͼ���������ť�ۺ���
void on_pushButton_clicked();//����Ҷ�任
void on_pushButton_2_clicked();//�˲���ť
void on_pushButton_3_clicked();//����Ҷ���任
void on_pushButton_4_clicked();//����λ
void on_pushButton_5_clicked();//����λ
void on_pushButton_6_clicked();//����λ

//��ά�ؽ�һ������
void on_pushButton_7_clicked();//One Step 

//�˵���������ť�ۺ���
void on_actionOpen_triggered();
void on_actionSave_triggered();
void on_actionPMP_triggered();

//ComboBox �л�
void on_comboBox_activated(int);

};


//class MyThread : public QThread
//{
//	Q_OBJECT
//
//public:
//	MyThread(QObject *parent);
//	~MyThread();
//
//protected:
//	//�̴߳�����
//	//ֻ��ͨ��start��ӵ��ã�����ֱ�ӵ���
//	void run();
//
//signals:
//	void signalEndPlot();
//};

