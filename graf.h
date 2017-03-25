#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define		NO_EDGE  0			//wartosc wagi oznaczajecej brak krawedzi
#define		MAX_INT	 2147483647


using namespace std; 




class krawedz{

public:
	int po;			//poczatek krawedzi
	int ko;			//koniec krawedzi
	int waga;		//waga


};




class graf{

	void zrob_sasiadow(int lw);
	bool czy_w_nalezy(int w, vector<int> k);
	krawedz najmniejsza(int v);
	krawedz graf::najmniejsza(vector<int> k);
	int **sasiedzi2;		//pomocnicza macierz sasiedztwa
	int suma_MST();



public:
	int lk;             //liczba krawedzi
	int lw;				//liczba wierzcholkow
	int wp;				//wierzcho³ek pocz¹tkowy
	int wk;				//wierzcho³ek koñcowy
	int **sasiedzi;		//macierz sasiedztwa
	krawedz *krawedzi;  //tablica krawedzi
	krawedz *MST;		//minimalne drzewo rozpinajace
	vector<int> *d;		//najkrotsze drogi

	int s_MST;
	vector<int> s_drog;


	graf();

	bool czy_pusty();
	void wczytaj(string nazwa);
	void wyswietl_sasiadow();
	void wyswietl_dane();
	void wyswietl_MST();
	void wyswietl_MR();
	void zapisz(string nazwa);
	bool czy_krawedz(int n, int m);
	void sortuj_krawedzie();
	void generuj_graf(int wierz, double ro);

	void Dijkstra();
	void Bellman();



};


#endif