#include <iostream>  
#include <opencv2/core/core.hpp>  
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 



//���δ���  
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

using namespace cv;
using namespace std;

int main()
{
	// ����һ��ͼƬ��poyanghu��Сͼ��    
	Mat img = imread("D:\\Project\\CV\\image\\990436704.jpg");
	Mat logoImage = imread("D:\\Project\\CV\\image\\990436704.jpg");


	Mat imageROI(img,Rect(0,0,logoImage.cols,logoImage.rows));


	logoImage.copyTo(imageROI, logoImage);

	// ����һ����Ϊ "ͼƬ"����    
	namedWindow("ͼƬ");
	// �ڴ�������ʾͼƬ   
	imshow("ͼƬ", img);





   
	waitKey(0);

	return 0;
}
