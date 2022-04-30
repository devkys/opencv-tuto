#include "iostream"
#include "opencv2/opencv.hpp"   

using namespace std;
using namespace cv;

static void on_trackbar(int, void*){

}
int main(){
    Mat img_color = imread("red-ball.jpeg", IMREAD_COLOR);
    
    if(img_color.empty()){
        cout << "can not read image file" << endl;
        return -1;
    }
    imshow("color", img_color);
    Mat img_gray;
    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);
    imshow("GraySclae", img_gray);

    namedWindow("Binary");
    createTrackbar("threshold", "Binary", 0, 255, on_trackbar);
    setTrackbarPos("threshold", "Binary", 127);

    while(1){
        int thresh = getTrackbarPos("threshold", "Binary");

        Mat img_binary;
        threshold(img_gray, img_binary, thresh, 255, THRESH_BINARY_INV);

        imshow("Binary", img_binary);

        if(waitKey(1) == 27)
            break;
    }
    return 0;
}