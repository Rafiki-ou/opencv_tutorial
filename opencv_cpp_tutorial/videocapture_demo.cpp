#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main(int argc, char** argv)
{
#if 0
	// ��Ƶ�������  ���������ʾ��ʹ����һ������ͷ
	cv::VideoCapture cap(0);
	//cap.open(0);
	cv::Mat img;
	while (true) {
		cap.read(img);
		cv::imshow("Image", img);
		cv::waitKey(1);
	}

#else
	std::string path = "Resources/test_video.mp4";
	cv::VideoCapture cap(path);
	cv::Mat img;
	while (true) {
		cap.read(img);
		if (img.empty())
			break;
		cv::imshow("image", img);
		cv::waitKey(1);
	}
#endif
	return 0;
}

