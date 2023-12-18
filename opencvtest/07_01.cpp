//
//  07_01.cpp
//  opencvtest
//
//  Created by 吴坤城 on 12/18/23.
//

#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
    
    //图片
    
    while(true) {
        Mat image = imread("Users/lex./Desktop/Picture.jpg");
            if(img.empty()) { //找不到图片就结束
                break;
            }
            imshow("Image", image);
            char c = waitKey();
            if(c == 27) { //ESC退出
                destroyAllWindows();
                return 0;
            }
    }
    
    //视频
    VideoCapture cap("/Users/lex./Desktop/Video.mp4");
        while(true) {
            Mat video;
            cap >> video;
            if(video.empty()) { //找不到视频就结束
                break;
            }
            imshow("Video", video);
            char c = waitKey(25);
            if(c == 27) { //ESC退出
                break;
            }
        }
    
    //摄像头
    VideoCapture camera(0);
        while(true) {
            Mat frame;
            camera >> frame;
            flip(frame, frame, 1); //镜像视频
            if(frame.empty()) { //捉不到画面就结束
                break;
            }
            imshow("Camera", frame);
            char c = waitKey(1);
            if(c == 27) { //ESC退出
                break;
            }
        }

        return 0;
        }



