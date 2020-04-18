#pragma once

#include <QMainWindow>
#include "ui_pmpTrans.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
using namespace std;

class PMPTrans : public QMainWindow
{
	Q_OBJECT

public:
	PMPTrans(QWidget *parent = Q_NULLPTR);
	~PMPTrans();

	void sendSlot();

protected:

	void LabelDisplayMat(Mat& mat_img, QLabel* label);

private:
	Ui::PMPTrans ui;

public:
	//�����ķ����ƹ�դͼ��
	Mat imgSrc1;
	Mat imgSrc2;
	Mat imgSrc3;
	Mat imgSrc4;

	//�����ķ�ԭ��դͼ��
	Mat imgSrc5;
	Mat imgSrc6;
	Mat imgSrc7;
	Mat imgSrc8;

	//��λ
	Mat phaseFG;
	Mat phaseBG;

	Mat wrappedPhase;
	Mat unwrappedPhase;

signals:
	/*
	*�źű�����signals�ؼ���������
	*�ź�û�з���ֵ���������в���
	*�źž��Ǻ�����������ֻ�����������趨��
	*ʹ�÷�����emit mysignal();
	*/
	void signalSwitch();

public slots:

void on_actionFTP_triggered();
void on_actionOpen_triggered();
void on_pushButton1_clicked();
void on_pushButton2_clicked();

};
