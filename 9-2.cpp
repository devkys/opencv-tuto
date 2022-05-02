#include "opencv2/opencv.hpp"   

using namespace cv;

int main(){
    Mat img_color;

    img_color = imread("cat.jpeg", IMREAD_COLOR);
    imshow("original", img_color);


    Mat img_result;
    
    //이미지 확대/축소 비율을 정해 줄 수 있음
    //여기에선 가로 방향(fx)으로 2배, 세로 방향(fy)으로 2배 확대
    //이미지 확대 시에는 보간법으로 INTER_CUBIC 또는 INTER_LINEAR를 권장
    resize(img_color, img_result, Size(), 2,2, INTER_CUBIC);
    imshow("x2 INTER_CUBIC", img_result);

    int width = img_color.cols;
    int height = img_color.rows;

    //확대 및 축소되는 이미지 크기를 너비와 높이로 지정할 수 있음
    //여기에선 너비와 높이를 3배로 확대
    resize(img_color, img_result, Size(3*width, 3*height), INTER_LINEAR);
    imshow("x3 INTER_LINEAR", img_result);

    //이미지의 너비와 높이르르 0.5배 줄임
    resize(img_color, img_result, Size(), 0.5, 0.5, INTER_AREA);
    imshow("x0.5 INTER_AREA", img_result);

    waitKey(0);
    destroyAllWindows();

    return 0;
}