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
	double moyO3 = o3->moyenne(dateDebut,dateFin,latitude1,longitude1,latitude2,longitude2, capteurs);
	return NULL;
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
	return NULL;
} //----- Fin de M�thode

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
