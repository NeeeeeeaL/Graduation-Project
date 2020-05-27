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

	//求四个图像的平均
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

	//阈值分割
	Mat imgAverageSplit(imgHeight, imgWidth, CV_8U, Scalar(0));

	imgAverage.convertTo(imgAverage, CV_8U);
	threshold(imgAverage, imgAverageSplit, 0, 255, CV_THRESH_OTSU);

	//showImg("imgAverageSplit", imgAverageSplit);

	//连通域分析
	vector<vector<cv::Point>> contours;
	vector<Vec4i> hierarchy;

	//检测物体的轮廓，CV_RETR_LIST：检测所有轮廓，但是不建立等级关系，CV_CHAIN_APPROX_NONE：仅保留轮廓上的拐点信息，即关键点
	findContours(imgAverageSplit, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

	//计算轮廓的面积  画出面积大于一定值的连通域
	vector<Rect>boundRect(contours.size());//定义外接矩形集合
	vector<RotatedRect> box(contours.size()); //定义最小外接矩形集合
	Point2f rect[4]; //定义数组，存放最小外接矩形四个角点

	Mat mask(src1.size(), CV_8U);
	//cvtColor(mask, mask, CV_GRAY2RGB);//为了显示RGB形式

	for (int i = contours.size() - 1; i > 0; --i)
	{
		double Area = fabs(contourArea(contours[i], true));

		if (Area > 2e6)
		{
			drawContours(mask, contours, i, cvScalar(0, 0, 0), CV_FILLED);
		}
		else if ((Area > 2000 && Area < 9e5))
		{
			drawContours(mask, contours, i, cvScalar(255, 255, 255), CV_FILLED); //监控rectroi，运行时注释

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
