#pragma once

//��C++��Ϊͼ�����࣬��������ͼ�������к���

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>

using namespace std;

class ImageProcess
{
public:
	ImageProcess();
	~ImageProcess();

void circshift(cv::Mat &out, const cv::Point &delta);
void fftshift(cv::Mat &out);
void ifftshift(cv::Mat &out);

void fft2(const cv::Mat &src, cv::Mat &Fourier);
void ifft2(const cv::Mat &src, cv::Mat &Fourier);

void filt(const cv::Mat & src, cv::Mat & imgFilt);

void changeCh(const cv::Mat & src, cv::Mat & dst);//��˫ͨ��ͼ��תΪ��ͨ����ʾ

cv::Mat getPhase(cv::Mat src1, cv::Mat src2, cv::Mat src3, cv::Mat src4);

};

