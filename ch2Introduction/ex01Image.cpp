#include <opencv2/opencv.hpp>

int main (int argc, char*argv[]){

    cv::Mat img = cv::imread(argv[1], cv::IMREAD_ANYCOLOR);
    if(img.empty()) return -1;
    cv::namedWindow("Example1", cv::WINDOW_NORMAL);
    cv::imshow("Example1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
    return 0;
}

