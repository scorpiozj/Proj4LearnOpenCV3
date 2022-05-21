#include <opencv2/opencv.hpp>
using namespace cv;
int main (int argc, char*argv[]){

    Mat img = imread(argv[1], IMREAD_ANYCOLOR);
    if(img.empty()) return -1;
    namedWindow("Example1", WINDOW_NORMAL);
    imshow("Example1", img);
    waitKey(0);
    destroyWindow("Example1");
    return 0;
}

/*
clang -x c++ -target arm64-apple-macos12.3 ex01Image.cpp  -o ex01 -I /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

*/