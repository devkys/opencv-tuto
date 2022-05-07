#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat img_gary = imread("test.png", IMREAD_GRAYSCALE);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    Mat img_result;
    dilate(img_gary, img_result, kernel, Point(-1,-1), 1);
    imshow("Input", img_gary);
    imshow("Result", img_result);
    waitKey(0);

    destroyAllWindows();

    return 0;
}