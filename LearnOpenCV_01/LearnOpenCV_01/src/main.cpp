#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img = cv::imread("./img/test.jpg");

	cv::imshow("img", img);

	cv::waitKey();

	return 0;
}