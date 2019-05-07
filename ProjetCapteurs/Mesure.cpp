/***********************************************************************************************************************************
						   Mesure  -  description
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/


//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <math.h>
//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
double Mesure::getValue()
// Algorithme :
//
{
	return value;
} //----- Fin de Méthode

string Mesure::getSensorID()
// Algorithme :
//
{
	return sensorID;
} //----- Fin de Méthode


int Mesure::getAnnee()
// Algorithme :
//
{
	return annee;
} //----- Fin de Méthode

int Mesure::getMois()
// Algorithme :
//
{
	return mois;
} //----- Fin de Méthode

int Mesure::getJour()
// Algorithme :
//
{
	return jour;
} //----- Fin de Méthode

int Mesure::getHeure()
// Algorithme :
//
{
	return heure;
} //----- Fin de Méthode

int Mesure::getMinute()
// Algorithme :
//
{
	return minute;
} //----- Fin de Méthode

double Mesure::getSeconde()
// Algorithme :
//
{
	return seconde;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/*Mesure & Mesure::operator = (const Mesure &unMesure)
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*Mesure::Mesure(const Mesure &unMesure)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Mesure>" << endl;
#endif
} //----- Fin de Mesure (constructeur de copie)
*/


Mesure::Mesure(string time, double val,string sensor)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
	value = val;
	sensorID = sensor;

	 annee = atoi(time.substr(0, 4).c_str());
	 mois = atoi(time.substr(5, 2).c_str());
	 jour = atoi(time.substr(8, 2).c_str());

	 heure = atoi(time.substr(11, 2).c_str());
	 minute = atoi(time.substr(13, 2).c_str());
	 seconde = stod(time.substr(15, 7).c_str());
} //----- Fin de Mesure


Mesure::~Mesure()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
