/*************************************************************************
						   OperationsDonnees  -  description
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <OperationsDonnees> (fichier OperationsDonnees.h) ------
#if ! defined ( OPERATIONSDONNEES_H )
#define OPERATIONSDONNEES_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include<cstring>
#include<set>
#include<map>
#include"ComposantAir.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <OperationsDonnees>
//
//
//------------------------------------------------------------------------ 

class OperationsDonnees
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	int qualiteAirMoyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs);
	// Mode d'emploi :
	//
	// Contrat :
	//

	set<Capteur> bonFonctionnementCapteurs(string dateDebut, string dateFin, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10);
	// Mode d'emploi :
	//
	// Contrat :


	int qualiteAirPointFixe(string dateDebut, string dateFin, double latitude1, double longitude1, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs);
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
//OperationsDonnees & operator = (const OperationsDonnees & unOperationsDonnees);
// Mode d'emploi :
//
// Contrat :
//


//-------------------------------------------- Constructeurs - destructeur
	//OperationsDonnees (const OperationsDonnees &unOperationsDonnees);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//


	OperationsDonnees();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~OperationsDonnees();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <OperationsDonnees>

#endif // OPERATIONSDONNEES_H
