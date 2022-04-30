#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat img_color, img_gray;

    img_color = imread("cat-laptop.jpeg",  IMREAD_COLOR);

    if(img_color.empty()) {
        cout << "don't read image file" <<endl;
        return -1;
    }

    // namedWindow("Color");
    imshow("Color",img_color);

    cvtColor(img_color, img_gray, COLOR_BGR2GRAY);
    
    imshow("Grayscale",img_gray);

    imwrite("grayscale.jpeg", img_gray);


    waitKey(0);
    destroyAllWindows();   

    return 0;
}
