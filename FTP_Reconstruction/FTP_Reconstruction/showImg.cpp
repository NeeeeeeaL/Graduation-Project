#include "showImg.h"

void showImg(const char *windowName, const Mat & src)
{
	const int windowWidth = 700;//489
	const int windowHeight = 500;//500

	namedWindow(windowName, WINDOW_NORMAL);
	resizeWindow(windowName, windowWidth, windowHeight);
	imshow(windowName, src);
}
