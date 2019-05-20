#define CRT_SECURE_NO_WARNINGS

using namespace std;
#include <iostream>

#include "Capteur.h"
#include "ComposantAir.h"
#include "DataSet.h"
#include "Mesure.h"
#include "OperationsDonnees.h"

void testLireMesuresComposantAir() {

	DataSet * dataSet =  new DataSet();
	ComposantAir * o3 = new ComposantAir();
	ComposantAir * no2 = new ComposantAir();
	ComposantAir * so2 = new ComposantAir();
	ComposantAir * pm10 = new ComposantAir();

	dataSet->lireMesures("data_10sensors_1year.cvs",o3,no2,so2,pm10);

}


int main() {

	//Obligé pour qu'on voit que qql chose s'affiche !
	char * a = new char[10];
	cout << "coucou" << endl;


	//Tests
	//testLireMesuresComposantAir();

	//
	cin >> a;
	cout << a;
	return 0;


}