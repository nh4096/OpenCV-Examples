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

void point_example_1()
{
    Point2d p(3, 4);
    cout << p << endl;
    Point3d q(3, 4, 5);
    cout << q << endl;
}

int main()
{
    //mat_example_1();
    //mat_example_2();
    //mat_example_3();
    point_example_1();
}