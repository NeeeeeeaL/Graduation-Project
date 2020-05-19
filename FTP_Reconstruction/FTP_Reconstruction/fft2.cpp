#include "fft2.h"

using namespace std;

void fft2(const cv::Mat & src, cv::Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //不支持的数据格式

	if (mat_type < 7)
	{
		cv::Mat planes[] = { cv::Mat_<double>(src), cv::Mat::zeros(src.size(),CV_64F)};
		merge(planes, 2, Fourier);
		dft(Fourier, Fourier);
	}
	else // 7<mat_type<15
	{
		cv::Mat tmp;
		dft(src, tmp);
		//vector<Mat> planes;
		//split(tmp, planes); //planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		//magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
		//Fourier = planes[0];
	}
}

void ifft2(const cv::Mat & src, cv::Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //不支持的数据格式

	if (mat_type < 7)
	{
		cv::Mat planes[] = { cv::Mat_<double>(src), cv::Mat::zeros(src.size(),CV_64F) };
		merge(planes, 2, Fourier);
		dft(Fourier, Fourier, cv::DFT_INVERSE + cv::DFT_SCALE, 0);
	}
	else // 7<mat_type<15
	{
		cv::Mat tmp;
		dft(src, Fourier, cv::DFT_INVERSE + cv::DFT_SCALE, 0);
		//vector<Mat> planes;
		//split(tmp, planes);
		//magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
		//Fourier = planes[0];
	}
}



