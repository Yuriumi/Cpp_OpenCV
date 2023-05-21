#include "OnMouse.h"

#define LOG(x) std::cout << x << '\n'

void onMouse(int event, int x, int y, int flags, void* param)
{
	cv::Mat* im = reinterpret_cast<cv::Mat*>(param);

	switch (event)
	{
	// 鼠标左键按下
	case cv::EVENT_LBUTTONDOWN:
		if (static_cast<int>(im->channels()) == 1)	// 单通道图像,灰度图
		{
			switch (im->type())
			{
			case 0:
				LOG("at (" << x << ',' << y << ") Value is: " << static_cast<int>(im->at<uchar>(cv::Point(x, y))));
				break;
			case 1:
				LOG("at (" << x << ',' << y << ") Value is: " << static_cast<int>(im->at<char>(cv::Point(x, y))));
				break;
			case 2:
				LOG("at (" << x << ',' << y << ") Value is: " << static_cast<int>(im->at<ushort>(cv::Point(x, y))));
				break;
			case 3:
				LOG("at (" << x << ',' << y << ") Value is: " << static_cast<int>(im->at<short>(cv::Point(x, y))));
				break;
			case 4:
				LOG("at (" << x << ',' << y << ") Value is: " << static_cast<int>(im->at<int>(cv::Point(x, y))));
				break;
			case 5:
				LOG("at (" << x << ',' << y << ") Value is: " << static_cast<float>(im->at<float>(cv::Point(x, y))));
				break;
			case 6:
				LOG("at (" << x << ',' << y << ") Value is: " << static_cast<float>(im->at<double>(cv::Point(x, y))));
				break;
			}
		}
		else    // 图像为BGR图,显示鼠标点击坐标以及对应的BGR值
		{
			LOG("at (" << x << ", " << y << ")"
				<< " B value is: " << static_cast<int>(im->at<cv::Vec3b>(cv::Point(x, y))[0])
				<< " G value is: " << static_cast<int>(im->at<cv::Vec3b>(cv::Point(x, y))[1])
				<< " R value is: " << static_cast<int>(im->at<cv::Vec3b>(cv::Point(x, y))[2])
				);
		}
		break;
	}
}
