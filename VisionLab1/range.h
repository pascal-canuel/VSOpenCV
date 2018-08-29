#pragma once
#include <opencv2/opencv.hpp>

class range {
public:
	cv::Scalar minScalar;
	cv::Scalar maxScalar;
	cv::Scalar bgrScalar;
	
	range(cv::Scalar pMinScalar, cv::Scalar pMaxScalar, cv::Scalar pBgrScalar);
};