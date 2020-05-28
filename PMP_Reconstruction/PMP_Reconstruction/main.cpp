#include "main.h"

#define PI (acos(-1))

int main()
{
	/**********读入四幅光栅图像*************/

	Mat imgSrc1 = imread("12-5.bmp", 0); //3- ：面具调制图
	Mat imgSrc2 = imread("12-6.bmp", 0);
	Mat imgSrc3 = imread("12-7.bmp", 0);
	Mat imgSrc4 = imread("12-8.bmp", 0);

	/***********读入四幅背景图像************/
	Mat imgSrc5 = imread("12-1.bmp", 0);
	Mat imgSrc6 = imread("12-2.bmp", 0);
	Mat imgSrc7 = imread("12-3.bmp", 0);
	Mat imgSrc8 = imread("12-4.bmp", 0);

	imgSrc1.convertTo(imgSrc1, CV_64F, 1.0 / 255.0);
	imgSrc2.convertTo(imgSrc2, CV_64F, 1.0 / 255.0);
	imgSrc3.convertTo(imgSrc3, CV_64F, 1.0 / 255.0);
	imgSrc4.convertTo(imgSrc4, CV_64F, 1.0 / 255.0);

	imgSrc5.convertTo(imgSrc5, CV_64F, 1.0 / 255.0);
	imgSrc6.convertTo(imgSrc6, CV_64F, 1.0 / 255.0);
	imgSrc7.convertTo(imgSrc7, CV_64F, 1.0 / 255.0);
	imgSrc8.convertTo(imgSrc8, CV_64F, 1.0 / 255.0);


	//用面具图像做测试，不需要mask
	//Mat mask = getMask(imgSrc1, imgSrc2, imgSrc3, imgSrc4);

	Mat phaseFG = getPhase(imgSrc1, imgSrc2, imgSrc3, imgSrc4);
	Mat phaseBG = getPhase(imgSrc5, imgSrc6, imgSrc7, imgSrc8);

	//normalize(phaseFG, phaseFG, 0, 1, CV_MINMAX);
	//showImg("phaseFG", phaseFG);

	//normalize(phaseBG, phaseBG, 0, 1, CV_MINMAX);
	//showImg("phaseBG", phaseBG);


	const int imgWidth = imgSrc1.cols;
	const int imgHeight = imgSrc1.rows;

	Mat imgRoiFG(imgHeight, imgWidth, CV_64F, Scalar(0));
	Mat imgRoiBG(imgHeight, imgWidth, CV_64F, Scalar(0));

	Mat wrappedPhase(imgHeight, imgWidth, CV_64F, Scalar(0));
	Mat unwrappedPhase(imgHeight, imgWidth, CV_32F, Scalar(0));
	Mat unwrappedPhaseM(imgHeight, imgWidth, CV_32F, Scalar(0));
	
	for (int i = 0; i < imgHeight; ++i)
	{
		for (int j = 0; j < imgWidth; ++j)
		{
			imgRoiFG.at<double>(i, j) = /*mask.at<uchar>(i, j) * */phaseFG.at<double>(i, j);
			imgRoiBG.at<double>(i, j) = /*mask.at<uchar>(i, j) * */phaseBG.at<double>(i, j);

			wrappedPhase.at<double>(i, j) = imgRoiFG.at<double>(i, j) - imgRoiBG.at<double>(i, j);
		}
	}

	//normalize(imgRoiFG, imgRoiFG, 0, 1, CV_MINMAX);
	//normalize(imgRoiBG, imgRoiBG, 0, 1, CV_MINMAX);

	Mat wrappedPhaseNormal(imgHeight, imgWidth, CV_64F, Scalar(0));
	normalize(wrappedPhase, wrappedPhaseNormal, 0, 1, CV_MINMAX);

	//showImg("imgRoiFG", imgRoiFG);
	//showImg("imgRoiBG", imgRoiBG);
	showImg("wrappedPhase", wrappedPhaseNormal);

	//解包裹(面具图像)
	unwrap(wrappedPhase, unwrappedPhase);

	unwrappedPhase = abs(unwrappedPhase);

	Mat unwrappedPhaseNormal(imgHeight, imgWidth, CV_32F, Scalar(0));
	normalize(unwrappedPhase, unwrappedPhaseNormal, 0, 1, CV_MINMAX);

	showImg("unwrappedPhase", unwrappedPhaseNormal);

	//解包裹
	//Mat unwrappedPhaseFG(imgHeight, imgWidth, CV_32F, Scalar(0));
	//Mat unwrappedPhaseNormalFG(imgHeight, imgWidth, CV_32F, Scalar(0));

	//Mat unwrappedPhaseBG(imgHeight, imgWidth, CV_32F, Scalar(0));
	//Mat unwrappedPhaseNormalBG(imgHeight, imgWidth, CV_32F, Scalar(0));

	//unwrap(imgRoiFG, unwrappedPhaseFG);
	//unwrap(imgRoiBG, unwrappedPhaseBG);

	//unwrappedPhaseFG = abs(unwrappedPhaseFG);
	//unwrappedPhaseBG = abs(unwrappedPhaseBG);

	//normalize(unwrappedPhaseFG, unwrappedPhaseNormalFG, 0, 1, CV_MINMAX);
	//showImg("unwrappedPhaseFG", unwrappedPhaseNormalFG);
	//normalize(unwrappedPhaseBG, unwrappedPhaseNormalBG, 0, 1, CV_MINMAX);
	//showImg("unwrappedPhaseBG", unwrappedPhaseNormalBG);

	//Mat resultPhase(imgHeight, imgWidth, CV_32F, Scalar(0));
	//Mat resultPhaseNormal(imgHeight, imgWidth, CV_32F, Scalar(0));

	//for (int i = 0; i < imgHeight; ++i)
	//{
	//	for (int j = 0; j < imgWidth; ++j)
	//	{

	//		resultPhase.at<float>(i, j) = unwrappedPhaseFG.at<float>(i, j) - unwrappedPhaseBG.at<float>(i, j);
	//	}
	//}

	//normalize(resultPhase, resultPhaseNormal, 0, 1, CV_MINMAX);
	//showImg("resultPhase", resultPhaseNormal);

	/*********************pi相移法*************************/
	//Mat pi1 = imread("7-1.bmp", 0);
	//Mat pi2 = imread("7-2.bmp", 0);

	//pi1.convertTo(pi1, CV_64F, 1.0 / 255.0);
	//pi2.convertTo(pi2, CV_64F, 1.0 / 255.0);

	//Mat dst(imgHeight, imgWidth, CV_64F, Scalar(0));
	//dst = subtract(pi1, pi2);
	//showImg("piPhase", dst);
	//
	//for (int i = 0; i < dst.rows; ++i)
	//{
	//	for (int j = 0; j < dst.cols; ++j)
	//	{

	//		dst.at<double>(i, j) *= 255;
	//	}
	//}
	//dst.convertTo(dst, CV_8U);
	//imwrite("dst1.bmp", dst);

	waitKey(0);
	destroyAllWindows();
}