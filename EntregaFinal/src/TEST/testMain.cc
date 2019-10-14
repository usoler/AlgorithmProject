/**
 * Created by Luis Oriol Soler Cruz on 21/09/19
 * Modified by Jose Camilo Romero Limones on 23/09/19
 * Modified by Pau Escofet Majoral on 25/09/19
 * Modified by Luis Oriol Soler Cruz on 30/09/19
 */
#include <iostream>
#include "Graph.h"
#include "RandomGeometricGraphGenerator.h"
#include "RandomBinomialGraphGenerator.h"
#include "ConnectivityExperiment.h"

using namespace std;

typedef vector<vector<int> > AdjacentList;
typedef vector<vector<int> > ConnectedComponents;

void print_menu ();
void make_adjacentList1(AdjacentList &);
void make_adjacentList2(AdjacentList &);
void make_adjacentList3(AdjacentList &);
void make_adjacentList4(AdjacentList &);
void make_adjacentList5(AdjacentList &);
void print_graph (Graph &);
void print_component (vector<int> &);
void print_connected_components (ConnectedComponents &);

void verify_Graph_generateConnectedComponentsDFS_whenValidExecution (int, int, AdjacentList &);
void verify_Graph_isConnectedGraph_whenValidExecution (int, int, AdjacentList &);
void verify_RandomGeometricGraphGenerator_generateGraph (int, float, Graph &, RandomGeometricGraphGenerator &);
void verify_RandomBinomialGraphGenerator_generateGraph (int, float, Graph &, RandomBinomialGraphGenerator &);
void run_Graph_tests ();
void run_RandomGeometricGraphGenerator_tests ();
void run_RandomBinomialGraphGenerator_tests ();
void run_ConnectivityExperiment_tests();

int main() {
	print_menu();
	int option;
	while (cin >> option) {
		if (option == 0) {
			run_Graph_tests();
			run_RandomGeometricGraphGenerator_tests();
			run_RandomBinomialGraphGenerator_tests();
			run_ConnectivityExperiment_tests();
		} else if (option == 1) {
			run_Graph_tests();
		} else if (option == 2) {
			run_RandomGeometricGraphGenerator_tests();
		} else if (option == 3) {
			run_RandomBinomialGraphGenerator_tests();
		} else if (option == 4) {
			run_ConnectivityExperiment_tests();
		}

		print_menu();
	}
}

void print_menu () {
	cout << "**********************************************" << endl;
	cout << "*                TEST CONSOLE                *" << endl;
	cout << "**********************************************" << endl;
	cout << "* Run All Unit Tests:                press 0 *" << endl;
	cout << "*                                            *" << endl;
	cout << "* Run Unit Tests for                         *" << endl;
	cout << "*   - Graph:                         press 1 *" << endl;
	cout << "*   - RandomGeometricGraphGenerator: press 2 *" << endl;
	cout << "*   - RandomBinomialGraphGenerator:  press 3 *" << endl;
	cout << "*   - ConnectivityExperiment:        press 4 *" << endl;
	cout << "**********************************************" << endl;
}

void run_Graph_tests () {
	cout << endl;
	cout << "******************************" << endl;
	cout << "Running Graph Tests" << endl;
	cout << "******************************" << endl;
	cout << endl;
	// ------------- TEST 1 -------------
	// 3 componentes, 0-1-2, 3-4, 5-6-7-8
	int n = 9;
	int m = 8;
	AdjacentList adjacentList = AdjacentList(n, vector<int>());
	make_adjacentList1(adjacentList);

	verify_Graph_generateConnectedComponentsDFS_whenValidExecution(n, m, adjacentList);
	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);

	// ------------- TEST 2 -------------
	// 5 componentes, 0, 1-2, 3-4-5-6, 7, 8-9-10-11
	n = 12;
	m = 10;
	adjacentList = AdjacentList(n, vector<int>());
	make_adjacentList2(adjacentList);

	verify_Graph_generateConnectedComponentsDFS_whenValidExecution(n, m, adjacentList);
	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);

	// ------------- TEST 3 -------------
	// 0-1-2
	n = 3;
	m = 3;
	adjacentList = AdjacentList(n, vector<int>());
	make_adjacentList3(adjacentList);

	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);

	// ------------- TEST 4 -------------
	// 0-1
	n = 2;
	m = 1;
	adjacentList = AdjacentList(n, vector<int>());
	make_adjacentList4(adjacentList);

	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);

	// ------------- TEST 5 -------------
	// 0-1-2-3-4
	n = 5;
	m = 4;
	adjacentList = AdjacentList(n, vector<int>());
	make_adjacentList5(adjacentList);

	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);
	cout << endl;
	cout << "******************************" << endl;
	cout << "Graph Tests Finished" << endl;
	cout << "******************************" << endl;
	cout << endl;
}

void run_RandomGeometricGraphGenerator_tests () {
	cout << endl;
	cout << "*****************************************" << endl;
	cout << "Running Random Geometric Graph Tests" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
	// ------------- TEST 8 -------------
	int n = 20;
	float r = 0.3;

	RandomGeometricGraphGenerator generator = RandomGeometricGraphGenerator();
	Graph graph;
	verify_RandomGeometricGraphGenerator_generateGraph(n, r, graph, generator);
	int m = graph.getNumOfEdges();
	AdjacentList adjacentList = graph.getAdjacentList();
	verify_Graph_generateConnectedComponentsDFS_whenValidExecution(n, m, adjacentList);
	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);

	cout << "------------------------" << endl;

	// ------------- TEST 9 -------------
	verify_RandomGeometricGraphGenerator_generateGraph(n, r, graph, generator);
	m = graph.getNumOfEdges();
	adjacentList = graph.getAdjacentList();
	verify_Graph_generateConnectedComponentsDFS_whenValidExecution(n, m, adjacentList);
	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);
	cout << endl;
	cout << "*****************************************" << endl;
	cout << "Random Geometric Graph Tests Finished" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

void run_RandomBinomialGraphGenerator_tests () {
	cout << endl;
	cout << "*****************************************" << endl;
	cout << "Running Random Binomial Graph Tests" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
	// ------------- TEST 10 -------------
	int n = 20;
	float p = 0.3;

	RandomBinomialGraphGenerator generator = RandomBinomialGraphGenerator();
	Graph graph;
	verify_RandomBinomialGraphGenerator_generateGraph(n, p, graph, generator);
	int m = graph.getNumOfEdges();
	AdjacentList adjacentList = graph.getAdjacentList();
	verify_Graph_generateConnectedComponentsDFS_whenValidExecution(n, m, adjacentList);
	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);

	cout << "------------------------" << endl;

	// ------------- TEST 11 -------------
	verify_RandomBinomialGraphGenerator_generateGraph(n, p, graph, generator);
	m = graph.getNumOfEdges();
	adjacentList = graph.getAdjacentList();
	verify_Graph_generateConnectedComponentsDFS_whenValidExecution(n, m, adjacentList);
	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);
	cout << endl;
	cout << "*****************************************" << endl;
	cout << "Random Binomial Graph Tests Finished" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

void run_ConnectivityExperiment_tests () {
	cout << endl;
	cout << "*****************************************" << endl;
	cout << "Running Random Binomial Graph Tests" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
	// ------------- TEST 12 -------------
	int n = 20;
	float r = 0.3;

	RandomGeometricGraphGenerator generator = RandomGeometricGraphGenerator();
	Graph graph;
	int numOfConnectedGraphs = 0;
	for (int i = 0; i < 1000; ++i) {
		graph = generator.generateGraph(n, r);
		if (graph.isConnectedGraph()) {
			cout << "Graph is connected" << endl;
			++numOfConnectedGraphs;
		} else {
			cout << "NOT" << endl;
		}
		cout << "Num of connected graphs: " << numOfConnectedGraphs << endl;
		cout << "Num of graphs: " << 1000 << endl;
		cout << "Probability: " << (double)((double)numOfConnectedGraphs / 1000) << endl;
	}
	verify_RandomGeometricGraphGenerator_generateGraph(n, r, graph, generator);
	int m = graph.getNumOfEdges();
	AdjacentList adjacentList = graph.getAdjacentList();
	verify_Graph_generateConnectedComponentsDFS_whenValidExecution(n, m, adjacentList);
	verify_Graph_isConnectedGraph_whenValidExecution(n, m, adjacentList);

	cout << endl;
	cout << "*****************************************" << endl;
	cout << "Random Binomial Graph Tests Finished" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

void verify_Graph_generateConnectedComponentsDFS_whenValidExecution (int n, int m, AdjacentList &adjacentList) {
	Graph graph = Graph(n, m, adjacentList);
	cout << "Num of connected components: " << graph.getNumOfConnectedComponents() << endl;
	ConnectedComponents connectedComponents = graph.getConnectedComponents();
	print_connected_components(connectedComponents);
}

void verify_Graph_isConnectedGraph_whenValidExecution (int n, int m, AdjacentList &adjacentList) {
	Graph graph(n, m, adjacentList);

	if (graph.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}
}

void verify_RandomGeometricGraphGenerator_generateGraph (int n, float r, Graph &graph, RandomGeometricGraphGenerator &generator) {
	graph = generator.generateGraph(n, r);
	print_graph(graph);
}

void verify_RandomBinomialGraphGenerator_generateGraph (int n, float p, Graph &graph, RandomBinomialGraphGenerator &generator) {
	graph = generator.generateGraph(n, p);
	print_graph(graph);
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

void print_graph (Graph &graph) {
	AdjacentList adjacentList = graph.getAdjacentList();
	int numOfNodes = adjacentList.size();
	for (int i = 0; i < numOfNodes; ++i) {
		cout << "Node #" << i<< ":";
		int numOfAdjacents = adjacentList[i].size();
		for (int j = 0; j < numOfAdjacents; ++j) {
			cout << adjacentList[i][j] << " ";
		}
		cout << endl;
	}
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