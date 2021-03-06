/**
 * Created by Luis Oriol Soler Cruz on 21/09/19
 * Modified by Luis Oriol Soler Cruz on 14/10/19
 */
#include "Graph.h"

Graph::Graph () {
	this->numOfNodes = 0;
	this->numOfEdges = 0;
	this->isChecked = false;
	this->adjacentList = vector<vector<int> >();
	this->connectedComponents = vector<vector<int> >();
	this->sizeOfLargestConnectedComponent = 0;
}

Graph::Graph (int numOfNodes, int numOfEdges, AdjacentList &adjacentList) {
	this->numOfNodes = numOfNodes;
	this->numOfEdges = numOfEdges;
	this->isChecked = false;
	this->adjacentList = adjacentList;
	this->connectedComponents = vector<vector<int> >();
	this->sizeOfLargestConnectedComponent = 0;
}

int Graph::getNumOfNodes () {
	return this->numOfNodes;
}

int Graph::getNumOfEdges () {
	return this->numOfEdges;
}

bool Graph::isConnectedGraph () {
	if (this->isChecked == false) {
		this->isChecked = true;
		this->isConnected = true;
		int size = this->numOfNodes;
		vector<bool> visited(size, false);

		isConnectedGraphrec(visited, 0);

		for (int i = 0; i < size and this->isConnected; ++i) {
			if (not visited[i]) {
				this->isConnected = false;
			}
		}
	}

	return this->isConnected;
}

AdjacentList Graph::getAdjacentList() {
	return this->adjacentList;
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

void Graph::isConnectedGraphrec (vector<bool> &visited, int v) {
	visited[v] = true;
	vector<int> adjacentList = this->adjacentList[v];

	for (int i = 0; i < adjacentList.size(); ++i) {
		int adjacent = adjacentList[i];
		if (not visited[adjacent]) {
			isConnectedGraphrec(visited, adjacent);
		}
	}
}

void Graph::generateConnectedComponentsDFS () {
	int size = this->numOfNodes;
	vector<bool> visited(size, false);

	for (int i = 0; i < size; ++i) {
		if (not visited[i]) {
			this->connectedComponents.push_back(vector<int>());
			generateConnectedComponentsDFSrec(visited, i);
		}
	}

	if ( (this->connectedComponents).size() > 1 ) {
		this->isConnected = false;
	} else {
		this->isConnected = true;
	}

	this->isChecked = true;
}

void Graph::generateConnectedComponentsDFSrec (vector<bool> &visited, int v) {
	this->connectedComponents[this->connectedComponents.size()-1].push_back(v);
	visited[v] = true;
	vector<int> adjacentList = this->adjacentList[v];

	for (int i = 0; i < adjacentList.size(); ++i) {
		int adjacent = adjacentList[i];
		if (not visited[adjacent]) {
			generateConnectedComponentsDFSrec(visited, adjacent);
		}
	}
}

vector<int> Graph::getLargestConnectedComponent () {
	vector<int> largestConnectedComponent = this->connectedComponents[0];
	int actualSize = largestConnectedComponent.size();
	int numOfConnectedComponents = this->connectedComponents.size();

	for (int i = 1; i < numOfConnectedComponents; ++i) {
		vector<int> nextConnectedComponent = this->connectedComponents[i];

		if (actualSize < nextConnectedComponent.size()) {
			largestConnectedComponent = nextConnectedComponent;
			actualSize = nextConnectedComponent.size();
		}
	}

	this->sizeOfLargestConnectedComponent = actualSize;

	return largestConnectedComponent;
}

int Graph::getSizeOfLargestConnectedComponent () {
	if (this->sizeOfLargestConnectedComponent == 0) {
		if (this->connectedComponents.empty()) {
			generateConnectedComponentsDFS();
		}
		return getLargestConnectedComponent().size();
	} else {
		return this->sizeOfLargestConnectedComponent;
	}
}