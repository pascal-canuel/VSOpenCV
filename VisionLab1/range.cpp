#include "pch.h"
#include "range.h"

range::range(cv::Scalar pMinScalar, cv::Scalar pMaxScalar, cv::Scalar pBgrScalar) {
	minScalar = pMinScalar;
	maxScalar = pMaxScalar;
	bgrScalar = pBgrScalar;
}
