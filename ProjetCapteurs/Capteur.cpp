/*************************************************************************
						   Capteur  -  Cette classe mod�lise un capteur 
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/

//---------- R�alisation de la classe <Capteur> (fichier Capteur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
double Capteur::getLongitude()
{
	return longitude;
} //----- Fin de getLongitude

double Capteur::getLatitude()
{
	return latitude;
} //----- Fin de getLatitude


Capteur::Capteur(string sensor, double lat, double longi, string descri)
{
#ifdef MAP
	cout << "Appel au constructeur de <Capteur>" << endl;
#endif
	sensorID = sensor;
	latitude = lat;
	longitude = longi;
	descrption = descri;

} //----- Fin de Capteur


Capteur::~Capteur()
{
#ifdef MAP
	cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur

