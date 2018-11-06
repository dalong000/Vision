#include <iostream>  
#include <opencv2/core/core.hpp>  
#include<opencv2\opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 


using namespace cv;
using namespace std;

int main()
{
	// ����һ��ͼƬ��poyanghu��Сͼ��    
	Mat img = imread("D:\\Project\\CV\\image\\990436704.jpg");
	// ����һ����Ϊ "ͼƬ"����    
	namedWindow("ͼƬ");
	// �ڴ�������ʾͼƬ   
	imshow("ͼƬ", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�    
	waitKey(6000);
	ROI();
	return 0;
}

int ROI()
{
	Mat srcImage = imread("D:\\Project\\CV\\image\\990436704.jpg");
	if (!srcImage.data)
	{
		cout << "��ȡͼƬʧ�ܣ�" << endl;
		return -1;
	}
	rectangle(srcImage, Rect(0, 0, 600, 200), Scalar(0, 255, 0), 2);
	imshow("ROI", srcImage);
	waitKey();
	return 0;

}
