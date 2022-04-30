#include "iostream" 
#include "opencv2/opencv.hpp"   

using namespace std;
using namespace cv;

int main() {
    
    Mat img_color = imread("gray.jpeg", IMREAD_COLOR);

    if(img_color.empty()) {
        cout << "can nato read image file" << endl;
        return -1;
    }

    Mat img_gray;
    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);

    Mat img_binary;
    threshold(img_gray, img_binary, 127, 255, THRESH_BINARY);

    imshow("GrayScale", img_gray);
    imshow("binary-threshold", img_binary);

    waitKey(0);
    destroyAllWindows();

    return 0;
}