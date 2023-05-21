#include <opencv2/opencv.hpp>
#include <iostream>

#define LOG(x) std::cout << x << '\n'

int main()
{
	cv::Mat image = cv::imread("./img/kawaii.jpg");

	if (image.empty())
	{
		LOG("Read Image file Failed!");
	}

	cv::imshow("Kawaii", image);

	LOG("图像的高度为: " << image.rows);	// 矩阵的行数
	LOG("图像的宽度为: " << image.cols);	// 矩阵的列数
	LOG("图像的通道数为: " << image.channels());	// 图像色彩通道数
	LOG("图像的尺寸为: " << image.size);	// 行数 * 列数

	cv::Mat imageKeen(image, cv::Rect(0, 0, 270, 270));

	cv::imshow("Kawaii", imageKeen);

	cv::waitKey(0);

	return 0;
}