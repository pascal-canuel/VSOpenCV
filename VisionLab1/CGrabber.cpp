#include "pch.h"
#include "CGrabber.h"

// Member functions definitions including constructor
CGrabber::CGrabber(void) {
	cout << "Loaded" << endl;
}
void CGrabber::setColor(Mat pColor) {
	_color = pColor;
}
void CGrabber::getColor(Mat pColor) {
	// Check if red is present in the picture
	bool isRed = false; 
	

	for (int i = 0; i < pColor.rows; i++) {
		for (int j = 0; j < pColor.cols; j++) {
			if ((int)pColor.at<Vec3b>(i, j)[2] > 100 && (int)pColor.at<Vec3b>(i, j)[1] < 40 && (int)pColor.at<Vec3b>(i, j)[0] < 40) {
				isRed = true;
			}
			else {
				pColor.at<Vec3b>(i, j)[2] = 0;
				pColor.at<Vec3b>(i, j)[1] = 0;
				pColor.at<Vec3b>(i, j)[0] = 0;
			}
		}	
	}
	
	//std::cout << (int)pColor.at<Vec3b>(i, j)[0] << " " << (int)pColor.at<Vec3b>(i, j)[1] << " " << (int)pColor.at<Vec3b>(i, j)[2] << std::endl;
	if (isRed) {
		cout << "Red!";

		imshow("its red looolll", pColor);
	}
}

void CGrabber::getHSV(Mat pColor) {
	Mat hsv;
	cvtColor(pColor, hsv, COLOR_BGR2HSV);
	bool isRed = false;

	for (int i = 0; i < hsv.rows; i++) {
		for (int j = 0; j < hsv.cols; j++) {
			if ((int)hsv.at<Vec3b>(i, j)[0] > 160 || (int)hsv.at<Vec3b>(i, j)[0] < 5) {
				isRed = true;
			}				
			else {
				pColor.at<Vec3b>(i, j)[2] = 0;
				pColor.at<Vec3b>(i, j)[1] = 0;
				pColor.at<Vec3b>(i, j)[0] = 0;
			}
		}
	}

	if (isRed) {
		cout << "";

		imshow("Color detected", pColor);
	}
}

