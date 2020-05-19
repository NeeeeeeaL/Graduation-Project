#include "showImg.h"

void showImg(const char *windowName, const cv::Mat & src)
{
	const int windowWidth = 650;//489
	const int windowHeight = 500;//500

	cv::namedWindow(windowName, cv::WINDOW_NORMAL);
	cv::resizeWindow(windowName, windowWidth, windowHeight);
	cv::imshow(windowName, src);
}
