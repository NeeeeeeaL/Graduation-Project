#include "circshift.h"


void circshift(Mat & out, const Point & delta)
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

void fftshift(Mat & out)
{
	Size sz = out.size();
	Point pt(0, 0);
	pt.x = (int)floor(sz.width / 2.0);//floor: ���㲻���� arg ���������ֵ
	pt.y = (int)floor(sz.height / 2.0);
	circshift(out, pt);
}

void ifftshift(Mat & out)
{
	Size sz = out.size();
	Point pt(0, 0);
	pt.x = (int)ceil(sz.width / 2.0);//ceil: ���㲻С�� arg ����С����ֵ
	pt.y = (int)ceil(sz.height / 2.0);
	circshift(out, pt);
}
