#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void usage(const string& prog)
{
    cout
        << "----------------------------------------------------------------" << endl
        << " Usage: " << prog << " <in_image> <out_image>" << endl
        << "         in_image: Input image file" << endl
        << "         out_image: Output image file" << endl
        << "----------------------------------------------------------------" << endl;
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        usage(argv[0]);
        return -1;
    }
    
    cout << "Loading image" << endl;
    Mat input = imread(argv[1], IMREAD_COLOR); // Read the file
    if (input.empty()) // Check for invalid input
    {
        cout << "Could not open the image" << endl;
        return -1;
    }

    // cout << "shape (w,h): " << input.cols << "," << input.rows << endl;

    namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("Display window", input); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window

    cout << "Detecting edges" << endl;
    Mat edges;
    Canny(input, edges, 10, 100, 3, false);

    imwrite(argv[2], edges);
    namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("Display window", edges); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window

    return 0;
}
