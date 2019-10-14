/**
 * Created by Luis Oriol Soler Cruz on 21/09/19
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;

typedef vector<vector<int> > AdjacentList;
typedef vector<vector<int> > ConnectedComponents;
typedef vector<bool> Visited;

class Graph {
private:
	int numOfNodes;
	int numOfEdges;
	bool isChecked;
	bool isConnected;
	AdjacentList adjacentList;
	ConnectedComponents connectedComponents;
	
	void isConnectedGraphrec (Visited &visited, int v);
	void generateConnectedComponentsDFS ();
	void generateConnectedComponentsDFSrec (Visited &visited, int v);

public:
	/**
	 * Constructs an empty graph
	 *
	 * @return an empty graph
	 */
	Graph ();

	/**
	 * Constructs a filled graph
	 *
	 * @param numOfNodes number of nodes in the graph
	 * @param numOfEdges number of edges in the graph
	 * @param adjacentList adjacent list of the graph
	 * 
	 * @return a filled graph
	 */
	Graph (int numOfNodes, int numOfEdges, AdjacentList &adjacentList);

	/**
	 * Returns the number of nodes in the graph.
	 */
	int getNumOfNodes ();

	/**
	 * Returns the number of edges in the graph.
	 */
	int getNumOfEdges ();

	/**
	 * Returns if the graph is connected.
	 */
	bool isConnectedGraph ();

	/**
	 * Returns the adjacent list of the graph.
	 */
	AdjacentList getAdjacentList ();

	/**
	 * Returns the number of connected components of the graph.
	 */
	int getNumOfConnectedComponents ();

	/**
	 * Returns the connected components of the graph
	 */
	ConnectedComponents getConnectedComponents ();
};
#endif