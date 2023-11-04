#ifndef QUICKOPENCV_H
#define QUICKOPENCV_H
#include <opencv2//opencv.hpp>
#include <iostream>

class QuickDemo {
public:
	void colorSpaceDemo(cv::Mat& image);	// 色彩空间
	void matCreationDemo(cv::Mat& image);	// Mat使用
	void pixelVisitDemo(cv::Mat& image);	// 像素遍历
	void arithmetiralOperationDemo(cv::Mat& image); // 算术操作
	void trackbarDemo(cv::Mat& image);		// 拖动条-->亮度调节
	void keyDemo(cv::Mat& image);	// 键盘事件
};
#endif // QUICKOPENCV_H
