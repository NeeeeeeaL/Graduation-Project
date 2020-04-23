#pragma once

#include <QMainWindow>
#include "ui_pmpTrans.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;

class PMPTrans : public QMainWindow
{
	Q_OBJECT

public:
	PMPTrans(QWidget *parent = Q_NULLPTR);
	~PMPTrans();


protected:

	void LabelDisplayMat(cv::Mat& mat_img, QLabel* label);

private:
	Ui::PMPTrans ui;

private:
	//�жϰ�ť�Ƿ񰴹���־λ
	bool isOpen = false;
	bool isGetP = false;
	bool isUnwrap = false;

public:
	//�����ķ����ƹ�դͼ��
	cv::Mat imgSrc1;
	cv::Mat imgSrc2;
	cv::Mat imgSrc3;
	cv::Mat imgSrc4;

	//�����ķ�ԭ��դͼ��
	cv::Mat imgSrc5;
	cv::Mat imgSrc6;
	cv::Mat imgSrc7;
	cv::Mat imgSrc8;

	//��λ
	cv::Mat phaseFG;
	cv::Mat phaseBG;

	cv::Mat wrappedPhase;
	cv::Mat unwrappedPhase;

signals:
	/*
	*�źű�����signals�ؼ���������
	*�ź�û�з���ֵ���������в���
	*�źž��Ǻ�����������ֻ�����������趨��
	*ʹ�÷�����emit mysignal();
	*/
	void signalSwitch();
	void signalNotOpen();
	void signalNotGetP();

public slots:

void on_actionFTP_triggered();
void on_actionOpen_triggered();
void on_pushButton1_clicked();
void on_pushButton2_clicked();
void on_pushButton3_clicked();

};
