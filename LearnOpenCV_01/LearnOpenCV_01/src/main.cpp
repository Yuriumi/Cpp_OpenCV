#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
	cv::Mat image;	// 创建一个空图像

	image = cv::imread("./img/kawaii.jpg");	// 读取图像文件

	// 检测读取是否成功
	if (image.empty())
	{
		std::cout << "ERROR : Read image Failed!\n";
		return -1;
	}

	cv::namedWindow("Image");	// 创建图片显示窗口,可不写
	cv::imshow("Image", image);	// 在窗口显示图片

	cv::imwrite("./img/1.png", image);	// 将图像保存为png格式

	cv::waitKey(0);

	return 0;
}