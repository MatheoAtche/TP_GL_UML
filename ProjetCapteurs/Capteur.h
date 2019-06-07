/*************************************************************************
						   Capteur  -  Cette classe modélise un capteur
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

//------------------------------------------------------------------------ 
// Rôle de la classe <Capteur>
// Cette classe modélise un capteur en utilisant un identifiant ainsi
// que sa position et une description
//------------------------------------------------------------------------ 

class Capteur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	double getLongitude();

	double getLatitude();

	Capteur(string sensor="", double lat=0.0, double longi=0.0, string descri="");

	virtual ~Capteur ();

//------------------------------------------------------------------ PRIVE 

private:
	//------------------------------------------------------- Attributs privés
	string sensorID;
	double latitude;
	double longitude;
	string descrption;

};

#endif // CAPTEUR_H