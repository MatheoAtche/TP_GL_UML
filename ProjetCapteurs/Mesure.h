/*************************************************************************
						   Mesure  -  description
							 -------------------
	d�but                : 06/05/2019
	copyright            : (C) 2019 par Alice d'Oncieu, Andrea Croc, Sophie Laboucheix, Math�o Atche
*************************************************************************/
#define CRT_SECURE_NO_WARNINGS

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ------
#if ! defined ( MESURE_H )
#define MESURE_H

//--------------------------------------------------- Interfaces utilis�es
using namespace std;

#include<cstring>
#include<string>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Mesure>
//
//
//------------------------------------------------------------------------ 

class Mesure
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
		double getValue ();
		// Mode d'emploi :
		//
		// Contrat :
		//

		string getSensorID();
		// Mode d'emploi :
		//
		// Contrat :
		//


		string getDate();
		// Mode d'emploi :
		//
		// Contrat :
		//

		int getAnnee();
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs
	//Mesure & operator = (const Mesure & uneMesure);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	//Mesure (const Mesure &uneMesure);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//


	Mesure(string time="",double val=0.0,string sensor="");
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Mesure();
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
	double value;
	string sensorID;
	string date;
	int annee;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Mesure>

#endif // MESURE_H
