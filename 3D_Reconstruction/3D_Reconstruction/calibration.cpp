#include "calibration.h"
#include <QFile>
#include <QFileDialog>

using namespace std;

Calibration::Calibration(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

}

Calibration::~Calibration()
{
}

void Calibration::dealLoadCalibImg()
{
	qDebug() << "Acquire the signal successfully!" << endl;

}

//�궨
void Calibration::on_pushButton2_clicked()
{
	//QString outfilename = "sample/left/caliberation_result.txt";
	////����궨�Ľ��  ofstream �Ǵ��ڴ�д��Ӳ��
	//ofstream fout(outfilename);

	/******************************��ȡ�ǵ�****************************/
	//1.��ȡ��һ��ͼ�񣬴�����ȡ���ǵ㣬Ȼ��Խǵ���������ؾ�ȷ������ȡÿ���ǵ�����������ϵ�е�����
	//��������ϵ��ԭ��λ��ͼ������Ͻ�

	//ͼ������
	int imageCount = 12;
	//ͼ��ߴ�
	cv::Size imageSize;
	//�궨����ÿ��ÿ�еĽǵ���
	cv::Size boardSize = cv::Size(9, 6);
	//����ÿ��ͼ���ϼ�⵽�Ľǵ�
	vector<cv::Point2f>  imagePointsBuf;
	//�����⵽�����нǵ�
	vector<std::vector<cv::Point2f>> imagePointsSeq;

	for (int i = 0; i < imageCount; ++i)
	{
		if (i == 0)
		{
			imageSize.width = calibImg[i].cols;
			imageSize.height = calibImg[i].rows;
		}

		if (cv::findChessboardCorners(calibImg[i], boardSize, imagePointsBuf) == 0)
		{
			//�Ҳ����ǵ�
			std::cout << "Can not find chessboard corners!" << std::endl;
			exit(1);
		}
		else
		{
			cv::Mat viewGray;
			//ת��Ϊ�Ҷ�ͼƬ
			cv::cvtColor(calibImg[i], viewGray, cv::COLOR_BGR2GRAY);
			//�����ؾ�ȷ��   �Դ���ȡ�Ľǵ���о�ȷ��
			cv::find4QuadCornerSubpix(viewGray, imagePointsBuf, cv::Size(5, 5));
			//���������ص�
			imagePointsSeq.push_back(imagePointsBuf);
			//��ͼ������ʾ�ǵ�λ��
			cv::drawChessboardCorners(calibImg[i], boardSize, imagePointsBuf, true);
			//��ʾͼƬ
			//cv::imshow("Camera Calibration", calibImg[i]);
			//cv::imwrite("test.jpg", calibImg[i]);
			//�ȴ�0.5s
			//cv::waitKey(0);
		}
	}

	//����ÿ��ͼƬ�ϵĽǵ���
	int cornerNum = boardSize.width * boardSize.height;

	//�ǵ�����
	int total = imagePointsSeq.size() * cornerNum;

	/******************************��ʼ�궨*******************************/
	//2.������궨 ��������ϵԭ��λ�ڱ궨�����Ͻ�(��һ����������Ͻ�)

	//������ά��Ϣ��������������������ϵ������
	//ʵ�ʲ����õ��궨����ÿ�����̸�Ĵ�С
	cv::Size squareSize = cv::Size(26, 26);
	//����ͼƬ�ǵ�����
	vector<int> pointCounts;
	//����궨���Ͻǵ����ά����
	vector<vector<cv::Point3f>> objectPoints;
	//������ڲ������� M=[fx �� u0,0 fy v0,0 0 1]
	cv::Mat cameraMatrix = cv::Mat(3, 3, CV_64F, cv::Scalar::all(0));
	//�������5������ϵ��k1,k2,p1,p2,k3
	cv::Mat distCoeffs = cv::Mat(1, 5, CV_64F, cv::Scalar::all(0));
	//ÿ��ͼƬ����ת����
	vector<cv::Mat> tvecsMat;
	//ÿ��ͼƬ��ƽ������
	vector<cv::Mat> rvecsMat;

	//��ʼ���궨���Ͻǵ����ά����
	int i, j, number;
	for (number = 0; number < imageCount; number++)
	{
		vector<cv::Point3f> tempPointSet;
		//����
		for (i = 0; i < boardSize.height; i++)
		{
			//����
			for (j = 0; j < boardSize.width; j++)
			{
				cv::Point3f realPoint;
				//����궨�������������ϵ��z=0��ƽ���ϡ�
				realPoint.x = i*squareSize.width;
				realPoint.y = j*squareSize.height;
				realPoint.z = 0;
				tempPointSet.push_back(realPoint);
			}
		}
		objectPoints.push_back(tempPointSet);
	}

	//��ʼ��ÿ��ͼ���еĽǵ��������ٶ�ÿ��ͼ���ж����Կ��������ı궨��
	for (i = 0; i < imageCount; i++)
	{
		pointCounts.push_back(boardSize.width*boardSize.height);
	}

	//��ʼ�궨
	cv::calibrateCamera(objectPoints, imagePointsSeq, imageSize, cameraMatrix, distCoeffs, rvecsMat, tvecsMat);

}

//��ԭͼ��
void Calibration::on_pushButton1_clicked()
{

	QStringList pathList = QFileDialog::getOpenFileNames(this, "open", "../");//�������ļ�

	for (int i = 0; i < pathList.size(); ++i)
	{
		if (false == pathList[i].isEmpty())
		{
			//����QFile����
			QFile file(pathList[i]);

			switch (i)
			{

				/***********�����ķ�ԭ��դͼ��************/

			case 0: {
				imgSrc1 = cv::imread("..\\sample\\left\\left01.jpg");
				calibImg.push_back(imgSrc1);
				LabelDisplayMat(imgSrc1, ui.label1);
			}break;

				case 1: {
				imgSrc2 = cv::imread("..\\sample\\left\\left02.jpg");
				calibImg.push_back(imgSrc2);
				LabelDisplayMat(imgSrc2, ui.label2);

				}break;

				case 2: {
				imgSrc3 = cv::imread("..\\sample\\left\\left03.jpg");
				calibImg.push_back(imgSrc3);
				LabelDisplayMat(imgSrc3, ui.label3);

				}break;

				case 3: {
				imgSrc4 = cv::imread("..\\sample\\left\\left04.jpg");
				calibImg.push_back(imgSrc4);
				LabelDisplayMat(imgSrc4, ui.label4);

				}break;

				case 4: {
				imgSrc5 = cv::imread("..\\sample\\left\\left05.jpg");
				calibImg.push_back(imgSrc5);
				LabelDisplayMat(imgSrc5, ui.label5);

				}break;

				case 5: {
				imgSrc6 = cv::imread("..\\sample\\left\\left06.jpg");
				calibImg.push_back(imgSrc6);
				LabelDisplayMat(imgSrc6, ui.label6);

				}break;

				case 6: {
				imgSrc7 = cv::imread("..\\sample\\left\\left07.jpg");
				calibImg.push_back(imgSrc7);
				LabelDisplayMat(imgSrc7, ui.label7);

				}break;

				case 7: {
				imgSrc8 = cv::imread("..\\sample\\left\\left08.jpg");
				calibImg.push_back(imgSrc8);
				LabelDisplayMat(imgSrc8, ui.label8);

				}break;
				case 8: {
				imgSrc9 = cv::imread("..\\sample\\left\\left09.jpg");
				calibImg.push_back(imgSrc9);
				LabelDisplayMat(imgSrc9, ui.label9);

				}break;

				case 9: {
				imgSrc10 = cv::imread("..\\sample\\left\\left10.jpg");
				calibImg.push_back(imgSrc10);
				LabelDisplayMat(imgSrc10, ui.label10);

				}break;

				case 10: {
				imgSrc11 = cv::imread("..\\sample\\left\\left11.jpg");
				calibImg.push_back(imgSrc11);
				LabelDisplayMat(imgSrc11, ui.label11);

				}break;

				case 11: {
				imgSrc12 = cv::imread("..\\sample\\left\\left12.jpg");
				calibImg.push_back(imgSrc12);
				LabelDisplayMat(imgSrc12, ui.label12);

				}break;


			default: break;
			}

		}
	}
}

//��QLabel����ʾMatͼ��
void Calibration::LabelDisplayMat(cv::Mat & mat_img, QLabel * label)
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
