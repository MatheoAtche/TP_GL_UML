/***********************************************************************************************************************************
						   ComposantAir  -  description
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/

//---------- Réalisation de la classe <ComposantAir> (fichier ComposantAir.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <math.h>

//------------------------------------------------------ Include personnel
#include "ComposantAir.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

bool ComposantAir::verifierDate(string dateDebut, string dateFin, Mesure mesure)
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

	int anneeT = mesure.getAnnee();
	int moisT = mesure.getMois();
	int jourT = mesure.getJour();

	int heureT = mesure.getHeure();
	int minuteT = mesure.getMinute();
	double secT = mesure.getSeconde();

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
	int an = 0;
	int anneeD = 0;
	int anneeF = 0;
	map<string, Capteur>::iterator itCapt;
	tabMesure_type::iterator it1;
	map<int, set<Mesure>>::iterator it2;
	set<Mesure>::iterator it3;

	map<int, set<Mesure>> tabM;
	//parcourir la map
	for (it1=tabMesure.begin();it1!=tabMesure.end();it1++)
	{
		itCapt = tabCapteurs->find(it1->first); //trouver le capteur dans tabCapteurs
		if (itCapt != tabCapteurs->end()) 
		{
			anneeD = atoi(dateDebut.substr(0, 4).c_str());
			anneeF = atoi(dateFin.substr(0, 4).c_str());

			//recuperer l'annee et verifier qu'elle est entre annee debut et annee fin
			//parcourir la set des mesure si annee ok
			
			//parcourir la map
			for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
			{
				an = it2->first;
				if (an >= anneeD && an <= anneeF)
				{
					//parcourir le set des mesures
					for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
					{
						if (verifierDate(dateDebut, dateFin, *it3) && verifierPosition(latitude1, longitude1, latitude2, longitude2, itCapt->second))
						{
							Mesure mesure = *it3;
							sum = sum + mesure.getValue(); 
							compteur++;
						}
					}
				}
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
	int annee = mesure->getAnnee();
	map<int, set<Mesure>>::iterator it2;
	string sensorId = mesure->getSensorID();
	tabMesure_type::iterator it1 = tabMesure.find(sensorId);

	//Si le capteur est deja dans la map
	if (it1 != tabMesure.end()) 
	{
		it2 = it1->second.find(annee);

		//Si le set existe deja pour annee
		if (it2 != it1->second.end()) 
		{
			//Inserer la mesure dans le set
			it2->second.insert(*mesure);

		} else {
			//Creer le set et l'ajouter a la deuxieme map
			set<Mesure> setMes = { *mesure };
			it1->second.insert(make_pair(annee, setMes));
		}

	} else {
		map<int, set<Mesure>> mapMes;
		set<Mesure> setMes = { *mesure };
		mapMes.insert(make_pair(annee,setMes));
		tabMesure.insert(make_pair(sensorId,mapMes));
	}
	 
	/*if (nbActuel == tailleTab) //Agrandissement de la taille du tableau si nécessaire
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
	nbActuel++;*/

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
} //----- Fin de ComposantAir


ComposantAir::~ComposantAir()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ComposantAir>" << endl;
#endif

} //----- Fin de ~ComposantAir


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
