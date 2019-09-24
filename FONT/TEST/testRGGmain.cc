/**
 * Created by Jose Camilo Romero Limones on 23/09/19
 */
#include <iostream>
#include "Graph.h"
#include "RandomGeometricGraphGenerator.h"

using namespace std;

typedef vector<vector<int> > AdjacentList;
typedef vector<vector<int> > ConnectedComponents;

void print_graph (Graph &);
void print_component (vector<int> &);
void print_connected_components (ConnectedComponents &);

int main() {
	// ------------ TEST 1 ------------
	cout << "START TESTS" << endl;
	int n = 20;
	float r = 0.3;
	RandomGeometricGraphGenerator generator = RandomGeometricGraphGenerator();
	Graph graph = generator.generateGraph(n, r);
	print_graph(graph);

	cout << "Num of connected components: " << graph.getNumOfConnectedComponents() << endl;
	ConnectedComponents connectedComponents = graph.getConnectedComponents();
	print_connected_components(connectedComponents);

	if (graph.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}

	cout << "------------------------" << endl;

	// ------------ TEST 2 ------------
	graph = generator.generateGraph(n, r);
	print_graph(graph);

	cout << "Num of connected components: " << graph.getNumOfConnectedComponents() << endl;
	connectedComponents = graph.getConnectedComponents();
	print_connected_components(connectedComponents);

	if (graph.isConnectedGraph()) {
		cout << "Graph is connected" << endl;
	} else {
		cout << "Graph is not connected" << endl;
	}

	cout << "END TESTS" << endl;
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