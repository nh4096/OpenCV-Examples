#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void mat_example_1()
{
    Mat a = Mat(8, 8, CV_32F);
    
    // reference
    Mat b = a;
    assert(b.data == a.data);

    // duplicate
    Mat c = a.clone();
    assert(c.data != a.data);

    b.release();
    // assert(a.data == nullptr); FALSE!
}

void mat_example_2()
{
    Mat img = Mat(Size(800, 600), CV_8UC3);
    Mat out;
    cvtColor(img, out, COLOR_BGR2GRAY);
    //assert(out.channels == 1 && img.channels == 1 && out.type==img.type);
}

void mat_example_3()
{
    vector<float> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    Mat m = Mat(v);
    cout << m.rows <<","<< m.cols << endl;
    cout << m <<endl;
}

void mat_example_4()
{
    Mat a = Mat::ones(Size(8, 8), CV_8U) * 255;
    Mat roi = Mat(a, Rect(2, 2, 4, 4));
    roi = 0;
    cout << a << endl;
    //Mat ar = a.row(2);
    //ar = Scalar(0);    
    //a.col(6) = Scalar(2);
}

void mat_example_5()
{
    Mat m(4, 4, CV_8UC3, Scalar(192, 192, 64));
    cout << m << endl;
}

void mat_example_6()
{
    CV_8UC(0);
}
void point_example_1()
{
    Point2d p(3, 4);
    cout << p << endl;
    Point3d q(3, 4, 5);
    cout << q << endl;
}

void scalar_example_1()
{
    Scalar a = Scalar(2.5); // (2.5,0,0,0)
    Scalar b = Scalar(1.5, 2.5, 3.5, 4.5);
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    //mat_example_1();
    //mat_example_2();
    //mat_example_3();
    //mat_example_4();
    mat_example_5();
    //point_example_1();
    //scalar_example_1();
}