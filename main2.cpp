// #include <opencv2/opencv.hpp>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <dirent.h>
// #include <string>
// #include <vector>
// #include <fstream>

// using namespace cv;
// using namespace std;

// unsigned int swap_endian(unsigned int val)
// {
//     val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
//     return (val << 16) | (val >> 16);
// }

// int main()
// {
//     DIR *dp;
//     int a_cnt(0);
    
//     string path = "/Users/kyeongseo/work/mnist/A";
//     string data_path = "/Users/kyeongseo/work/emnist/archive/emnist_source_files/";
//     struct stat sb = {0};
//     dirent* dirp;
//     if (stat(path.c_str(), &sb) == -1) mkdir(path.c_str(), 0700);
//     else {
//         dp = opendir(path.c_str());
//         while((dirp = readdir(dp)) != NULL) {
//             string fname = string(dirp->d_name);
//             if (fname == "." || fname == "..") continue;
//             a_cnt++;
//         }
//         closedir(dp);
//         cout << a_cnt << " files exist." << endl;
//     }

//     string image_name[6] = {"emnist-balanced-train-images-idx3-ubyte",
//         "emnist-balanced-test-images-idx3-ubyte",
//         "emnist-byclass-train-images-idx3-ubyte",
//         "emnist-byclass-test-images-idx3-ubyte",
//         "emnist-bymerge-train-images-idx3-ubyte",
//         "emnist-bymerge-test-images-idx3-ubyte"};
//     string label_name[6] = {"emnist-balanced-train-labels-idx1-ubyte",
//         "emnist-balanced-test-labels-idx1-ubyte",
//         "emnist-byclass-train-labels-idx1-ubyte",
//         "emnist-byclass-test-labels-idx1-ubyte",
//         "emnist-bymerge-train-labels-idx1-ubyte",
//         "emnist-bymerge-test-labels-idx1-ubyte"};

//     char filename[128];
//     int i;
//     for (i = 0; i < 6; i++) {
//         ifstream image_file(data_path+image_name[i], ios::in | ios::binary);
//         ifstream label_file(data_path+label_name[i], ios::in | ios::binary);

//         if (!image_file.is_open()) {
//             cout << "Unable to open file " << image_name[i] << endl;
//             return -1;
//         }

//         if (!label_file.is_open()) {
//             cout << "Unable to open file " << label_name[i] << endl;
//             return -1;            
//         }

//         unsigned int head;
//         image_file.read(reinterpret_cast<char*>(&head), 4);
//         head = swap_endian(head);
//         if (head != 2051) {
//             cout << "Incorrect image file header." << endl;
//             return -1;
//         }

//         int num_items, rows, cols, l_cnt(0);
//         image_file.read(reinterpret_cast<char*>(&num_items), 4);
//         num_items = swap_endian(num_items);
//         image_file.read(reinterpret_cast<char*>(&rows), 4);
//         rows = swap_endian(rows);
//         image_file.read(reinterpret_cast<char*>(&cols), 4);
//         cols = swap_endian(cols);

//         label_file.read(reinterpret_cast<char*>(&head), 4);
//         head = swap_endian(head);
//         if (head != 2049) {
//             cout << "Incorrect image file header." << endl;
//             return -1;
//         }

//         int num_labels;
//         label_file.read(reinterpret_cast<char*>(&num_labels), 4);
//         num_labels = swap_endian(num_labels);
//         if (num_items != num_labels) {
//             cout << "Invalid data." << endl;
//             return -1;
//         }

//         Mat mat(rows, cols, CV_8UC1);
//         Mat rot;
//         unsigned char* pixels = mat.data;
//         char label;
//         vector<int> compression_params;
//         compression_params.push_back(IMWRITE_PNG_COMPRESSION);
//         compression_params.push_back(0);
//         while(num_items--) {
//             image_file.read(reinterpret_cast<char*>(pixels), rows*cols);
//             label_file.read(&label, 1);

//             if (label != 10 || a_cnt > 6999) continue;

//             rotate(mat, rot, ROTATE_90_CLOCKWISE);

//             sprintf(filename, "%s/A_%05d.png", path.c_str(), a_cnt++);
//             imwrite(filename, rot, compression_params);
//             l_cnt++;
//         }

//         cout << image_name[i] << " = " << l_cnt << " files copied" << endl;
//     }

//     cout << "label A = " << a_cnt << endl;

//     return 0;
// }