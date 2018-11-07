#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

bool draw;
Mat src;//ԭʼͼ��  
Mat roi;//ROIͼ��
Point cursor;//��ʼ����   
Rect rect;//���ROI�ľ��ο�

		  /*
		  void onMouse(int event, int x, int y, int flags, void *param);
		  ��һ��������������ʱ����������ţ���opencv�У�event����¼��ܹ���10�У���0-9���δ�������:
		  EVENT_MOUSEMOVE      =0,    //����
		  EVENT_LBUTTONDOWN    =1,    //������
		  EVENT_RBUTTONDOWN    =2,    //�Ҽ����
		  EVENT_MBUTTONDOWN    =3,    //�м���
		  EVENT_LBUTTONUP      =4,    //����ͷ�
		  EVENT_RBUTTONUP      =5,    //�Ҽ��ͷ�
		  EVENT_MBUTTONUP      =6,    //�м��ͷ�
		  EVENT_LBUTTONDBLCLK  =7,    //���˫��
		  EVENT_RBUTTONDBLCLK  =8,    //�Ҽ�˫��
		  EVENT_MBUTTONDBLCLK  =9     //�м��ͷ�
		  �ڶ����������������λ�ڴ��ڵ�(x��y)����λ�ã��������Ͻ�Ĭ��Ϊԭ�㣬����Ϊx�ᣬ����Ϊy�᣻
		  ����������������������ק�¼����Լ�������������¼����ܹ���32���¼������ﲻ��׸����
		  ���ĸ����������������ı�š�
		  */
void onMouse(int event, int x, int y, int flags, void *param)
{
	Mat img = src.clone();
	switch (event)
	{
		//����������
	case CV_EVENT_LBUTTONDOWN:
		//������ͼ��ʱ�����֮ǰROIͼ�����ʾ����  
		cvDestroyWindow("ROI");
		//�����ʼ����  
		cursor = Point(x, y);
		//��ʼ����ʼ���ο�  
		rect = Rect(x, y, 0, 0);
		draw = true;
		break;

		//�ɿ�������      
	case CV_EVENT_LBUTTONUP:
		if (rect.height > 0 && rect.width > 0)
		{
			//��img�еľ��������Ƹ�roi������ʾ��SignROI���� 
			roi = img(Rect(rect.x, rect.y, rect.width, rect.height));
			rectangle(img, rect, Scalar(0, 0, 255), 2);
			namedWindow("SignROI");
			imshow("SignROI", img);

			//���������ο��ͼ����ԭͼ��ԭ  
			src.copyTo(img);
			imshow("SrcImage", img);

			//��ʾROIͼ��
			namedWindow("ROI");
			imshow("ROI", roi);
			waitKey(0);
		}
		draw = false;
		break;

		//�ƶ����
	case CV_EVENT_MOUSEMOVE:
		if (draw)
		{
			//��MIN�õ����ϵ���Ϊ���ο����ʼ���꣬������������������ʱֻ����һ���������  
			rect.x = MIN(x, cursor.x);
			rect.y = MIN(y, cursor.y);
			rect.width = abs(cursor.x - x);
			rect.height = abs(cursor.y - y);
			//��ֹ�������򳬳�ͼ��ķ�Χ  
			rect &= Rect(0, 0, src.cols, src.rows);
		}
		break;
	}
}

int main()
{
	src = imread("D:\\Project\\CV\\image\\990436704.jpg");
	if (src.data == 0)
	{
		cout << "ͼƬ������" << endl;
		return -1;
	}
	namedWindow("SrcImage");
	imshow("SrcImage", src);
	/*
	void setMouseCallback(const string& winname, MouseCallback onMouse, void* userdata=0 );
	Parameters:
	��һ��������windows�Ӵ����ƣ�����Ϊwinname���Ӵ���������أ�
	�ڶ��������������Ӧ���������������ĵ�����ƶ����ɿ����ж����Ĳ������ͣ���������Ӧ�ĺ�������
	�����������������Ӧ��������ID���������Ӧ��������ƥ����У���ʱֻ�õ�Ĭ��Ϊ0�������
	*/
	setMouseCallback("SrcImage", onMouse, NULL);
	waitKey();
	return 0;
}