#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){

    //사과 이미지 초기화
    Mat img_color = imread("apple.jpeg", IMREAD_COLOR);

    //이미지의 높이와 너비를 가져오기
    int height = img_color.rows;
    int width = img_color.cols;

    //그레이 스케일 이미지를 저장할 Mat 객체 생성
    Mat img_gray(height, width,CV_8UC1);
    //for문을 돌리면서 (x,y)에 있는 픽셀을 하나씩 접근
    for(int y = 0; y < height; y++) {
        //속도 향상을 위해 y좌표를 사용하여 포인터 위치를 미리 계산
        uchar* pointer_input = img_color.ptr<uchar>(y);
        uchar* pointer_ouput = img_gray.ptr<uchar>(y);
        
        for(int x = 0; x < width; x++) {
            uchar b = pointer_input[x * 3 + 0];
            uchar g = pointer_input[x * 3 + 1];
            uchar r = pointer_input[x * 3 + 2];

            //(x,y) 위치의 픽셀에 그레이 스케일값이 저장됨
            //평균값 사용하는 경우
            //pointer_output[x] = (r + g + b) / 3.0;
            //BT.709에 명시ㅊㅍ_8ㅕㅊ된 비율 사용ㅇ하는 경우
            pointer_ouput[x] = r * 0.2126 + g * 0.7152 + b * 0.0722;

        }
    }

    Mat img_result;
    cvtColor(img_gray, img_result, COLOR_GRAY2BGR);

    for(int y = 372; y <589; y++) {
        uchar* pointer_input = img_result.ptr<uchar>(y);
        for(int x = 167; x < 405; x++) {
            pointer_input[x * 3 + 0] = 0;   //b
            pointer_input[x * 3 + 1] = 255; //g
            pointer_input[x * 3 + 2] = 0;   //r
        }
    }
    imshow("color", img_color);
    imshow("result", img_result);

    waitKey(0);
    return 0;

}