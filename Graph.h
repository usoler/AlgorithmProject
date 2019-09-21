/**
 * Created by Luis Oriol Soler Cruz on 21/09/19
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;

typedef vector<vector<int>> AdjacentList;
typedef vector<vector<int>> ConnectedComponents;
typedef vector<bool> Visited;

class Graph {
private:
	int numOfNodes;
	int numOfEdges;
	AdjacentList adjacentList;
	ConnectedComponents connectedComponents;

	void generateConnectedComponentsDFS();
	void generateConnectedComponentsDFSrec(Visited &visited, int v, int father);

public:
	Graph ();
	Graph (int numOfNodes, int numOfEdges, AdjacentList &adjacentList);

	int getNumOfConnectedComponents ();
	ConnectedComponents getConnectedComponents ();
};
#endif