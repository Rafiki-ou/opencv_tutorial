#include "quickopencv.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::string path = "E:/opencv/image/-36.jpg";
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

	// inrangeDemoʹ�õ�ͼƬΪE:/opencv/image/2.png
	// quick.inrangeDemo(img);
	// quick.pixelStatisticDemo(img);
	// quick.drawingDemo(img);
	// quick.randomDrawingDemo(img);
	// quick.drawingPolylinesDemo(img);
	// quick.mouseDrawingDemo(img);
	// quick.normalizeDemo(img);
	// quick.resizeDemo(img);
	// quick.flipDemo(img);
	// quick.warpAffineDemo(img);
	// quick.videoDemo(img);
	// quick.videoDemo(img);
	// -36.jpg
	// quick.histogramDemo(img);
	quick.histogram2DDemo(img);
	cv::waitKey(0);
	return 0;
}