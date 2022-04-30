#include "iostream"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){
   //Mat 변수 img_frame 선언
   Mat img_frame;

   //비디오캡처 비디오 변수 cap 선언, 비디오 열기 실패시 리턴값 -1
   VideoCapture cap(0);
   
   if(!cap.isOpened()){
       cout << "can not opened camera" << endl;
       return -1;
   }

   //보여줄 결과를 지정하기 위해 사용하는 변수 step 선언
    int step = 1;

   //while 루프
   while(1) {
       //img_frame 변수에 저장된 이미지를 윈도우에 보여주게 됨
       //처음에는 카메라에 캡처된 컬러 이미지
       bool ret = cap.read(img_frame);
        //캡처 실패시 break
        if(!ret) {
            cout << "can not capture!" << endl;
            break;
        }
        
        //1초 동안 키보드 입력을 대기
        int key = waitKey(1);
        //esc키가 입력되면 루프 중지
        if(key == 27)
            break;
        //key가 1
        else if(key == 49)
            step = 1;
        //key가 2
        else if(key == 50)
            step = 2;
        //key가 3
        else if(key == 51)
            step = 3;

        //step이 2 이상이면 img_frame에 그레이 스케일 이미지 저장
        if(step > 1){
            cvtColor(img_frame, img_frame, COLOR_BGR2GRAY);
            //step이 3이상이면 img_frame에 에지 이미지 저장
            if(step > 2)
                Canny(img_frame, img_frame, 30, 90);
        }
        //앞에서 처리된 결과에 따라 다른 이미지가 result 윈도우에 보여지게 됨
        imshow("Result", img_frame);
   }

   cap.release();
   destroyAllWindows();
   return 0;
    
}