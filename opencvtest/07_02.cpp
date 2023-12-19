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
    Mat image = imread("/Users/lex./Desktop/Picture.jpg");
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
    double sigmaY = 2.5; // Y方向标准差
    GaussianBlur(grayImage, blurredImage, ksize, sigmaX, sigmaY);

    // 输出原始图像和处理后的图像
    imshow("Original Image", image); //输出原始图像
    imshow("Gray Image", grayImage); //输出灰度图
    imshow("Binary Image", binaryImage); //输出二值化图像
    imshow("Blurred Image", blurredImage); //输出马赛克图像

    //ESC 退出
    waitKey(0);

    return 0;
}

