#include <iostream>  
#include <opencv2/core/core.hpp>  
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 



//屏蔽窗口  
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")  

using namespace cv;
using namespace std;

int main()
{
	// 读入一张图片（poyanghu缩小图）    
	Mat img = imread("D:\\Project\\CV\\image\\990436704.jpg");
	Mat logoImage = imread("D:\\Project\\CV\\image\\990436704.jpg");


	Mat imageROI(img,Rect(0,0,logoImage.cols,logoImage.rows));


	logoImage.copyTo(imageROI, logoImage);

	// 创建一个名为 "图片"窗口    
	namedWindow("图片");
	// 在窗口中显示图片   
	imshow("图片", img);





   
	waitKey(0);

	return 0;
}
