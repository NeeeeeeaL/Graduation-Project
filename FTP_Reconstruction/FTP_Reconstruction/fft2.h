#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

void fft2(const Mat &src, Mat &Fourier);
void ifft2(const Mat &src, Mat &Fourier);