#include "opencv2/opencv.hpp"   

using namespace cv;

int main(){

    Mat img;
    img = imread("test.png");

    Mat kernel = Mat(5,5, CV_32F, Scalar(1/25.0));

    Mat dst;
    filter2D(img, dst, -1, kernel);

    imshow("Original", img);
    imshow("result", dst);

    waitKey(0);
    destroyAllWindows();
    return 0;
}