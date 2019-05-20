#define CRT_SECURE_NO_WARNINGS

using namespace std;
#include <iostream>

#include "Capteur.h"
#include "ComposantAir.h"
#include "DataSet.h"
#include "Mesure.h"
#include "OperationsDonnees.h"

//Non testé
void testLireMesuresComposantAir() {

	DataSet * dataSet =  new DataSet();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireMesures("data_10sensors_1year.cvs",o3,no2,so2,pm10);

}

//En cours de test
void testLireCaracteristiquesCapteurs() {

	cout << "*** TEST DE LA LECTURE DES CARACTERISTIQUES DES CAPTEURS ***" << endl;
	DataSet * dataSet = new DataSet();
	map<string, Capteur>* tabCapteurs = new map<string,Capteur>();
	dataSet->lireCapteurs("../Fichiers/Sensors.csv",tabCapteurs);

}

int main() {

	//Obligé pour qu'on voit que qql chose s'affiche !
	char * a = new char[10];
	cout << "coucou" << endl;


	//Tests
	//testLireMesuresComposantAir();
	cout << "Bienvenue sur l'application ! " << endl;
	cout << "Chargement des données en cours ..." << endl;

	// APPEL AUX FONCTIONS DE LECTURE
	testLireCaracteristiquesCapteurs();

	//Menu
	/*
	bool estFini = false;
	while (!estFini) {
		cout << "Que souhaitez-vous faire ? " << endl;
	}
	*/
	

	//
	cin >> a;
	cout << a;
	return 0;


}