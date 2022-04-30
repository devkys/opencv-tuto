#include "iostream"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){

    //declare Mat img_color
    Mat img_color = imread("ball.jpeg", IMREAD_COLOR);
    //cannot read image file
    if(img_color.empty()){
        cout << "can not read image file" << endl;
        return -1;
    }
    //change to gray_scale image file
    // Mat img_gray;

    Mat img_gray;
    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);
    //detect edge for use canny
    Mat img_canny;
    Canny(img_gray, img_canny, 90,180);
    //show result image file 
    imshow("Grayscale", img_gray);
    imshow("Canny", img_canny);
    //waitkey
    waitKey(0);
    //close all windows
    destroyAllWindows();

    return 0;
}