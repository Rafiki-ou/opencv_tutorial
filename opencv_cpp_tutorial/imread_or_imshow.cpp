#include <opencv2/highgui.hpp>
#include <iostream>

int main(int argc, char** argv) 
{
	// �ڶ�������ָ����ʲôɫ�ʶ����������
	cv::Mat img = cv::imread("E:/image/lena.jpg", cv::IMREAD_COLOR);
	if (img.empty()) {
		std::cout << "���ܴ��ļ�";
		return -1;
	}
	// ����һ�����ڣ�ͬʱָ��һ�����ڵĿ�����Ϊ��Ĭ����WINDOW_AUTOSIZE��ӦͼƬ��С�Ҳ����޸�
	cv::namedWindow("Window", WINDOW_NORMAL);
	// ��һ��������ʾ�������� �ڶ���������ָ������ͼ��
	cv::imshow("Window", img);
	// ָ����ʱ��ʾʱ��
	cv::waitKey(0);
	// �������еĴ���
	cv::destroyAllWindows();
	return 0;
}