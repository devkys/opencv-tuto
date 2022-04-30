#include "iostream"
#include "opencv2/opencv.hpp"   

using namespace std;
using namespace cv;

//마우스 왼쪽 버튼 상태 체크를 위해 사용
bool mouse_is_pressing = false;
//현재 그리기 모드 선택을 위해 사용(원/사각형)
bool drawing_mode = true;

//최초로 마우스 왼쪽 버튼 누른 위치를 저장하기 위해 사용
int start_x = -1;
int start_y = -1;

//도형 내부 채울 때 사용할 색 지정 시 사용
Scalar color(255, 255, 255);
//그리기 결과를 저장할 이미지
Mat img;
RNG rng(543210);

//마우스 이벤트 발생 시 호출될 함수를 정의함
void mouse_callback(int event, int x, int y, int flags, void *userdata) {

    //마우스를 이동하면 발생하는 이벤트
    if(event == EVENT_MOUSEMOVE){
        //마우스 왼쪽 버튼을 누른 채 이동하면
        if(mouse_is_pressing == true) {
            //이동된 마우스 커서 위치를 반영하여 사각형/원을 그림
            if(drawing_mode == true) 
                rectangle(img, Point(start_x, start_y), Point(x, y), color, -1);
            else
                circle(img, Point(start_x, start_y), max(abs(start_x-x), abs(start_y-y)), color, -1);
        }
    }

    //마우스 왼쪽 버튼을 누르면 발생하는 이벤트
    else if(event == EVENT_LBUTTONDOWN) {
        //랜덤으로(b,g,r)로 사용될 색을 생성
        color = Scalar(rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255));
        //마우스 왼쪽 버튼을 누른 것을 체크
        mouse_is_pressing=true;
        //마우스 왼쪽 버튼 누른 위치를 저장
        start_x = x;
        start_y = y;
    }
    //누르고 있는 마우스 왼쪽 버튼에서 손을 떼면 발생하는 이벤트
    else if(event == EVENT_LBUTTONUP){
        //마우스 왼쪽 버튼에서 손뗀 것을 체크
        mouse_is_pressing = false;
        //왼쪽 버튼을 누른 위치와 손 뗀 위치를 사용하여 사각형/원을 그림
        if(drawing_mode == true)
            rectangle(img, Point(start_x, start_y), Point(x, y), color, -1);
        else
            circle(img, Point(start_x, start_y),max(abs(start_x-x), abs(start_y-y)), color, -1);
    }
    //마우스 오른쪽 버튼을 누를 때 발생하는 이벤트
    else if(event == EVENT_RBUTTONDOWN){
        drawing_mode = !drawing_mode;
    }
}

int main()  {
    int width = 500;
    int height = 500;

    img = Mat(height, width, CV_8UC3, Scalar(0,0,0));

    namedWindow("image");

    setMouseCallback("image", mouse_callback, 0);

    while(1){
        imshow("image", img);
        
        int key = waitKey(1);
        if(key == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}