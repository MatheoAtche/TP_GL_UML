/*************************************************************************
						   DataSet  -  Cette classe permet de lire les fichiers
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/

//---------- R�alisation de la classe <DataSet> (fichier DataSet.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "DataSet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

// Algorithme :
// On ouvre puis on parcourt le fichier. 
// On identifie les donnees et on cree des mesures
//Qu on ajoute a notre composant de l air aproprie
void DataSet::lireMesures(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, vector<Mesure*> * ptrMesures)
//
{

	ifstream file(nomFichier.c_str(), ios::in);

	if (file.fail()) {

		cout << "Erreur lors de l'ouverture du fichier demande" << endl;
		return;

	}
	else if (file) {

		//Si le fichier s'est bien ouvert...

		//On d�cortique la ligne
		string date;
		string idCapteur;
		string typeDonnee;
		string valeurMesure;


		//On r�cup�re la premi�re ligne
		string ligneFic;
		istringstream parcoursLigne;
		getline(file, ligneFic);

		while (!file.eof()) {

			//R�cup�ration des informations de la ligne
			getline(file, ligneFic);
			parcoursLigne.str(ligneFic);
			getline(parcoursLigne, date, ';');
			getline(parcoursLigne, idCapteur, ';');
			getline(parcoursLigne, typeDonnee, ';');
			getline(parcoursLigne, valeurMesure, ';');
			
			//On verifie que les donnees ne sont pas nulle
			if (date != "" && valeurMesure != "" && idCapteur != "" && typeDonnee != "") {

				Mesure * mesure = new Mesure(date, atof(valeurMesure.c_str()), idCapteur);
				ptrMesures->push_back(mesure);
				
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


void DataSet::lireCapteurs(string nomFichier, map<string, Capteur>* tabCapteurs, vector<Capteur*> * ptrCapteurs)
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

		//On d�cortique la ligne
		string idCapteur;
		string latitude;
		string longitude;
		string description;


		//On r�cup�re la premi�re ligne
		string ligneFic;
		istringstream parcoursLigne;
		getline(file, ligneFic);

		while (!file.eof()) {

			//R�cup�ration des informations de la ligne
			getline(file, ligneFic);
			parcoursLigne.str(ligneFic);
			getline(parcoursLigne, idCapteur, ';');
			getline(parcoursLigne, latitude, ';');
			getline(parcoursLigne, longitude, ';');
			getline(parcoursLigne, description, ';');

			//On v�rifie que les donn�es essentielles sont pr�sentes
			if (idCapteur != "" && latitude != "" && longitude != "") {
				Capteur * capteur = new Capteur(idCapteur, atof(latitude.c_str()), atof(longitude.c_str()), description);
				ptrCapteurs->push_back(capteur);
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

		cout << "Erreur lors de l'ouverture du fichier demand�" << endl;
		return;

	}
	else if (file) {

		//Si le fichier s'est bien ouvert...

		//On d�cortique la ligne
		string attribut;
		string unite;
		string description;


		//On r�cup�re la premi�re ligne
		string ligneFic;
		istringstream parcoursLigne;
		getline(file, ligneFic);

		while (!file.eof()) {

			//R�cup�ration des informations de la ligne
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


DataSet::DataSet()
{
	#ifdef MAP
		cout << "Appel au constructeur de <DataSet>" << endl;
	#endif

} //----- Fin de DataSet


DataSet::~DataSet()
{
	#ifdef MAP
		cout << "Appel au destructeur de <DataSet>" << endl;
	#endif
} //----- Fin de ~DataSet

