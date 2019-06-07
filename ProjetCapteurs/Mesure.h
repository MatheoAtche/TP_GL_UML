/*************************************************************************
						   Mesure  -  Cette classe modelise une mesure
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ------
#if ! defined ( MESURE_H )
#define MESURE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include<cstring>
#include<string>
//------------------------------------------------------------------------ 
// Rôle de la classe <Mesure>
// Cette classe modelise une mesure avec une valeur faite a une date 
// specifique et par un certain capteur
//------------------------------------------------------------------------ 

class Mesure
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
		double getValue ();

		string getSensorID();

		string getDate();

		int getAnnee();

//-------------------------------------------- Constructeurs - destructeur

	Mesure(string time="",double val=0.0,string sensor="");

	virtual ~Mesure();

//------------------------------------------------------------------ PRIVE 

private:
	//------------------------------------------------------- Attributs privés
	double value;
	string sensorID;
	string date;
	int annee;

};

#endif // MESURE_H
