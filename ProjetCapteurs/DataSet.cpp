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
#include <sstream>
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

void DataSet::lireCapteurs(string nomFichier, map<string, Capteur>* tabCapteurs)
//
{

} //----- Fin de Méthode

void DataSet::lireComposantsAirs(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
//
{

	ifstream file(nomFichier.c_str(),ios::in);
	if (file) {

		//Si le fichier s'est bien ouvert...

		//On décortique la ligne
		string date;
		string idCapteur;
		string typeDonnee;
		string valeurMesure;


		//On récupère la première ligne
		string ligneFic;
		istringstream parcoursLigne;
		getline(file, ligneFic);

		while (!file.eof()) {

			//Récupération des informations de la ligne
			getline(file, ligneFic);
			parcoursLigne.str(ligneFic);
			getline(parcoursLigne,date,';');
			getline(parcoursLigne, idCapteur, ';');
			getline(parcoursLigne, typeDonnee, ';');
			getline(parcoursLigne, valeurMesure);

		}


		file.close();
	}


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
