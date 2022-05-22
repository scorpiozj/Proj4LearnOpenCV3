#include <opencv2/opencv.hpp>

/**
 * @brief how to use x-Blur funcs;
 * 
 */

using namespace cv;

void example2_5(const Mat &image) {
    namedWindow("Example2_5-in", WINDOW_AUTOSIZE);
    namedWindow("Example2_5-out", WINDOW_AUTOSIZE);

    imshow("Example2_5-in", image);

    Mat out;
    GaussianBlur(image, out, Size(15,15), 3, 3);// size: must be odd;
    GaussianBlur(out, out, Size(15,15), 3, 3);

    imshow("Example2_5-out", out);

    waitKey(0);
}


int main (int argc, char*argv[]){

    Mat img = imread(argv[1], IMREAD_ANYCOLOR);
    if(img.empty()) return -1;

    example2_5(img);

    return 0;
}

/*

clang -x c++ -target arm64-apple-macos12.3 ex05.cpp  -o ex05  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

*/