#include "filter.h"

#define PI (acos(-1))

void filt(const Mat & src, Mat & imgFilt)

{
	//��ƷǶԳƺ�����
	const int hannRows = 22; //ԭͼ��50��ROI��22
	const int hannCols = 410; //ԭͼ��1348��ROI��410
	const int offsetY = 18; //ԭͼ������ƫ��44��ROI��18

	Mat hann = Mat::zeros(hannRows, hannCols, CV_64FC1);
	for (int i = 0; i < hannRows; ++i)
	{
		for (int j = 0; j < hannCols; ++j)
		{
			hann.at<double>(i, j) = 0.5 +
				0.5 * cos(2.0 * PI * sqrt(pow((i - hannRows / 2.0), 2) / pow(40.0, 2) + pow((j - hannCols / 2.0), 2) / pow(800.0, 2)));
		}
	}

	//showImg("Hann", hann);
	namedWindow("Hann", WINDOW_NORMAL);
	resizeWindow("Hann", 820, 44);
	imshow("Hann", hann);

	//�˲�
	const int imgRows = src.rows;
	const int imgCols = src.cols;
	const int centerX = imgCols / 2;
	const int centerY = imgRows / 2;

	vector<Mat> fftPlanes;
	split(src, fftPlanes); //CV_64FC2

	//��ѡ��ROI
	
	Mat filtPlanes[] = { Mat::zeros(src.size(),CV_64F), Mat::zeros(src.size(),CV_64F) };

	for (size_t p = 0; p < fftPlanes.size(); ++p)
	{
		for (int j = centerX - (hannCols / 2)-1, m = 0; j < centerX + (hannCols / 2)-1, m < hannCols; ++j, ++m)
		{
			for (int i = centerY + offsetY - (hannRows / 2)-1, n = 0; i < centerY + offsetY + (hannRows / 2)-1, n < hannRows; ++i, ++n)
			{
				fftPlanes[p].at<double>(i, j) *= hann.at<double>(n, m);//ԭΪ��(i - 840, j - 477)
				filtPlanes[p].at<double>(i - offsetY - 1, j) = fftPlanes[p].at<double>(i, j);
			}
		}
	}

	merge(filtPlanes, 2, imgFilt); //CV_64FC2

}
