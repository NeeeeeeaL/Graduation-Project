#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Reconstruction.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include "pmpTrans.h"
#include "welcome.h"

#include <QSqlTableModel>

using namespace cv;
using namespace std;


class Reconstruction : public QMainWindow
{
	Q_OBJECT

public:
	Reconstruction(QWidget *parent = Q_NULLPTR);

	void dealChild();

protected:
	//��д��ͼ�¼����麯��
	//����ڴ��ڻ�ͼ��������ڻ�ͼ�¼���ʵ��
	//��ͼ�¼��ڲ��Զ����ã�������Ҫ�ػ��ʱ��
	void paintEvent(QPaintEvent *);

	void LabelDisplayMat(Mat& mat_img, QLabel* label);

private:
	Ui::ReconstructionClass ui;

	PMPTrans windowPMP;
	Welcome welcomeW;
	QSqlTableModel *model;


public:
	//���������ȫ�ֱ������в��������ں�����������ʱ������
	//����ʱ�������в�������ɺ��ٽ�ֵ����ȫ�ֱ���
	QImage img1, img2;

	Mat imgOriginal_src;
	Mat imgOriginal_fft;
	Mat imgOriginal_filt;
	Mat imgOriginal_ifft;
	Mat imgOriginal_angel;

	Mat imgModulated_src;
	Mat imgModulated_fft;
	Mat imgModulated_filt;
	Mat imgModulated_ifft;
	Mat imgModulated_angel;

	Mat wrappedPhase;
	Mat unwrappedPhase;

public slots:

//ͼ���������ť�ۺ���
void on_pushButton_clicked();//����Ҷ�任
void on_pushButton_2_clicked();//�˲���ť
void on_pushButton_3_clicked();//����Ҷ���任
void on_pushButton_4_clicked();//����λ
void on_pushButton_5_clicked();//����λ

//��ά�ؽ�һ������
void on_pushButton_7_clicked();//One Step 

//�˵���������ť�ۺ���
void on_actionOpen_triggered();
void on_actionSave_triggered();
void on_actionPMP_triggered();

};
