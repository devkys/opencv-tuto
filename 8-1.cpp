#include "iostream"
#include "opencv2/opencv.hpp"   

using namespace std;
using namespace cv;

//전역변수로 필요한 것: 좌표, 불리언 타입의 마우스 체크, Mat 클래스의 이미지 선언
bool mouse_is_pressing = false;
int start_x, start_y, end_x, end_y;
Mat img_color;
int step = 0;

void swap(int* v1, int* v2){
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void mouse_callback(int event, int x, int y, int flags, void* param){
    //왼쪽 버튼 눌렀을 때 스텝은 1
    if (event == EVENT_LBUTTONDOWN) {
        step = 1;
        mouse_is_pressing = true;
        start_x=x;
        start_y=y;
    }
    //마우스를 누른 상태이면 현재 마우스 커서 위치를 ROI 끝점을 저장하여 현재 선택된 ROI 영역을 보여주도록 함, 스텝은 2
    else if(event == EVENT_MOUSEMOVE){
        if(mouse_is_pressing == true){
            end_x=x;
            end_y=y;
            step = 2;
        }
    }
    //왼쪽 버튼 뗐을때 스텝은 3
    else if(event == EVENT_LBUTTONUP){
        mouse_is_pressing = false;
        end_x=x;
        end_y=y;
        step=3;
    }
}

int main(){
    VideoCapture cap(0);
    if(cap.isOpened() == false){
        cout << "can not opened camera" <<endl;
        return -1;
    }

    namedWindow("Color");
    setMouseCallback("Color", mouse_callback);

    while(true){
        cap.read(img_color);
        if(img_color.empty()){
            cout << "failed capture" << endl;
            break;
        }

        switch (step)
        {
        case 1:
            circle(img_color,Point(start_x, start_y),10,Scalar(0,255,0), -1);
            break;
        case 2:
            rectangle(img_color, Point(start_x,start_y), Point(end_x, end_y),Scalar(0,255,0),3);
            break;
        case 3:
            if(start_x > end_x){
                swap(&start_x, &end_x);
                swap(&start_y, &end_y);
            }
            Mat ROI(img_color,Rect(start_x, start_y, end_x-start_x,end_y-start_y));

            cvtColor(ROI, ROI, COLOR_BGR2GRAY);
            Canny(ROI, ROI, 150,50);
            cvtColor(ROI,ROI, COLOR_GRAY2BGR);

            ROI.copyTo(img_color(Rect(start_x, start_y, end_x-start_x, end_y-start_y)));
            break;
        }
        imshow("Color", img_color);
        if(waitKey(25) > 0)
            break;
    }
    destroyAllWindows();
    return 0;
}