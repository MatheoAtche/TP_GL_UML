/***********************************************************************************************************************************
						   OperationsDonnees  -  description
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/

//---------- Réalisation de la classe <OperationsDonnees> (fichier OperationsDonnees.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "OperationsDonnees.h"

//------------------------------------------------------------- Constantes
#define TAILLE 20
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


int OperationsDonnees::qualiteAirMoyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs)
//
{
	return NULL;
} //----- Fin de Méthode

/*set<Capteur> OperationsDonnees::bonFonctionnementCapteurs(string dateDebut, string dateFin, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10)
// Algorithme :
//
{
} //----- Fin de Méthode
*/

int OperationsDonnees::qualiteAirPointFixe(string dateDebut, string dateFin, double latitude1, double longitude1, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs)
// Algorithme :
//
{
	return NULL;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
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

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
