#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char** argv)
{
	std::string path = "Resources/test.png";
	cv::Mat img = cv::imread(path);

	cv::Mat img_gray, img_blur, img_canny;
	// 颜色转换
	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
	// 高斯模糊
	cv::GaussianBlur(img_gray, img_blur, cv::Size(3, 3), 3, 0);
	// 边缘检测
	cv::Canny(img_blur, img_canny, 25, 75);

	cv::imshow("img", img);
	cv::imshow("img_gray", img_gray);
	cv::imshow("img_blur", img_blur);
	cv::imshow("img_canny", img_canny);
	cv::waitKey(0);
	return 0;
}

