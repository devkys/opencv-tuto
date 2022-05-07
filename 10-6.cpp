#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

    Mat img_color = imread("house.png");

    Mat img_gray;
    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);
    imshow("Original", img_color);

    Mat img_edge;
    blur(img_gray, img_edge, Size(3,3));

    Canny(img_edge, img_edge, 50,150,3);

    imshow("Canny Edge", img_edge);
    waitKey(0);

    destroyAllWindows();
    return 0;
}