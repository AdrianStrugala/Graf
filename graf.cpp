#include "graf.h"


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
graf::graf(){
	lw=0;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
bool graf::czy_pusty(){
	if(lw==0) return true;
	else return false;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void graf::wczytaj(string nazwa){
			fstream plik;
			plik.open(nazwa, ios::in);
	if( plik.good()==true){
			
		plik >> lk >> lw >> wp >> wk;



		krawedzi= new krawedz[lk];
		for(int i=0; i<lk; i++){
			plik >> krawedzi[i].po >> krawedzi[i].ko >> krawedzi[i].waga;
		}
		zrob_sasiadow(lw);
	}

	plik.close();
	}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::zrob_sasiadow(int lw){
		sasiedzi= new int *[lw];
		for(int i=0; i<lw;i++){
			sasiedzi[i]=new int [lw];
		}

		for(int j=0; j<lw; j++){
			for(int i=0; i<lw; i++){
			sasiedzi[j][i] = NO_EDGE;
			}}

		for(int j=0; j<lk; j++){
			sasiedzi[krawedzi[j].po][krawedzi[j].ko]=sasiedzi[krawedzi[j].ko][krawedzi[j].po]=krawedzi[j].waga;
		}

	}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::wyswietl_sasiadow(){

		if(!czy_pusty()){
		cout<< "Macierz sasiedztwa (wag)" <<endl;
			for(int j=0; j<lw; j++){
				for(int i=0; i<lw; i++){
					cout << sasiedzi[j][i] << " ";
				}
			cout<<endl;		}
		cout<<endl;
		}
	};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::wyswietl_dane(){

		if(!czy_pusty()){
		cout<< "Dane:" <<endl;
			cout<<lk << " " << lw << " " << wp << " " << wk << " "<< endl;
		for(int i=0; i<lk; i++){
			cout << krawedzi[i].po << " " << krawedzi[i].ko << " " << krawedzi[i].waga << endl;
		}
		}
	}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::wyswietl_MST(){

		cout<<endl<<"MST:"<<endl;
		for(int i=0; i<lw-1; i++){
			cout << MST[i].po << " " << MST[i].ko << " " << MST[i].waga << endl;

		}
	}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::zapisz(string nazwa){
			fstream plik;
			plik.open(nazwa, ios::out);
	if( plik.good()==true){
			
		plik << "Dane:" <<endl;
			plik << lk << " " << lw << " " << wp << " " << wk << " "<< endl;
		for(int i=0; i<lk; i++){
			plik << krawedzi[i].po << " " << krawedzi[i].ko << " " << krawedzi[i].waga << endl;

		}
	}

	plik.close();
	};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	bool graf::czy_krawedz(int n, int m){

		if(n>lw || m>lw){
			cout<< "Podano niepoprawny wierzcholek" <<endl;
			return false;
		}
		else{
			if(sasiedzi[n][m]!=NO_EDGE) return true;
			else return false;
		}
	}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	krawedz graf::najmniejsza(int v){
		
		krawedz min;
		min.po=v;
		min.waga=2147483647;
		for(int i=0; i<lw; i++){
			if(sasiedzi[v][i]<min.waga && sasiedzi[v][i]!=NO_EDGE){
				min.ko=i;
				min.waga=sasiedzi[v][i];
			}
		}
	return min;	
	}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	krawedz graf::najmniejsza(vector<int> k){

		krawedz min;
		min.waga=2147483647;
		for(int i=0; i<k.size(); i++){
			for(int j=0; j<lw; j++){
				if(sasiedzi2[k[i]][j]<min.waga && sasiedzi2[k[i]][j]!=NO_EDGE){
					min.po=k[i];
					min.ko=j;
					min.waga=sasiedzi2[k[i]][j];			
				}
			}
		}
		return min;
	}		

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::sortuj_krawedzie(){

        for (int i=0; i < lk; i++)
        for (int j=0; j < lk-1; j++)
        if ( krawedzi[j].waga > krawedzi[j+1].waga){
		swap(krawedzi[j],krawedzi[j+1]);
        }
	}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void graf::Kruskal(){

	int j=0;					//zmienna pomocnicza
	int x,y;

	MST= new krawedz[lw-1];		//MST

	vector<int> *k;				//tablica klastrow
	k= new vector<int>[lk];

	for(int i=0; i<lw; i++){		//w kazdym klastrze jest jeden wierzcholek
		k[i].push_back(i);
	}

	sortuj_krawedzie();			//krawedzie sa posortowane


	for(int i=0; j<lw-1; i++){		//glowna petla	
		for(int a=0; a<lw; a++){	//znajdowanie wierzcholka poczatkowego w tablicy klastrow
			if(czy_w_nalezy(krawedzi[i].po, k[a])) 
				x=a;
		}
		for(int a=0; a<lw; a++){	//znajdowanie wierzcholka koncowego w tablicy klastrow
			if(czy_w_nalezy(krawedzi[i].ko, k[a])) 
				y=a;
		}
		if(x!=y){					//jesli wierzcholek poczatkowy i koncowy nie sa w tym samym klastrze
			MST[j]=krawedzi[i];			
			j++;	
			k[x].reserve(k[x].size()+k[y].size());					// prealokowanie pamieci przy laczeniu klastrow
			k[x].insert( k[x].end(), k[y].begin(), k[y].end() );    // dodawanie klastrow
			k[y].clear();											//czyszczenie skopiowanego klastra

		}	
	}
	delete[] k;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::Prim(){

		int j=0;									//zmienne pomocnicze
		vector<int> k;								//do wektora naleza wszystkie wierzcholki uwzglednione w MST
		MST= new krawedz[lw-1];						//MST
		k.push_back(rand()%lw);


		sasiedzi2= new int *[lw];
		for(int i=0; i<lw;i++){
			sasiedzi2[i]=new int [lw];
		}

		for(int j=0; j<lw; j++){
			for(int i=0; i<lw; i++){
			sasiedzi2[j][i] = sasiedzi[j][i];
			}
		}

		for(int i=0; j<lw-1; i++){					//glowna petla programu
			MST[j]=najmniejsza(k);
			k.push_back(MST[j].ko);
			sasiedzi2[MST[j].ko][MST[j].po]=sasiedzi2[MST[j].po][MST[j].ko]=NO_EDGE;
			j++;
		}
	}
	/*
	void graf::Kruskal(){

		int j=0;									//zmienne pomocnicze
		vector<int> k;								//do wektora naleza wszystkie wierzcholki uwzglednione w MST

		sortuj_krawedzie();							//sortowanie krawedzi

		MST= new krawedz[lw-1];						//MST o rozmiarze l.wierzcholkow-1

		k.push_back(krawedzi[0].po);				//krawedz o indeksie 0 na pewno bedzie nalezala do MST
		k.push_back(krawedzi[0].ko);
		MST[j]=krawedzi[0];
		j++;


		
		for(int i=1; k.size() < lw; i++){
			if(czy_w_nalezy(krawedzi[i].po, k) && !czy_w_nalezy(krawedzi[i].ko, k)){
				k.push_back(krawedzi[i].ko);								//jesli nie ma ko dodaj ko do wektora i krawedz do MST
				MST[j]=krawedzi[i];
				j++;
			}
			if(!czy_w_nalezy(krawedzi[i].po, k) && czy_w_nalezy(krawedzi[i].ko, k)){
				k.push_back(krawedzi[i].po);								//jesli nie ma po dodaj po do wektora i krawedz do MST
				MST[j]=krawedzi[i];
				j++;
			}
			if(!czy_w_nalezy(krawedzi[i].po, k) && !czy_w_nalezy(krawedzi[i].ko, k)){

				MST[j]=najmniejsza(krawedzi[i].po, krawedzi[i].po, k);
				k.push_back(krawedzi[i].po);
				k.push_back(krawedzi[i].ko);
				MST[j]=krawedzi[i];
				j++;

			}
		}	


	}
	*/

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	bool graf::czy_w_nalezy(int w, vector<int> k){
			
		for(int i=0; i < k.size(); i++){
				if (w==k[i]) 
					return true;
			}
			return false;
	}
