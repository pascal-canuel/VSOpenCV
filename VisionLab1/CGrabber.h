#pragma once
#include "pch.h"
#include "range.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class CGrabber {
public:
	void getHSV(cv::Mat pFrame);
	CGrabber();  // This is the constructor
private:
	std::tuple<cv::Mat, cv::Mat> drawColorScalar(std::vector<range>::iterator pIt);

	cv::Mat initFrame;
	cv::Mat hsvFrame;

	int iLowH;
	int iHighH;

	int iLowS;
	int iHighS;

	int iLowV;
	int iHighV;
};
