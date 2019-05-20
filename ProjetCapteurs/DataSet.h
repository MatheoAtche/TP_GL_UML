/*************************************************************************
						   DataSet  -  description
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <DataSet> (fichier DataSet.h) ------
#if ! defined ( DATASET_H )
#define DATASET_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;

#include<cstring>
#include<set>
#include<map>
#include"ComposantAir.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// R�le de la classe <DataSet>
//
//
//------------------------------------------------------------------------ 

class DataSet
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	void lireMesures(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10);
	// Mode d'emploi :
	// Parcours d un fichier de mesures et on remplit les objets o3, no2, so2 et pm10 en fonction des mesures lues
	//Parametres :
	// - nomFichier : nom du fichier a lire
	// - o3 : le composant o3
	// - no2 : le composant no2
	// - so2 : le composant so2
	// - pm10 : le composant pm10
	// Contrat :
	// Aucun

	void lireCapteurs(string nomFichier, map<string, Capteur>* tabCapteurs);
	// Mode d'emploi :
	// Parcours d un fichier de capteurs et on remplit une map qui contient tous les capteurs
	// Parametres :
	// - nomFichier : nom du fichier a lire
	// - tabCapteur : tableau contenant tous les capteurs
	// Contrat :
	// Aucun


	void lireComposantsAirs(string nomFichier, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10);
	// Mode d'emploi :
	// Parcours d un fichier des composants de l air et on met a jour les caracteristiques des composants apropries
	//Parametres :
	// - nomFichier : nom du fichier a lire
	// - o3 : le composant o3
	// - no2 : le composant no2
	// - so2 : le composant so2
	// - pm10 : le composant pm10
	// Contrat :
	// Aucun


//-------------------------------------------- Constructeurs - destructeur

	DataSet();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~DataSet();
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

//----------------------------------------- Types d�pendants de <DataSet>

#endif // DATASET_H


