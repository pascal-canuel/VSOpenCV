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

	// Show camera https://docs.opencv.org/3.0-beta/modules/videoio/doc/reading_and_writing_video.html
	CGrabber grab;

	VideoCapture cap(0); 
	if (!cap.isOpened()) 
	{
		cout << "The camera is not opened" << endl;
		return -1;
	}
	
	Mat frame;
	namedWindow("CamView", 1);
	while (true)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
			
		imshow("CamView", frame);
	
		grab.getHSV(frame);
		if (waitKey(30) >= 0) break; // Quit if key entered		
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
