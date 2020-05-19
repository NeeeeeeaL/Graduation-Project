#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>


using namespace std;

void circshift(cv::Mat &out, const cv::Point &delta);
void fftshift(cv::Mat &out);
void ifftshift(cv::Mat &out);