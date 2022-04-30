//그레이 스케일로 같은 이미지 데이터 공유

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat img_color;

    img_color = imread("cat-laptop.jpeg", IMREAD_GRAYSCALE);
    Mat img_copyed1(img_color);
    Mat img_copyed2(img_color);

    threshold(img_color, img_color,127,255, THRESH_BINARY);

    imshow("img_color", img_color);
    imshow("img_copyed1", img_copyed1);
    imshow("img_copyed2", img_copyed2);

    waitKey(0);
    return 0;
}