/***********************************************************************************************************************************
						   OperationsDonnees  -  description
							 -------------------
	debut                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Matheo Atche
*************************************************************************/

//---------- Realisation de la classe <OperationsDonnees> (fichier OperationsDonnees.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "OperationsDonnees.h"

//------------------------------------------------------------- Constantes
#define TAILLE 20
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques


int OperationsDonnees::qualiteAirMoyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs)
// Algorithme :
// Les moyennes de chaque particule sont calculees a l'aide des methodes des ComposantsAir
// elles sont ensuite comparées aux valeurs permettant de determiner l'indice ATMO,
// une fois l'indice trouve, il est retourne
{
	double moyO3 = o3->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude2,longitude2, tabCapteurs);
	double moyNO2 = no2->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude2,longitude2, tabCapteurs);
	double moySO2 = so2->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude2,longitude2, tabCapteurs);
	double moyPM10 = pm10->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude2,longitude2, tabCapteurs);
	int indice = 1;
	if (moyO3>=30 || moySO2>=40 || moyNO2>=30 || moyPM10 >=7)
	{
		indice =2;
	}
	else if (moyO3>=55 || moySO2>=80 || moyNO2>=55 || moyPM10 >=14)
	{
		indice =3;
	}
	else if (moyO3>=80 || moySO2>=120 || moyNO2>=85 || moyPM10 >=21)
	{
		indice =4;
	}
	else if (moyO3>=105 || moySO2>=160 || moyNO2>=110 || moyPM10 >=28)
	{
		indice =5;
	}
	else if (moyO3>=130 || moySO2>=200 || moyNO2>=135 || moyPM10 >=35)
	{
		indice =6;
	}
	else if (moyO3>=150 || moySO2>=250 || moyNO2>=165 || moyPM10 >=42)
	{
		indice =7;
	}
	else if (moyO3>=180 || moySO2>=300 || moyNO2>=200 || moyPM10 >=50)
	{
		indice =8;
	}
	else if (moyO3>=210 || moySO2>=400 || moyNO2>=275 || moyPM10 >=65)
	{
		indice =9;
	}
	else if (moyO3>=240 || moySO2>=500 || moyNO2>=400 || moyPM10 >=80)
	{
		indice =10;
	}
	return indice;
} //----- Fin de qualiteAirMoyenne

int OperationsDonnees::qualiteAirPointFixe(string dateDebut, string dateFin, double latitude1, double longitude1, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs)
// Algorithme :
// L'algo est presque le meme que pour qualiteAirMoyenne, seulement nous entrons deux fois
// les memes coordonnees pour la localisation dans le calcul de moyenne, de sorte à ne calculer
// la qualite de l'air que sur un capteur
{
	double moyO3 = o3->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude1,longitude1, tabCapteurs);
	double moyNO2 = no2->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude1,longitude1, tabCapteurs);
	double moySO2 = so2->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude1,longitude1, tabCapteurs);
	double moyPM10 = pm10->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude1,longitude1, tabCapteurs);
	int indice = 1;
	if (moyO3>=30 || moySO2>=40 || moyNO2>=30 || moyPM10 >=7)
	{
		indice =2;
	}
	else if (moyO3>=55 || moySO2>=80 || moyNO2>=55 || moyPM10 >=14)
	{
		indice =3;
	}
	else if (moyO3>=80 || moySO2>=120 || moyNO2>=85 || moyPM10 >=21)
	{
		indice =4;
	}
	else if (moyO3>=105 || moySO2>=160 || moyNO2>=110 || moyPM10 >=28)
	{
		indice =5;
	}
	else if (moyO3>=130 || moySO2>=200 || moyNO2>=135 || moyPM10 >=35)
	{
		indice =6;
	}
	else if (moyO3>=150 || moySO2>=250 || moyNO2>=165 || moyPM10 >=42)
	{
		indice =7;
	}
	else if (moyO3>=180 || moySO2>=300 || moyNO2>=200 || moyPM10 >=50)
	{
		indice =8;
	}
	else if (moyO3>=210 || moySO2>=400 || moyNO2>=275 || moyPM10 >=65)
	{
		indice =9;
	}
	else if (moyO3>=240 || moySO2>=500 || moyNO2>=400 || moyPM10 >=80)
	{
		indice =10;
	}
	return indice;
	return NULL;
} //----- Fin de qualitéAirPointFixe

set<string> OperationsDonnees::bonFonctionnementCapteurs(string dateDebut, string dateFin, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
// Algorithme :
// La totalite des mesures capteurs sont recuperees selon le type de particule, puis pour chaque capteur
// les mesures sont parcourues sur la periode donnee, si plus de 10% d'entre elles sont nulles,
// le capteur est considere comme defaillant et son identifiant est stocke dans la structure de retour
{
	set<string> CapteurNonFonctionnel;
	tabMesure_type mesO3 = o3->getTabMesure();
	tabMesure_type mesSO2 = so2->getTabMesure();
	tabMesure_type mesNO2 = no2->getTabMesure();
	tabMesure_type mesPM10 = pm10->getTabMesure();
	long cmptO3=0, cmptNO2=0, cmptSO2=0, cmptPM10=0, totalMesO3=0, totalMesNO2=0, totalMesSO2=0, totalMesPM10=0;
	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;
	for (it1=mesO3.begin(); it1!=mesO3.end(); it1++)
	{
		for (it2=it1->second.begin();it2!=it1->second.end(); it2++)
		{
			for (it3= it2->second.begin(); it3!=it2->second.end(); it3++)
			{
				if (o3->verifierDate(dateDebut,dateFin,*it3) && *it3->getValue==0)
				{
					cmptO3++;
				}
			}
			totalMesO3+=it2->second.size();
		}
		if ((double)cmptO3/totalMesO3>0.1)
		{
			CapteurNonFonctionnel.insert(it1->first);
		}
	}
	for (it1=mesSO2.begin(); it1!=mesSO2.end(); it1++)
	{
		for (it2=it1->second.begin();it2!=it1->second.end(); it2++)
		{
			for (it3= it2->second.begin(); it3!=it2->second.end(); it3++)
			{
				if (o3->verifierDate(dateDebut,dateFin,*it3) && *it3->getValue==0)
				{
					cmptSO2++;
				}
			}
			totalMesSO2+=it2->second.size();
		}
		if ((double)cmptSO2/totalMesSO2>0.1)
		{
			CapteurNonFonctionnel.insert(it1->first);
		}
	}
	for (it1=mesNO2.begin(); it1!=mesNO2.end(); it1++)
	{
		for (it2=it1->second.begin();it2!=it1->second.end(); it2++)
		{
			for (it3= it2->second.begin(); it3!=it2->second.end(); it3++)
			{
				if (o3->verifierDate(dateDebut,dateFin,*it3) && *it3->getValue==0)
				{
					cmptNO2++;
				}
			}
			totalMesNO2+=it2->second.size();
		}
		if ((double)cmptNO2/totalMesNO2>0.1)
		{
			CapteurNonFonctionnel.insert(it1->first);
		}
	}
	for (it1=mesPM10.begin(); it1!=mesPM10.end(); it1++)
	{
		for (it2=it1->second.begin();it2!=it1->second.end(); it2++)
		{
			for (it3= it2->second.begin(); it3!=it2->second.end(); it3++)
			{
				if (o3->verifierDate(dateDebut,dateFin,*it3) && *it3->getValue==0)
				{
					cmptPM10++;
				}
			}
			totalMesO3+=it2->second.size();
		}
		if ((double)cmptPM10/totalMesPM10>0.1)
		{
			CapteurNonFonctionnel.insert(it1->first);
		}
	}
	return CapteurNonFonctionnel;
} //----- Fin de bonFonctionnementCapteurs

OperationsDonnees::OperationsDonnees()
{
#ifdef MAP
	cout << "Appel au constructeur de <OperationsDonnees>" << endl;
#endif
} //----- Fin de OperationsDonnees


OperationsDonnees::~OperationsDonnees()
{
#ifdef MAP
	cout << "Appel au destructeur de <OperationsDonnees>" << endl;
#endif
} //----- Fin de ~OperationsDonnees