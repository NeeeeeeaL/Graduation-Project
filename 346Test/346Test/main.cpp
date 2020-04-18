#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		Mat imgSrc = imread("phase2-" + to_string(i) + ".bmp", 0);
		Mat imgPart = imread("park2-" + to_string(i) + ".bmp", 0);
		Mat tmp = imgSrc.clone();

		//Mat imgCutted = imgSrc(Range(260, 720), Range(20, 1900));
		//int type = imgCutted.type();
		//equalizeHist(imgCutted, imgCutted);
		//convertScaleAbs(imgCutted, imgCutted, 0.8, -10);

		for (int j = 0; j < 5; ++j)
		{
			imgPart.copyTo(tmp(Range(j * 460, (j + 1) * 460), Range(0, 1880)));
		}

		blur(tmp, tmp, Size(5, 5));

		imwrite(("backGround2-" + to_string(i) + ".bmp"), tmp);

	}

	return 1;
}