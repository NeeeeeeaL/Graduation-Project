#include "main.h"

#define PI (acos(-1))

using namespace cv;
using namespace std;

int main()
{
	/***************** ԭ����ͼ���� ********************/

	Mat imgOriginal_src = imread("3-1.bmp");//15.5blue;
	cvtColor(imgOriginal_src, imgOriginal_src, COLOR_BGR2GRAY);

	if (imgOriginal_src.empty())
	{
		cout << "cannot open the image!";
	}
	else
	{
		cout << "Load imgOriginal_src successfully!\n";

		//showImg("Original_Pic", imgOriginal_src);

	}

	//����Ҷ�任
	Mat imgOriginal_fft(imgOriginal_src.rows, imgOriginal_src.cols, CV_64FC2, Scalar(0));
	imgOriginal_src.convertTo(imgOriginal_src, CV_64F, 1.0 / 255.0);//����Ҷ�任���������б����Ǹ�����

	fft2(imgOriginal_src, imgOriginal_fft);//��ʱimgOriginal_fft������ΪCV_64FC2

	fftshift(imgOriginal_fft); //CV_64FC2

	Mat imgOriginal_filt(imgOriginal_src.rows, imgOriginal_src.cols, CV_64FC2, Scalar(0));

	//�˲�
	filt(imgOriginal_fft, imgOriginal_filt);

	//ifft2
	Mat imgOriginal_ifft(imgOriginal_src.rows, imgOriginal_src.cols, CV_64FC2, Scalar(0));
	
	
	ifftshift(imgOriginal_filt); //CV_64FC2
	int matishift_type = imgOriginal_filt.type();

	int matifft_type1 = imgOriginal_fft.type();
	ifft2(imgOriginal_filt, imgOriginal_ifft); //CV_64FC2

	
	int matifft_type2 = imgOriginal_ifft.type();

	//��ʾ��λ
	vector<Mat> filtPlanes1;
	split(imgOriginal_ifft, filtPlanes1);
	Mat imgOriginal_angel(imgOriginal_src.rows, imgOriginal_src.cols, CV_64F, Scalar(0));


	for (int i = 0; i < imgOriginal_ifft.rows; ++i)
	{
		for (int j = 0; j < imgOriginal_ifft.cols; ++j)
		{
			imgOriginal_angel.at<double>(i, j) =
				atan2(filtPlanes1[1].at<double>(i, j), filtPlanes1[0].at<double>(i, j));
		}
	}

	showImg("angel-1", imgOriginal_angel);

	//showImg("img_ifft", imgOriginal_ifft);

	/***************** ��������ͼ���� ******************/
	Mat imgModulated_src = imread("3-2.bmp");//15.5blue
	cvtColor(imgModulated_src, imgModulated_src, COLOR_BGR2GRAY);


	if (imgModulated_src.empty())
	{
		cout << "cannot open the image!";
	}
	else
	{
		cout << "Load imgModulated_src successfully!\n";
		
		//showImg("Modulated_Pic", imgModulated_src);
	}

	//����Ҷ�任
	Mat imgModulated_fft(imgModulated_src.rows, imgModulated_src.cols, CV_64FC2, Scalar(0));
	imgModulated_src.convertTo(imgModulated_src, CV_64F, 1.0 / 255.0);//����Ҷ�任���������б����Ǹ�����

	fft2(imgModulated_src, imgModulated_fft);//��ʱimgOriginal_fft������ΪCV_64FC2

	fftshift(imgModulated_fft); //CV_64FC2

	Mat imgModulated_filt(imgModulated_src.rows, imgModulated_src.cols, CV_64FC2, Scalar(0));

	//�˲�
	filt(imgModulated_fft, imgModulated_filt);

	//ifft2
	Mat imgModulated_ifft(imgModulated_src.rows, imgModulated_src.cols, CV_64FC2, Scalar(0));


	ifftshift(imgModulated_filt); //CV_64FC2

	ifft2(imgModulated_filt, imgModulated_ifft); //CV_64FC2


	//��ʾ��λ
	vector<Mat> filtPlanes2;
	split(imgModulated_ifft, filtPlanes2);
	//magnitude(filtPlanes2[0], filtPlanes2[1], filtPlanes2[0]); //������ת��Ϊ��ֵ
	//imgModulated_ifft = filtPlanes2[0];
	//showImg("imgModulated_ifft", imgModulated_ifft);


	Mat imgModulated_angel(imgModulated_src.rows, imgModulated_src.cols, CV_64F, Scalar(0));


	for (int i = 0; i < imgModulated_ifft.rows; ++i)
	{
		for (int j = 0; j < imgModulated_ifft.cols; ++j)
		{
			imgModulated_angel.at<double>(i, j) =
				atan2(filtPlanes2[1].at<double>(i, j), filtPlanes2[0].at<double>(i, j));
		}
	}

	showImg("angel-2", imgModulated_angel);
	int type = imgModulated_angel.type();
	cout << "imgModulated_angel_type = " << type << endl;

	//���������λ
	Mat wrappedPhase(imgModulated_src.rows, imgModulated_src.cols, CV_64F, Scalar(0));

	for (int i = 0; i < imgModulated_ifft.rows; ++i)
	{
		for (int j = 0; j < imgModulated_ifft.cols; ++j)
		{
			wrappedPhase.at<double>(i, j) =
			imgModulated_angel.at<double>(i, j) - imgOriginal_angel.at<double>(i, j);
			//wrappedPhase.at<double>(i, j) *= 255;
		}
	}

	//��һ����λ��ʾ
	Mat wrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_64F, Scalar(0));
	normalize(wrappedPhase, wrappedPhaseNormal, 0, 1, CV_MINMAX);

	showImg("wrappedPhase", wrappedPhaseNormal);

	//�鿴wrappedPhase������
	//for (int i = 1000; i < 1500; ++i)
	//{
	//	for (int j = 600; j < 1100; ++j)
	//	{
	//		cout << wrappedPhase.at<double>(i, j) << " | ";
	//	}
	//	cout << endl;
	//}

	//vector<int> compression_params;
	//compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION); //PNG��ʽͼƬ��ѹ������  
	//compression_params.push_back(0);  //�������ñ����ͼ����������

	//wrappedPhase.convertTo(wrappedPhase, CV_32F, 1.0 );

	//imwrite("wrappedPhaseTest304.png", wrappedPhase, compression_params);


	//��λ�����
	Mat unwrappedPhase(imgModulated_src.rows, imgModulated_src.cols, CV_32F, Scalar(0));
	unwrap(wrappedPhase, unwrappedPhase);

	Mat unwrappedPhaseNormal(imgModulated_src.rows, imgModulated_src.cols, CV_32F, Scalar(0));

	unwrappedPhase = abs(unwrappedPhase);
	normalize(unwrappedPhase, unwrappedPhaseNormal, 0, 1, CV_MINMAX);
	showImg("unwrappedPhase", unwrappedPhase);

	waitKey(0);
	destroyAllWindows();


}