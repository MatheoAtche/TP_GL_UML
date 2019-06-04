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

// Algorithme :
// On ouvre puis on parcourt le fichier. 
// On identifie les donnees et on cree des mesures
//Qu on ajoute a notre composant de l air aproprie
void DataSet::lireMesures(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
//
{

	ifstream file(nomFichier.c_str(), ios::in);

	if (file.fail()) {

		cout << "Erreur lors de l'ouverture du fichier demande" << endl;
		return;

	}
	else if (file) {

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
			getline(parcoursLigne, date, ';');
			getline(parcoursLigne, idCapteur, ';');
			getline(parcoursLigne, typeDonnee, ';');
			getline(parcoursLigne, valeurMesure, ';');

			
			cout << "Date : " << date << endl;
			cout << "Capteur : " << idCapteur << endl;
			cout << "Type : " << typeDonnee << endl;
			cout << "Valeur : " << valeurMesure << endl;
			
			//On verifie que les donnees ne sont pas nulle
			if (date != "" && valeurMesure != "" && idCapteur != "" && typeDonnee != "") {

				Mesure * mesure = new Mesure(date, atof(valeurMesure.c_str()), idCapteur);

				if (typeDonnee == "O3") {
					o3->addMesure(mesure);
				}
				else if (typeDonnee == "SO2") {
					so2->addMesure(mesure);
				}
				else if (typeDonnee == "NO2") {
					no2->addMesure(mesure);
				}
				else if (typeDonnee == "PM10") {
					pm10->addMesure(mesure);
				}
				else { //Dans aucun des derniers cas
					cout << "Composant d'air " << typeDonnee << " inconnu" << endl;
				}

			}

		}

		file.close();
	}

} //----- Fin de lireMesures


void DataSet::lireCapteurs(string nomFichier, map<string, Capteur>* tabCapteurs)
// Algorithme :
// On ouvre puis parcourt le fichier. 
// On identifie les donnees et on cree des capteurs
//Que l on ajoute a notre tableau de capteurs
{
	ifstream file(nomFichier.c_str(), ios::in);

	if (file.fail()) {

		cout << "Erreur lors de l'ouverture du fichier demande" << endl;
		return;

	}
	else if (file) {

		//Si le fichier s'est bien ouvert...

		//On décortique la ligne
		string idCapteur;
		string latitude;
		string longitude;
		string description;


		//On récupère la première ligne
		string ligneFic;
		istringstream parcoursLigne;
		getline(file, ligneFic);

		while (!file.eof()) {

			//Récupération des informations de la ligne
			getline(file, ligneFic);
			parcoursLigne.str(ligneFic);
			getline(parcoursLigne, idCapteur, ';');
			getline(parcoursLigne, latitude, ';');
			getline(parcoursLigne, longitude, ';');
			getline(parcoursLigne, description, ';');

			//On vérifie que les données essentielles sont présentes
			if (idCapteur != "" && latitude != "" && longitude != "") {
				Capteur * capteur = new Capteur(idCapteur, atof(latitude.c_str()), atof(longitude.c_str()), description);
				tabCapteurs->insert(make_pair(idCapteur, *capteur));
			}
			
		}

		file.close();
	}

} //----- Fin de lireCapteurs


void DataSet::lireComposantsAirs(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
// Algorithme :
// On ouvre puis parcourt le fichier. 
// On identifie les donnees et on met a jour les caracteristiques
// des capteurs
{

	ifstream file(nomFichier.c_str(), ios::in);

	if (file.fail()) {

		cout << "Erreur lors de l'ouverture du fichier demandé" << endl;
		return;

	}
	else if (file) {

		//Si le fichier s'est bien ouvert...

		//On décortique la ligne
		string attribut;
		string unite;
		string description;


		//On récupère la première ligne
		string ligneFic;
		istringstream parcoursLigne;
		getline(file, ligneFic);

		while (!file.eof()) {

			//Récupération des informations de la ligne
			getline(file, ligneFic);
			parcoursLigne.str(ligneFic);
			getline(parcoursLigne, attribut, ';');
			getline(parcoursLigne, unite, ';');
			getline(parcoursLigne, description, ';');

			
			//On verifie que la ligne n est pas vide
			if (attribut != "" && unite != "" && description != "") {

				if (attribut == "O3") {
					o3->setDescription(description);
					o3->setUnite(unite);
					o3->setAttributeID(attribut);
				}
				else if (attribut == "SO2") {
					so2->setDescription(description);
					so2->setUnite(unite);
					so2->setAttributeID(attribut);
				}
				else if (attribut == "NO2") {
					no2->setDescription(description);
					no2->setUnite(unite);
					no2->setAttributeID(attribut);
				}
				else if (attribut == "PM10") {
					pm10->setDescription(description);
					pm10->setUnite(unite);
					pm10->setAttributeID(attribut);
				}
				else { //Dans aucun des derniers cas
					cout << "Composant d'air " << attribut << " inconnu" << endl;
				}

			}

		}

		file.close();
	}
	


} //----- Fin de lireComposantsAirs

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
