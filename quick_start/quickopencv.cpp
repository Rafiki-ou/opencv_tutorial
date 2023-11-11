#include "quickopencv.h"
void QuickDemo::colorSpaceDemo(cv::Mat& image) {
	cv::Mat img_gray, img_hsv;
	cv::cvtColor(image, img_gray, cv::COLOR_BGR2GRAY);
	// 
	cv::cvtColor(image, img_hsv, cv::COLOR_BGR2HSV);
	cv::namedWindow("img_gray", cv::WINDOW_GUI_EXPANDED);
	cv::namedWindow("img_hsv", cv::WINDOW_GUI_EXPANDED);
	// imshow只支持8位或浮点数的图像显示
	cv::imshow("img_gray", img_gray);
	cv::imshow("img_hsv", img_hsv);
	// cv::imwrite(path, img);
}

void QuickDemo::matCreationDemo(cv::Mat& image) {
	// 深copy
	cv::Mat m1, m2;
	m1 = image.clone();
	image.copyTo(m2);

	// 浅cooy
	cv::Mat m3 = image;
	
	/** 创建空白图像  
	8位无符号字符型单通道CV_8UC1:
		[  0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0;
		   0,   0,   0,   0,   0,   0,   0,   0]

	8位无符号型3通道CV_8UC3: -->每3列为一个像素值
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

	// ones这个函数创建Mat的时候在CV_8UC3的时候只会把每个像素的第一个通道初始化为1其他全为0  而CV_8C1时全为1
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
	// 操作符重载 使用一个整数对Mat赋值的时候会将第一个通道赋值
	m5 = 127;
	// 要想对3个通道值值，需要用到另外一个数据结构
	m5 = cv::Scalar(127, 127, 127);
}

void QuickDemo::pixelVisitDemo(cv::Mat& image) {
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();
#if 0
	// 因为一层层来 所以先遍历行
	for (int row = 0; row < h; ++row) {
		for (int col = 0; col < w; ++col) {
			if (dims == 1) { // 单通道-->灰度图像
				int pixel_val = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pixel_val;
			}
			if (dims == 3) { // 3通道-->彩色图像
				cv::Vec3b bgr = image.at<cv::Vec3b>(row, col);
				image.at<cv::Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<cv::Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<cv::Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}
#else
	for (int row = 0; row < h; ++row) {
		uchar* cur_row = image.ptr<uchar>(row);// 获取到当前行的首指针地址
		for (int col = 0; col < w; ++col) {
			if (dims == 1) { // 单通道-->灰度图像
				int pv = *cur_row;
				*cur_row++ = 255 - pv;
			}
			if (dims == 3) { // 3通道-->彩色图像
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
	// Scalar是一个标量
	aux = cv::Scalar(-50, -50, -50);
	for (int row = 0; row < h; ++row) {
		for (int col = 0; col < w; ++col) {
			// 3通道-->彩色图像
			cv::Vec3b bgr1 = image.at<cv::Vec3b>(row, col);
			cv::Vec3b bgr2 = aux.at<cv::Vec3b>(row, col);
			// saturate_cast函数可以将会做一个值的范围检查，如果大于255当做255 小于0则当做0 以避免造成数据溢出
			dst.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(bgr1[0] + bgr2[0]);
			dst.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(bgr1[1] + bgr2[1]);
			dst.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(bgr1[2] + bgr2[2]);
		}
	}
	/**
	 * opencv都有自带的几个函数
	 * 加法-->add
	 * 减法-->subtract
	 * 乘法-->multiply
	 * 除法-->divide
	 * @TODO 当然后面最好自己都实现一下
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
	cv::imshow("亮度与对比度调节", dst);
}

static void trackbarCallbackOnWeighted(int pos, void* userdata) {
	cv::Mat image = *(cv::Mat*)userdata;
	cv::Mat dst, aux;
	dst = cv::Mat::zeros(image.size(), image.type());
	aux = cv::Mat::zeros(image.size(), image.type());
	aux = cv::Scalar(pos, pos, pos);
	cv::addWeighted(image, pos / 200.0, aux, 0.0, 0, dst);
	cv::imshow("亮度与对比度调节", dst);
}

void QuickDemo::trackbarDemo(cv::Mat& image) {
	cv::namedWindow("亮度与对比度调节", cv::WINDOW_GUI_EXPANDED);
	int max_value = 100;
	int lightness = 50;
	int contrast_value = 100;
	// 这里的params不能为局部变量 否则变量生命周期问题会导致空指针异常
	static std::pair<cv::Mat, int> params = std::make_pair(image, lightness);
	// 其实回调函数接收的第一个参数默认就是trackbar当前的值，不需要手动传入的，所以其实也可以不用定义这个params，而是直接传入第6个参数(void*)&image
	cv::createTrackbar("lightnessBar", "亮度与对比度调节", &params.second, max_value, trackbarCallback, (void*)&params);
	// 对比度调整 亮的越亮 暗的越暗
	cv::createTrackbar("contrastBar", "亮度与对比度调节", &contrast_value, max_value * 2, trackbarCallbackOnWeighted, (void*)&image);
	trackbarCallback(50, (void*)&params);
}

void QuickDemo::keyDemo(cv::Mat& image) {
	cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
	int c = 0;
	while (true) {
		c = cv::waitKey(100);
		// 返回的键就是ASCII值对应的字符
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
		// 伪彩色函数

		cv::applyColorMap(image, dst, color_map_types[index++ % 22]);
		cv::imshow("Image", dst);
	}
}

void QuickDemo::logicOperationDemo(cv::Mat& image) {
	cv::Mat m1 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
	cv::Mat m2 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
	cv::Mat dst = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
	// 绘制一个矩形 第四个参数表示线宽，大于0表示描边  小于0表示填充
	// LINE_4 LINE_8 表示以4领域或8领域进行像素绘制 LINE_AA表示反锯齿
	// Rect(x, y, width, heigh)
	cv::rectangle(m1, cv::Rect(100, 100, 80, 80), cv::Scalar(255, 255, 0), -1, cv::LINE_8, 0);
	cv::rectangle(m2, cv::Rect(150, 150, 80, 80), cv::Scalar(0, 255, 255), -1, cv::LINE_8, 0);
	cv::imshow("m1", m1);
	cv::imshow("m2", m2);

	// 逻辑操作
#if 0
	// 与操作
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
	cv::imshow("与运算", dst);

#if 0
	// 或操作
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
	cv::imshow("或运算", dst);

#if 0
	// 异或操作
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
	cv::imshow("异或运算", dst);

#if 0
	// 取反操作
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
	cv::imshow("取反运算", dst);
}

void QuickDemo::channelsSplitAndMergeDemo(cv::Mat& image) {
	std::vector<cv::Mat> mv;
	// 颜色分离
	cv::split(image, mv);
	cv::imshow("blue_gray", mv[0]);
	cv::imshow("green_gray", mv[1]);
	cv::imshow("red_gray", mv[2]);

	// 颜色合并
	cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
	mv[0] = 0;
	mv[1] = 0;
	cv::merge(mv, dst);
	cv::imshow("red_image", dst);

	// 交换通道  实现复杂通道的组合
	// 表示第一个通道和第三个通道交换
	int from_to[] = { 0, 2, 1, 1, 2, 0 };
	// 第2 4个参数表示input output矩阵数量 6表示通道的数量
	cv::mixChannels(&image, 1, &dst, 1, from_to, 3);
	cv::imshow("mix_image", dst);
}

void QuickDemo::inrangeDemo(cv::Mat& image) {
	cv::Mat hsv;
	cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
	cv::Mat mask;
	// 将在两个阈值内的像素值设置为白色（255），而不在阈值区间内的像素值设置为黑色（0）
	// hsv-->input Scalar-->min/max  mask-->output
	// 此处要求去除蓝色-->参考important下的hsv取值范围
	cv::inRange(hsv, cv::Scalar(100, 43, 46), cv::Scalar(124, 255, 255), mask);

	cv::Mat redback = cv::Mat::zeros(image.size(), image.type());
	redback = cv::Scalar(40, 40, 200);

	cv::bitwise_not(mask, mask);
	// mask作为掩膜板， 只有mask上的某一个像素点为1的时候才将image上像素拷贝到redback上面，否则保留redback原来的值
	image.copyTo(redback, mask);
	cv::imshow("roi区域提取", redback);
}

void QuickDemo::pixelStatisticDemo(cv::Mat& image) {
	double min, max;
	cv::Point min_loc, max_loc;
	std::vector<cv::Mat> mv;
	cv::split(image, mv);
	// 这个函数只支持单通道的图
	for (int dims = 0; dims < image.channels(); ++dims) {
		// 获取像素最值及最值的位置
		cv::minMaxLoc(mv[dims], &min, &max, &min_loc, &max_loc, cv::Mat());
		std::cout << "min value:" << min << "\tmax value:" << max << "\tmin location:" 
				  << min_loc << "\tmax location:" << max_loc << std::endl;
	}
	// 获取图像的均值和方差 每个通道的都可以打印出来
	// 均值是对区域内亮度的一个度量，可以用来反应图像的明暗程度
	// 方差就是数据的分散程度-->即对比度
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
	// 椭圆中心
	rrt.center = cv::Point(100, 300);
	// a b轴
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
	// 绘制多边形 但是这个函数不能填充
	cv::polylines(bg, pts, true, cv::Scalar(22, 33, 44), 2, cv::LINE_AA);
	// 填充 法一
	// cv::fillPoly(bg, pts, cv::Scalar(255, 255, 32), cv::LINE_AA);
	// 法二
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
			cv::destroyWindow("ROI区域"); // 销毁窗口  清除之前的内容
			cv::imshow("ROI区域", image(rect));
		}
		// 坐标重置
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
	else if (event == cv::EVENT_MOUSEWHEEL) {
		cv::Mat zoom_image;
		int w = image.cols;
		int h = image.rows;
		int value = 0;
		// 获取鼠标滚动的方向
		value = cv::getMouseWheelDelta(flags);
		if (value > 0) {
			// 向上
			cv::resize(image, zoom_image, cv::Size(1.5 * w, 1.5 * h), 0, 0, cv::INTER_LINEAR);
			temp = zoom_image.clone();
		}
		else {
			cv::resize(image, zoom_image, cv::Size(0.5 * w, 0.5 * h), 0, 0, cv::INTER_LINEAR);
			temp = zoom_image.clone();
		}
		cv::imshow("zoom", zoom_image);
	}
}

void QuickDemo::mouseDrawingDemo(cv::Mat& image) {
	cv::setMouseCallback("Image", onDraw, (void*)&image);
	temp = image.clone();
}

void QuickDemo::normalizeDemo(cv::Mat& image) {
	cv::Mat dst;
	// 转换为float   如果不转换成float  image中的数据都是char型  在归一化之后无法存储归一化的小数结果 舍掉变成0
	image.convertTo(image, CV_32F);
	// 需要浮点数据来进行归一化  1.0 0 表示取值在0到1之间 
	cv::normalize(image, dst, 1.0, 0, cv::NORM_MINMAX);
	/*
	 *	归一化几种方式：
	 *	1. NORM_L1:依据和来算平均
	 *  2. NORM_L2:单位向量为1
	 *  3. NORM_INF:依据最大值来求占比
	 *	4. NORM_MINMAX:根据delta=max-min
	 */
	cv::imshow("normalize", dst);
}

void QuickDemo::resizeDemo(cv::Mat& image) {
	cv::Mat zoomin, zoomout;
	int h = image.rows;
	int w = image.cols;
	/*cv::resize(image, zoomin, cv::Size(w / 2, h / 2), 0, 0, cv::INTER_LINEAR);
	cv::resize(image, zoomout, cv::Size(1.5 * w, 1.5 * h), 0, 0, cv::INTER_LINEAR);
	cv::imshow("zoomin", zoomin);
	cv::imshow("zoomout", zoomout);*/
	temp = image.clone();
	cv::namedWindow("zoom");
	cv::setMouseCallback("zoom", onDraw, (void*)&temp);
}

void QuickDemo::flipDemo(cv::Mat& image) {
	cv::Mat dst;
	//cv::flip(image, dst, 0);	// 上下
	//cv::flip(image, dst, 1);	// 左右
	cv::flip(image, dst, -1);	// 对角线
	cv::imshow("flip", dst);
}

void QuickDemo::warpAffineDemo(cv::Mat& image) {
	/*
		[cos	sin		x]
		[-sin	cos		y]
		x y 表示图像的原点
	*/
	cv::Mat dst, M;
	int w = image.cols;
	int h = image.rows;
	// 获取原图像旋转的api 第一个参数是原图像的中心  第2个是旋转角度 第三个是缩放比例
	M = cv::getRotationMatrix2D(cv::Point2f(w / 2, h / 2), 45, 1.0);
	double cos = cv::abs(M.at<double>(0, 0));
	double sin = cv::abs(M.at<double>(0, 1));
	int nw = cos * w + sin * h;
	int nh = sin * w + cos * h;
	M.at<double>(0, 2) += (nw / 2 - w / 2);
	M.at<double>(1, 2) += (nh / 2 - h / 2);
	// 最后一个参数是设置背景颜色
	cv::warpAffine(image, dst, M, cv::Size(nw, nh), cv::INTER_LINEAR, 0, cv::Scalar(255, 255, 0));
	cv::imshow("Image", dst);
}

void QuickDemo::videoDemo(cv::Mat& image) {
	cv::VideoCapture capture("E:/opencv/image/mulballs.mp4");
	int frame_width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
	int frame_height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);
	int frame_count = capture.get(cv::CAP_PROP_FRAME_COUNT);
	double fps = capture.get(cv::CAP_PROP_FPS);
	std::cout << "frame_width:" << frame_width << "\n"
			  << "frame_height:" << frame_height << "\n"
			  << "frame_count:" << frame_count << "\n"
			  << "fps:" << fps << std::endl;
	cv::VideoWriter writer("E:/opencv/testvideo.mp4", capture.get(cv::CAP_PROP_FOURCC), fps, cv::Size(frame_width, frame_height), true);
	cv::Mat frame;
	while (true) {
		capture.read(frame);
		writer.write(frame);
		int key = cv::waitKey(100);
		if (key == 27)	break;
		if (!frame.empty())	cv::imshow("Image", frame);
		else break;
	}
	capture.release(); 
}

void QuickDemo::histogramDemo(cv::Mat& image) {// 一维直方图
	/*
		cvRound()：返回跟参数最接近的整数值，即四舍五入；
		cvFloor()：返回不大于参数的最大整数值，即向下取整；
		cvCeil()：返回不小于参数的最小整数值，即向上取整；
	*/
	// 三通道分离
	std::vector<cv::Mat> bgr_plane;
	cv::split(image, bgr_plane);
	// 定义参数变量
	const int channels[1] = { 0 };
	const int bins[1] = { 256 }; // 灰度级等级
	float hranges[2] = { 0, 255 };// 灰度值范围
	const float* ranges[1] = { hranges };
	cv::Mat b_hist;
	cv::Mat g_hist;
	cv::Mat r_hist;
	// 计算b g r通道的直方图
	cv::calcHist(&bgr_plane[0], 1, 0, cv::Mat(), b_hist, 1, bins, ranges);
	cv::calcHist(&bgr_plane[1], 1, 0, cv::Mat(), g_hist, 1, bins, ranges);
	cv::calcHist(&bgr_plane[2], 1, 0, cv::Mat(), r_hist, 1, bins, ranges);
	// 显示直方图
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / bins[0]);
	// 作为一张画布
	cv::Mat histImage = cv::Mat::zeros(hist_h, hist_w, CV_8UC3);
	// 归一化直方图数据  因为每个像素值的个数取值范围不一样 会超出显示范围 所以归一化到一个范围
	cv::normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
	cv::normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
	cv::normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
	// 绘制直方图曲线
	for (int i = 1; i < bins[0]; ++i) {
		// hist_h - cv::cvRound(b_hist.at<float>(i - 1)这里用减法是因为我们想要获得的是每个像素统计值最高点坐标
		cv::line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			cv::Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), cv::Scalar(255, 0, 0));
		cv::line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			cv::Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), cv::Scalar(0, 255, 0));
		cv::line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			cv::Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), cv::Scalar(0, 0, 255));
	}
	// 显示直方图
	cv::namedWindow("Histogram", cv::WINDOW_AUTOSIZE);
	cv::imshow("Histogram", histImage);
}

void QuickDemo::histogram2DDemo(cv::Mat& image) {
	// 2D 直方图
	cv::Mat hsv, hs_hist;
	cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
	// 水平分为多少格 均分之和  步长为32
	int hbins = 30, sbins = 32;
	int hist_bins[] = { hbins, sbins };
	float h_range[] = { 0, 180 };
	float s_range[] = { 0, 256 };
	const float* hs_ranges[] = { h_range, s_range };
	int hs_channels[] = { 0, 1 };
	cv::calcHist(&hsv, 1, hs_channels, cv::Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);
	double maxVal = 0;
	cv::minMaxLoc(hs_hist, 0, &maxVal, 0, 0);
	int scale = 10;
	cv::Mat hist2d_image = cv::Mat::zeros(sbins*scale, hbins * scale, CV_8UC3);
	for (int h = 0; h < hbins; h++) {
		for (int s = 0; s < sbins; s++)
		{
			float binVal = hs_hist.at<float>(h, s);
			int intensity = cvRound(binVal * 255 / maxVal);
			cv::rectangle(hist2d_image, cv::Point(h*scale, s*scale),
				cv::Point((h + 1)*scale - 1, (s + 1)*scale - 1),
				cv::Scalar::all(intensity),
				-1);
		}
	}
	cv::applyColorMap(hist2d_image, hist2d_image, cv::COLORMAP_JET);
	cv::imshow("H-S Histogram", hist2d_image);
	cv::imwrite("D:/hist_2d.png", hist2d_image);
}