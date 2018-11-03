#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;
int main()
{
	Mat srcImage = imread("");
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


