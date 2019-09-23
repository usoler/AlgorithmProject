#include <iostream>
#include <vector>
#include <math.h>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

double distEucli (double p, double q) {
	return sqrt(pow((q-p),2)); 
}

vector <double> generateSamples (int n) {
	vector <double> V (n);
	for (int i = 0; i < n; ++i) {
		V[i] = (float)(rand() % 10001)/10000;
	}
	return V;
}

void addConnection (double p, double q, vector<vector<int> > & G) {
	G[p][q] = 1;
	G[q][p] = 1;
}

int main() {
	srand((unsigned) time(NULL));
	int n = 100;
	float r = 0.0;	
	// cout << "radio = " <<   r << endl;
	vector <double> V = generateSamples (n);
	while (r <= 1) {
		vector <vector <int> > G (n, vector<int>(n,0));
		/* cout << "V = ";
		for (int i = 0; i < n; ++i) {
			cout << V[i] << " ";
		}
		cout << endl;*/
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (distEucli(V[i],V[j]) <= r) {
					addConnection(i,j,G);
				}
			}
		}
		//Mostrar grafo
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
		//cout << endl << endl << endl;
		r += (float)(rand() % 10001)/1000000;
	}
}
