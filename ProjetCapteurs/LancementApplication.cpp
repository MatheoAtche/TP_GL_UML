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

	of << chaineDate << "---->" << typeAction << endl;
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

//Valide
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

//Valide
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

//Valide
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
//Valide
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
	cout << "Moyenne du composant o3 : " << moyenneO3 << endl;

	double ecartTypeO3 = o3->ecartType(dateDebut, dateFin, lat1, longi1, lat2, longi2, tabCapteurs);
	cout << "Ecart Type du composant o3 : " << ecartTypeO3 << endl;

	double minimumO3 = o3->minimum(dateDebut, dateFin, lat1, longi1, lat2, longi2, tabCapteurs);
	cout << "Minimum du composant o3 : " << minimumO3 << endl;

	double maximumO3 = o3->maximum(dateDebut, dateFin, lat1, longi1, lat2, longi2, tabCapteurs);
	cout << "Maximum du composant o3 : " << maximumO3 << endl;
}

//Valide
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
		cout << "{" << it->first << ", ";
		cout << it->second << "}" << endl;
	}

}

int main() {

	cout << "Bienvenue sur l'application ! " << endl;

	DataSet * dataSet = new DataSet();
	map<string, Capteur>* tabCapteurs = new map<string, Capteur>();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();
	OperationsDonnees * op = new OperationsDonnees();
	


	//Lecture des donnees
	cout << "Entrez le chemin du fichier contenant vos informations de capteurs" << endl;
	string cheminCapteur;
	cin >> cheminCapteur;
	dataSet->lireCapteurs(cheminCapteur,tabCapteurs);

	cout << "Entrez le chemin du fichier contenant vos informations sur les composants de l'air" << endl;
	string cheminComposant;
	cin >> cheminComposant;
	dataSet->lireComposantsAirs(cheminComposant,o3,no2,so2,pm10);
	cout << "Pour O3 : " << endl;
	cout << "AttributeID = " << o3->getAttributeID() << " | Unite = " << o3->getUnite() << " | Description = " << o3->getDescription() << endl;
	cout << "Pour NO2 : " << endl;
	cout << "AttributeID = " << no2->getAttributeID() << " | Unite = " << no2->getUnite() << " | Description = " << no2->getDescription() << endl;
	cout << "Pour SO2 : " << endl;
	cout << "AttributeID = " << so2->getAttributeID() << " | Unite = " << so2->getUnite() << " | Description = " << so2->getDescription() << endl;
	cout << "Pour PM10 : " << endl;
	cout << "AttributeID = " << pm10->getAttributeID() << " | Unite = " << pm10->getUnite() << " | Description = " << pm10->getDescription() << endl;

	cout << "Entrez le chemin du fichier contenant vos mesures" << endl;
	string cheminMesure;
	cin >> cheminMesure;
	dataSet->lireMesures(cheminMesure,o3,no2,so2,pm10);


	//Menu
	bool estFini = false;
	while (!estFini) {
		cout << "------------------- Menu Principal -------------------" << endl;
		cout << "1 : Calcul d'informations agregees (moyenne, ecart-type, minimum, maximum)" << endl;
		cout << "2 : Calculer la qualite de l'air" << endl;
		cout << "3 : Chercher des capteurs ayant des valeurs similaires" << endl;
		cout << "4 : Verifier le bon fonctionnement des capteurs" << endl;
		cout << "Que souhaitez-vous faire ? " << endl;
		int choix;
		cin >> choix;
		while(cin.fail()) {
			cout << "Entrez un entier !" <<endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> choix;
		}
		string compo, dateDebut, dateFin;
		double lat1, lat2, long1, long2;
		int secondChoice;
		double epsilon;
		multimap<string,string> valsimi;
		set <string> capteursNonFonctionnel;
		bool check = false;
		multimap<string, string>::iterator it1;
		set<string>::iterator it2;
		switch (choix)
		{
		case 1:
			cout << "Sur quel composant voulez vous calculer les informations ? (no2, so2, pm10 ou o3)" << endl;
			cin >> compo;
			cout << "Entrez la date de debut (aaaa-mm-jjThh:mm:ss)" << endl;
			cin >> dateDebut;
			cout << "Entrez la date de fin (aaaa-mm-jjThh:mm:ss)" << endl;
			cin >> dateFin;
			cout << "Entrez la premiere latitude" << endl;
			cin >> lat1;
			cout << "Entrez la premiere longitude" << endl;
			cin >> long1;
			cout << "Entrez la seconde latitude" << endl;
			cin >> lat2;
			cout << "Entrez la seconde longitude" << endl;
			cin >> long2;
			if (compo == "no2")
			{
				cout << "la moyenne de no2 est " << no2->moyenne(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs);
				cout << " " << no2->getUnite() << endl;
				cout << "l'ecart-type est : " << no2->ecartType(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) <<endl;
				cout << "la valeur maximale est : " << no2->maximum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
				cout << "la valeur minimale est : " << no2->minimum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
				ajouteFichierLog("Calcul no2");
			}
			else if (compo == "o3")
			{
				cout << "la moyenne de o3 est " << o3->moyenne(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs);
				cout << " " << o3->getUnite() << endl;
				cout << "l'ecart-type est : " << o3->ecartType(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) <<endl;
				cout << "la valeur maximale est : " << o3->maximum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
				cout << "la valeur minimale est : " << o3->minimum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
			}
			else if (compo == "so2")
			{
				cout << "la moyenne de so2 est " << so2->moyenne(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs);
				cout << " " << so2->getUnite() << endl;
				cout << "l'ecart-type est : " << no2->ecartType(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) <<endl;
				cout << "la valeur maximale est : " << so2->maximum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
				cout << "la valeur minimale est : " << so2->minimum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
			}
			else if (compo == "pm10")
			{
				cout << "la moyenne de pm10 est " << pm10->moyenne(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs);
				cout << " " << pm10->getUnite() << endl;
				cout << "l'ecart-type est : " << no2->ecartType(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) <<endl;
				cout << "la valeur maximale est : " << pm10->maximum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
				cout << "la valeur minimale est : " << pm10->minimum(dateDebut,dateFin,lat1,long1,lat2,long2,tabCapteurs) << " " << no2->getUnite() << endl;
			}
			else
			{
				cout << "votre composant n'est pas connu (pensez a tout ecrire en minuscule)" << endl;
			}
			break;
		
		case 2:
			cout << "Voulez vous calculer la qualite de l'air a un point precis (1)" << endl;
			cout << "ou la qualite moyenne dans une certaine zone geographique (2) ?" << endl;
			cin >> secondChoice;
			while(cin.fail()) {
				cout << "Entrez un entier !" <<endl;
				cin.clear();
				cin.ignore(256,'\n');
				cin >> secondChoice;
			}
			if (secondChoice==1)
			{
				cout << "Entrez la date de debut (aaaa-mm-jjThh:mm:ss)" << endl;
				cin >> dateDebut;
				cout << "Entrez la date de fin (aaaa-mm-jjThh:mm:ss)" << endl;
				cin >> dateFin;
				cout << "Entrez la latitude exacte" << endl;
				cin >> lat1;
				cout << "Entrez la longitude exacte" << endl;
				cin >> long1;
				cout << "L'indice ATMO de ce point est : " << op->qualiteAirPointFixe(dateDebut,dateFin,lat1,lat2,o3,no2,so2,pm10,tabCapteurs) << endl;
			}
			else if (secondChoice==2)
			{
				cout << "Entrez la date de debut (aaaa-mm-jjThh:mm:ss)" << endl;
				cin >> dateDebut;
				cout << "Entrez la date de fin (aaaa-mm-jjThh:mm:ss)" << endl;
				cin >> dateFin;
				cout << "Entrez la premiere latitude" << endl;
				cin >> lat1;
				cout << "Entrez la premiere longitude" << endl;
				cin >> long1;
				cout << "Entrez la seconde latitude" << endl;
				cin >> lat2;
				cout << "Entrez la seconde longitude" << endl;
				cin >> long2;
				cout << "L'indice ATMO de cette zone geographique est : " << op->qualiteAirMoyenne(dateDebut,dateFin,lat1,long1,lat2,long2,o3,no2,so2,pm10,tabCapteurs);
			}
			else
			{
				cout << "choix inconnu" << endl;
			}
			break;

		case 3:
			cout << "Sur quel composant voulez vous chercher des valeurs similaires ? (no2, so2, pm10 ou o3)" << endl;
			cin >> compo;
			cout << "Entrez la date de debut (aaaa-mm-jjThh:mm:ss)" << endl;
			cin >> dateDebut;
			cout << "Entrez la date de fin (aaaa-mm-jjThh:mm:ss)" << endl;
			cin >> dateFin;
			cout << "Entrez la tolerance pour vos valeurs similaires (epsilon)" << endl;
			cin >> epsilon;
			
			if (compo == "no2")
			{
				valsimi = no2->valeursSimilaires(dateDebut,dateFin,epsilon);
				check = true;
			}
			else if (compo == "o3")
			{
				valsimi = o3->valeursSimilaires(dateDebut,dateFin,epsilon);
				check = true;
			}
			else if (compo == "so2")
			{
				valsimi = so2->valeursSimilaires(dateDebut,dateFin,epsilon);
				check = true;
			}
			else if (compo == "pm10")
			{
				valsimi = pm10->valeursSimilaires(dateDebut,dateFin,epsilon);
				check = true;
			}
			else
			{
				cout << "votre composant n'est pas connu (pensez a tout ecrire en minuscule)" << endl;
			}
			
			if(check)
			{
				cout << "les id des capteurs ayant des valeurs similaires sont : " << endl;
				
				for (it1=valsimi.begin(); it1!=valsimi.end(); it1++)
				{
					cout << (*it1).first << " " << (*it1).second << endl;
				}
			}
			break;

		case 4:
			cout << "Entrez la date de debut (aaaa-mm-jjThh:mm:ss)" << endl;
			cin >> dateDebut;
			cout << "Entrez la date de fin (aaaa-mm-jjThh:mm:ss)" << endl;
			cin >> dateFin;
			cout << "Verification du bon fonctionnement des capteurs sur cette periode..." << endl;
			capteursNonFonctionnel = op->bonFonctionnementCapteurs(dateDebut,dateFin,o3,no2,so2,pm10);
			cout << "les capteurs non fonctionnel sont : " << endl;
			
			for (it2=capteursNonFonctionnel.begin(); it2!=capteursNonFonctionnel.end(); it2++)
			{
				cout << *it2 << endl;
			}
			break;
		
		default:
			estFini=true;
			break;
		}
	}
	

	//testLireMesuresComposantAir();
	//cout << "Donnees chargees ! " << endl;

	//testMoyenne();
	//cout << "Moyenne o3 " << endl;


	//
	//Obligï¿½ pour qu'on voit que qql chose s'affiche !
	/*char * a = new char[10];
	cin >> a;
	cout << a;
	return 0;*/


}