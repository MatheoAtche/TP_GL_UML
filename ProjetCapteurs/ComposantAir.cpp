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
	string date = mesure.getDate();
	
	if ((strcmp(dateDebut.c_str(),date.c_str()))<=0 && (strcmp(date.c_str(), dateFin.c_str())<=0))
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

	double minLat = latitude1;
	double maxLat = latitude2;
	double minLong = longitude1;
	double maxLong = longitude2;
	

	if (latitude1 > latitude2) {
		minLat = latitude2;
		maxLat = latitude1;
	}
	if (longitude1 > longitude2) {
		minLong = longitude2;
		maxLong = longitude1;
	}

	if (lat >= minLat && lat <= maxLat && longi >= minLong && longi <= maxLong)
	{
		return true;
	}
	return false;

}//----- Fin de Méthode

double ComposantAir::moyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string,Capteur>* tabCapteurs)
// Algorithme :
//
{
	double sum = 0.0;
	int compteur = 0; 
	double moyenne = 0.0;
	int an = 0;
	int anneeD = atoi(dateDebut.substr(0, 4).c_str());
	int anneeF = atoi(dateFin.substr(0, 4).c_str());

	map<string, Capteur>::iterator itCapt;
	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;

	cout << "Methode moyenne" << endl;
	//parcourir la map
	for (it1=tabMesure.begin();it1!=tabMesure.end();it1++)
	{
		itCapt = tabCapteurs->find(it1->first); //trouver le capteur dans tabCapteurs
		if (itCapt != tabCapteurs->end()) 
		{
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

	int an = 0;
	int anneeD = atoi(dateDebut.substr(0, 4).c_str());
	int anneeF = atoi(dateFin.substr(0, 4).c_str());

	map<string, Capteur>::iterator itCapt;
	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;

	double minimum = 100000.0;

	//parcourir la map
	for (it1 = tabMesure.begin(); it1 != tabMesure.end(); it1++)
	{
		itCapt = tabCapteurs->find(it1->first); //trouver le capteur dans tabCapteurs
		if (itCapt != tabCapteurs->end())
		{

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
							double value = mesure.getValue();
							if ( value< minimum) {
								minimum = value;
							}
						}
					}
				}
			}
		}

	}

	return minimum;

} //----- Fin de minimum

double ComposantAir::maximum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	int an = 0;
	int anneeD = atoi(dateDebut.substr(0, 4).c_str());
	int anneeF = atoi(dateFin.substr(0, 4).c_str());

	map<string, Capteur>::iterator itCapt;
	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;

	double maximum = -1.0;

	//parcourir la map
	for (it1 = tabMesure.begin(); it1 != tabMesure.end(); it1++)
	{
		itCapt = tabCapteurs->find(it1->first); //trouver le capteur dans tabCapteurs
		if (itCapt != tabCapteurs->end())
		{

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
							double value = mesure.getValue();
							if (value > maximum) {
								maximum = value;
							}
						}
					}
				}
			}
		}

	}

	return maximum;

} //----- Fin de maximum

double ComposantAir::ecartType(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	double moy = moyenne(dateDebut, dateFin, latitude1, longitude1, latitude2, longitude2, tabCapteurs);
	double sum = 0;
	int compteur = 0;
	double ecartT = 0.0;

	int an = 0;
	int anneeD = atoi(dateDebut.substr(0, 4).c_str());
	int anneeF = atoi(dateFin.substr(0, 4).c_str());

	map<string, Capteur>::iterator itCapt;
	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;

	//parcourir la map
	for (it1 = tabMesure.begin(); it1 != tabMesure.end(); it1++)
	{
		itCapt = tabCapteurs->find(it1->first); //trouver le capteur dans tabCapteurs
		if (itCapt != tabCapteurs->end())
		{
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
							double value = mesure.getValue();
							sum = sum + pow((value - moy), 2);
							compteur++;
						}
					}
				}
			}
		}

	}

	if (compteur != 0)
	{
		ecartT = sqrt(sum / compteur);
	}
	
	return ecartT;	

} //----- Fin de ecartType

multimap<string,string> ComposantAir::valeursSimilaires(string dateDebut, string dateFin, double epsilon)
// Algorithme :
//
{
	map<string, vector<double>> mapPreTriee;
	
	int an = 0;
	int anneeD = atoi(dateDebut.substr(0, 4).c_str());
	int anneeF = atoi(dateFin.substr(0, 4).c_str());

	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;

	//--------------------------------------Tri du tabMesure en une map<string,vector<double>>

	//parcourir la map
	for (it1 = tabMesure.begin(); it1 != tabMesure.end(); it1++)
	{
		vector<double> vecVal;

		//recuperer l'annee et verifier qu'elle est entre annee debut et annee fin
		//parcourir la set des mesures si annee ok

		//parcourir la map
		for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
			an = it2->first;
			if (an >= anneeD && an <= anneeF)
			{
				//parcourir le set des mesures
				for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
				{
					
					if (verifierDate(dateDebut, dateFin, *it3))
					{
						Mesure mesure = *it3;
						vecVal.push_back(mesure.getValue());

					}
				}
			}

		}
		if (!vecVal.empty()) {
			mapPreTriee.insert(make_pair(it1->first, vecVal));
		}
	}

	//--------------------------------------Trouver les valeurs similaires 

	map<string, vector<double>>::iterator it5,it6;
	vector<double>::iterator it7,it8;
	double sum = 0.0;
	double compTot = 0.0;
	multimap<string, string>paireCapt = {};

	if (mapPreTriee.empty()) {
		return paireCapt;
	}

	for (it5 = mapPreTriee.begin(); it5 != mapPreTriee.end(); it5++) {		

		if (it5 == mapPreTriee.end()) {
			break;
		}
		for (it6 = next(it5,1); it6 != mapPreTriee.end(); it6++) {
			compTot = 0.0;
			sum = 0.0;

			for (it7 = it5->second.begin(),it8 = it6->second.begin(); it7 != it5->second.end() && it8 != it6->second.end(); it7++,it8++) {
				compTot++;
				sum += abs(*it7 - *it8);
			}
			if (compTot != 0) {
				sum = sum / compTot;

				if (sum <= epsilon) {
					paireCapt.insert(make_pair(it5->first, it6->first));
				}
			}
		}
		
	}

	return paireCapt;

} //----- Fin de valeursSimilaires


void ComposantAir::addMesure(Mesure * mesure)
// Algorithme :
//
{
	// typedef map<string, map<int, vector<Mesure>>> tabMesure_type;

	int annee = mesure->getAnnee();
	map<int, vector<Mesure>>::iterator it2;
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
			it2->second.push_back(*mesure);

		} else {
			//Creer le set et l'ajouter a la deuxieme map
			vector<Mesure> vecMes = { *mesure };
			it1->second.insert(make_pair(annee, vecMes));
		}

	} else {
		map<int, vector<Mesure>> mapMes;
		vector<Mesure> vecMes = { *mesure };
		mapMes.insert(make_pair(annee,vecMes));
		tabMesure.insert(make_pair(sensorId,mapMes));
	}

} //----- Fin de addMesure


string ComposantAir::getDescription()
// Algorithme :
//
{
	return description;
}

string ComposantAir::getUnite()
// Algorithme :
//
{
	return unit;
}

string ComposantAir::getAttributeID()
// Algorithme :
//
{
	return attributeID;
}


tabMesure_type ComposantAir::getTabMesure()
// Algorithme :
//
{
	return tabMesure;
}

void ComposantAir::setDescription(string descri) 
// Algorithme :
//
{
		description = descri;
}

void ComposantAir::setUnite(string unite)
// Algorithme :
//
{
	unit = unite;
}

void ComposantAir::setAttributeID(string attributeId)
// Algorithme :
//
{
	attributeID = attributeId;
}

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

	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;
	cout << "destructeur composant air " << endl;
	//parcourir la premiere map
	for (it1 = tabMesure.begin(); it1 != tabMesure.end(); it1++)
	{
		//parcourir la deuxieme map
		for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
			//parcourir le vector des mesures
			for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
			{
				delete &it3;
				cout << "destructeur composant air delete" << endl;
			}
		}
	}


} //----- Fin de ~ComposantAir


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
