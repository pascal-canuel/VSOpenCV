#include "pch.h"
#include "CGrabber.h"
#include "range.h"

CGrabber::CGrabber(void) {
	iLowH = 0;
	iHighH = 179;

	iLowS = 0;
	iHighS = 255;

	iLowV = 0;
	iHighV = 255;

	cout << "Loaded" << endl;
}

//	Hue values range 
//	Orange  0 - 22
//	Yellow 22 - 38
//	Green 38 - 75
//	Blue 75 - 130
//	Violet 130 - 160
//	Red 160 - 179
void CGrabber::getHSV(Mat pFrame) {
	Mat hsvFrame;
	cvtColor(pFrame, hsvFrame, COLOR_BGR2HSV);

	bool isColor = false;


	vector<range> colorToDetect;
	vector<range>::iterator it;

	it = colorToDetect.begin();
	it = colorToDetect.insert(it, range(38, 75));	//	Green
	it = colorToDetect.insert(it, range(76, 130));	//	Blue
	it = colorToDetect.insert(it, range(160, 179)); //	Red

	for (int y = 0; y < pFrame.rows; y++) {
		for (int x = 0; x < pFrame.cols; x++) {		
			Vec3b hsvPix = hsvFrame.at<Vec3b>(y, x);
			Vec3b *pix = &pFrame.at<Vec3b>(y , x);

			int hue = (int)hsvPix.val[0];		
			
			for (it = colorToDetect.begin(); it < colorToDetect.end(); it++) {
				if (it->min < hue && hue < it->max) {
					isColor = true;
				}		
			}	
			if (!isColor) {
				pix->val[0] = 0;
				pix->val[1] = 0;
				pix->val[2] = 0;
			}
			else
				isColor = false;
		}
	}

	imshow("ColorView", pFrame);
}
