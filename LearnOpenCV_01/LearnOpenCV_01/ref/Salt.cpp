#include "Salt.h"

void Salt(cv::Mat& image, int n)
{
	// 随机数生成器
	std::default_random_engine generater;
	std::uniform_int_distribution<int>randomRow(0, image.rows - 1);
	std::uniform_int_distribution<int>randomCol(0, image.cols - 1);

	int x, y;
	for (int i = 0; i < n; i++)
	{
		x = randomRow(generater);
		y = randomCol(generater);
		if (image.channels() == 1)
			image.at<uchar>(x, y) = 255;
		else if (image.channels() == 3)
		{
			image.at<cv::Vec3b>(x, y)[0] = 255;
			image.at<cv::Vec3b>(x, y)[1] = 255;
			image.at<cv::Vec3b>(x, y)[2] = 255;
		}
	}
}
