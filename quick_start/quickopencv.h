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
	void colorStyleDemo(cv::Mat& image); // 颜色表-->伪彩色函数
	void logicOperationDemo(cv::Mat& image); // 逻辑操作-->api-->自己实现
	void channelsSplitAndMergeDemo(cv::Mat& image); // 通道分离与合并
	void inrangeDemo(cv::Mat& image);	// ROI区域提取
	void pixelStatisticDemo(cv::Mat& image);	// 像素统计
	void drawingDemo(cv::Mat& image);	// 绘制几何图形
	void randomDrawingDemo(cv::Mat& image); // 随机绘制
	void drawingPolylinesDemo(cv::Mat& image); // 绘制多边形
	void mouseDrawingDemo(cv::Mat& image);
};
#endif // QUICKOPENCV_H
