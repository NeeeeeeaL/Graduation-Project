#include "circshift.h"


void circshift(cv::Mat & out, const cv::Point & delta)
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

void fftshift(cv::Mat & out)
{
	cv::Size sz = out.size();
	cv::Point pt(0, 0);
	pt.x = (int)floor(sz.width / 2.0);//floor: 计算不大于 arg 的最大整数值
	pt.y = (int)floor(sz.height / 2.0);
	circshift(out, pt);
}

void ifftshift(cv::Mat & out)
{
	cv::Size sz = out.size();
	cv::Point pt(0, 0);
	pt.x = (int)ceil(sz.width / 2.0);//ceil: 计算不小于 arg 的最小整数值
	pt.y = (int)ceil(sz.height / 2.0);
	circshift(out, pt);
}
