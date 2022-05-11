#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    //템플릿 이미지를 검출할 이미지를 불러옴
    Mat img_rgb = imread("circle.jpg");
    Mat img_gray;
    cvtColor(img_rgb, img_gray, COLOR_BGR2GRAY);

    //템플릿 이미지 불러오기
    Mat img_template = imread("template.jpg", IMREAD_GRAYSCALE);
    int w = img_template.cols;
    int h = img_template.rows;

    //템플릿 매칭
    Mat result;
    matchTemplate(img_gray, img_template, result, TM_CCOEFF_NORMED);

    double min_v, max_v;
    Point min_loc, max_loc;
    minMaxLoc(result, &min_v, &max_v, &min_loc, &max_loc);

    //검출된 템플릿 이미지와 유사한 영역에 사각형을 그려줌
    Point top_left = max_loc;
    Point bottom_right = Point(top_left.x+h, top_left.y+w);
    rectangle(img_rgb, top_left, bottom_right, Scalar(0,0,255), 2);

    imshow("result", img_rgb);
    waitKey(0);
    destroyAllWindows();
    return 0;
}