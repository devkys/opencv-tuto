//동영상 파일 재생하기
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()  {

    Mat img_frame;
    VideoCapture cap("output.avi");
    if(!cap.isOpened()){
        cout << "can not opened camera" << endl;
        return -1;
    }

    while(1) {
        bool ret = cap.read(img_frame);
        if(!ret) {
            cout << "complete read video file" << endl;
            break;
        }
        imshow("Color", img_frame);

        int key = waitKey(25);
        if (key == 27)
            break;
    }
    cap.release();
    return 0;
}