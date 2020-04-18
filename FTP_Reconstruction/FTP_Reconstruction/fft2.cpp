#include "fft2.h"

using namespace std;

void fft2(const Mat & src, Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //不支持的数据格式

	if (mat_type < 7)
	{
		Mat planes[] = { Mat_<double>(src), Mat::zeros(src.size(),CV_64F)};
		merge(planes, 2, Fourier);
		dft(Fourier, Fourier);
	}
	else // 7<mat_type<15
	{
		Mat tmp;
		dft(src, tmp);
		//vector<Mat> planes;
		//split(tmp, planes); //planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		//magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
		//Fourier = planes[0];
	}
}

void ifft2(const Mat & src, Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //不支持的数据格式

	if (mat_type < 7)
	{
		Mat planes[] = { Mat_<double>(src), Mat::zeros(src.size(),CV_64F) };
		merge(planes, 2, Fourier);
		dft(Fourier, Fourier, DFT_INVERSE + DFT_SCALE, 0);
	}
	else // 7<mat_type<15
	{
		Mat tmp;
		dft(src, Fourier, DFT_INVERSE + DFT_SCALE, 0);
		//vector<Mat> planes;
		//split(tmp, planes);
		//magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
		//Fourier = planes[0];
	}
}



