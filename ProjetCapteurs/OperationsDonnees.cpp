/***********************************************************************************************************************************
						   OperationsDonnees  -  description
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/

//---------- R�alisation de la classe <OperationsDonnees> (fichier OperationsDonnees.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "OperationsDonnees.h"

//------------------------------------------------------------- Constantes
#define TAILLE 20
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques


int OperationsDonnees::qualiteAirMoyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs)
//
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
} //----- Fin de M�thode

/*set<Capteur> OperationsDonnees::bonFonctionnementCapteurs(string dateDebut, string dateFin, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
// Algorithme :
//
{
} //----- Fin de M�thode
*/

int OperationsDonnees::qualiteAirPointFixe(string dateDebut, string dateFin, double latitude1, double longitude1, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
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
} //----- Fin de M�thode

vector<string> OperationsDonnees::bonFonctionnementCapteurs(string dateDebut, string dateFin, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
{
	vector<string> CapteurNonFonctionnel;
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
			CapteurNonFonctionnel.push_back(it1->first);
		}
	}
	return CapteurNonFonctionnel;
}

//------------------------------------------------- Surcharge d'op�rateurs
/*OperationsDonnees & OperationsDonnees::operator = (const OperationsDonnees &unOperationsDonnees)
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*OperationsDonnees::OperationsDonnees(const OperationsDonnees &unOperationsDonnees)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <OperationsDonnees>" << endl;
#endif
} //----- Fin de OperationsDonnees (constructeur de copie)
*/


OperationsDonnees::OperationsDonnees()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <OperationsDonnees>" << endl;
#endif
} //----- Fin de OperationsDonnees


OperationsDonnees::~OperationsDonnees()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <OperationsDonnees>" << endl;
#endif
} //----- Fin de ~OperationsDonnees


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
