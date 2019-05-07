/***********************************************************************************************************************************
						   Mesure  -  description
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/


//---------- R�alisation de la classe <Mesure> (fichier Mesure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <math.h>
//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
double Mesure::getValue()
// Algorithme :
//
{
	return value;
} //----- Fin de M�thode

string Mesure::getSensorID()
// Algorithme :
//
{
	return sensorID;
} //----- Fin de M�thode


int Mesure::getAnnee()
// Algorithme :
//
{
	return annee;
} //----- Fin de M�thode

int Mesure::getMois()
// Algorithme :
//
{
	return mois;
} //----- Fin de M�thode

int Mesure::getJour()
// Algorithme :
//
{
	return jour;
} //----- Fin de M�thode

int Mesure::getHeure()
// Algorithme :
//
{
	return heure;
} //----- Fin de M�thode

int Mesure::getMinute()
// Algorithme :
//
{
	return minute;
} //----- Fin de M�thode

double Mesure::getSeconde()
// Algorithme :
//
{
	return seconde;
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
