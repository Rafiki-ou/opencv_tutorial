#include "quickopencv.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::string path = "E:/opencv/image/2.png";
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
	// quick.keyDemo(img);
	// quick.colorStyleDemo(img);
	// quick.logicOperationDemo(img);
	// quick.channelsSplitAndMergeDemo(img);

	// inrangeDemo使用的图片为E:/opencv/image/2.png
	// quick.inrangeDemo(img);
	// quick.pixelStatisticDemo(img);
	// quick.drawingDemo(img);
	// quick.randomDrawingDemo(img);
	// quick.drawingPolylinesDemo(img);
	quick.mouseDrawingDemo(img);
	cv::waitKey(0);
	return 0;
}