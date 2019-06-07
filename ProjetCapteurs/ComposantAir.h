/*************************************************************************
						   ComposantAir  -  Cette classe modélise un composant de l'air
							 -------------------
	début                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Mathéo Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <ComposantAir> (fichier ComposantAir.h) ------
#if ! defined ( COMPOSANTAIR_H )
#define COMPOSANTAIR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include<cstring>
#include<string>
#include<set>
#include<map>
#include<vector>
#include"Mesure.h"
#include"Capteur.h"

//------------------------------------------------------------- Constantes 
#define TAILLE 20
//------------------------------------------------------------------ Types 

typedef map<string, map<int, vector<Mesure>>> tabMesure_type;
//------------------------------------------------------------------------ 
// Rôle de la classe <ComposantAir>
// Cette classe modélise un composant de l'air : o3, no2, so2 ou pm10
// et realise des calculs de moyenne, minimum, maximum et ecart-type 
// sur l'ensemble de ses valeurs selon une periode et une position donnees
// Cette classe permet egalement de trouver des capteurs similaires
//------------------------------------------------------------------------ 

class ComposantAir
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Methodes publiques
		double moyenne ( string dateDebut,string dateFin,double latitude1,double longitude1,double latitude2,double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		// Calcul de la moyenne sur toutes les valeurs selectionnees selon la periode et le secteur geographique donnes
		//Parametres :
		// - dateDebut : la date du debut de la periode souhaitee
		// - dateFin : la date de fin de la periode souhaitee
		// - latitude1 : la latitude d un des points du rectangle definissant le secteur souhaite
		// - longitude1 : la longitude de ce meme point
		// - latitude2 : la latitude de l autre point du rectangle definissant le secteur souhaite
		// - longitude2 : la longitude de ce meme point
		// - tabCapteurs : tableau contenant tous les capteurs
		// Contrat :
		// Aucun

		double minimum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		// Calcul du minimum sur toutes les valeurs selectionnees selon la periode et le secteur geographique donnes
		//Parametres :
		// - dateDebut : la date du debut de la periode souhaitee
		// - dateFin : la date de fin de la periode souhaitee
		// - latitude1 : la latitude d un des points du rectangle definissant le secteur souhaite
		// - longitude1 : la longitude de ce meme point
		// - latitude2 : la latitude de l autre point du rectangle definissant le secteur souhaite
		// - longitude2 : la longitude de ce meme point
		// - tabCapteurs : tableau contenant tous les capteurs
		// Contrat :
		// Aucun

		double maximum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		// Calcul du maximum sur toutes les valeurs selectionnees selon la periode et le secteur geographique donnes
		//Parametres :
		// - dateDebut : la date du debut de la periode souhaitee
		// - dateFin : la date de fin de la periode souhaitee
		// - latitude1 : la latitude d un des points du rectangle definissant le secteur souhaite
		// - longitude1 : la longitude de ce meme point
		// - latitude2 : la latitude de l autre point du rectangle definissant le secteur souhaite
		// - longitude2 : la longitude de ce meme point
		// - tabCapteurs : tableau contenant tous les capteurs
		// Contrat :
		// Aucun

		double ecartType(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		// Calcul de l ecart type sur toutes les valeurs selectionnees selon la periode et le secteur geographique donnes
		//Parametres :
		// - dateDebut : la date du debut de la periode souhaitee
		// - dateFin : la date de fin de la periode souhaitee
		// - latitude1 : la latitude d un des points du rectangle definissant le secteur souhaite
		// - longitude1 : la longitude de ce meme point
		// - latitude2 : la latitude de l autre point du rectangle definissant le secteur souhaite
		// - longitude2 : la longitude de ce meme point
		// - tabCapteurs : tableau contenant tous les capteurs
		// Contrat :
		// Aucun

		multimap<string,string> valeursSimilaires(string dateDebut, string dateFin, double epsilon);
		// Mode d'emploi :
		// Cherche les paires de capteurs ayant des valeurs similaires de mesures de ce composant
		// pour une periode donnee respectant une tolerance epsilon
		//Parametres :
		// - dateDebut : la date du debut de la periode souhaitee
		// - dateFin : la date de fin de la periode souhaitee
		// - epsilon : tolerance souhaitee pour l ecart moyen entre les valeurs de deux capteurs 
		// Contrat :
		// Aucun

		void addMesure(Mesure * mesure);
		// Mode d'emploi :
		// Ajoute une mesure au tableau de mesures de ce composant (tabMesure)
		//Parametres :
		// - mesure : mesure a ajouter au tableau tabMesure
		// Contrat :
		// Aucun


		bool verifierDate(string dateDebut, string dateFin, Mesure mesure);
		// Mode d'emploi :
		// Verifie que la mesure a ete faite pendant la periode souhaitee
		//Parametres : 
		// - dateDebut : la date du debut de la periode souhaitee
		// - dateFin : la date de fin de la periode souhaitee
		// - mesure : la mesure a evaluer 
		// Contrat :
		// Aucun

		bool verifierPosition(double latitude1, double longitude1, double latitude2, double longitude2, Capteur capteur);
		// Mode d'emploi :
		// Verifie que le capteur est dans le secteur souhaite
		//Parametres : 
		// - latitude1 : la latitude d un des points du rectangle definissant le secteur souhaite
		// - longitude1 : la longitude de ce meme point
		// - latitude2 : la latitude de l autre point du rectangle definissant le secteur souhaite
		// - longitude2 : la longitude de ce meme point
		// - capteur : le capteur a evaluer
		// Contrat :
		// Aucun
		
		void setDescription(string descri);

		void setUnite(string unite);

		void setAttributeID(string attributeId);

		string getDescription();

		string getUnite();

		string getAttributeID();

		tabMesure_type getTabMesure();

	ComposantAir(string attribute="", string u="",string descri="",int taille=TAILLE);

	virtual ~ComposantAir();

//------------------------------------------------------------------ PRIVE 

private:
	//------------------------------------------------------- Attributs privés
	string attributeID;
	string unit;
	string description;
	tabMesure_type tabMesure;

};

#endif // COMPOSANTAIR_H
