/*************************************************************************
						   ComposantAir  -  description
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <ComposantAir> (fichier ComposantAir.h) ------
#if ! defined ( COMPOSANTAIR_H )
#define COMPOSANTAIR_H

//--------------------------------------------------- Interfaces utilis�es
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
typedef map<double, set<string>> valSimi;
typedef map<string, map<int, vector<Mesure>>> tabMesure_type;
//------------------------------------------------------------------------ 
// R�le de la classe <ComposantAir>
//
//
//------------------------------------------------------------------------ 

class ComposantAir
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
		double moyenne ( string dateDebut,string dateFin,double latitude1,double longitude1,double latitude2,double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		//
		// Contrat :
		//

		double minimum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		//
		// Contrat :
		//

		double maximum(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		//
		// Contrat :
		//

		double ecartType(string dateDebut, string dateFin, double latitude1, double longitude1, double latitude2, double longitude2, map<string, Capteur>* tabCapteurs);
		// Mode d'emploi :
		//
		// Contrat :
		//

		valSimi valeursSimilaires(string dateDebut, string dateFin, double epsilon);
		// Mode d'emploi :
		//
		// Contrat :
		//

		void addMesure(Mesure * mesure);
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool verifierDate(string dateDebut, string dateFin, Mesure mesure);
		// Mode d'emploi :
		//
		// Contrat :
		//

		bool verifierPosition(double latitude1, double longitude1, double latitude2, double longitude2, Capteur capteur);
		// Mode d'emploi :
		//
		// Contrat :
		//

		tabMesure_type getTabMesure();
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs
	//ComposantAir & operator = (const ComposantAir & unComposantAir);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	//ComposantAir (const ComposantAir &unComposantAir);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//


	ComposantAir(string attribute="", string u="",string descri="",int taille=TAILLE);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~ComposantAir();
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
	string attributeID;
	string unit;
	string description;
	tabMesure_type tabMesure;
	
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <ComposantAir>

#endif // COMPOSANTAIR_H
