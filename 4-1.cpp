#include <opencv2/opencv.hpp>

using namespace cv;

//트랙바를 조정할 때마다 실행되는 콜백함수
//여기서는 아무 일 하지 않는 더미함수

static void on_trackbar(int, void*){

}

int main()  {

    namedWindow("Canny");
    
    //트랙바 생성
    //트랙바 이름, 윈도우 이름, 최솟값, 최댓값, 콜백함수
    createTrackbar("low threshold", "Canny", 0, 1000, on_trackbar);
    createTrackbar("high threshold", "Canny", 0, 1000, on_trackbar);

    //트랙바 초기값 설정
    //트랙바 이름, 트랙바가 붙어있는 윈도우 이름으로 트랙바에 접근
    setTrackbarPos("low threshold:", "Canny", 50);
    setTrackbarPos("high threshold:", "Canny", 150);

    //이미지를 그레이 스케일로 불러옴
    Mat img_gray;
    img_gray = imread("orange.png", IMREAD_GRAYSCALE);

    //트랙바 조정시 Canny함수에 반영되도록 루프를 사용
    while(1){

        //현재 트랙바의 위치 가져오기
        int low = getTrackbarPos("low threshold", "Canny");
        int high = getTrackbarPos("high threshold", "Canny");

        //트랙바로부터 가져온 값으로 Canny함수의 파라미터를 조정
        Mat img_canny;
        Canny(img_gray, img_canny, low, high);

        imshow("Canny", img_canny);

        if(waitKey(1) == 27)
            break;
    }

    destroyAllWindows();

    return 0;
}