/*************************************************************************
						   Capteur  -  description
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include<cstring>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------ 

class Capteur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
		double getLongitude();
		// Mode d'emploi :
		//
		// Contrat :
		//

		double getLatitude();
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs
	//Capteur & operator = (const Capteur & unCapteur);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	//Capteur (const Capteur &unCapteur);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//


	Capteur(string sensor="", double lat=0.0, double longi=0.0, string descri="");
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Capteur ();
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
	string sensorID;
	double latitude;
	double longitude;
	string descrption;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Capteur>

#endif // CAPTEUR_H