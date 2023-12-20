//
//  07_04.cpp
//  opencvtest
//
//  Created by 吴坤城 on 12/19/23.
//

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void on_trackbar(int, void* userdata) {
    // 获取用户数据，包括图像和窗口名
    auto data = reinterpret_cast<pair<Mat*, string>*>(userdata);
    Mat src = data->first->clone();
    string window_name = data->second;

    // 获取滑动条当前位置
    int brightness_value = getTrackbarPos("Brightness", window_name);
    int contrast_value = getTrackbarPos("Contrast", window_name);

    // 初始化亮度与对比度
    double con = 1.0 + (contrast_value - 50) / 50.0;
    double bri = (brightness_value - 50) * 2.55;

    // 调整亮度和对比度
    src.convertTo(src, -1, con, bri);

    // 显示调整后的图像
    imshow(window_name, src);
}

int main() {
    // 加载图像
    Mat img = imread("/Users/lex./Desktop/Picture.jpg");
    if(img.empty()) {
        cout << "找不到图像！" << endl;
        return 1;
    }

    // 创建显示图像的窗口
    string window_name = "Image";
    namedWindow(window_name, 1);

    int brightness_value = 50; // 初始亮度值
    int contrast_value = 50;   // 初始对比度值

    // 存储图像和窗口名的用户数据
    pair<Mat*, string> userdata(&img, window_name);

    //生成滑动条
    createTrackbar("Brightness", window_name, &brightness_value, 100, on_trackbar, &userdata);
    createTrackbar("Contrast", window_name, &contrast_value, 100, on_trackbar, &userdata);

    // 初始化回调函数
    on_trackbar(0, &userdata);

    // ESC退出
    waitKey(0);
    return 0;
}

