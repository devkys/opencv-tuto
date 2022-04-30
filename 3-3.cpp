//새로운 메모리 공간에 이미지 데이터 복사

#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat img_color;
    img_color = imread("deep-learning.jpeg", IMREAD_GRAYSCALE);

    //use 'clone' method
    Mat img_copyed1 = img_color.clone();

    //use 'copyTo' method
    Mat img_copyed2;
    img_color.copyTo(img_copyed2);

    threshold(img_color, img_color, 127, 255, THRESH_BINARY);

    imshow("img_color", img_color);
    imshow("img_copyed1", img_copyed1);
    imshow("img_copyed2", img_copyed2);

    waitKey(0);

    return 0;
}