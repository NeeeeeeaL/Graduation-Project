#include "filter.h"

#define PI (acos(-1))

void filt(const Mat & src, Mat & imgFilt)

{
	//��ƷǶԳƺ�����
	const int hannRows = 30; //ԭͼ��50��ROI3��22��ROI4��30����꣺32
	const int hannCols = 800; //ԭͼ��1348��ROI3��410��ROI4��750����꣺1490
	const int offsetY = 25; //ԭͼ������ƫ��44��ROI3��18��ROI4��25����꣺30

	Mat hann = Mat::zeros(hannRows, hannCols, CV_64FC1);
	for (int i = 0; i < hannRows; ++i)
	{
		for (int j = 0; j < hannCols; ++j)
		{
			hann.at<double>(i, j) = 0.5 +
				0.5 * cos(2.0 * PI * sqrt(pow((i - hannRows / 2.0), 2) / pow(40.0, 2) + pow((j - hannCols / 2.0), 2) / pow(900.0, 2)));
			//ԭͼ��40�� 1200��ROI3��35�� 700����꣺50�� 1200
		}
	}

	//showImg("Hann", hann);
	namedWindow("Hann", WINDOW_NORMAL);
	resizeWindow("Hann", 800, 30);
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
				filtPlanes[p].at<double>(i - offsetY, j) = fftPlanes[p].at<double>(i, j);
			}
		}
	}

	merge(filtPlanes, 2, imgFilt); //CV_64FC2

}
