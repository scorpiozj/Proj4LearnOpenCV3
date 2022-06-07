#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main (int argc, char*argv[]){
    //1
    //
    Point2f p1 = Point2f(3.2,2.3);
    float num = 2.33;
    Point2f p2 = Point2f();
    p2.x = num;
    p2.y = num;
    cout<< "p1: " << p1 <<", p2: "<<p2<<endl;
    //
    Point p3 = p1;
    cout<< "p3: " << p3 <<endl;
    Point2f p4 = Point2f(p3);
    cout<< "p4: " << p4 <<endl;
    // 注意 cvRound(2.5) = 2;
    cout<< cvRound(2.5)<<", "<< cvCeil(2.5) <<", "<<cvFloor(2.9)<<endl;
    //
    cout<<"Random num: " <<randu<uint16_t>()<<endl;
    cout<<"Random num: " <<randu<uint16_t>()<<endl;
    
    //2
    Matx33f matf1 = Matx33f();//Matx33f::eye();
    randu(matf1, 1, 3);
    cout<<"matf1: "<< matf1<<endl;
    cout<<matf1(1,2)<<";"<<matf1.row(1)<<endl;

    Vec3f vecf1 = Vec3f(1,2,3);
    cout<<"vecf1:"<<vecf1<<endl;

    // cout<<"multiplication:"<<vecf1.mul(matf1)<<endl;//build error

    //3
    Matx<int, 3,3> m33d = Matx<int, 3, 3>(1,2,3,4,5,6,7,8,9);
    cout<<"m33d: "<< m33d<<endl;
    Vec<int, 3> v3d = Vec<int, 3> (1,2,3);
    cout<<"v3d: "<< v3d<<endl;
    cout<<"product:"<<m33d * v3d<< endl;
    // v3d * m33d;
    // ((Matx<int,3,1>)v3d).mul(m33d);
    Matx<int, 3, 1> m31d = Matx<int, 3, 1>(v3d);
    cout<<"m31d:"<< m31d<<endl;
    cout<<m33d * m31d<<endl;;

    //helper functions
    char *buffer = (char *)malloc(100);
    cout<<buffer<<endl;
    cout<<(int*)buffer<<endl; //0x600003f1c070  
    char *buffer2 = alignPtr(buffer, 32);
    cout<<(int*)buffer2<<endl; //0x600003f1c080
    /*
    0xc070 % 32 = 16
    0xc080 % 32 = 0
    */
    
    
    return 0;
}

