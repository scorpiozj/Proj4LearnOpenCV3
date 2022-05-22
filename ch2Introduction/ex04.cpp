#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

int g_slide_position = 0;
int g_run = 1, g_dontset = 0;
VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
    g_cap.set(CAP_PROP_POS_FRAMES, pos);
    if(!g_dontset) {
        g_run = 1;
    }
    g_dontset = 0;
}

int main (int argc, char*argv[]){

    namedWindow("Example2_4", WINDOW_AUTOSIZE);

    g_cap.open(argv[1], 0);
    int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
    int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
    int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "Video has " << frames << " frames of dimensions(" << tmpw << ", " << tmph << ")." << endl;

    createTrackbar("position", "Example2_4", &g_slide_position, frames, onTrackbarSlide);

    Mat frame;
    for (;;) {

        if(g_run != 0) {
            g_cap >> frame;
            if(frame.empty()) break;
            int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            setTrackbarPos("position", "Example2_4", current_pos);
            imshow("Example2_4", frame);

            g_run = -1;
        }

        char c = (char)waitKey(10);
        if(c == 's') {
            g_run = 1;
            cout << "Single Step, run = "<< g_run << endl;
        }else if ( c == 'r') {
            g_run = -1;
            cout << "Run mode, run = "<< g_run << endl;
        }else if( c == 27){
            break;
        }  
    }
    return 0;
}

/*

clang -x c++ -target arm64-apple-macos12.3 ex04.cpp  -o ex04  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_videoio -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

*/