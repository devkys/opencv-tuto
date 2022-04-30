#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()  {
    Mat img_frame;
    VideoCapture cap(0);

    if(!cap.isOpened()){
        cout << "can not opened camera" <<endl;
        return -1;
    }

    while(1) {
        bool ret = cap.read(img_frame);

        if(!ret) { 
            cout << "can not capture" << endl;
            return -1;
        }

        imshow("Camera", img_frame);

        if (waitKey(1) != -1){
            imwrite("photo2.jpg", img_frame);
            break;
        }

    }
    cap.release();
    destroyAllWindows();

    return 0;
}