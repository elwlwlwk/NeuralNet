
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

#include "NeuralNet.h"

#ifdef __DEBUG__

#define Mat vector<double>

#endif

class MyImage{

public:
	Mat Image;
	Mat Result;

	void ImageProc();
	MyImage(char* ImageSrc);

};