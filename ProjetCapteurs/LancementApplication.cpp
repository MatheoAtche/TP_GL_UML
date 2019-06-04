#define CRT_SECURE_NO_WARNINGS

using namespace std;
#include <iostream>

#include "Capteur.h"
#include "ComposantAir.h"
#include "DataSet.h"
#include "Mesure.h"
#include "OperationsDonnees.h"

//PB dans addMesure
void testLireMesuresComposantAir() {

	cout << "*** TEST DE LA LECTURE DES MESURES DES CAPTEURS ***" << endl;

	DataSet * dataSet =  new DataSet();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireMesures("Fichiers/Mesures.csv",o3,no2,so2,pm10);

	tabMesure_type mesuresO3 = o3->getTabMesure();
	tabMesure_type::iterator it1;
	map<int, vector<Mesure>>::iterator it2;
	vector<Mesure>::iterator it3;
	for (it1 = mesuresO3.begin(); it1 != mesuresO3.end(); it1++)
	{
		for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
		{
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

void testCalculsComposantAir() {

	DataSet * dataSet = new DataSet();
	map<string, Capteur>* tabCapteurs = new map<string, Capteur>();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireComposantsAirs("Fichiers/AttributeType.csv", o3, no2, so2, pm10);
	dataSet->lireCapteurs("Fichiers/Sensors.csv", tabCapteurs);
	dataSet->lireMesures("Fichiers/MesuresCompletes.csv", o3, no2, so2, pm10);

	string dateDebut = "2017-01-01T00:00:10.0100000";
	string dateFin = "2018-01-01T00:00:24.5880000";

	double lat1 = -31.0;
	double longi1 = -90.0;
	double lat2 = 40.0;
	double longi2 = -34.0;

	double moyenneO3 = o3->moyenne(dateDebut, dateFin, lat1, longi1, lat2, longi2, tabCapteurs);
	cout << "Moyenne du composant o3 : " << moyenneO3<<endl;

	double ecartTypeO3 = o3->ecartType(dateDebut, dateFin, lat1, longi1, lat2, longi2, tabCapteurs);
	cout << "Ecart Type du composant o3 : " << ecartTypeO3 << endl;

	double minimumO3 = o3->minimum(dateDebut, dateFin, lat1, longi1, lat2, longi2, tabCapteurs);
	cout << "Minimum du composant o3 : " << minimumO3 << endl;

	double maximumO3 = o3->maximum(dateDebut, dateFin, lat1, longi1, lat2, longi2, tabCapteurs);
	cout << "Maximum du composant o3 : " << maximumO3 << endl;
}

void testValeursSimilaires() {
	DataSet * dataSet = new DataSet();
	map<string, Capteur>* tabCapteurs = new map<string, Capteur>();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireComposantsAirs("Fichiers/AttributeType.csv", o3, no2, so2, pm10);
	dataSet->lireCapteurs("Fichiers/Sensors.csv", tabCapteurs);
	dataSet->lireMesures("Fichiers/MesuresCompletes.csv", o3, no2, so2, pm10);

	string dateDebut = "2017-01-01T00:00:10.0100000";
	string dateFin = "2018-01-01T00:00:24.5880000";

	double epsilon = 10.0;

	multimap<string, string> mapValSim = o3->valeursSimilaires(dateDebut, dateFin, epsilon);
	cout << "Paires de capteurs :" << endl;
	for (multimap <string, string>::iterator it = mapValSim.begin(); it != mapValSim.end(); it++) {
		cout << "{" << it->first <<", ";
		cout << it->second << "}"<< endl;
	}

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
	/*testLireMesuresComposantAir();
	cout << "Donnees chargees ! " << endl;*/

	//Menu
	/*
	bool estFini = false;
	while (!estFini) {
		cout << "Que souhaitez-vous faire ? " << endl;
	}
	*/
	
	//testCalculsComposantAir();
	testValeursSimilaires();

	//
	//Obligé pour qu'on voit que qql chose s'affiche !
	char * a = new char[10];
	cin >> a;
	cout << a;
	return 0;


}