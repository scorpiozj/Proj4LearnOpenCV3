#include <opencv2/opencv.hpp>

/**
 * @brief 
 * convert image from one color space to another;
 * detect edge using Canny;
 * 
 * 
 */

int main(int argc, char **argv)
{
    cv::Mat img_rgb, img_gry, img_cny;
    cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);
    img_rgb = cv::imread(argv[1]);
    cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::imshow("Example Gray", img_gry);
    cv::Canny(img_gry, img_cny, 10, 100, 3, true);
    cv::imshow("Example Canny", img_cny);
    cv::waitKey(0);
}

/*

clang -x c++ -target arm64-apple-macos12.3 ex07.cpp  -o ex07  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

*/