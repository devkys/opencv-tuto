#include "iostream"
#include "opencv2/opencv.hpp"   

using namespace std;
using namespace cv;

int main(){
    Mat img_logo = imread("logo.png", IMREAD_COLOR);
    Mat img_background = imread("background.png", IMREAD_COLOR);

    Mat img_gray;
    cvtColor(img_logo, img_gray, COLOR_BGR2GRAY);

    Mat img_mask;
    Mat img_mask_inv;
    threshold(img_gray, img_mask, 200, 255,THRESH_BINARY);
    threshold(img_gray, img_mask_inv, 200,255, THRESH_BINARY_INV);

   
    // Mat img_mask_inv;
    // bitwise_not(img_mask, img_mask_inv);

    int height = img_logo.rows;
    int width = img_logo.cols;

    Mat img_roi(img_background, Rect(100,100,width,height));

    Mat img1, img2;

    //컬러 로고이미지에서 에서 배경만 뺀 비트연산
    bitwise_and(img_logo, img_logo, img1, img_mask_inv);
    //백그라운드 이미지에서 넣을 로고 모양만 뺀 비트연산
    bitwise_and(img_roi, img_roi, img2, img_mask);

    Mat dst;
    add(img1, img2, dst);

    dst.copyTo(img_background(Rect(100,100,width, height)));

    imshow("background", img_background);
    imshow("logo", img_logo);
    imshow("img_mask_inv", img_mask_inv);
    imshow("img_mask", img_mask);
    imshow("img1", img1);
    imshow("img2", img2);
    imshow("dst", dst);
    waitKey(0);
    destroyAllWindows();
}