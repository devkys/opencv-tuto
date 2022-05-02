#include "opencv2/opencv.hpp"   

using namespace cv;

int main(){
    //Mat객체의 img_color 선언후 ,imread로 읽어오기, imshow로 보여주기
    Mat img_color = imread("cat.jpeg", IMREAD_COLOR);
    imshow("Cat", img_color);

    //이미지 높이, 넓이 가져오기
    int height = img_color.rows;
    int width = img_color.cols;

    //이미지 중앙을 중심으로 반시계방향으로 45도 회전 시키는 회전 행렬 생성(getRotationMatrix2D)
    Mat M = getRotationMatrix2D(Point(width/2.0, height/2.0), 45, 1);

    //회전 행렬 M을 이미지 img_color에 적용하기(mat 객체 선언후, wrapAffine())
    Mat img_rotated;
    warpAffine(img_color, img_rotated, M, Size(width, height), 1);
    imshow("rotation", img_rotated);
    waitKey(0);
    destroyAllWindows();

    return 0;    
}