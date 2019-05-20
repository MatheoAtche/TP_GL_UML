/*************************************************************************
						   DataSet  -  description
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

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

void DataSet::lireMesures(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
//
{

	ifstream file(nomFichier.c_str(), ios::in);

	if (file.fail()) {

		cout << "Erreur lors de l'ouverture du fichier demand�" << endl;
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

			cout << "Date : " << date << endl;
			cout << "Capteur : " << idCapteur << endl;
			cout << "Type : " << typeDonnee << endl;
			cout << "Valeur : " << valeurMesure << endl;


			Mesure * mesure = new Mesure(date,atof(valeurMesure.c_str()),idCapteur);
			
			if (typeDonnee == "O3") {
				o3->addMesure(mesure);
			} else if (typeDonnee == "SO2") {
				so2->addMesure(mesure);
			} else if (typeDonnee == "NO2") {
				no2->addMesure(mesure);
			} else if (typeDonnee == "PM10") {
				pm10->addMesure(mesure);
			}
			else { //Dans aucun des derniers cas
				cout << "Composant d'air " << typeDonnee << " inconnu" << endl;
			}

		}

		file.close();
	}

} //----- Fin de lireMesures


void DataSet::lireCapteurs(string nomFichier, map<string, Capteur>* tabCapteurs)
//
{
	ifstream file(nomFichier.c_str(), ios::in);

	if (file.fail()) {

		cout << "Erreur lors de l'ouverture du fichier demand�" << endl;
		return;

	}
	else if (file) {

		//Si le fichier s'est bien ouvert...
		cout << "Fichier " << nomFichier << " en cours de lecture ..." << endl;

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

			cout << "Capteur : " << idCapteur << endl;
			cout << "Latitude : " << latitude << endl;
			cout << "Longitude : " << longitude << endl;
			cout << "Description : " << description << endl;

			Capteur * capteur = new Capteur(idCapteur, atof(latitude.c_str()), atof(longitude.c_str()), description);

			tabCapteurs->insert(make_pair(idCapteur,*capteur));
		}

		file.close();
	}

} //----- Fin de lireCapteurs

//MANQUE SET COMPOSANTAIR
void DataSet::lireComposantsAirs(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
//
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

			cout << "attribut : " << attribut << endl;
			cout << "unite : " << unite << endl;
			cout << "Type : " << description << endl;


			if (attribut == "O3") {
				//o3->setDescription(description);
				//o3->setUnite(unite);
			}
			else if (attribut == "SO2") {
				//so2->setDescription(description);
				//so2->setUnite(unite);
			}
			else if (attribut == "NO2") {
				//no2->setDescription(description);
				//no2->setUnite(unite);
			}
			else if (attribut == "PM10") {
				//pm10->setDescription(description);
				//pm10->setUnite(unite);
			}
			else { //Dans aucun des derniers cas
				cout << "Composant d'air " << attribut << " inconnu" << endl;
			}

		}

		file.close();
	}
	


} //----- Fin de lireComposantsAirs

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
