#ifndef QUICKOPENCV_H
#define QUICKOPENCV_H
#include <opencv2//opencv.hpp>
#include <iostream>

class QuickDemo {
public:
	void colorSpaceDemo(cv::Mat& image);	// ɫ�ʿռ�
	void matCreationDemo(cv::Mat& image);	// Matʹ��
	void pixelVisitDemo(cv::Mat& image);	// ���ر���
	void arithmetiralOperationDemo(cv::Mat& image); // ��������
	void trackbarDemo(cv::Mat& image);		// �϶���-->���ȵ���
	void keyDemo(cv::Mat& image);	// �����¼�
};
#endif // QUICKOPENCV_H
