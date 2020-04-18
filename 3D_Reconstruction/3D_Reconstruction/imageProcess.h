#pragma once

//��C++��Ϊͼ�����࣬��������ͼ�������к���

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

class ImageProcess
{
public:
	ImageProcess();
	~ImageProcess();

void circshift(Mat &out, const Point &delta);
void fftshift(Mat &out);
void ifftshift(Mat &out);

void fft2(const Mat &src, Mat &Fourier);
void ifft2(const Mat &src, Mat &Fourier);

void filt(const Mat & src, Mat & imgFilt);

void changeCh(const Mat & src, Mat & dst);//��˫ͨ��ͼ��תΪ��ͨ����ʾ

Mat getPhase(Mat src1, Mat src2, Mat src3, Mat src4);

};

