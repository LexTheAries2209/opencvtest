//
//  main.cpp
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
        string image_path = "/Users/lex./Desktop/Picture.jpg";
        Mat gray_img = imread(image_path, 1);
        imshow("Picture", gray_img);
        char c = waitKey(25);
        if(c == 27) {
            break;
        }
    }
    
    //视频
    VideoCapture cap("/Users/lex./Desktop/Video.mp4");
        while(true) {
            Mat video;
            cap >> video;
            if(video.empty()) {
                break;
            }
            imshow("Video", video);
            char c = waitKey(17);
            if(c == 27) {
                break;
            }
        }
    
    //摄像头
    VideoCapture camera(0);
        while(true) {
            Mat frame;
            camera >> frame;
            flip(frame, frame, 1);
            if(frame.empty()) {
                break;
            }
            imshow("Camera", frame);
            char c = waitKey(1);
            if(c == 27) {
                break;
            }
        }

        return 0;
        }



