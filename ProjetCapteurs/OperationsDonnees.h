/*************************************************************************
						   OperationsDonnees  -  Cette classe regroupe les fonctionnalites qui mettent 
												 en commun les differents composants de l air
							 -------------------
	debut                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Matheo Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <OperationsDonnees> (fichier OperationsDonnees.h) ------
#if ! defined ( OPERATIONSDONNEES_H )
#define OPERATIONSDONNEES_H

//--------------------------------------------------- Interfaces utilisees
using namespace std;

#include<cstring>
#include<set>
#include<set>
#include<map>
#include"ComposantAir.h"

//------------------------------------------------------------------ Types 
typedef map<string, map<int, vector<Mesure>>> tabMesure_type;

//------------------------------------------------------------------------ 
// Role de la classe <OperationsDonnees>
// Cette classe va réaliser des opérations sur l'ensemble des données capteurs
// telles que le mesure de la qualité de l'air ou la vérification du bon
// fonctionnement des capteurs
//------------------------------------------------------------------------ 

class OperationsDonnees
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Methodes publiques
	int qualiteAirMoyenne(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs);
	// Mode d'emploi :
	// Cette methode prend en entree les dates de debut et de fin ainsi que les coordonnee
	// permettant de definir la zone geographique, et les 4 composants d'air pour faire appel
	// à leur methode de moyenne. Le retour correspond a la valeur d'indice ATMO indiquant 
	// la qualite de l'air.

	set<string> bonFonctionnementCapteurs(string dateDebut, string dateFin, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10);
	// Mode d'emploi :
	// Cette methode prend en entree une date de debut et une date de fin, ainsi que l'ensemble des
	// donnees capteurs pour retourner tous ceux qui sont defaillant


	int qualiteAirPointFixe(string dateDebut, string dateFin, double latitude1, double longitude1, ComposantAir* o3, ComposantAir* no2, ComposantAir* so2, ComposantAir* pm10, map<string, Capteur>* tabCapteurs);
	// Mode d'emploi :
	// Cette methode est presque exactement la meme que qualiteAirMoyenne, sauf qu'elle ne prend
	// en parametre la position que d'un seul capteur

	OperationsDonnees();

	virtual ~OperationsDonnees();

};

#endif // OPERATIONSDONNEES_H
