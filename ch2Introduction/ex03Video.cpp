#include <opencv2/opencv.hpp>

using namespace cv;

int main (int argc, char*argv[]){

    namedWindow("Example3", WINDOW_NORMAL);
    VideoCapture cap;
    // cap.open(String(argv[1]));
    cap.open(argv[1], 0);

    Mat frame;
    for (;;) {
        cap >> frame;
        if (frame.empty()) break;
        imshow("Example3", frame);
        if (waitKey(33) >= 0)   // wait for any key pressed event;
        {
            break;
        }   
    }
    return 0;
}

/*
clang -x c++ -target arm64-apple-macos12.3 ex03Video.cpp  -o ex03  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

clang -x c++ -target arm64-apple-macos12.3 ex03Video.cpp  -o ex03  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_videoio -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

*/