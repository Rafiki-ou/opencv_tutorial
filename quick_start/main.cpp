#include "quickopencv.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::string path = "E:/image/lena.jpg";
	cv::Mat img = cv::imread(path);
	cv::namedWindow("Image", cv::WINDOW_GUI_EXPANDED);
	if (img.empty()) {
		std::cout << "not found!";
		return -1;
	}
	cv::imshow("Image", img);
	QuickDemo quick;
	// quick.colorSpaceDemo(img);
	// quick.matCreationDemo(img);
	// quick.pixelVisitDemo(img);
	// quick.arithmetiralOperationDemo(img);
	// quick.trackbarDemo(img);
	quick.keyDemo(img);
	cv::waitKey(0);
	return 0;
}