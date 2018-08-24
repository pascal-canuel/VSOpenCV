#pragma once
#include "pch.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


class CGrabber {
public:
	void setColor(Mat pColor);
	void getColor(Mat pColor);
	CGrabber();  // This is the constructor
private:
	Mat _color;
	int _nbImage;
};