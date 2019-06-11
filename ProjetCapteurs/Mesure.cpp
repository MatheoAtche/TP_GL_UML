/***********************************************************************************************************************************
						   Mesure  -  Cette classe modelise une mesure
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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
double Mesure::getValue()
{
	return value;
} //----- Fin de getValue

string Mesure::getSensorID()
{
	return sensorID;
} //----- Fin de getSensorID


string Mesure::getDate()
{
	return date;
} //----- Fin de getDate

int Mesure::getAnnee()
{
	return annee;
} //----- Fin de getAnnee


Mesure::Mesure(string time, double val,string sensor)
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
	value = val;
	sensorID = sensor;
	date = time;
	annee = atoi(time.substr(0, 4).c_str());

} //----- Fin de Mesure


Mesure::~Mesure()
// Algorithme :
//
{
	
#ifdef MAP
	cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure

