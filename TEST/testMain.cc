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
void make_adjacentList3(AdjacentList &);
void make_adjacentList4(AdjacentList &);
void make_adjacentList5(AdjacentList &);
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
	graph1.getConnectedComponents();
	graph1.getConnectedComponents();
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

	// ------------- TEST 3 -------------
	// 0-1-2
	n = 3;
	m = 3;
	AdjacentList adjacentList3(n, vector<int>());
	make_adjacentList3(adjacentList3);

	Graph graph3(n, m, adjacentList3);

	if (graph3.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}

	// ------------- TEST 4 -------------
	// 0-1
	n = 2;
	m = 1;
	AdjacentList adjacentList4(n, vector<int>());
	make_adjacentList4(adjacentList4);

	Graph graph4(n, m, adjacentList4);

	if (graph4.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}

	// ------------- TEST 5 -------------
	// 0-1-2-3-4
	n = 5;
	m = 4;
	AdjacentList adjacentList5(n, vector<int>());
	make_adjacentList5(adjacentList5);

	Graph graph5(n, m, adjacentList5);

	if (graph5.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}

	// ------------- TEST 6 -------------
	// 3 componentes, 0-1-2, 3-4, 5-6-7-8
	if (graph1.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}

	// ------------- TEST 7 -------------
	// 5 componentes, 0, 1-2, 3-4-5-6, 7, 8-9-10-11
	if (graph2.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}
}

void make_adjacentList1 (AdjacentList &adjacentList1) {
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

void make_adjacentList2 (AdjacentList &adjacentList2) {
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

void make_adjacentList3 (AdjacentList &adjacentList3) {
	adjacentList3[0].push_back(1);
	adjacentList3[0].push_back(2);

	adjacentList3[1].push_back(0);
	adjacentList3[1].push_back(2);

	adjacentList3[2].push_back(0);
	adjacentList3[2].push_back(1);
}

void make_adjacentList4 (AdjacentList &adjacentList4) {
	adjacentList4[0].push_back(1);

	adjacentList4[1].push_back(0);
}

void make_adjacentList5 (AdjacentList &adjacentList5) {
	adjacentList5[0].push_back(1);

	adjacentList5[1].push_back(0);
	adjacentList5[1].push_back(2);

	adjacentList5[2].push_back(1);
	adjacentList5[2].push_back(3);

	adjacentList5[3].push_back(2);
	adjacentList5[3].push_back(4);

	adjacentList5[4].push_back(3);
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