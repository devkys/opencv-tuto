#include "opencv2/videoio.hpp"
#include "opencv2/opencv.hpp"
#include <cstdlib>
#include <unistd.h>

using namespace std;
using namespace cv;

int main()
{
  VideoCapture cap(0);
  if (!cap.isOpened()) return -1;

  Mat cut_frame;
  while (1) {
    Mat frame;
    cap >> frame;
   
    if (!frame.empty()) {
      int width = frame.cols;
      int height = frame.rows;
      Point pt(60,60);
      int length = min(width, height);     
      if (width < height) pt.y += (height - length) / 2;
      else pt.x += (width - length) / 2;
      Scalar green(0, 255, 0);  //BGR

      length -= 120;
      Rect r(pt.x, pt.y, length, length);
      rectangle(frame, r, green, 4);
      imshow("view", frame);

      char ch = waitKey(10);
      if (ch == 27) break;       // 27 == ESC key
      if (ch == 32)                // 32 == SPACE key
      {
        Mat mid_frame = frame(r);
        resize(mid_frame, cut_frame, Size(32, 32));

        imshow("cut", cut_frame);
        vector<int> flags;
        flags.push_back(IMWRITE_PNG_COMPRESSION);
        flags.push_back(0);

        char* cwd = getcwd(0, 0); 
        char filename[1024];
        time_t t = time(0);   // get time now
        tm *now = localtime(&t);
       
        sprintf(filename, "%s/%02d%02d%02d%02d%05d.png", "/Users/kyeongseo/Desktop/cifar10", now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec, rand()%10000+1);
        free(cwd);

        imwrite(filename, cut_frame, flags);
      }
    }
  }

  return 0;
}
