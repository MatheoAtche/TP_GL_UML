/*************************************************************************
						   OperationsDonnees  -  description
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <OperationsDonnees> (fichier OperationsDonnees.h) ------
#if ! defined ( OPERATIONSDONNEES_H )
#define OPERATIONSDONNEES_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;

#include<cstring>
#include<vector>
#include<map>
#include"ComposantAir.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef map<string, map<int, vector<Mesure>>> tabMesure_type;

//------------------------------------------------------------------------ 
// R�le de la classe <OperationsDonnees>
//
//
//------------------------------------------------------------------------ 

class OperationsDonnees
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	int qualiteAirMoyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs);
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector<string> bonFonctionnementCapteurs(string dateDebut, string dateFin, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10);
	// Mode d'emploi :
	//
	// Contrat :


	int qualiteAirPointFixe(string dateDebut, string dateFin, double latitude1, double longitude1, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs);
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <OperationsDonnees>

#endif // OPERATIONSDONNEES_H
