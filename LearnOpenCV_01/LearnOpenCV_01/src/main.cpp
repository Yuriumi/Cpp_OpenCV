#include "../ref/OnMouse.h"
#include <iostream>

#define LOG(x) std::cout << x << '\n'

int main()
{
	cv::Mat image = cv::imread("./img/kawaii.jpg");

	if (image.empty())
	{
		LOG("Read Image file Failed!");
		return -1;
	}

	cv::imshow("Kawaii", image);

	cv::setMouseCallback("Kawaii", onMouse, reinterpret_cast<void*>(&image));

	cv::waitKey(0);

	return 0;
}