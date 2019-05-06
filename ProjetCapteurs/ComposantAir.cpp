/***********************************************************************************************************************************
						   ComposantAir  -  description
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/

//---------- Réalisation de la classe <ComposantAir> (fichier ComposantAir.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<math.h>

//------------------------------------------------------ Include personnel
#include "ComposantAir.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

bool ComposantAir::verifierDate(string dateDebut, string dateFin, Mesure * mesure)
// Algorithme :
//
{
	int anneeD = atoi(dateDebut.substr(0, 4).c_str());
	int moisD = atoi(dateDebut.substr(5, 2).c_str());
	int jourD = atoi(dateDebut.substr(8, 2).c_str());

	int heureD = atoi(dateDebut.substr(11, 2).c_str());
	int minuteD = atoi(dateDebut.substr(13, 2).c_str());
	double secD = stod(dateDebut.substr(15, 7).c_str());

	int anneeF = atoi(dateFin.substr(0, 4).c_str());
	int moisF = atoi(dateFin.substr(5, 2).c_str());
	int jourF = atoi(dateFin.substr(8, 2).c_str());

	int heureF = atoi(dateFin.substr(11, 2).c_str());
	int minuteF = atoi(dateFin.substr(13, 2).c_str());
	double secF = stod(dateFin.substr(15, 7).c_str());

	string time = mesure->getTimestamp;

	int anneeT = atoi(time.substr(0, 4).c_str());
	int moisT = atoi(time.substr(5, 2).c_str());
	int jourT = atoi(time.substr(8, 2).c_str());

	int heureT = atoi(time.substr(11, 2).c_str());
	int minuteT = atoi(time.substr(13, 2).c_str());
	double secT = stod(time.substr(15, 7).c_str());

	if (anneeT <= anneeF && anneeT >= anneeD && moisT <= moisF && moisT >= moisD && jourT <= jourF && jourT >= jourD && heureT <= heureF && heureT >= heureD && minuteT <= minuteF && minuteT >= minuteD && secT <= secF && secT >= secD) 
	{
		return true;
	}
	return false;

} //----- Fin de verifierDate

bool ComposantAir::verifierPosition(double latitude1, double longitude1, double latitude2, double longitude2, Capteur capteur)
// Algorithme :
//
{
	double lat = capteur.getLatitude();
	double longi = capteur.getLongitude();

	if (lat >= latitude2 && lat <= latitude1 && longi >= longitude1 && longi <= longitude2)
	{
		return true;
	}
	return false;

}//----- Fin de Méthode

double ComposantAir::moyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string,Capteur>* tabCapteurs)
// Algorithme :
//
{
	double sum = 0;
	int compteur = 0; 
	double moyenne = 0;
	map<string, Capteur>::iterator itCapt;

	for (int i = 0; i < nbActuel; i++)
	{
		itCapt = tabCapteurs->find(tabMesure[i]->getSensorID());
		if (itCapt != tabCapteurs->end()) {

			if (verifierDate(dateDebut, dateFin, tabMesure[i]) && verifierPosition(latitude1, longitude1, latitude2, longitude2, itCapt->second))
			{
				sum += tabMesure[i]->getValue();
				compteur++;
			}
		}

	}

	if (compteur != 0) 
	{
		moyenne=sum/compteur;
	}
	return moyenne;

} //----- Fin de moyenne

double ComposantAir::minimum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	if (nbActuel > 0)
	{
		double minimum = tabMesure[0]->getValue();
		map<string, Capteur>::iterator itCapt;

		for (int i = 1; i < nbActuel; i++)
		{
			itCapt = tabCapteurs->find(tabMesure[i]->getSensorID());
			if (itCapt != tabCapteurs->end()) {

				if (verifierDate(dateDebut, dateFin, tabMesure[i]) && verifierPosition(latitude1, longitude1, latitude2, longitude2, itCapt->second))
				{
					if (minimum > tabMesure[i]->getValue()) {
						minimum = tabMesure[i]->getValue();
					}
				}
			}

		}
		return minimum;
	}
	return -1;
	
} //----- Fin de minimum

double ComposantAir::maximum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	if (nbActuel > 0)
	{
		double maximum = tabMesure[0]->getValue();
		map<string, Capteur>::iterator itCapt;

		for (int i = 1; i < nbActuel; i++)
		{
			itCapt = tabCapteurs->find(tabMesure[i]->getSensorID());
			if (itCapt != tabCapteurs->end()) {

				if (verifierDate(dateDebut, dateFin, tabMesure[i]) && verifierPosition(latitude1, longitude1, latitude2, longitude2, itCapt->second))
				{
					if (maximum < tabMesure[i]->getValue()) {
						maximum = tabMesure[i]->getValue();
					}
				}
			}

		}
		return maximum;
	}
	return -1;

} //----- Fin de Méthode

double ComposantAir::ecartType(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	double moy = moyenne(dateDebut, dateFin, latitude1, longitude1, latitude2, longitude2, tabCapteurs);
	double sum = 0;
	int compteur = 0;
	double ecartT = 0;

	map<string, Capteur>::iterator itCapt;

	for (int i = 0; i < nbActuel; i++)
	{
		itCapt = tabCapteurs->find(tabMesure[i]->getSensorID());
		if (itCapt != tabCapteurs->end()) {

			if (verifierDate(dateDebut, dateFin, tabMesure[i]) && verifierPosition(latitude1, longitude1, latitude2, longitude2, itCapt->second))
			{
				sum = sum + pow((tabMesure[i]->getValue()-moy),2);
				compteur++;
			}
		}
	}

	if (compteur != 0)
	{
		ecartT = sqrt(sum / compteur);
	}
	return ecartT;
	

} //----- Fin de Méthode

/*valSimi ComposantAir::valeursSimilaires(string dateDebut, string dateFin, double epsilon)
// Algorithme :
//
{

} //----- Fin de Méthode
*/

void ComposantAir::addMesure(Mesure * mesure)
// Algorithme :
//
{
	if (nbActuel == tailleTab) //Agrandissement de la taille du tableau si nécessaire
	{
		int i;
		tailleTab += 10;
		Mesure ** tabNouveau = new Mesure*[tailleTab];
		Mesure ** temp = tabMesure;
		for (i = 0; i < tailleTab - 10; i++)
		{
			tabNouveau[i] = tabMesure[i];
		}
		tabMesure = tabNouveau;
		delete[]temp;
	}

	tabMesure[nbActuel] = mesure; //Ajout au tableau
	nbActuel++;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*ComposantAir & ComposantAir::operator = (const ComposantAir &unComposantAir)
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*ComposantAir::ComposantAir(const ComposantAir &unComposantAir)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <ComposantAir>" << endl;
#endif
} //----- Fin de ComposantAir (constructeur de copie)
*/


ComposantAir::ComposantAir(string attribute, string u, string descri,int taille)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <ComposantAir>" << endl;
#endif
	attributeID = attribute;
	unit = u;
	description = descri;
	tailleTab = taille;
	nbActuel = 0;
	tabMesure = new Mesure*[tailleTab];
} //----- Fin de ComposantAir


ComposantAir::~ComposantAir()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ComposantAir>" << endl;
#endif
for(int i=0;i<nbActuel;i++)
{
	delete tabMesure[i];
}
delete[]tabMesure;
} //----- Fin de ~ComposantAir


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
