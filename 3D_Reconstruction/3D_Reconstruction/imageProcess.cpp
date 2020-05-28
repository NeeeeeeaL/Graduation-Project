#include "imageProcess.h"

#define PI (acos(-1))

ImageProcess::ImageProcess()
{
}


ImageProcess::~ImageProcess()
{
}

/************************* fftshift & ifftshift 函数部分 ****************************/
void ImageProcess::circshift(cv::Mat & out, const cv::Point & delta)
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

void ImageProcess::fftshift(cv::Mat & out)
{
	cv::Size sz = out.size();
	cv::Point pt(0, 0);
	pt.x = (int)floor(sz.width / 2.0);//floor: 计算不大于 arg 的最大整数值
	pt.y = (int)floor(sz.height / 2.0);
	circshift(out, pt);
}

void ImageProcess::ifftshift(cv::Mat & out)
{
	cv::Size sz = out.size();
	cv::Point pt(0, 0);
	pt.x = (int)ceil(sz.width / 2.0);//ceil: 计算不小于 arg 的最小整数值
	pt.y = (int)ceil(sz.height / 2.0);
	circshift(out, pt);
}


/*************************** fft2 & ifft2 函数 *****************************/
void ImageProcess::fft2(const cv::Mat & src, cv::Mat & Fourier)
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
		//vector<Mat> planes;
		//split(tmp, planes); //planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		//magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
		//Fourier = planes[0];
	}
}

void ImageProcess::ifft2(const cv::Mat & src, cv::Mat & Fourier)
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

/*************************** filt 滤波器*****************************/
void ImageProcess::filt(const cv::Mat & src, cv::Mat & imgFilt)
{
	//设计非对称汉宁窗
	const int hannRows = 50;
	const int hannCols = 160;
	const int offsetY = 29;
	
	cv::Mat hann = cv::Mat::zeros(hannRows, hannCols, CV_64FC1);
	for (int i = 0; i < hannRows; ++i)
	{
		for (int j = 0; j < hannCols; ++j)
		{
			hann.at<double>(i, j) = 0.5 +
				0.5 * cos(2.0 * PI * sqrt(pow((i - hannRows / 2.0), 2) / pow(49.0, 2) + pow((j - hannCols / 2.0), 2) / pow(170.0, 2)));
		}
	}

	//滤波
	const int imgRows = src.rows;
	const int imgCols = src.cols;
	const int centerX = imgCols / 2;
	const int centerY = imgRows / 2;

	vector<cv::Mat> fftPlanes;
	split(src, fftPlanes); //CV_64FC2

	//框选出ROI

	cv::Mat filtPlanes[] = { cv::Mat::zeros(src.size(),CV_64F), cv::Mat::zeros(src.size(),CV_64F) };

	for (size_t p = 0; p < fftPlanes.size(); ++p)
	{
		for (int j = centerX - (hannCols / 2) - 1, m = 0; j < centerX + (hannCols / 2) - 1, m < hannCols; ++j, ++m)
		{
			for (int i = centerY + offsetY - (hannRows / 2) - 1, n = 0; i < centerY + offsetY + (hannRows / 2) - 1, n < hannRows; ++i, ++n)
			{
				fftPlanes[p].at<double>(i, j) *= hann.at<double>(n, m);//原为：(i - 840, j - 477)
				filtPlanes[p].at<double>(i - offsetY, j) = fftPlanes[p].at<double>(i, j);
			}
		}
	}

	merge(filtPlanes, 2, imgFilt); //CV_64FC2

}

//将双通道图像转为单通道显示
void ImageProcess::changeCh(const cv::Mat & src, cv::Mat & dst)
{
	if (src.channels() > 1)
	{
		vector<cv::Mat> planes;
		split(src, planes);
		magnitude(planes[0], planes[1], planes[0]); //将复数转化为幅值
		dst = planes[0];

		dst.convertTo(dst, CV_8U);
	}

	else
		return;
}

cv::Mat ImageProcess::getPhase(cv::Mat src1, cv::Mat src2, cv::Mat src3, cv::Mat src4)
{
	cv::Mat phase(src1.size(), CV_64F);
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
