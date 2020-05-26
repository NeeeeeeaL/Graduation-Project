#include "calibration.h"
#include <QFile>
#include <QFileDialog>
#include "Reconstruction.h"

using namespace std;

Calibration::Calibration(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.tabWidget->setCurrentIndex(0);
}

Calibration::~Calibration()
{
}


//标定
void Calibration::on_pushButton2_clicked()
{
	string outfilename = "..//sample//left//caliberation_result.txt";
	////保存标定的结果  ofstream 是从内存写到硬盘
	ofstream fout(outfilename);

	/******************************提取角点****************************/
	//1.读取毎一幅图像，从中提取出角点，然后对角点进行亚像素精确化、获取每个角点在像素坐标系中的坐标
	//像素坐标系的原点位于图像的左上角

	//图像数量
	int imageCount = 12;
	//图像尺寸
	cv::Size imageSize;
	//标定板上每行每列的角点数
	cv::Size boardSize = cv::Size(9, 6);
	//缓存每幅图像上检测到的角点
	vector<cv::Point2f>  imagePointsBuf;
	//保存检测到的所有角点
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
			//找不到角点
			cout << "Can not find chessboard corners!" << endl;
			exit(1);
		}
		else
		{
			cv::Mat viewGray;
			//转换为灰度图片
			cv::cvtColor(calibImg[i], viewGray, cv::COLOR_BGR2GRAY);
			//亚像素精确化   对粗提取的角点进行精确化
			cv::find4QuadCornerSubpix(viewGray, imagePointsBuf, cv::Size(5, 5));
			//保存亚像素点
			imagePointsSeq.push_back(imagePointsBuf);
			//在图像上显示角点位置
			cv::Mat imageDisplay = calibImg[i].clone();
			cv::drawChessboardCorners(imageDisplay, boardSize, imagePointsBuf, true);
			//显示图片
			//cv::imshow("Camera Calibration", calibImg[i]);
			LabelDisplayMat(imageDisplay, imgLabel[i]);
			//cv::imwrite("test.jpg", calibImg[i]);
			//等待0.5s
			//cv::waitKey(0);
		}
	}

	//计算每张图片上的角点数
	int cornerNum = boardSize.width * boardSize.height;

	//角点总数
	int total = imagePointsSeq.size() * cornerNum;

	/******************************开始标定*******************************/
	//2.摄像机标定 世界坐标系原点位于标定板左上角(第一个方格的左上角)

	//棋盘三维信息，设置棋盘在世界坐标系的坐标
	//实际测量得到标定板上每个棋盘格的大小
	cv::Size squareSize = cv::Size(26, 26);
	//毎幅图片角点数量
	vector<int> pointCounts;
	//保存标定板上角点的三维坐标
	vector<vector<cv::Point3f>> objectPoints;
	//摄像机内参数矩阵 M=[fx γ u0,0 fy v0,0 0 1]
	cv::Mat cameraMatrix = cv::Mat(3, 3, CV_64F, cv::Scalar::all(0));
	//摄像机的5个畸变系数k1,k2,p1,p2,k3
	cv::Mat distCoeffs = cv::Mat(1, 5, CV_64F, cv::Scalar::all(0));
	//每幅图片的旋转向量
	vector<cv::Mat> tvecsMat;
	//每幅图片的平移向量
	vector<cv::Mat> rvecsMat;
	
	//初始化标定板上角点的三维坐标
	int i, j, number;
	for (number = 0; number < imageCount; number++)
	{
		vector<cv::Point3f> tempPointSet;
		//行数
		for (i = 0; i < boardSize.height; i++)
		{
			//列数
			for (j = 0; j < boardSize.width; j++)
			{
				cv::Point3f realPoint;
				//假设标定板放在世界坐标系中z=0的平面上。
				realPoint.x = i*squareSize.width;
				realPoint.y = j*squareSize.height;
				realPoint.z = 0;
				tempPointSet.push_back(realPoint);
			}
		}
		objectPoints.push_back(tempPointSet);
	}
	
	//初始化每幅图像中的角点数量，假定每幅图像中都可以看到完整的标定板
	for (i = 0; i < imageCount; i++)
	{
		pointCounts.push_back(boardSize.width*boardSize.height);
	}

	//开始标定
	cv::calibrateCamera(objectPoints, imagePointsSeq, imageSize, cameraMatrix, distCoeffs, rvecsMat, tvecsMat);

	//标定完成
	cout << "标定完成" << endl;

	/************************保存定标结果************************/
	cout << "开始保存标定结果....." << endl;
	cv::Mat rotationMatrix = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0));

	fout << "相机内参数矩阵:" << endl;
	fout << cameraMatrix << endl << endl;
	fout << "畸变系数:" << endl;
	fout << distCoeffs << endl << endl;

	for (int i = 0; i < imageCount; i++)
	{
		fout << "第" << i + 1 << "幅图像的旋转向量:" << endl;
		fout << tvecsMat[i] << endl;
		//将旋转向量转换为相对应的旋转矩阵
		cv::Rodrigues(tvecsMat[i], rotationMatrix);
		fout << "第" << i + 1 << "幅图像的旋转矩阵:" << endl;
		fout << rotationMatrix << endl;
		fout << "第" << i + 1 << "幅图像的平移向量:" << endl;
		fout << rvecsMat[i] << endl;
	}
	cout << "保存完成" << endl;

	/************************显示定标结果************************/
	cv::Mat mapx = cv::Mat(imageSize, CV_32FC1);
	cv::Mat mapy = cv::Mat(imageSize, CV_32FC1);
	cv::Mat R = cv::Mat::eye(3, 3, CV_32F);
	std::cout << "显示矫正图像" << endl;
	
	for (int i = 0; i != imageCount; i++)
	{
		std::cout << "Frame #" << i + 1 << "..." << endl;
		//计算图片畸变矫正的映射矩阵mapx、mapy(不进行立体校正、立体校正需要使用双摄)
		initUndistortRectifyMap(cameraMatrix, distCoeffs, R, cameraMatrix, imageSize, CV_32FC1, mapx, mapy);
		//读取一张图片
		cv::Mat newimage = calibImg[i].clone();
		//另一种不需要转换矩阵的方式
		//undistort(imageSource,newimage,cameraMatrix,distCoeffs);
		//进行校正
		remap(calibImg[i], newimage, mapx, mapy, cv::INTER_LINEAR);
		LabelDisplayMat(newimage, imgLabel2[i]);

	}

	ui.tabWidget->setCurrentIndex(1);

	emit signalCaliProgress();

}

//打开原图像
void Calibration::on_pushButton1_clicked()
{

	QStringList pathList = QFileDialog::getOpenFileNames(this, "open", "../");//打开所有文件

	for (int i = 0; i < pathList.size(); ++i)
	{
		if (false == pathList[i].isEmpty())
		{
			//定义QFile对象
			QFile file(pathList[i]);

			switch (i)
			{

				/***********读入四幅原光栅图像************/

			case 0: {
				imgSrc1 = cv::imread("..\\sample\\left\\left01.jpg");
				calibImg.push_back(imgSrc1);
				imgLabel.push_back(ui.label1);
				imgLabel2.push_back(ui.label1_2);
				LabelDisplayMat(imgSrc1, ui.label1);
			}break;

				case 1: {
				imgSrc2 = cv::imread("..\\sample\\left\\left02.jpg");
				calibImg.push_back(imgSrc2);
				imgLabel.push_back(ui.label2);
				imgLabel2.push_back(ui.label2_2);
				LabelDisplayMat(imgSrc2, ui.label2);

				}break;

				case 2: {
				imgSrc3 = cv::imread("..\\sample\\left\\left03.jpg");
				calibImg.push_back(imgSrc3);
				imgLabel.push_back(ui.label3);
				imgLabel2.push_back(ui.label3_2);
				LabelDisplayMat(imgSrc3, ui.label3);

				}break;

				case 3: {
				imgSrc4 = cv::imread("..\\sample\\left\\left04.jpg");
				calibImg.push_back(imgSrc4);
				imgLabel.push_back(ui.label4);
				imgLabel2.push_back(ui.label4_2);
				LabelDisplayMat(imgSrc4, ui.label4);

				}break;

				case 4: {
				imgSrc5 = cv::imread("..\\sample\\left\\left05.jpg");
				calibImg.push_back(imgSrc5);
				imgLabel.push_back(ui.label5);
				imgLabel2.push_back(ui.label5_2);
				LabelDisplayMat(imgSrc5, ui.label5);

				}break;

				case 5: {
				imgSrc6 = cv::imread("..\\sample\\left\\left06.jpg");
				calibImg.push_back(imgSrc6);
				imgLabel.push_back(ui.label6);
				imgLabel2.push_back(ui.label6_2);
				LabelDisplayMat(imgSrc6, ui.label6);

				}break;

				case 6: {
				imgSrc7 = cv::imread("..\\sample\\left\\left07.jpg");
				calibImg.push_back(imgSrc7);
				imgLabel.push_back(ui.label7);
				imgLabel2.push_back(ui.label7_2);
				LabelDisplayMat(imgSrc7, ui.label7);

				}break;

				case 7: {
				imgSrc8 = cv::imread("..\\sample\\left\\left08.jpg");
				calibImg.push_back(imgSrc8);
				imgLabel.push_back(ui.label8);
				imgLabel2.push_back(ui.label8_2);
				LabelDisplayMat(imgSrc8, ui.label8);

				}break;
				case 8: {
				imgSrc9 = cv::imread("..\\sample\\left\\left09.jpg");
				calibImg.push_back(imgSrc9);
				imgLabel.push_back(ui.label9);
				imgLabel2.push_back(ui.label9_2);
				LabelDisplayMat(imgSrc9, ui.label9);

				}break;

				case 9: {
				imgSrc10 = cv::imread("..\\sample\\left\\left10.jpg");
				calibImg.push_back(imgSrc10);
				imgLabel.push_back(ui.label10);
				imgLabel2.push_back(ui.label10_2);
				LabelDisplayMat(imgSrc10, ui.label10);

				}break;

				case 10: {
				imgSrc11 = cv::imread("..\\sample\\left\\left11.jpg");
				calibImg.push_back(imgSrc11);
				imgLabel.push_back(ui.label11);
				imgLabel2.push_back(ui.label11_2);
				LabelDisplayMat(imgSrc11, ui.label11);

				}break;

				case 11: {
				imgSrc12 = cv::imread("..\\sample\\left\\left12.jpg");
				calibImg.push_back(imgSrc12);
				imgLabel.push_back(ui.label12);
				imgLabel2.push_back(ui.label12_2);
				LabelDisplayMat(imgSrc12, ui.label12);

				}break;


			default: break;
			}

		}
	}
}

//在QLabel上显示Mat图像
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
	//QPixmap fitpixmap = pixmap.scaled(label->width(), label->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); //饱满填充
	QPixmap fitpixmap = pixmap.scaled(label->width(), label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation); //等比例填充
	label->setPixmap(fitpixmap);
	label->setAlignment(Qt::AlignCenter);//图片居中显示
}
