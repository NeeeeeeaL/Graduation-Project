#include "differtest.h"

using namespace std;

DifferTest::DifferTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	cv::Mat imgSrc = cv::imread("3-2.bmp");

	cv::namedWindow("imgSrc", cv::WINDOW_NORMAL);
	cv::resizeWindow("imgSrc", 960, 640);
	cv::imshow("imgSrc", imgSrc);

	//sobel-y

	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	cv::Mat imgSrcGray;
	cv::Mat imgGradY;
	cv::Mat imgGradYAbs;
	cv::cvtColor(imgSrc, imgSrcGray, cv::COLOR_RGB2GRAY);

	cv::Mat imgfft;
	imgSrcGray.convertTo(imgSrcGray, CV_64F, 1.0 / 255.0);
	fft2(imgSrcGray, imgfft);

	fftshift(imgfft);

	vector<cv::Mat> planes;
	split(imgfft, planes);
	cv::magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
	imgfft = planes[0];

	//cv::normalize(imgfft, imgfft, 0, 255, CV_MINMAX);
	imgfft.convertTo(imgfft, CV_8U);

	cv::imwrite("fft.bmp", imgfft);

	//cv::GaussianBlur(imgfft, imgfft, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

	cv::namedWindow("imgfft", cv::WINDOW_NORMAL);
	cv::resizeWindow("imgfft", 960, 640);
	cv::imshow("imgfft", imgfft);

	cv::Sobel(imgfft, imgGradY, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(imgGradY, imgGradYAbs, 1, 0);

	int type = imgGradY.type(); //type = 3
	int type2 = imgGradYAbs.type(); //type = 0

	imgGradY.convertTo(imgGradY, CV_32F, 1.0 / 255.0);

	cv::namedWindow("imgSobel", cv::WINDOW_NORMAL);
	cv::resizeWindow("imgSobel", 960, 640);
	cv::imshow("imgSobel", imgGradYAbs);

//	//找出基频f0
//	float min = 0.0;
//	int num = 0;
//	int col = 1151;
//	for (int i = 821; i < 1644; ++i)
//	{
//		cout << imgGradY.at<float>(i, col) << endl;
//		
//		if (imgGradY.at<float>(i, col) < min)
//		{
//			min = imgGradY.at<float>(i, col);
//			num = i;
//		}
//	}
//
//	cout << "num:" << num << " is the minimum, its value = " << min << endl;
//	cout << "num:865  value = " << imgGradY.at<float>(865, col) << endl;
}

//傅里叶变换
void DifferTest::fft2(const cv::Mat & src, cv::Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //不支持的数据格式

	if (mat_type < 7)
	{
		cv::Mat planes[] = { cv::Mat_<double>(src), cv::Mat::zeros(src.size(),CV_64F) };
		merge(planes, 2, Fourier);
		dft(Fourier, Fourier);

	}
	else // 7<mat_type<15
	{
		cv::Mat tmp;
		dft(src, tmp);
		//vector<cv::Mat> planes;
		//split(tmp, planes); //planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		//cv::magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
		//Fourier = planes[0];
	}
}

void DifferTest::circshift(cv::Mat & out, const cv::Point & delta)
{
	cv::Size sz = out.size();

	// 错误检查
	assert(sz.height > 0 && sz.width > 0);
	// 此种情况不需要移动
	if ((sz.height == 1 && sz.width == 1) || (delta.x == 0 && delta.y == 0))
		return;

	// 需要移动参数的变换，这样就能输入各种整数了
	int x = delta.x;
	int y = delta.y;
	if (x > 0) x = x % sz.width; //向下移动
	if (y > 0) y = y % sz.height; //向右移动
	if (x < 0) x = x % sz.width + sz.width; //向上移动
	if (y < 0) y = y % sz.height + sz.height; //向左移动


	// 多维的Mat也能移动
	vector<cv::Mat> planes;
	split(out, planes);

	for (size_t i = 0; i < planes.size(); i++)
	{
		// 竖直方向移动
		cv::Mat tmp0, tmp1, tmp2, tmp3;
		cv::Mat q0(planes[i], cv::Rect(0, 0, sz.width, sz.height - y));
		cv::Mat q1(planes[i], cv::Rect(0, sz.height - y, sz.width, y));
		q0.copyTo(tmp0);
		q1.copyTo(tmp1);
		tmp0.copyTo(planes[i](cv::Rect(0, y, sz.width, sz.height - y)));
		tmp1.copyTo(planes[i](cv::Rect(0, 0, sz.width, y)));

		// 水平方向移动
		cv::Mat q2(planes[i], cv::Rect(0, 0, sz.width - x, sz.height));
		cv::Mat q3(planes[i], cv::Rect(sz.width - x, 0, x, sz.height));
		q2.copyTo(tmp2);
		q3.copyTo(tmp3);
		tmp2.copyTo(planes[i](cv::Rect(x, 0, sz.width - x, sz.height)));
		tmp3.copyTo(planes[i](cv::Rect(0, 0, x, sz.height)));
	}

	merge(planes, out);
}

void DifferTest::fftshift(cv::Mat & out)
{
	cv::Size sz = out.size();
	cv::Point pt(0, 0);
	pt.x = (int)floor(sz.width / 2.0);//floor: 计算不大于 arg 的最大整数值
	pt.y = (int)floor(sz.height / 2.0);
	circshift(out, pt);
}
