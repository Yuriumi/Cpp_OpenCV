#include "../ref/OnMouse.h"
#include <iostream>

#include "../ref/Salt.h"

#define LOG(x) std::cout << x << '\n'

void GrayTransform()
{
	cv::Mat image_in, image_out, image_gray;
	image_in = cv::imread("./img/kawaii.jpg");

	if (image_in.empty())
	{
		LOG("Load Image Error!");
	}

	cv::cvtColor(image_in, image_gray, cv::COLOR_BGR2GRAY);
	cv::imshow("image_gray", image_gray);

	image_out = image_gray.clone();

	for (int i = 0; i < image_gray.rows; i++)
	{
		for (int j = 0; j < image_gray.cols; j++)
			image_out.at<uchar>(i, j) = 255 - image_gray.at<uchar>(i, j);
	}

	cv::imshow("image_out", image_out);
}

void LogarithmTransform()
{
	cv::Mat image_in, image_out, image_gray;
	image_in = cv::imread("./img/kawaii.jpg");

	if (image_in.empty())
	{
		LOG("Load Image Error!");
	}

	cv::cvtColor(image_in, image_gray, cv::COLOR_BGR2GRAY);
	cv::imshow("image_gray", image_gray);

	image_out = image_gray.clone();

	for (int i = 0; i < image_gray.rows; i++)
	{
		for (int j = 0; j < image_gray.cols; j++)
			image_out.at<uchar>(i, j) = 6 * log((double)(image_gray.at<uchar>(i, j)) + 1);
	}

	cv::normalize(image_out, image_out, 0, 255, cv::NORM_MINMAX);	// 图像归一化,转换到0 ~ 255
	cv::convertScaleAbs(image_out, image_out);
	cv::imshow("image_out", image_out);
}

int main()
{
	// Gamma Transform
	cv::Mat image_in, image_out, image_gray;
	image_in = cv::imread("./img/kawaii.jpg");

	if (image_in.empty())
	{
		LOG("Load Image Error!");
		return -1;
	}

	cv::cvtColor(image_in, image_gray, cv::COLOR_BGR2GRAY);
	cv::imshow("image_gray", image_gray);

	image_out = image_gray.clone();

	for (int i = 0; i < image_gray.rows; i++)
	{
		for (int j = 0; j < image_gray.cols; j++)
			image_out.at<uchar>(i, j) = 6 * pow((double)image_gray.at<uchar>(i, j), 1);
	}

	cv::normalize(image_out, image_out, 0, 255, cv::NORM_MINMAX);
	cv::convertScaleAbs(image_out, image_out);
	cv::imshow("image_out", image_out);

	cv::waitKey(0);

	return 0;
}