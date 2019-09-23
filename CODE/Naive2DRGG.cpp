#include <iostream>
#include <vector>
#include <math.h>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct {
	float x;
	float y;
} Punto;

double distEucli (double p, double q) {
	return sqrt(pow((q-p),2)); 
}

double dist (float a, float b, float c, float d) {
	return sqrt (pow((a-c),2)+pow((b-d),2));
}

vector <Punto> generateSamples (int n) {
	vector <Punto> V (n);
	for (int i = 0; i < n; ++i) {
		V[i].x = (float)(rand() % 10001)/10000;
		V[i].y = (float)(rand() % 10001)/10000;
	}
	return V;
}

void addConnection (double p, double q, vector<vector<int> > & G) {
	G[p][q] = 1;
	G[q][p] = 1;
}

// el puntero del vector es el identificador del punto
int main() {
	srand((unsigned) time(NULL));
	int n = 100;
	float r = 0.0;	
	// cout << "radio = " <<   r << endl;
	vector <Punto> V = generateSamples (n);
	while (r <= 1) {
		vector <vector <int> > G (n, vector<int>(n,0));
		/* cout << "V = ";
		for (int i = 0; i < n; ++i) {
			cout << V[i] << " ";
		}
		cout << endl;*/
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (dist(V[i].x,V[i].y,V[j].x,V[j].y) <= r) {
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
				if (G[i][j] ==0) cout << "r= "<< r << " i= " << i << " " << "j= " << j << " distancia =" << dist(V[i].x,V[i].y,V[j].x,V[j].y) <<  endl;
			}
			//cout << endl;
		}*/
		//cout << endl << endl << endl;
		r += (float)(rand() % 10001)/1000000;
	}
}
