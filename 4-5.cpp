#include "iostream" 
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()  {

    Mat img_color = imread("ball.jpeg", IMREAD_COLOR);
    
    if(img_color.empty()){
        cout << "can not read image file" <<endl;
        return -1;
    }
    Mat img_gray;
    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);

    Mat img_canny;
    Canny(img_gray, img_canny, 90, 180);

    vector<Mat> matrices = {img_gray, img_canny};

    Mat img_result;
    hconcat(matrices, img_result);
    // vconcat(matrices, img_result);

    imshow("Result", img_result);

    waitKey(0);
    destroyAllWindows();

    return 0;
}