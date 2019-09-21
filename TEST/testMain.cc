/**
 * Created by Luis Oriol Soler Cruz on 21/09/19
 */
#include <iostream>
#include "Graph.h"

using namespace std;

typedef vector<vector<int>> AdjacentList;
typedef vector<vector<int>> ConnectedComponents;

void make_adjacentList1(AdjacentList &);
void make_adjacentList2(AdjacentList &);
void print_component (vector<int> &);
void print_connected_components (ConnectedComponents &);

int main() {
	// ------------- TEST 1 -------------
	// 3 componentes, 0-1-2, 3-4, 5-6-7-8
	int n = 9;
	int m = 8;
	AdjacentList adjacentList1(n, vector<int>());
	make_adjacentList1(adjacentList1);

	Graph graph1 = Graph(n, m, adjacentList1);
	cout << "Num of connected components: " << graph1.getNumOfConnectedComponents() << endl;
	ConnectedComponents connectedComponents = graph1.getConnectedComponents();
	print_connected_components(connectedComponents);

	// ------------- TEST 2 -------------
	// 5 componentes, 0, 1-2, 3-4-5-6, 7, 8-9-10-11
	n = 12;
	m = 10;
	AdjacentList adjacentList2(n, vector<int>());
	make_adjacentList2(adjacentList2);

	Graph graph2(n, m, adjacentList2);

	cout << "Num of connected components: " << graph2.getNumOfConnectedComponents() << endl;
	connectedComponents = graph2.getConnectedComponents();
	print_connected_components(connectedComponents);
}

void make_adjacentList1(AdjacentList &adjacentList1) {
	adjacentList1[0].push_back(1);
	adjacentList1[0].push_back(2);

	adjacentList1[1].push_back(0);
	adjacentList1[1].push_back(2);

	adjacentList1[2].push_back(0);
	adjacentList1[2].push_back(1);

	adjacentList1[3].push_back(4);

	adjacentList1[4].push_back(3);

	adjacentList1[5].push_back(6);
	adjacentList1[5].push_back(7);

	adjacentList1[6].push_back(5);
	adjacentList1[6].push_back(8);

	adjacentList1[7].push_back(5);
	adjacentList1[7].push_back(8);

	adjacentList1[8].push_back(6);
	adjacentList1[8].push_back(7);
}

void make_adjacentList2(AdjacentList &adjacentList2) {
	adjacentList2[1].push_back(2);

	adjacentList2[2].push_back(1);

	adjacentList2[3].push_back(4);
	adjacentList2[3].push_back(5);

	adjacentList2[4].push_back(3);
	adjacentList2[4].push_back(5);
	adjacentList2[4].push_back(6);

	adjacentList2[5].push_back(3);
	adjacentList2[5].push_back(4);
	adjacentList2[5].push_back(6);

	adjacentList2[6].push_back(4);
	adjacentList2[6].push_back(5);

	adjacentList2[8].push_back(9);
	adjacentList2[8].push_back(11);

	adjacentList2[9].push_back(8);
	adjacentList2[9].push_back(10);	

	adjacentList2[10].push_back(9);
	adjacentList2[10].push_back(11);

	adjacentList2[11].push_back(8);
	adjacentList2[11].push_back(10);
}

void print_connected_components (ConnectedComponents &connectedComponents) {
	for (int i = 0; i < connectedComponents.size(); ++i) {
		cout << "Connected component #" << i+1 << ":" << endl;
		print_component(connectedComponents[i]);
		cout << endl;
	}
}

void print_component (vector<int> &component) {
	for (int i = 0; i < component.size(); ++i) {
		cout << component[i] << " ";
	}
}