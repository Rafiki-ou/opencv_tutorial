#include "quickopencv.h"
void QuickDemo::colorSpaceDemo(cv::Mat& image) {
	cv::Mat img_gray, img_hsv;
	cv::cvtColor(image, img_gray, cv::COLOR_BGR2GRAY);
	// 
	cv::cvtColor(image, img_hsv, cv::COLOR_BGR2HSV);
	cv::namedWindow("img_gray", cv::WINDOW_GUI_EXPANDED);
	cv::namedWindow("img_hsv", cv::WINDOW_GUI_EXPANDED);
	// imshowֻ֧��8λ�򸡵�����ͼ����ʾ
	cv::imshow("img_gray", img_gray);
	cv::imshow("img_hsv", img_hsv);
	// cv::imwrite(path, img);
}

void QuickDemo::matCreationDemo(cv::Mat& image) {
	// ��copy
	cv::Mat m1, m2;
	m1 = image.clone();
	image.copyTo(m2);

	// ǳcooy
	cv::Mat m3 = image;
	
	/** �����հ�ͼ��  
	8λ�޷����ַ��͵�ͨ��CV_8UC1:
		[  0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0]

	8λ�޷�����3ͨ��CV_8UC3: -->ÿ3��Ϊһ������ֵ
		[  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0]
	 */
	cv::Mat m4 = cv::Mat::zeros(cv::Size(8, 8), CV_8UC3);
	std::cout << "width:" << m4.cols << "\theight:" << m4.rows << "\tchannels:" << m4.channels() << std::endl;

	// ones�����������Mat��ʱ����CV_8UC3��ʱ��ֻ���ÿ�����صĵ�һ��ͨ����ʼ��Ϊ1����ȫΪ0  ��CV_8C1ʱȫΪ1
	/**
		[  1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0;
		   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0;
		   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0;
		   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0;
		   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0;
		   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0;
		   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0;
		   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0,   1,   0,   0]
	 */
	cv::Mat m5 = cv::Mat::ones(cv::Size(8, 8), CV_8UC3);
	// ���������� ʹ��һ��������Mat��ֵ��ʱ��Ὣ��һ��ͨ����ֵ
	m5 = 127;
	// Ҫ���3��ͨ��ֵֵ����Ҫ�õ�����һ�����ݽṹ
	m5 = cv::Scalar(127, 127, 127);
}

void QuickDemo::pixelVisitDemo(cv::Mat& image) {
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();
#if 0
	// ��Ϊһ����� �����ȱ�����
	for (int row = 0; row < h; ++row) {
		for (int col = 0; col < w; ++col) {
			if (dims == 1) { // ��ͨ��-->�Ҷ�ͼ��
				int pixel_val = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pixel_val;
			}
			if (dims == 3) { // 3ͨ��-->��ɫͼ��
				cv::Vec3b bgr = image.at<cv::Vec3b>(row, col);
				image.at<cv::Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<cv::Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<cv::Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
#else
	for (int row = 0; row < h; ++row) {
		uchar* cur_row = image.ptr<uchar>(row);// ��ȡ����ǰ�е���ָ���ַ
		for (int col = 0; col < w; ++col) {
			if (dims == 1) { // ��ͨ��-->�Ҷ�ͼ��
				int pv = *cur_row;
				*cur_row++ = 255 - pv;
			}
			if (dims == 3) { // 3ͨ��-->��ɫͼ��
				*cur_row++ = 255 - *cur_row;
				*cur_row++ = 255 - *cur_row;
				*cur_row++ = 255 - *cur_row;
			}
		}
	}
#endif
	cv::imshow("image", image);
}

void QuickDemo::arithmetiralOperationDemo(cv::Mat& image) {
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();
	cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
	cv::Mat aux = cv::Mat::zeros(image.size(), image.type());
	// Scalar��һ������
	aux = cv::Scalar(-50, -50, -50);
	for (int row = 0; row < h; ++row) {
		for (int col = 0; col < w; ++col) {
			// 3ͨ��-->��ɫͼ��
			cv::Vec3b bgr1 = image.at<cv::Vec3b>(row, col);
			cv::Vec3b bgr2 = aux.at<cv::Vec3b>(row, col);
			// saturate_cast�������Խ�����һ��ֵ�ķ�Χ��飬�������255����255 С��0����0 �Ա�������������
			dst.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(bgr1[0] + bgr2[0]);
			dst.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(bgr1[1] + bgr2[1]);
			dst.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(bgr1[2] + bgr2[2]);
		}
	}
	/**
	 * opencv�����Դ��ļ�������
	 * �ӷ�-->add
	 * ����-->subtract
	 * �˷�-->multiply
	 * ����-->divide
	 * @TODO ��Ȼ��������Լ���ʵ��һ��
	 */
	cv::imshow("dst", dst);
}

static void trackbarCallback(int pos, void* userdata) {
	auto params = static_cast<std::pair<cv::Mat, int>*>(userdata);
	cv::Mat image = params->first;
	int lightness = params->second;
	cv::Mat dst, aux;
	dst = cv::Mat::zeros(image.size(), image.type());
	aux = cv::Mat::zeros(image.size(), image.type());
	aux = cv::Scalar(lightness, lightness, lightness);
	cv::add(image, aux, dst);
	cv::imshow("������Աȶȵ���", dst);
}

static void trackbarCallbackOnWeighted(int pos, void* userdata) {
	cv::Mat image = *(cv::Mat*)userdata;
	cv::Mat dst, aux;
	dst = cv::Mat::zeros(image.size(), image.type());
	aux = cv::Mat::zeros(image.size(), image.type());
	aux = cv::Scalar(pos, pos, pos);
	cv::addWeighted(image, pos / 200.0, aux, 0.0, 0, dst);
	cv::imshow("������Աȶȵ���", dst);
}

void QuickDemo::trackbarDemo(cv::Mat& image) {
	cv::namedWindow("������Աȶȵ���", cv::WINDOW_GUI_EXPANDED);
	int max_value = 100;
	int lightness = 50;
	int contrast_value = 100;
	// �����params����Ϊ�ֲ����� �������������������ᵼ�¿�ָ���쳣
	static std::pair<cv::Mat, int> params = std::make_pair(image, lightness);
	// ��ʵ�ص��������յĵ�һ������Ĭ�Ͼ���trackbar��ǰ��ֵ������Ҫ�ֶ�����ģ�������ʵҲ���Բ��ö������params������ֱ�Ӵ����6������(void*)&image
	cv::createTrackbar("lightnessBar", "������Աȶȵ���", &params.second, max_value, trackbarCallback, (void*)&params);
	// �Աȶȵ��� ����Խ�� ����Խ��
	cv::createTrackbar("contrastBar", "������Աȶȵ���", &contrast_value, max_value * 2, trackbarCallbackOnWeighted, (void*)&image);
	trackbarCallback(50, (void*)&params);
}

void QuickDemo::keyDemo(cv::Mat& image) {
	cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
	int c = 0;
	while (true) {
		c = cv::waitKey(100);
		// ���صļ�����ASCIIֵ��Ӧ���ַ�
		switch (c)
		{
		case 27: // Esc==>27
			break;
		case 49: // 1
			std::cout << "you enter key #1" << std::endl;
			cv::cvtColor(image, dst, cv::COLOR_BGR2GRAY);
			break;
		case 50: // 2
			std::cout << "you enter key #2" << std::endl;
			cv::cvtColor(image, dst, cv::COLOR_BGR2HSV);
			break;
		case 51: // 3
			std::cout << "you enter key #3" << std::endl;
			dst = cv::Scalar(50, 50, 50);
			cv::add(image, dst, dst);
			break;
		}
		if (c != -1)
			cv::imshow("Image", dst);
	}
}