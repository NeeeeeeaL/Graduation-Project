#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>


using namespace std;

void fft2(const cv::Mat &src, cv::Mat &Fourier);
void ifft2(const cv::Mat &src, cv::Mat &Fourier);