// VisionLab1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "CGrabber.h"

using namespace std;
using namespace cv;

int main()
{
	// ** IMPORTANT **
	// x = B
	// y = G
	// z = R

	//Mat img = imread("red.png");
	
	//effective looping see: https://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html#a952ef1a85d70a510240cb645a90efc0d
	/*for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			std::cout << (int)img.at<Vec3b>(i, j)[0] << " " << (int)img.at<Vec3b>(i, j)[1] << " " << (int)img.at<Vec3b>(i, j)[2] << std::endl;	
	imshow("image", img);
	waitKey(0);*/
	////grayscale
	//Mat imgGray = imread("lena.png", 0);
	//for (int i = 0; i < imgGray.rows; i++)
	//	for (int j = 0; j < imgGray.cols; j++)
	//		std::cout << (int)imgGray.at<uchar>(j, i) << std::endl;
	//
	//imshow("image", imgGray);

	//Mat procImg = imread("lena.png");
	//Mat procImgGray;

	//cvtColor(procImg, procImgGray, CV_RGB2GRAY);
	//imshow("image", procImgGray);

	// Show camera https://docs.opencv.org/3.0-beta/modules/videoio/doc/reading_and_writing_video.html
	CGrabber grab;

	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;
	
	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
					  //cvtColor(frame, edges, COLOR_BGR2GRAY);
					  //GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
					  //Canny(edges, edges, 0, 30, 3);
					  //imshow("edges", edges);
					
		imshow("edges", frame);
		
		//grab.getColor(frame);
		grab.getHSV(frame);
		if (waitKey(30) >= 0) break;	
	
	}
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
