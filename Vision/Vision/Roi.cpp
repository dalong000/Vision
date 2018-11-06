#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;
int ROI9()
{
	Mat srcImage = imread("D:\\Project\\CV\\image\\990436704.jpg");
	if (!srcImage.data)
	{
		cout << "¶ÁÈ¡Í¼Æ¬Ê§°Ü£¡" << endl;
		return -1;
	}
	rectangle(srcImage, Rect(0, 0, 600, 200), Scalar(0, 255, 0), 2);
	imshow("ROI", srcImage);
	waitKey();
	return 0;

}


