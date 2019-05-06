/*************************************************************************
						   Capteur  -  description
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

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
double Capteur::getLongitude()
// Algorithme :
//
{
	return longitude;
} //----- Fin de getLongitude

double Capteur::getLatitude()
// Algorithme :
//
{
	return latitude;
} //----- Fin de getLatitude


//------------------------------------------------- Surcharge d'opérateurs
/*Capteur & Capteur::operator = (const Capteur &unCapteur)
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Capteur::Capteur(const Capteur &unCapteur)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Capteur>" << endl;
#endif
} //----- Fin de Capteur (constructeur de copie)
*/


Capteur::Capteur(string sensor, double lat, double longi, string descri)
// Algorithme :
//
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
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
