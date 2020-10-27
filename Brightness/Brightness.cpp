#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	const String cmdkeys =
		"{help h ? |          | print this message           }"
		"{alpha a  | 1.0      | gain (contrast)  [1.0..3.0]  }"
		"{beta b   | 0.0      | bias (brightness) [0..100]   }"
		"{@image1  | <none>   | input image                  }"
		"{@image2  | <none>   | output image                 }";
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

	// parse args
	String infile = parser.get<String>(0);
	String outfile = parser.get<String>(1);
	float alpha = parser.get<float>("alpha");
	float beta = parser.get<float>("beta");

	// load input image
	Mat image = imread(infile, IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Cannot read from file: " << infile << endl;
		return -1;
	}

	// perform linear transform
	Mat out = Mat::zeros(image.size(), image.type());
	const int nchan = image.channels();
	for (int y = 0; y < image.rows; ++y) {
		for (int x = 0; x < image.cols; ++x) {
			for (int c = 0; c < nchan; ++c) {
				float p = image.at<Vec3b>(y, x)[c];
				float q = alpha * p + beta;
				out.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(q);
			}
		}
	}

	// save output image
	imwrite(outfile, out);
	return 0;
}
