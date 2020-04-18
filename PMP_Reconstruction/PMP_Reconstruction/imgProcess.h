#pragma once

#include "main.h"

using namespace cv;
using namespace std;

//void loadImg(const char *imgName);

void showImg(const char *windowName, const Mat & src);
Mat getMask(Mat src1,  Mat src2,  Mat src3,  Mat src4);
Mat getPhase(Mat src1, Mat src2, Mat src3, Mat src4);