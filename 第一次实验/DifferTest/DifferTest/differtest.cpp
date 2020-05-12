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
	cv::magnitude(planes[0], planes[1], planes[0]); //������ת��Ϊ��ֵ
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

//	//�ҳ���Ƶf0
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

//����Ҷ�任
void DifferTest::fft2(const cv::Mat & src, cv::Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //��֧�ֵ����ݸ�ʽ

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
		//cv::magnitude(planes[0], planes[1], planes[0]); //������ת��Ϊ��ֵ
		//Fourier = planes[0];
	}
}

void DifferTest::circshift(cv::Mat & out, const cv::Point & delta)
{
	cv::Size sz = out.size();

	// ������
	assert(sz.height > 0 && sz.width > 0);
	// �����������Ҫ�ƶ�
	if ((sz.height == 1 && sz.width == 1) || (delta.x == 0 && delta.y == 0))
		return;

	// ��Ҫ�ƶ������ı任�����������������������
	int x = delta.x;
	int y = delta.y;
	if (x > 0) x = x % sz.width; //�����ƶ�
	if (y > 0) y = y % sz.height; //�����ƶ�
	if (x < 0) x = x % sz.width + sz.width; //�����ƶ�
	if (y < 0) y = y % sz.height + sz.height; //�����ƶ�


	// ��ά��MatҲ���ƶ�
	vector<cv::Mat> planes;
	split(out, planes);

	for (size_t i = 0; i < planes.size(); i++)
	{
		// ��ֱ�����ƶ�
		cv::Mat tmp0, tmp1, tmp2, tmp3;
		cv::Mat q0(planes[i], cv::Rect(0, 0, sz.width, sz.height - y));
		cv::Mat q1(planes[i], cv::Rect(0, sz.height - y, sz.width, y));
		q0.copyTo(tmp0);
		q1.copyTo(tmp1);
		tmp0.copyTo(planes[i](cv::Rect(0, y, sz.width, sz.height - y)));
		tmp1.copyTo(planes[i](cv::Rect(0, 0, sz.width, y)));

		// ˮƽ�����ƶ�
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
	pt.x = (int)floor(sz.width / 2.0);//floor: ���㲻���� arg ���������ֵ
	pt.y = (int)floor(sz.height / 2.0);
	circshift(out, pt);
}
