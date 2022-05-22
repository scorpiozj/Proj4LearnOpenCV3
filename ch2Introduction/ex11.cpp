#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    namedWindow("Example2_11", WINDOW_AUTOSIZE);
    namedWindow("Log_Polar", WINDOW_AUTOSIZE);
    // ( Note: could capture from a camera by giving a camera id as an int.)
    //
    VideoCapture capture(argv[1]);
    double fps = capture.get(CAP_PROP_FPS);
    Size size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter writer;
    bool result = writer.open(argv[2], CAP_FFMPEG, fps, size); // CV_FOURCC('M', 'J', 'P', 'G')
    cout << "result is " << result << endl;
    Mat logpolar_frame, bgr_frame;
    for (;;)
    {
        capture >> bgr_frame;
        if (bgr_frame.empty())
            break; // end if done
        imshow("Example2_11", bgr_frame);

        logPolar(
            bgr_frame,
            logpolar_frame,
            Point2f(
                bgr_frame.cols / 2,
                bgr_frame.rows / 2),
            40,
            WARP_FILL_OUTLIERS);
        // Input color frame
        // Output log-polar frame
        // Centerpoint for log-polar transformation //x
        // y
        // Magnitude (scale parameter)
        // Fill outliers with 'zero'
        imshow("Log_Polar", logpolar_frame);
        writer << logpolar_frame;
        char c = waitKey(10);
        if (c == 27)
        {
            break;
        }
    }

    capture.release();
}
/*
clang -x c++ -target arm64-apple-macos12.3 ex11.cpp  -o ex11  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib
*/


