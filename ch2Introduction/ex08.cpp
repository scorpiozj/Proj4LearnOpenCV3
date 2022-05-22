#include <opencv2/opencv.hpp>

/**
 * @brief pipeline: pyrdown twice; Canny detect;
 * 
 * 
 */

using namespace cv;

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
}

