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
	void colorStyleDemo(cv::Mat& image); // ��ɫ��-->α��ɫ����
	void logicOperationDemo(cv::Mat& image); // �߼�����-->api-->�Լ�ʵ��
	void channelsSplitAndMergeDemo(cv::Mat& image); // ͨ��������ϲ�
	void inrangeDemo(cv::Mat& image);	// ROI������ȡ
	void pixelStatisticDemo(cv::Mat& image);	// ����ͳ��
	void drawingDemo(cv::Mat& image);	// ���Ƽ���ͼ��
	void randomDrawingDemo(cv::Mat& image); // �������
	void drawingPolylinesDemo(cv::Mat& image); // ���ƶ����
	void mouseDrawingDemo(cv::Mat& image);
};
#endif // QUICKOPENCV_H
