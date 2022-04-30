//ROI도 이미지 데이터 공유힘

#include <opencv2/opencv.hpp>

using namespace cv;

int main(){

    Mat img_color;
    img_color = imread("cat-laptop.jpeg", IMREAD_GRAYSCALE);
    
    //Rect(start_x, start_y, width, height)로 ROI할 영역을 지정
    Mat img_rect(img_color, Rect(20,20,150,150));

    //Range(start_y, end_y), Range(start_x, end_y)로 ROI할 영역 지정
    //전체 x영역을 지정하기 위해 Range:all()를 사용
    Mat img_range = img_color(Range(100,150), Range::all());

    threshold(img_rect, img_range, 127, 255, THRESH_BINARY);

    imshow("img_color", img_color);
    imshow("img_rect", img_rect);
    imshow("img_range", img_range);

    waitKey(0);

    return 0;
}