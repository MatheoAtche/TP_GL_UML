/***********************************************************************************************************************************
						   ComposantAir  -  description
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/

//---------- R�alisation de la classe <ComposantAir> (fichier ComposantAir.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ComposantAir.h"

//------------------------------------------------------------- Constantes
#define TAILLE 20
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques


double ComposantAir::moyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, set<Capteur>* tabCapteurs)
// Algorithme :
//
{
	return NULL;
} //----- Fin de M�thode

double ComposantAir::minimum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, set<Capteur> * tabCapteurs)
// Algorithme :
//
{
	return NULL;

} //----- Fin de M�thode

double ComposantAir::maximum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, set<Capteur> * tabCapteurs)
// Algorithme :
//
{
	return NULL;

} //----- Fin de M�thode

double ComposantAir::ecartType(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, set<Capteur> * tabCapteurs)
// Algorithme :
//
{
	return NULL;

} //----- Fin de M�thode

/*valSimi ComposantAir::valeursSimilaires(string dateDebut, string dateFin, double epsilon)
// Algorithme :
//
{

} //----- Fin de M�thode
*/

void ComposantAir::addMesure(Mesure mesure)
// Algorithme :
//
{
} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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
	tabMesure = new Mesure[tailleTab];
} //----- Fin de ComposantAir


ComposantAir::~ComposantAir()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <ComposantAir>" << endl;
#endif
for(int i=0;i<tailleTab;i++)
{
	delete tabMesure[i];
}
delete[]tabMesure;
} //----- Fin de ~ComposantAir


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
