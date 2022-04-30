// #include <opencv2/opencv.hpp>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <string>
// #include <vector>

// using namespace cv;
// using namespace std;

// void onMouse(int event, int x, int y, int flags, void* userdata)
// {
//     Mat *mat = (Mat*)userdata;
//     static int sx, sy;
//     static bool click(false);
//     static bool rclick(false);
    
//     if (event == EVENT_LBUTTONDOWN) {
//         sx = x;
//         sy = y;
//         click = true;
//     }
//     else if (event == EVENT_RBUTTONDOWN) {
//         sx = x;
//         sy = y;
//         rclick = true;
//     }
//     else if ((click == true || rclick == true) && 
//         event == EVENT_MOUSEMOVE && (sx != x || sy != y)) {
//         if (click == true) line(*mat, Point(sx,sy), Point(x,y), Scalar(0,0,0), 20);
//         else line(*mat, Point(sx,sy), Point(x,y), Scalar(255,255,255), 40);
//         sx = x;
//         sy = y;
//     }
//     else if (event == EVENT_LBUTTONUP) {
//         click = false;
//     }
//     else if (event == EVENT_RBUTTONUP) {
//         rclick = false;
//     }
// }

// int main()
// {
//     int rows(28), cols(28);
//     Mat mat(rows*8, cols*8, CV_8UC1, Scalar(255));
//     namedWindow("work", 1);
//     setMouseCallback("work", onMouse, &mat);

//     string path = "/Users/kyeongseo/work/mnist/A";

//     struct stat sb = { 0 };
//     if (stat(path.c_str(), &sb) == -1) mkdir(path.c_str(), 0700);

//     vector<int> compression_params;
//     compression_params.push_back(IMWRITE_PNG_COMPRESSION);
//     compression_params.push_back(0);

//     Mat mat2(rows, cols, CV_8UC1, Scalar(0));
//     uchar *idata = mat.data;
//     uchar *idata2 = mat2.data;

//     int num_label = 0;
//     char filename[1024];

//     while (1) {
//         imshow("work", mat);
//         char ch = waitKey(10);
//         if (ch == 27) break;
//         else if (ch == 'C' || ch == 'c') mat.setTo(Scalar(255));
//         else if (ch == 'S' || ch == 's') {
//             mat2.setTo(Scalar(0));
//             for (int y = 0; y < mat2.rows; y++) {
//                 for (int x = 0; x < mat2.cols; x++) {
//                     int cnt = 0;
//                     for (int yy = y*8; yy < y*8+8; yy++) {
//                         for (int xx = x*8; xx < x*8+8; xx++) {
//                             if (idata[yy*mat.cols + xx] == 0) cnt++;
//                         }
//                     }
//                     idata2[y*mat2.cols + x] = min(255, cnt*4);
//                 }
//             }
//             sprintf(filename, "%s/A_%05d.png", path.c_str(), num_label++);
//             imwrite(filename, mat2, compression_params);
//         }
//     }

//     return 0;
// }