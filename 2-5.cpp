//카메라에서 캡처한 이미지를 화면에 보여주기

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(){

    Mat img_frame;
    VideoCapture cap(0);

    if(!cap.isOpened()) {
        cout << "do not opened camera" << endl;
        return -1;
    }

    while(1) {

        bool ret = cap.read(img_frame);

        if(!ret) {
            cout << "failed capture!" <<endl;
            break;
        }

        imshow("Color", img_frame);
        int key = waitKey(1);
        if(key == 27)
            break;

    }
    cap.release();
    return 0;
}