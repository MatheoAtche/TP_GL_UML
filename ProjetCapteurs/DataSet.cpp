/*************************************************************************
						   DataSet  -  description
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/

//---------- Réalisation de la classe <DataSet> (fichier DataSet.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
//------------------------------------------------------ Include personnel
#include "DataSet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void DataSet::lireMesures(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
//
{

} //----- Fin de Méthode

void DataSet::lireCapteurs(string nomFichier, set<Capteur> * capteurs)
//
{

} //----- Fin de Méthode

void DataSet::lireComposantsAirs(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
//
{

	istream file(nomFichier,ios::in);
	//file.open(nomFichier);


} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
/*DataSet & DataSet::operator = (const DataSet &unDataSet)
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*DataSet::DataSet(const DataSet &unDataSet)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <DataSet>" << endl;
#endif
} //----- Fin de DataSet (constructeur de copie)
*/


DataSet::DataSet()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <DataSet>" << endl;
#endif

} //----- Fin de DataSet


DataSet::~DataSet()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <DataSet>" << endl;
#endif
} //----- Fin de ~DataSet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
