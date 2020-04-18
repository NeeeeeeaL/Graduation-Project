#include <iostream>
#include "unwrapM.h"

static float PI = 3.141592654;

void unwrapM(const Mat & src, Mat & dst)
{
	Mat tmpImg(src.rows, src.cols, CV_32FC1);
	src.convertTo(tmpImg, CV_32FC1);

	int image_width = src.cols;
	int image_height = src.rows;

	float *WrappedImageM = new float[image_height*image_width];
	float *UnwrappedImageM = new float[image_height*image_width];

	//������ͼ�񸳸�WrappedImageM����
	for (int j = 0; j<image_width; j++)
	{
		for (int i = 0; i<image_height; i++)
		{
			WrappedImageM[j*image_height + i] = tmpImg.at<float>(i, j);
		}
	}

	//��ʼ�����
	cout << "Start to unwrap..." << endl;
	int cen = 0;
	UnwrappedImageM[0] = WrappedImageM[0];

	if (((WrappedImageM[1]>WrappedImageM[0]) && ((WrappedImageM[1] - WrappedImageM[0]) < PI)) || ((WrappedImageM[1] - WrappedImageM[0])< - PI))
	{
		cen = 1;//+
	}
	else
	{
		cen = 2;//-
	}


	for (int i = 1; i < image_height*image_width; i++)
	{
		if (abs(WrappedImageM[i] - UnwrappedImageM[i - 1]) < PI)
		{
			UnwrappedImageM[i] = WrappedImageM[i];
		}
		else
		{
			if (cen == 1)//+
			{
				UnwrappedImageM[i] = WrappedImageM[i] + 2 * PI;
			loop1:
				if (abs(UnwrappedImageM[i] - UnwrappedImageM[i - 1]) > PI)
				{
					UnwrappedImageM[i] = UnwrappedImageM[i] + 2 * PI;
					goto loop1;
				}
			}
			else if (cen == 2)//-
			{
				UnwrappedImageM[i] = WrappedImageM[i] - 2 * PI;
			loop2:
				if (abs(UnwrappedImageM[i] - UnwrappedImageM[i - 1]) > PI)
				{
					UnwrappedImageM[i] = UnwrappedImageM[i] - 2 * PI;
					goto loop2;
				}

			}

		}
	}

	//��UnwrappedImageM��������ݴ���dst

	for (int j = 0; j<image_width; j++)
	{
		for (int i = 0; i<image_height; i++)
		{
			dst.at<float>(i, j) = (float)UnwrappedImageM[j*image_height + i];
		}
	}

	//�ͷ�
	delete WrappedImageM;
	delete UnwrappedImageM;
}
