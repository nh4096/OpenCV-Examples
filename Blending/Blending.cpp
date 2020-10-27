#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	const String cmdkeys =
		"{help h ? |          | print this message           }"
		"{alpha a  | 0.5      | image1 weight  [0.0..1.0]    }"
		"{@image1  | <none>   | image 1                      }"
		"{@image2  | <none>   | image 2                      }";
	CommandLineParser parser(argc, argv, cmdkeys);
	parser.about("Linear transform tool");

	// found args like --help
	if (parser.has("help"))
	{
		parser.printMessage();
		return 0;
	}

	// found errors
	if (!parser.check())
	{
		parser.printErrors();
		return 1;
	}

	// parse
	float alpha = parser.get<float>("alpha");
	String infile1 = parser.get<String>(0);
	String infile2 = parser.get<String>(1);

	Mat image1 = imread(infile1, IMREAD_COLOR);
	if (image1.empty()) {
		cout << "Cannot read from file: " << image1 << endl;
		return EXIT_FAILURE;
	}
	Mat image2 = imread(infile2, IMREAD_COLOR);
	if (image2.empty()) {
		cout << "Cannot read from file: " << image2 << endl;
		return EXIT_FAILURE;
	}


	// check
	CV_Assert(alpha >= 0 && alpha <= 1.0);
	CV_Assert(image1.rows == image2.rows && image1.cols == image2.cols);

	// blending
	Mat out;
	addWeighted(image1, alpha, image2, 1.0 - alpha, 0.0, out);

	imshow("blended",out);
	waitKey(0);

	return 0;
}