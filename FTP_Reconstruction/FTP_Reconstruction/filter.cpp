#include "filter.h"

#define PI (acos(-1))

void filt(const Mat & src, Mat & imgFilt)

{
	//设计非对称汉宁窗
	const int hannRows = 30; //原图：50；ROI3：22；ROI4：30；鼠标：32
	const int hannCols = 800; //原图：1348；ROI3：410；ROI4：750；鼠标：1490
	const int offsetY = 25; //原图：向下偏移44；ROI3：18；ROI4：25；鼠标：30

	Mat hann = Mat::zeros(hannRows, hannCols, CV_64FC1);
	for (int i = 0; i < hannRows; ++i)
	{
		for (int j = 0; j < hannCols; ++j)
		{
			hann.at<double>(i, j) = 0.5 +
				0.5 * cos(2.0 * PI * sqrt(pow((i - hannRows / 2.0), 2) / pow(40.0, 2) + pow((j - hannCols / 2.0), 2) / pow(900.0, 2)));
			//原图：40， 1200；ROI3：35， 700；鼠标：50， 1200
		}
	}

	//showImg("Hann", hann);
	namedWindow("Hann", WINDOW_NORMAL);
	resizeWindow("Hann", 800, 30);
	imshow("Hann", hann);

	//滤波
	const int imgRows = src.rows;
	const int imgCols = src.cols;
	const int centerX = imgCols / 2;
	const int centerY = imgRows / 2;

	vector<Mat> fftPlanes;
	split(src, fftPlanes); //CV_64FC2

	//框选出ROI
	
	Mat filtPlanes[] = { Mat::zeros(src.size(),CV_64F), Mat::zeros(src.size(),CV_64F) };

	for (size_t p = 0; p < fftPlanes.size(); ++p)
	{
		for (int j = centerX - (hannCols / 2)-1, m = 0; j < centerX + (hannCols / 2)-1, m < hannCols; ++j, ++m)
		{
			for (int i = centerY + offsetY - (hannRows / 2)-1, n = 0; i < centerY + offsetY + (hannRows / 2)-1, n < hannRows; ++i, ++n)
			{
				fftPlanes[p].at<double>(i, j) *= hann.at<double>(n, m);//原为：(i - 840, j - 477)
				filtPlanes[p].at<double>(i - offsetY, j) = fftPlanes[p].at<double>(i, j);
			}
		}
	}

	merge(filtPlanes, 2, imgFilt); //CV_64FC2

}
