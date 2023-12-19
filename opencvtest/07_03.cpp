//
//  07_03.cpp
//  opencvtest
//
//  Created by 吴坤城 on 12/19/23.
//

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    
    // 读取图像
    Mat img = imread("/Users/lex./Desktop/Picture.jpg");
    if(img.empty()) {
        cout << "找不到图像！" << endl;
        return 1;
    }
    
    // 检测图像边缘
    Mat edges;
    Canny(img, edges, 100, 200);
    
    // 进行膨胀操作
    Mat dilated;
    dilate(edges, dilated, Mat(), Point(-1, -1), 2);
    
    // 进行侵蚀操作
    Mat eroded;
    erode(dilated, eroded, Mat(), Point(-1, -1), 3);
    
    // 把图像缩放为50%
    Mat resized;
    resize(img, resized, Size(img.cols * 0.5, img.rows * 0.5));
    
    // 显示原始图像和处理后的图像
    imshow("Original Image", img); //原始图像
    imshow("Edges Image", edges); //边缘检测
    imshow("Dilated Image", dilated); //膨胀图像
    imshow("Eroded Image", eroded); //侵蚀图像
    imshow("Resized Image", resized); //缩放图像
    
    // ESC退出
    waitKey(0);
    return 0;
}
