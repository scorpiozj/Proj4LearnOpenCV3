#include <opencv2/opencv.hpp>

/**
 * @brief down-scaling, image pyramid;
 * 
 */

using namespace cv;

void example2_5(const Mat &image) {
    namedWindow("Example2_6-in", WINDOW_AUTOSIZE);
    namedWindow("Example2_6-out", WINDOW_AUTOSIZE);

    imshow("Example2_5-in", image);

    Mat image2;
    pyrDown(image, image2);

    imshow("Example2_6-out", image2);

    waitKey(0);
}


int main (int argc, char*argv[]){

    Mat img = imread(argv[1], IMREAD_ANYCOLOR);
    if(img.empty()) return -1;

    example2_5(img);

    return 0;
}

/*

clang -x c++ -target arm64-apple-macos12.3 ex06.cpp  -o ex06  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

*/