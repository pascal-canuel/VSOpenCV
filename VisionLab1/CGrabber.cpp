#include "pch.h"
#include "CGrabber.h"
#include "range.h"
#include <map>

RNG rng(12345);
// Links 
//	https://docs.opencv.org/3.4/d5/d69/tutorial_py_non_local_means.html
// https://docs.opencv.org/3.4/da/d97/tutorial_threshold_inRange.html
// https://www.opencv-srf.com/2010/09/object-detection-using-color-seperation.html

CGrabber::CGrabber(Mat pColor) {
	iLowH = 0;
	iHighH = 179;

	iLowS = 0;
	iHighS = 255;

	iLowV = 0;
	iHighV = 255;

	initFrame = pColor;

	std::cout << "Loaded" << std::endl;
}

//	Hue values range 
//	Orange  0 - 22
//	Yellow 22 - 38
//	Green 38 - 75
//	Blue 75 - 130
//	Violet 130 - 160
//	Red 160 - 179
void CGrabber::getHSV() {
	Mat3b hsv;
	cvtColor(initFrame, hsv, COLOR_BGR2HSV);

	std::vector<range> colorToDetect;
	std::vector<range>::iterator it;

	it = colorToDetect.begin();
	//it = colorToDetect.insert(it, range(Scalar(0, 70, 50), Scalar(10, 255, 255), Scalar(0, 0, 255)));		//	Red
	it = colorToDetect.insert(it, range(Scalar(160, 70, 50), Scalar(180, 255, 255), Scalar(0, 0, 255)));	//	Red
	//it = colorToDetect.insert(it, range(Scalar(22, 70, 50), Scalar(37, 255, 255), Scalar(0, 255, 255)));	//	Yellow
	//it = colorToDetect.insert(it, range(Scalar(38, 70, 50), Scalar(75, 255, 255), Scalar(0, 255, 0)));		//	Green
	//it = colorToDetect.insert(it, range(Scalar(75, 70, 50), Scalar(130, 255, 255), Scalar(255, 0, 0)));		//	Blue

	Mat result, drawingResult;
	for (it = colorToDetect.begin(); it < colorToDetect.end(); it++) {
	
		Mat binary;
		Mat colored;
		std::tie(binary, colored) = drawColorScalar(it);
		if (it == colorToDetect.begin())
		{
			result = binary;
			drawingResult = colored;
		}
		else
		{
			result = result | binary;
			drawingResult = drawingResult | colored;
		}
	}

	namedWindow("Threshed", WINDOW_NORMAL);
	resizeWindow("Threshed", 700, 500);
	imshow("Threshed", result);
	
	namedWindow("Contours");
	imshow("Contours", drawingResult);
}

std::tuple<cv::Mat, cv::Mat> CGrabber::drawColorScalar(std::vector<range>::iterator pIt)
{
	Mat currentFrame;
	inRange(initFrame, pIt->minScalar, pIt->maxScalar, currentFrame);
	
	//	Make object more intense
	erode(currentFrame, currentFrame, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	dilate(currentFrame, currentFrame, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	//	Remove small holes from the background
	dilate(currentFrame, currentFrame, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	erode(currentFrame, currentFrame, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	std::vector<Vec4i> hierarchy;
	std::vector<std::vector<Point> > contours;
	findContours(currentFrame, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	Mat drawing = Mat::zeros(currentFrame.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{		
		drawContours(drawing, contours, i, pIt->bgrScalar, 2, 8, hierarchy, 0, Point());
	}

	return std::pair<Mat, Mat>(currentFrame, drawing);
}