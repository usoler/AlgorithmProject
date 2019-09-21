/**
 * Created by Luis Oriol Soler Cruz on 21/09/19
 */
#include "Graph.h"

Graph::Graph () {
	this->numOfNodes = 0;
	this->numOfEdges = 0;
	this->adjacentList = vector<vector<int>>();
	this->connectedComponents = vector<vector<int>>();
}

Graph::Graph (int numOfNodes, int numOfEdges, AdjacentList &adjacentList) {
	this->numOfNodes = numOfNodes;
	this->numOfEdges = numOfEdges;
	this->adjacentList = adjacentList;
	this->connectedComponents = vector<vector<int>>();
}

int Graph::getNumOfConnectedComponents () {
	if (this->connectedComponents.empty()) {
		generateConnectedComponentsDFS();
	}

	return this->connectedComponents.size();
}

ConnectedComponents Graph::getConnectedComponents () {
	if (this->connectedComponents.empty()) {
		generateConnectedComponentsDFS();
	}
	return this->connectedComponents;
}

void Graph::generateConnectedComponentsDFS () {
	int size = this->numOfNodes;
	vector<bool> visited(size, false);

	for (int i = 0; i < size; ++i) {
		if (not visited[i]) {
			this->connectedComponents.push_back(vector<int>());
			generateConnectedComponentsDFSrec(visited, i, i);
		}
	}
}

void Graph::generateConnectedComponentsDFSrec (vector<bool> &visited, int v, int father) {
	this->connectedComponents[this->connectedComponents.size()-1].push_back(v);
	visited[v] = true;
	vector<int> adjacentList = this->adjacentList[v];
	int size = adjacentList.size();

	for (int i = 0; i < size; ++i) {
		int adjacent = adjacentList[i];
		if (not visited[adjacent]) {
			generateConnectedComponentsDFSrec(visited, adjacent, v);
		}
	}
}