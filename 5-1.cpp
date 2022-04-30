#include "iostream"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){

    Mat img_color = imread("copy.png", IMREAD_COLOR);
    if(img_color.empty()){
        cout << "can not read image" << endl;
        return -1;
    }
    
    Mat img_gray;
    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);

    Mat img_binary;
    adaptiveThreshold(img_gray, img_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5,4);

    imshow("GrayScale", img_gray);
    imshow("Binary", img_binary);
    waitKey(0);

    destroyAllWindows();
    return 0;
}