#include <iostream>  
#include <opencv2/core/core.hpp>  
#include<opencv2\opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 


using namespace cv;
using namespace std;

int main()
{
	// 读入一张图片（poyanghu缩小图）    
	Mat img = imread("D:\\Project\\CV\\image\\990436704.jpg");
	// 创建一个名为 "图片"窗口    
	namedWindow("图片");
	// 在窗口中显示图片   
	imshow("图片", img);
	// 等待6000 ms后窗口自动关闭    
	waitKey(6000);
	ROI();
	return 0;
}

int ROI()
{
	Mat srcImage = imread("D:\\Project\\CV\\image\\990436704.jpg");
	if (!srcImage.data)
	{
		cout << "读取图片失败！" << endl;
		return -1;
	}
	rectangle(srcImage, Rect(0, 0, 600, 200), Scalar(0, 255, 0), 2);
	imshow("ROI", srcImage);
	waitKey();
	return 0;

}
