// VisionLab1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("lena.png");
	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			std::cout << img.at<cv::Vec3b>(i, j)[0] << " " << img.at<cv::Vec3b>(i, j)[1] << " " << img.at<cv::Vec3b>(i, j)[2] << std::endl;

	//grayscale
	img = imread("lena.png", 0);
	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			std::cout << img.at<uchar>(i, j) << std::endl;

	imshow("image", img);
	waitKey(0);
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
