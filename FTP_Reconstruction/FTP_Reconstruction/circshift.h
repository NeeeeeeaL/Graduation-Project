#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

void circshift(Mat &out, const Point &delta);
void fftshift(Mat &out);
void ifftshift(Mat &out);