#include <opencv2/opencv.hpp>

/**
 * @brief pipeline: pyrdown twice; Canny detect;
 *
 *
 */

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat img_rgb, img_gry, img_cny;
    namedWindow("Example Gray", WINDOW_AUTOSIZE);
    namedWindow("Example Canny", WINDOW_AUTOSIZE);
    img_rgb = imread(argv[1]);
    cvtColor(img_rgb, img_gry, COLOR_BGR2GRAY);
    imshow("Example Gray", img_gry);

    

    Mat img_pry, img_pry2;
    pyrDown(img_gry, img_pry);
    pyrDown(img_pry, img_pry2);

    Canny(img_pry2, img_cny, 10, 100, 3, true);
    imshow("Example Canny", img_cny);
    waitKey(0);

    // example-09: getting and setting pixels;
    int x = 16, y = 32;
    Vec3b intensity = img_rgb.at<Vec3b>(y, x);
    uchar blue = intensity[0];
    uchar green = intensity[1];
    uchar red = intensity[2];
    cout << "At (x,y) = (" << x << ", " << y << "): (blue, green, red) = (" << (unsigned int)blue << ", " << (unsigned int)green << ", " << (unsigned int)red << ")" << endl;
    cout << "Gray pixel there is: " << (unsigned int)img_gry.at<uchar>(y, x) << endl;
    x /= 4;
    y /= 4;
    cout << "Pyramid2 pixel there is: " << (unsigned int)img_pry2.at<uchar>(y, x) << endl;
    img_cny.at<uchar>(x, y) = 128; // Set the Canny pixel there to 128
    waitKey(0);
    
    return 0;
}
/*

clang -x c++ -target arm64-apple-macos12.3 ex08.cpp  -o ex08  -I/Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/include/opencv4 -std=gnu++11 -L /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lstdc++ -L'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib' -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/pkgs/libopencv-4.5.5-py39h4853228_6/lib -Xlinker -rpath -Xlinker /Users/scorpiozj/miniforge3/envs/cv/lib

*/