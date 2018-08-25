#pragma once
#include "pch.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


class CGrabber {
public:
	void getHSV(Mat pFrame);
	CGrabber();  // This is the constructor
private:
	int iLowH;
	int iHighH;

	int iLowS;
	int iHighS;

	int iLowV;
	int iHighV;
};