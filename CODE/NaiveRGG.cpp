#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
using namespace std;

double distEucli (double p, double q) {
	double res = q-p;
	if (res < 0) return -res;
	return res;
}

vector <double> generateSamples (int n) {
	vector <double> V (n);
	for (int i = 0; i < n; ++i) {
		if (i%2 ==0) {
			V[i] = ((double)(rand() % 100001)/100000)*9.0;
		}
		V[i] = (double)(rand() % 10001)/10000;
	}
	return V;
}

void addConnection (double p, double q, vector<vector<int> > & G) {
	G[p][q] = 1;
	G[q][p] = 1;
}

void addConnectionListaAdya (double p, double q, vector<vector<int> > & lista) {
	lista[p].push_back(q);
	lista[q].push_back(p);
}

int main(int argc, char** argv) {
	srand(time(NULL));
	int n = 10000;
	double r = 0.0;	
	//cout << "radio = " <<   r << endl;
	vector <double> V = generateSamples (n);
	while (r <= 1) {
		//cout << "radio = " <<   r << endl;
		int aristas = 0;
		//PARA MATRIZ
		//vector <vector <int> > G (n, vector<int>(n,0));
		//PARA LISTA
		vector <vector <int> > lista_adya (n,vector<int>(0));
		/*cout << "V = ";
		for (int i = 0; i < n; ++i) {
			cout << V[i] << " ";
		}
		cout << endl;*/
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				
				if (distEucli(V[i],V[j]) <= r) {
					//cout <<"dist = " << distEucli(V[i],V[j]) << " Radio = " << r << endl;
					//PARA MATRIZ DE ADYACENCIA
					//addConnection(i,j,G);
					//PARA LISTA DE ADYACENCIA
					addConnectionListaAdya(i,j,lista_adya);
					aristas += 1;
				}
			}
		}
		//Mostrar grafo en lista
		/*for (int i = 0; i < n; i++) {
			cout << "lista[" << i << "] = ";
			for (int j = 0; j < lista_adya[i].size(); j++) {
				cout << lista_adya[i][j] << " ";
			}
			cout << endl;
		}*/	
		//Mostrar grafo en matriz
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout <<  G[i][j] << " ";
			}
			cout << endl;
		}*/
		//Observar que todo este como se espera
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (G[i][j] ==0) cout << "r= "<< r << " i= " << i << " " << "j= " << j <<  " " << "valor i= " << V[i]<< " Valor j=" << V[j] << " distancia =" << distEucli(V[i],V[j])<<  endl;
			}
			//cout << endl;
		}*/
		Graph graph = Graph(n,aristas,lista_adya);
		//cout << aristas << endl;
		//cout << graph.getNumOfConnectedComponents()<< endl;
		r += (double)(rand() % 101)/1000000;
		if (graph.getNumOfConnectedComponents()==1) {
			//cout << r << endl;
			r = 2;
		}
		//cout << endl << endl << endl;
	}
	return 0;

