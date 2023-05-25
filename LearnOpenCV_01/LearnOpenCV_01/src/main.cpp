#include <iostream>

#include "../ref/OnMouse.h"
#include "../ref/Salt.h"

#define LOG(x) std::cout << x << '\n'

void MyFilter(int filter_size, cv::Mat& image_input, cv::Mat& image_output);

int main()
{
	cv::Mat image, image_gray, image_output, image_output2;
	image = cv::imread("./img/kawaii.jpg");
	if (image.empty())
	{
		LOG("Load Image Failed!");
		return -1;
	}
	cv::imshow("image", image);

	cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);
	Salt(image_gray, 1000);
	cv::imshow("image_gray", image_gray);

	// 自己写
	int filter_size = 7;
	MyFilter(filter_size, image_gray, image_output);

	// OpenCV
	cv::blur(image_gray, image_output2, cv::Size(7, 7));

	cv::imshow("image_output", image_output);
	cv::imshow("image_output2", image_output2);

	cv::waitKey(0);

	return 0;
}

// 实现盒式滤波器
void MyFilter(int filter_size, cv::Mat& image_input, cv::Mat& image_output)
{
	image_output = image_input.clone();

	int k = (filter_size - 1) / 2;
	for (int i = k; i < (image_input.rows - k); i++)
	{
		for (int j = k; j < (image_input.cols - k); j++)
		{
			int sum = 0;
			for (int m = -k; m < k + 1; m++)
			{
				for (int n = -k; n < k + 1; n++)
				{
					sum = sum + image_input.at<uchar>(i + m, j + n);
				}
			}
			image_output.at<uchar>(i, j) = round(sum / (filter_size * filter_size));
		}
	}
}