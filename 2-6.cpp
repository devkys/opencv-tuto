//카메라에서 캡처한 이미지를 동영상 파일로 저장하기

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat img_frame;
    VideoCapture cap(0);

    if(!cap.isOpened()) {
        cout << "do not opened camera" << endl;
        return -1;
    }
    bool ret = cap.read(img_frame);

    if(!ret) {
        cout << "failed capture" << endl;
        return -1;
    }

    //동영상 파일을 위한 코댁을 설정
    int codec = VideoWriter::fourcc('M', 'J','P','G');
    //프레임 레이트(rate)설정
    double fps = 30.0;

    //동영상 파일을 저장하려면 VideoWriter 객체를 생성해야 함
    //코덱, 프레임 레이트, 이미지 크기를 지정 함
    VideoWriter writer("output.avi", codec, fps, img_frame.size());

    //VideoWriter 객체를 성공적으로 초기화했는지 체크
    if(!writer.isOpened()) {
        cout << "do not prepare video file" <<endl;
        return -1;  
    }

    //카메라에서 이미지 캡처와 동영상 파일에 추가를 반복하면 동영상 파일로 저장됨
    while(1){
        bool ret = cap.read(img_frame);
        if(!ret) {
            cout << "failed capture" <<endl;
            break;
        }
        
        //캡처한 이미지를 동영상 파일에 저장
        writer.write(img_frame);
        imshow("Color", img_frame);

        int key = waitKey(1);
        if (key == 27)
            break;

    }
    cap.release();
    writer.release();

    return 0;
}