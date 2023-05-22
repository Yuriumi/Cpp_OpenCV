#include "../ref/OnMouse.h"
#include <iostream>

#include "../ref/Salt.h"

#define LOG(x) std::cout << x << '\n'

void AddNoise()
{
	cv::Mat image = cv::imread("./img/kawaii.jpg");

	if (image.empty())
	{
		LOG("Read Image file Failed!");
	}

	// Ô­Í¼Ïñ
	cv::imshow("Kawaii01", image);

	// ¼ÓÔëÍ¼Ïñ
	Salt(image, 5000);
	cv::imshow("Kawaii02", image);
}

void BasicFilter()
{
	cv::Mat image_in, image_out;
	image_in = cv::imread("./img/kawaii.jpg");

	if (image_in.empty())
	{
		LOG("Load ERROR!");
	}

	image_out = cv::Mat(image_in.size(), image_in.type());
	image_out = image_in.clone();

	int rows = image_in.rows;
	int stepx = image_in.channels();
	int cols = (image_in.cols) * image_in.channels();

	for (int x = 1; x < (rows - 1); x++)
	{
		const uchar* previous = image_in.ptr<uchar>(x - 1);
		const uchar* current = image_in.ptr<uchar>(x);
		const uchar* next = image_in.ptr<uchar>(x + 1);
		uchar* output = image_out.ptr<uchar>(x);

		for (int y = stepx; y < (cols - stepx); y++)
		{
			output[y] = cv::saturate_cast<uchar>(5 * current[y] - (previous[y] + current[y - stepx] + current[y + stepx] + next[y]));
		}
	}

	cv::imshow("image_in", image_in);
	cv::imshow("image_out", image_out);
}

int main()
{
	cv::Mat image_in, image_out;
	image_in = cv::imread("./img/kawaii.jpg");
	if (image_in.empty())
	{
		LOG("Load ERROR!");
		return -1;
	}

	// ´´½¨¾í»ýºË(ÂË²¨Æ÷)
	cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cv::filter2D(image_in, image_out, image_in.depth(), kernel);

	cv::imshow("image_in", image_in);
	cv::imshow("image_out", image_out);

	cv::waitKey(0);

	return 0;
}