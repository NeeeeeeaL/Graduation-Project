#include "imgProcess.h"

#define PI (acos(-1))

void showImg(const char * windowName, const Mat & src)
{

	const int windowWidth = 650;//489
	const int windowHeight = 500;//500

	namedWindow(windowName, WINDOW_NORMAL);
	resizeWindow(windowName, windowWidth, windowHeight);
	imshow(windowName, src);

}

Mat getMask( Mat src1,  Mat src2,  Mat src3,  Mat src4)
{

	const int imgWidth = src1.cols;
	const int imgHeight = src1.rows;

	//���ĸ�ͼ���ƽ��
	Mat imgAverage(imgHeight, imgWidth, CV_64F, Scalar(0));

	for (int i = 0; i < imgHeight; ++i)
	{
		for (int j = 0; j < imgWidth; ++j)
		{
			imgAverage.at<double>(i, j) =
				(
					src1.at<double>(i, j) + src2.at<double>(i, j) +
					src3.at<double>(i, j) + src4.at<double>(i, j)
					) / 1.3;
		}
	}

	//��ֵ�ָ�
	Mat imgAverageSplit(imgHeight, imgWidth, CV_8U, Scalar(0));

	imgAverage.convertTo(imgAverage, CV_8U);
	threshold(imgAverage, imgAverageSplit, 0, 255, CV_THRESH_OTSU);

	//showImg("imgAverageSplit", imgAverageSplit);

	//��ͨ�����
	vector<vector<cv::Point>> contours;
	vector<Vec4i> hierarchy;

	//��������������CV_RETR_LIST������������������ǲ������ȼ���ϵ��CV_CHAIN_APPROX_NONE�������������ϵĹյ���Ϣ�����ؼ���
	findContours(imgAverageSplit, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

	//�������������  �����������һ��ֵ����ͨ��
	vector<Rect>boundRect(contours.size());//������Ӿ��μ���
	vector<RotatedRect> box(contours.size()); //������С��Ӿ��μ���
	Point2f rect[4]; //�������飬�����С��Ӿ����ĸ��ǵ�

	Mat mask(src1.size(), CV_8U);
	//cvtColor(mask, mask, CV_GRAY2RGB);//Ϊ����ʾRGB��ʽ

	for (int i = contours.size() - 1; i > 0; --i)
	{
		double Area = fabs(contourArea(contours[i], true));

		if (Area > 2e6)
		{
			drawContours(mask, contours, i, cvScalar(0, 0, 0), CV_FILLED);
		}
		else if ((Area > 2000 && Area < 9e5))
		{
			drawContours(mask, contours, i, cvScalar(255, 255, 255), CV_FILLED); //���rectroi������ʱע��

		}
	}

	showImg("mask", mask);

	return mask;
}


Mat getPhase(Mat src1, Mat src2, Mat src3, Mat src4)
{
	Mat phase(src1.size(), CV_64F);
	const int imgWidth = src1.cols;
	const int imgHeight = src1.rows;

	for (int i = 0; i < imgHeight; ++i)
	{
		for (int j = 0; j < imgWidth; ++j)
		{
			double I1 = src1.at<double>(i, j);
			double I2 = src2.at<double>(i, j);
			double I3 = src3.at<double>(i, j);
			double I4 = src4.at<double>(i, j);

			if (I1 != I3)
				phase.at<double>(i, j) = atan2((I4 - I2), (I1 - I3));
			else if (I2 == I4)
				phase.at<double>(i, j) = 0;
			else if (I4 > I2)
				phase.at<double>(i, j) = PI / 2;
			else
				phase.at<double>(i, j) = -PI / 2;

		}
	}

	return phase;
}

Mat subtract(Mat src1, Mat src2)
{
	Mat dst(src1.size(), CV_64F);
	const int imgWidth = src1.cols;
	const int imgHeight = src1.rows;

	for (int i = 0; i < imgHeight; ++i)
	{
		for (int j = 0; j < imgWidth; ++j)
		{
			dst.at<double>(i, j) = src2.at<double>(i, j) - src1.at<double>(i, j);
		}
	}

	return dst;
}
