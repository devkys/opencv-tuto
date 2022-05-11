#include <opencv2/opencv.hpp>
#include <cmath>

using namespace cv;
using namespace std;

vector<Point> detectedObjects;

//새로운 좌표와 근사한 좌표가 기존 리스트에 있는지 체크
bool notInList(Point newObject){
    for(int i=0; i< detectedObjects.size(); i++){
        float a = detectedObjects[i].x - newObject.x;
        float b = detectedObjects[i].y - newObject.y;

        if(sqrt(a*a+b*b < 5.0))
            return false;
    }
    return true;
}

int main(){
    Mat img_rgb = imread("circle.jpg");

    Mat img_gray;
    cvtColor(img_rgb, img_gray, COLOR_BGR2GRAY);

    Mat img_template = imread("template.jpg", IMREAD_GRAYSCALE);
    int w = img_template.cols;
    int h = img_template.rows;
    
    Mat result;
    matchTemplate(img_gray, img_template, result, TM_CCOEFF_NORMED);

    //임계값 0.9보다 크고
    //기존에 템플릿 검출 리스트에 포함된 좌표와 거리가 5이상이어야
    //새로운 좌표로 리스트에 추가
    int count = 0;
    for(int x=0; x<result.cols; x++)
    for(int y=0; y<result.rows; y++){
        if(result.at<float>(y,x) > 0.9 &&notInList(Point(x,y)))
        {
            detectedObjects.push_back(Point(x,y));
            rectangle(img_rgb, Point(x,y), Point(x+w, y+h), Scalar(0,0,255), 1);
            count++;
        }
    }

    cout << count << endl;
    imshow("result", img_rgb);
    waitKey(0);
    destroyAllWindows();

    return 0;
}