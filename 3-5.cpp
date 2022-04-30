// 컬러 이미지 B,G,R 채널로 분리한 후 -> 순서를 R,G,B로 바꾸어 컬러 이미지를 생성하는 예제

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat color_img = imread("color.png", IMREAD_COLOR);
    
    //컬러 이미지를 채널별로 분리
    //b,g,r 순으로 채널이 저장됨
    Mat img_channels[3];
    split(color_img, img_channels);

    vector<Mat> channels;
    channels.push_back(img_channels[2]);    //r
    channels.push_back(img_channels[1]);    //g
    channels.push_back(img_channels[0]);    //b

    Mat img_result;
    merge(channels, img_result);

    imshow("Color", img_result);
    imshow("B", img_channels[0]);
    imshow("G", img_channels[1]);
    imshow("R", img_channels[2]);

    waitKey(0);
    return 0;
}