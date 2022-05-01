#include "opencv2/opencv.hpp"

using namespace cv;

int main(){
    int width = 640;
    int height = 480;

    Mat img(height, width, CV_8UC3, Scalar(0,0,0));

    //왼쪽 위 좌표 (50,50), 오른쪽 아래 좌표(450,450)
    //선굵기가 3인 빨간색 사각형을 그림
    rectangle(img, Point(50,50), Point(450,450), Scalar(0,0,255), 3);

    //내부가 초록색으로 채워진 사각형 그림
    rectangle(img, Point(150,200), Point(250,300), Scalar(0,255,0), -1);

    //왼쪽 위 좌표 (300,150)이면서 너비, 높이가 각각 50,100인
    //내부가 마젠타색으로 채워진 사각형을 그림
    rectangle(img, Rect(300,150,50,100), Scalar(255,0,255), -1);

    imshow("result", img);
    waitKey(0);

    destroyAllWindows();
    return 0;
}