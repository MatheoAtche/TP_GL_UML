/*************************************************************************
						   Capteur  -  Cette classe modélise un capteur 
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
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

