//Adrian Strugala
//Jest Kruskal i Prim. 
//Trwaja prace nad Dijiskra (na grafie nieskierowanym)
//Wersja tymczasowa, wszystko w jednym programie

#include <fstream>
#include <iostream>
#include <ctime>

#include "graf.h"
using namespace std;

int main(){

	int po,ko,czas,caly_czas=0;
	int lw,ro;
	int ILOSC=100;


	string nazwa = "path_1.txt";


	graf pierwszy;

	pierwszy.wczytaj(nazwa);

	pierwszy.wyswietl_sasiadow();
pierwszy.Djikstra();
	pierwszy.Bellman();
	pierwszy.wyswietl_MR();



/*
	int zm=0;

	while(zm!=5){

	cout << endl << "Wybierz opcje: " << endl;
	cout << "1 - podaj liczbe wierzcholkow grafu." << endl;
	cout << "2 - podaj gestosc grafu w %." << endl;
	cout << "3 - Kruskal." << endl;
	cout << "4 - Prim." << endl;
	cout << "5 - Wyjscie." << endl;

	cin>>zm;

	switch(zm){

	case 1:
		cout<<"Podaj liczbe wierzcholkow w grafie"<<endl;
		cin>>lw;
	break;

	case 2:
		cout<<"Podaj gestosc grafu w %"<<endl;
		cin>>ro;
	break;

	case 3:
		caly_czas=0;
		pierwszy.generuj_graf(lw, ro);
		for(int i=0; i<ILOSC; i++){
		po=clock();
		pierwszy.Kruskal();
		ko=clock();
		czas=ko-po;
		caly_czas+=czas;
		}
		cout << "CZAS: " << caly_czas/ILOSC <<endl;
	break;

	case 4:
		caly_czas=0;
		pierwszy.generuj_graf(lw, ro);
		for(int i=0; i<ILOSC; i++){
		po=clock();
		pierwszy.Prim();
		ko=clock();
		czas=ko-po;
		caly_czas+=czas;
		}
		cout << "CZAS: " << caly_czas/ILOSC <<endl;
	break;

	case 5:
		cout<< "KONIEC" <<endl;
		break;

	default:
		cout<< "Niepoeprawna opcja" <<endl;
		break;

	};
	};

*/

	system ("pause");



};
