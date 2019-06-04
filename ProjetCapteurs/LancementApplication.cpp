#define CRT_SECURE_NO_WARNINGS

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<ctime>
#include<time.h>
#include "Capteur.h"
#include "ComposantAir.h"
#include "DataSet.h"
#include "Mesure.h"
#include "OperationsDonnees.h"

void ajouteFichierLog(string typeAction) {

	ofstream of;

	time_t date = time(NULL);

	of.open("Fichiers/fichierLog.txt", ofstream::app);
	char chaineDate[26];
	ctime_s(chaineDate,sizeof(chaineDate), &date);

	of << chaineDate << "/" << typeAction << endl;
	of.close();

}

void testQualiteAirMoyenne() {
	cout << "Test de la qualité de l'air moyenne" << endl;

	DataSet * dataSet = new DataSet();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireMesures("Fichiers/MesuresCompletes.csv", o3, no2, so2, pm10);

	map<string, Capteur>* tabCapteurs = new map<string, Capteur>();

	dataSet->lireCapteurs("Fichiers/Sensors.csv", tabCapteurs);

	OperationsDonnees * op = new OperationsDonnees();

	int qualite = op->qualiteAirMoyenne("2017-01-01", "2019-05-05", -8.0, -34.0, 36.0, 1.0 , o3, no2, so2, pm10, tabCapteurs);

	cout << "la qualité moyenne de l'air est : " << qualite << endl;
}

//Validé
void testLireMesuresComposantAir() {

	cout << "*** TEST DE LA LECTURE DES MESURES DES CAPTEURS ***" << endl;

	DataSet * dataSet =  new DataSet();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireMesures("Fichiers/MesuresCompletes.csv",o3,no2,so2,pm10);

	tabMesure_type mesuresO3 = o3->getTabMesure();
	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;
	for (it1 = mesuresO3.begin(); it1 != mesuresO3.end(); it1++)
	{
		cout << it1->first << endl;
		for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
			cout << it2->first << endl;
			for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
			{
				cout << "Mesure faite par : " << (*it3).getSensorID() << " | Valeur : " << (*it3).getValue() << endl;
			}
		}
	}

}

//Validé
void testLireCaracteristiquesCapteurs() {

	cout << "*** TEST DE LA LECTURE DES CARACTERISTIQUES DES CAPTEURS ***" << endl;

	DataSet * dataSet = new DataSet();
	map<string, Capteur>* tabCapteurs = new map<string,Capteur>();

	dataSet->lireCapteurs("Fichiers/Sensors.csv",tabCapteurs);

	for (map <string, Capteur>::iterator it = (*tabCapteurs).begin(); it != (*tabCapteurs).end(); it++) {
		cout << "Premier terme : " << it->first << endl;
		cout << "Longitude du deuxieme terme : " << (it->second).getLongitude() << endl;
	}

}

//Validé
void testLireComposantsAirs() {

	cout << "*** TEST DE LA LECTURE DES COMPOSANTS DE L'AIR ***" << endl;

	DataSet * dataSet = new DataSet();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireComposantsAirs("Fichiers/AttributeType.csv",o3,no2,so2,pm10);
	cout << "Pour O3 : " << endl;
	cout << "AttributeID = " << o3->getAttributeID() << " | Unite = " << o3->getUnite() << " | Description = " << o3->getDescription() << endl;

	cout << "Pour NO2 : " << endl;
	cout << "AttributeID = " << no2->getAttributeID() << " | Unite = " << no2->getUnite() << " | Description = " << no2->getDescription() << endl;

	cout << "Pour SO2 : " << endl;
	cout << "AttributeID = " << so2->getAttributeID() << " | Unite = " << so2->getUnite() << " | Description = " << so2->getDescription() << endl;

	cout << "Pour PM10 : " << endl;
	cout << "AttributeID = " << pm10->getAttributeID() << " | Unite = " << pm10->getUnite() << " | Description = " << pm10->getDescription() << endl;

}

int main() {

	cout << "Bienvenue sur l'application ! " << endl;
	cout << "Chargement des donnees en cours ..." << endl;

	// Appel aux fonctions de lecture
	DataSet * dataSet = new DataSet();
	map<string, Capteur>* tabCapteurs = new map<string, Capteur>();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	/*
	dataSet->lireComposantsAirs("Fichiers/AttributeType.csv", o3, no2, so2, pm10);
	dataSet->lireCapteurs("Fichiers/Sensors.csv", tabCapteurs);
	dataSet->lireMesures("Fichiers/Mesures.csv", o3, no2, so2, pm10);
	*/
	//testLireMesuresComposantAir();
	//cout << "Donnees chargees ! " << endl;

	//testQualiteAirMoyenne();
	ajouteFichierLog("Moyenne 03");

	//Menu
	/*
	bool estFini = false;
	while (!estFini) {
		cout << "Que souhaitez-vous faire ? " << endl;
	}
	*/
	

	//
	//Obligé pour qu'on voit que qql chose s'affiche !
	char * a = new char[10];
	cin >> a;
	cout << a;
	return 0;


}