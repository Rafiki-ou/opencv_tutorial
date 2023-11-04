#include <opencv2/highgui.hpp>
#include <iostream>

int main(int argc, char** argv) 
{
	// 第二个参数指定以什么色彩读入计算数据
	cv::Mat img = cv::imread("E:/image/lena.jpg", cv::IMREAD_COLOR);
	if (img.empty()) {
		std::cout << "不能打开文件";
		return -1;
	}
	// 命名一个窗口，同时指定一个窗口的控制行为，默认是WINDOW_AUTOSIZE适应图片大小且不能修改
	cv::namedWindow("Window", WINDOW_NORMAL);
	// 第一个参数表示窗口名称 第二个参数是指定输入图像
	cv::imshow("Window", img);
	// 指定延时显示时间
	cv::waitKey(0);
	// 销毁所有的窗口
	cv::destroyAllWindows();
	return 0;
}