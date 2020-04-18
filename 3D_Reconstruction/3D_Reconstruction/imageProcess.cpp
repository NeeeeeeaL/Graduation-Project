#include "imageProcess.h"

#define PI (acos(-1))

ImageProcess::ImageProcess()
{
}


ImageProcess::~ImageProcess()
{
}

/************************* fftshift & ifftshift �������� ****************************/
void ImageProcess::circshift(Mat & out, const Point & delta)
{
	Size sz = out.size();

	// ������
	assert(sz.height > 0 && sz.width > 0);
	// �����������Ҫ�ƶ�
	if ((sz.height == 1 && sz.width == 1) || (delta.x == 0 && delta.y == 0))
		return;

	// ��Ҫ�ƶ������ı任�����������������������
	int x = delta.x;
	int y = delta.y;
	if (x > 0) x = x % sz.width; //�����ƶ�
	if (y > 0) y = y % sz.height; //�����ƶ�
	if (x < 0) x = x % sz.width + sz.width; //�����ƶ�
	if (y < 0) y = y % sz.height + sz.height; //�����ƶ�


  // ��ά��MatҲ���ƶ�
	vector<Mat> planes;
	split(out, planes);

	for (size_t i = 0; i < planes.size(); i++)
	{
		// ��ֱ�����ƶ�
		Mat tmp0, tmp1, tmp2, tmp3;
		Mat q0(planes[i], Rect(0, 0, sz.width, sz.height - y));
		Mat q1(planes[i], Rect(0, sz.height - y, sz.width, y));
		q0.copyTo(tmp0);
		q1.copyTo(tmp1);
		tmp0.copyTo(planes[i](Rect(0, y, sz.width, sz.height - y)));
		tmp1.copyTo(planes[i](Rect(0, 0, sz.width, y)));

		// ˮƽ�����ƶ�
		Mat q2(planes[i], Rect(0, 0, sz.width - x, sz.height));
		Mat q3(planes[i], Rect(sz.width - x, 0, x, sz.height));
		q2.copyTo(tmp2);
		q3.copyTo(tmp3);
		tmp2.copyTo(planes[i](Rect(x, 0, sz.width - x, sz.height)));
		tmp3.copyTo(planes[i](Rect(0, 0, x, sz.height)));
	}

	merge(planes, out);
}

void ImageProcess::fftshift(Mat & out)
{
	Size sz = out.size();
	Point pt(0, 0);
	pt.x = (int)floor(sz.width / 2.0);//floor: ���㲻���� arg ���������ֵ
	pt.y = (int)floor(sz.height / 2.0);
	circshift(out, pt);
}

void ImageProcess::ifftshift(Mat & out)
{
	Size sz = out.size();
	Point pt(0, 0);
	pt.x = (int)ceil(sz.width / 2.0);//ceil: ���㲻С�� arg ����С����ֵ
	pt.y = (int)ceil(sz.height / 2.0);
	circshift(out, pt);
}


/*************************** fft2 & ifft2 ���� *****************************/
void ImageProcess::fft2(const Mat & src, Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //��֧�ֵ����ݸ�ʽ

	if (mat_type < 7)
	{
		Mat planes[] = { Mat_<double>(src), Mat::zeros(src.size(),CV_64F) };
		merge(planes, 2, Fourier);
		dft(Fourier, Fourier);
	}
	else // 7<mat_type<15
	{
		Mat tmp;
		dft(src, tmp);
		//vector<Mat> planes;
		//split(tmp, planes); //planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		//magnitude(planes[0], planes[1], planes[0]); //������ת��Ϊ��ֵ
		//Fourier = planes[0];
	}
}

void ImageProcess::ifft2(const Mat & src, Mat & Fourier)
{
	int mat_type = src.type();
	assert(mat_type<15); //��֧�ֵ����ݸ�ʽ

	if (mat_type < 7)
	{
		Mat planes[] = { Mat_<double>(src), Mat::zeros(src.size(),CV_64F) };
		merge(planes, 2, Fourier);
		dft(Fourier, Fourier, DFT_INVERSE + DFT_SCALE, 0);
	}
	else // 7<mat_type<15
	{
		Mat tmp;
		dft(src, Fourier, DFT_INVERSE + DFT_SCALE, 0);
		//vector<Mat> planes;
		//split(tmp, planes);
		//magnitude(planes[0], planes[1], planes[0]); //������ת��Ϊ��ֵ
		//Fourier = planes[0];
	}
}

/*************************** filt �˲���*****************************/
void ImageProcess::filt(const Mat & src, Mat & imgFilt)
{
	//��ƷǶԳƺ�����
	const int hannRows = 50;
	const int hannCols = 1348;
	Mat hann = Mat::zeros(hannRows, hannCols, CV_64FC1);
	for (int i = 0; i < hannRows; ++i)
	{
		for (int j = 0; j < hannCols; ++j)
		{
			hann.at<double>(i, j) = 0.5 +
				0.5 * cos(2.0 * PI * sqrt(pow((i - hannRows / 2.0), 2) / pow(50.0, 2) + pow((j - hannCols / 2.0), 2) / pow(1200.0, 2)));
		}
	}

	//showImg("Hann", hann);

	//�˲�
	const int imgRows = src.rows;
	const int imgCols = src.cols;
	const int centerX = imgCols / 2;
	const int centerY = imgRows / 2;

	vector<Mat> fftPlanes;
	split(src, fftPlanes); //CV_64FC2

	//��ѡ��ROI

	Mat filtPlanes[] = { Mat::zeros(src.size(),CV_64F), Mat::zeros(src.size(),CV_64F) };

	for (size_t p = 0; p < fftPlanes.size(); ++p)
	{
		for (int j = centerX - (hannCols / 2) - 1; j < centerX + (hannCols / 2) - 1; ++j)
		{
			for (int i = centerY + 44 - (hannRows / 2) - 1; i < centerY + 44 + (hannRows / 2) - 1; ++i)
			{
				fftPlanes[p].at<double>(i, j) *= hann.at<double>(i - 840, j - 477);
				filtPlanes[p].at<double>(i - 43, j) = fftPlanes[p].at<double>(i, j);
			}
		}
	}

	merge(filtPlanes, 2, imgFilt); //CV_64FC2
}

//��˫ͨ��ͼ��תΪ��ͨ����ʾ
void ImageProcess::changeCh(const Mat & src, Mat & dst)
{
	if (src.channels() > 1)
	{
		vector<Mat> planes;
		split(src, planes);
		magnitude(planes[0], planes[1], planes[0]); //������ת��Ϊ��ֵ
		dst = planes[0];

		dst.convertTo(dst, CV_8U);
	}

	else
		return;
}

Mat ImageProcess::getPhase(Mat src1, Mat src2, Mat src3, Mat src4)
{
	Mat phase(src1.size(), CV_64F);
	const int imgWidth = src1.cols;
	const int imgHeight = src1.rows;

	for (int i = 0; i < imgHeight; ++i)
	{
		for (int j = 0; j < imgWidth; ++j)
		{
			double I1 = src1.at<double>(i, j);
			double I2 = src2.at<double>(i, j);
			double I3 = src3.at<double>(i, j);
			double I4 = src4.at<double>(i, j);

			if (I1 != I3)
				phase.at<double>(i, j) = atan2((I4 - I2), (I1 - I3));
			else if (I2 == I4)
				phase.at<double>(i, j) = 0;
			else if (I4 > I2)
				phase.at<double>(i, j) = PI / 2;
			else
				phase.at<double>(i, j) = -PI / 2;

		}
	}

	return phase;
}
