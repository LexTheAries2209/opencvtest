//
//  07_02.cpp
//  opencvtest
//
//  Created by 吴坤城 on 12/18/23.
//

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    // 读取图像
    Mat image = imread("/Users/lex./Desktop/Picture.jpg"); // 替换为您的图像路径
    if(image.empty()) {
        cout << "找不到图像！" << endl;
        return 1;
    }

    // 将图像转换为灰度图
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // 将灰度图像二值化
    Mat binaryImage;
    double thresholdValue = 64; // 调节阈值
    threshold(grayImage, binaryImage, thresholdValue, 255, THRESH_BINARY);

    // 对灰度图像进行高斯模糊处理
    Mat blurredImage;
    Size ksize = Size(9, 9); // 高斯核大小
    double sigmaX = 2.5; // X方向的标准差
    double sigmaY = 2.5; // Y方向的标准差
    GaussianBlur(grayImage, blurredImage, ksize, sigmaX);

    // 输出原始图像和处理后的图像
    namedWindow("Original Image", WINDOW_AUTOSIZE); //输出原始图像
    imshow("Original Image", image);

    namedWindow("Gray Image", WINDOW_AUTOSIZE); //输出灰度图
    imshow("Gray Image", grayImage);

    namedWindow("Binary Image", WINDOW_AUTOSIZE); //输出二值化图像
    imshow("Binary Image", binaryImage);

    namedWindow("Blurred Image", WINDOW_AUTOSIZE); //输出马赛克图像
    imshow("Blurred Image", blurredImage);

    //ESC 退出
    waitKey(0);

    return 0;
}

