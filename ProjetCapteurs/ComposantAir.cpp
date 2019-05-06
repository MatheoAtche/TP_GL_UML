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

//------------------------------------------------------ Include personnel
#include "ComposantAir.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


double ComposantAir::moyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string,Capteur>* tabCapteurs)
// Algorithme :
//
{
	double sum = 0;
	int compteur = 0; 
	double moyenne = 0;
	
	for (int i = 0; i < nbActuel; i++)
	{
		set<Capteur>::iterator itCapt = tabCapteurs->find(tabMesure[i]->getSensorID());
		if (date ok && position ok) 
		{
			sum += tabMesure[i]->getValue();
			compteur++;
			
		}

	}

	if (compteur != 0) 
	{
		moyenne=sum/compteur;
	}
	return moyenne;
} //----- Fin de Méthode

double ComposantAir::minimum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	return NULL;

} //----- Fin de Méthode

double ComposantAir::maximum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	return NULL;

} //----- Fin de Méthode

double ComposantAir::ecartType(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	return NULL;

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
