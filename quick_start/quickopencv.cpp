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

void QuickDemo::colorStyleDemo(cv::Mat& image) {
	int color_map_types[] = {
		cv::ColormapTypes::COLORMAP_AUTUMN,
		cv::ColormapTypes::COLORMAP_BONE,
		cv::ColormapTypes::COLORMAP_JET,
		cv::ColormapTypes::COLORMAP_WINTER,
		cv::ColormapTypes::COLORMAP_RAINBOW,
		cv::ColormapTypes::COLORMAP_OCEAN,
		cv::ColormapTypes::COLORMAP_SUMMER,
		cv::ColormapTypes::COLORMAP_SPRING,
		cv::ColormapTypes::COLORMAP_COOL,
		cv::ColormapTypes::COLORMAP_HSV,
		cv::ColormapTypes::COLORMAP_PINK,
		cv::ColormapTypes::COLORMAP_HOT,
		cv::ColormapTypes::COLORMAP_PARULA,
		cv::ColormapTypes::COLORMAP_MAGMA,
		cv::ColormapTypes::COLORMAP_INFERNO,
		cv::ColormapTypes::COLORMAP_PLASMA,
		cv::ColormapTypes::COLORMAP_VIRIDIS,
		cv::ColormapTypes::COLORMAP_CIVIDIS,
		cv::ColormapTypes::COLORMAP_TWILIGHT,
		cv::ColormapTypes::COLORMAP_TWILIGHT_SHIFTED,
		cv::ColormapTypes::COLORMAP_TURBO,
		cv::ColormapTypes::COLORMAP_DEEPGREEN
	};
	cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
	int c = 0;
	int index = 0;
	while (true) {
		c = cv::waitKey(500);
		if (c == 27) break;
		// α��ɫ����

		cv::applyColorMap(image, dst, color_map_types[index++ % 22]);
		cv::imshow("Image", dst);
	}
}

void QuickDemo::logicOperationDemo(cv::Mat& image) {
	cv::Mat m1 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
	cv::Mat m2 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
	cv::Mat dst = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
	// ����һ������ ���ĸ�������ʾ�߿�����0��ʾ���  С��0��ʾ���
	// LINE_4 LINE_8 ��ʾ��4�����8����������ػ��� LINE_AA��ʾ�����
	// Rect(x, y, width, heigh)
	cv::rectangle(m1, cv::Rect(100, 100, 80, 80), cv::Scalar(255, 255, 0), -1, cv::LINE_8, 0);
	cv::rectangle(m2, cv::Rect(150, 150, 80, 80), cv::Scalar(0, 255, 255), -1, cv::LINE_8, 0);
	cv::imshow("m1", m1);
	cv::imshow("m2", m2);

	// �߼�����
#if 0
	// �����
	cv::bitwise_and(m1, m2, dst);
#else
	{
		int w = m1.cols;
		int h = m1.rows;
		for (int row = 0; row < h; ++row) {
			uchar* m1_cur_row = m1.ptr<uchar>(row);
			uchar* m2_cur_row = m2.ptr<uchar>(row);
			uchar* dst_cur_row = dst.ptr<uchar>(row);
			for (int col = 0; col < w; ++col) {
				*dst_cur_row++ = *m1_cur_row++ & *m2_cur_row++;
				*dst_cur_row++ = *m1_cur_row++ & *m2_cur_row++;
				*dst_cur_row++ = *m1_cur_row++ & *m2_cur_row++;
			}
		}
	}
#endif
	cv::imshow("������", dst);

#if 0
	// �����
	cv::bitwise_or(m1, m2, dst);
#else
	{
		int w = m1.cols;
		int h = m1.rows;
		for (int row = 0; row < h; ++row) {
			uchar* m1_cur_row = m1.ptr<uchar>(row);
			uchar* m2_cur_row = m2.ptr<uchar>(row);
			uchar* dst_cur_row = dst.ptr<uchar>(row);
			for (int col = 0; col < w; ++col) {
				*dst_cur_row++ = *m1_cur_row++ | *m2_cur_row++;
				*dst_cur_row++ = *m1_cur_row++ | *m2_cur_row++;
				*dst_cur_row++ = *m1_cur_row++ | *m2_cur_row++;
			}
	}
}
#endif
	cv::imshow("������", dst);

#if 0
	// ������
	cv::bitwise_xor(m1, m2, dst);
#else
	{
		int w = m1.cols;
		int h = m1.rows;
		for (int row = 0; row < h; ++row) {
			uchar* m1_cur_row = m1.ptr<uchar>(row);
			uchar* m2_cur_row = m2.ptr<uchar>(row);
			uchar* dst_cur_row = dst.ptr<uchar>(row);
			for (int col = 0; col < w; ++col) {
				*dst_cur_row++ = *m1_cur_row++ ^ *m2_cur_row++;
				*dst_cur_row++ = *m1_cur_row++ ^ *m2_cur_row++;
				*dst_cur_row++ = *m1_cur_row++ ^ *m2_cur_row++;
			}
		}
	}
#endif
	cv::imshow("�������", dst);

#if 0
	// ȡ������
	cv::bitwise_not(m1, dst);
#else
	{
		int w = m1.cols;
		int h = m1.rows;
		for (int row = 0; row < h; ++row) {
			uchar* m1_cur_row = m1.ptr<uchar>(row);
			uchar* dst_cur_row = dst.ptr<uchar>(row);
			for (int col = 0; col < w; ++col) {
				*dst_cur_row++ = 255 - *m1_cur_row++;
				*dst_cur_row++ = 255 - *m1_cur_row++;
				*dst_cur_row++ = 255 - *m1_cur_row++;
			}
		}
	}
#endif
	cv::imshow("ȡ������", dst);
}

void QuickDemo::channelsSplitAndMergeDemo(cv::Mat& image) {
	std::vector<cv::Mat> mv;
	// ��ɫ����
	cv::split(image, mv);
	cv::imshow("blue_gray", mv[0]);
	cv::imshow("green_gray", mv[1]);
	cv::imshow("red_gray", mv[2]);

	// ��ɫ�ϲ�
	cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
	mv[0] = 0;
	mv[1] = 0;
	cv::merge(mv, dst);
	cv::imshow("red_image", dst);

	// ����ͨ��  ʵ�ָ���ͨ�������
	// ��ʾ��һ��ͨ���͵�����ͨ������
	int from_to[] = { 0, 2, 1, 1, 2, 0 };
	// ��2 4��������ʾinput output�������� 6��ʾͨ��������
	cv::mixChannels(&image, 1, &dst, 1, from_to, 3);
	cv::imshow("mix_image", dst);
}

void QuickDemo::inrangeDemo(cv::Mat& image) {
	cv::Mat hsv;
	cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
	cv::Mat mask;
	// ����������ֵ�ڵ�����ֵ����Ϊ��ɫ��255������������ֵ�����ڵ�����ֵ����Ϊ��ɫ��0��
	// hsv-->input Scalar-->min/max  mask-->output
	// �˴�Ҫ��ȥ����ɫ-->�ο�important�µ�hsvȡֵ��Χ
	cv::inRange(hsv, cv::Scalar(100, 43, 46), cv::Scalar(124, 255, 255), mask);

	cv::Mat redback = cv::Mat::zeros(image.size(), image.type());
	redback = cv::Scalar(40, 40, 200);

	cv::bitwise_not(mask, mask);
	// mask��Ϊ��Ĥ�壬 ֻ��mask�ϵ�ĳһ�����ص�Ϊ1��ʱ��Ž�image�����ؿ�����redback���棬������redbackԭ����ֵ
	image.copyTo(redback, mask);
	cv::imshow("roi������ȡ", redback);
}

void QuickDemo::pixelStatisticDemo(cv::Mat& image) {
	double min, max;
	cv::Point min_loc, max_loc;
	std::vector<cv::Mat> mv;
	cv::split(image, mv);
	// �������ֻ֧�ֵ�ͨ����ͼ
	for (int dims = 0; dims < image.channels(); ++dims) {
		// ��ȡ������ֵ����ֵ��λ��
		cv::minMaxLoc(mv[dims], &min, &max, &min_loc, &max_loc, cv::Mat());
		std::cout << "min value:" << min << "\tmax value:" << max << "\tmin location:" 
				  << min_loc << "\tmax location:" << max_loc << std::endl;
	}
	// ��ȡͼ��ľ�ֵ�ͷ��� ÿ��ͨ���Ķ����Դ�ӡ����
	// ��ֵ�Ƕ����������ȵ�һ������������������Ӧͼ��������̶�
	// ����������ݵķ�ɢ�̶�-->���Աȶ�
	cv::Mat mean, stddev;
	cv::meanStdDev(image, mean, stddev);
	for (int dims = 0; dims < image.channels(); ++dims) {
		std::cout << "No.channels:" << dims << "mean" << dims << ":" << mean.at<double>(dims) << std::endl;
		std::cout << "No.channels:" << dims << "stddev" << dims << ":" << stddev.at<double>(dims) << std::endl;
	}
}

void QuickDemo::drawingDemo(cv::Mat& image) {
	cv::Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.width = 100;
	rect.height = 100;
	cv::Mat bg = cv::Mat::zeros(image.size(), image.type());
	cv::rectangle(bg, rect, cv::Scalar(0, 0, 200), 1, cv::LINE_4);
	cv::circle(bg, cv::Point(150, 150), 50, cv::Scalar(0, 200, 0), -1, cv::LINE_4);
	cv::line(bg, cv::Point(100, 400), cv::Point(400, 400), cv::Scalar(255, 255, 0), 2, cv::LINE_4);
	cv::RotatedRect rrt;
	// ��Բ����
	rrt.center = cv::Point(100, 300);
	// a b��
	rrt.size = cv::Size(100, 200);
	rrt.angle = 90.0;
	cv::ellipse(bg, rrt, cv::Scalar(0, 255, 255), 2, cv::LINE_4);
	cv::Mat dst;
	cv::addWeighted(image, 0.7, bg, 0.3, 0, dst);
	cv::imshow("Image", dst);

}

void QuickDemo::randomDrawingDemo(cv::Mat& image) {
	cv::Mat bg = cv::Mat::zeros(image.size(), image.type());
	cv::RNG rng(time(0));
	int w = image.cols;
	int h = image.rows;
	while (true) {
		if (cv::waitKey(50) == 27)	break;
		bg = cv::Scalar(0, 0, 0);
		int x1 = rng.uniform(0, w);
		int y1 = rng.uniform(0, h);
		int x2 = rng.uniform(0, w);
		int y2 = rng.uniform(0, h);
		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);
		cv::line(bg, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(b, g, r), 1, cv::LINE_AA);
		cv::imshow("Image", bg);
	}
}

void QuickDemo::drawingPolylinesDemo(cv::Mat& image) {
	cv::Mat bg = cv::Mat::zeros(cv::Size(512, 512), image.type());
	cv::Point p1(200, 100);
	cv::Point p2(50, 200);
	cv::Point p3(150, 400);
	cv::Point p4(250, 400);
	cv::Point p5(350, 200);
	std::vector<cv::Point> pts;
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
	// ���ƶ���� ������������������
	cv::polylines(bg, pts, true, cv::Scalar(22, 33, 44), 2, cv::LINE_AA);
	// ��� ��һ
	// cv::fillPoly(bg, pts, cv::Scalar(255, 255, 32), cv::LINE_AA);
	// ����
	std::vector<std::vector<cv::Point>> contours;
	contours.push_back(pts);
	cv::drawContours(bg, contours, -1, cv::Scalar(0, 255, 255), -1);
	cv::imshow("Image", bg);
}

cv::Point start_p(-1, -1);
cv::Point end_p(-1, -1);
cv::Mat temp;
static void onDraw(int event, int x, int y, int flags, void* userdata) {
	cv::Mat image = *(cv::Mat*)userdata;
	if (event == cv::EVENT_LBUTTONDOWN) {
		start_p.x = x;
		start_p.y = y;
	}
	else if (event == cv::EVENT_LBUTTONUP) {
		end_p.x = x;
		end_p.y = y;
		int dx = x - start_p.x;
		int dy = y - start_p.y;
		cv::Rect rect(start_p.x, start_p.y, dx, dy);
		if (dx > 0 && x < image.cols && dy > 0 && y < image.rows) {
			cv::rectangle(image, rect, cv::Scalar(255, 255, 0), 2, cv::LINE_AA);
			temp.copyTo(image);
			cv::destroyWindow("ROI����"); // ���ٴ���  ���֮ǰ������
			cv::imshow("ROI����", image(rect));
		}
		// ��������
		start_p.x = -1;
		start_p.y = -1;
		cv::imshow("Image", image);
	}
	else if (event == cv::EVENT_MOUSEMOVE) {
		if (start_p.x > 0 && start_p.y > 0) {
			end_p.x = x;
			end_p.y = y;
			int dx = x - start_p.x;
			int dy = y - start_p.y;
			if (dx > 0 && dy > 0) {
				temp.copyTo(image);
				cv::rectangle(image, cv::Rect(start_p.x, start_p.y, dx, dy), cv::Scalar(255, 255, 0), 2, cv::LINE_AA);
			}
			cv::imshow("Image", image);
		}
	}
}

void QuickDemo::mouseDrawingDemo(cv::Mat& image) {
	cv::setMouseCallback("Image", onDraw, (void*)&image);
	temp = image.clone();
}

