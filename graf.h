#ifndef GRAF_H
#define GRAF_H
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define		NO_EDGE		0				//wartosc wagi oznaczajecej brak krawedzi

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


public:
	int lk;             //liczba krawedzi
	int lw;				//liczba wierzcholkow
	int wp;				//wierzcho³ek pocz¹tkowy
	int wk;				//wierzcho³ek koñcowy
	int **sasiedzi;		//macierz sasiedztwa
	krawedz *krawedzi;  //tablica krawedzi
	krawedz *MST;		//minimalne drzewo rozpinajace


	graf();

	bool czy_pusty();
	void wczytaj(string nazwa);
	void wyswietl_sasiadow();
	void wyswietl_dane();
	void wyswietl_MST();
	void zapisz(string nazwa);
	bool czy_krawedz(int n, int m);
	void sortuj_krawedzie();
	void Kruskal();
	void Prim();


};


#endif