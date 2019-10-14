/**
 * Created by Luis Oriol Soler Cruz on 21/09/19
 * Modified by Luis Oriol Soler Cruz on 14/10/19
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
	int sizeOfLargestConnectedComponent;
	
	void isConnectedGraphrec (Visited &visited, int v);
	void generateConnectedComponentsDFS ();
	void generateConnectedComponentsDFSrec (Visited &visited, int v);

public:
	/**
	 * Constructs an empty graph
	 *
	 * @return an empty graph
	 */
	Graph (); // O(1)

	/**
	 * Constructs a filled graph
	 *
	 * @param numOfNodes number of nodes in the graph
	 * @param numOfEdges number of edges in the graph
	 * @param adjacentList adjacent list of the graph
	 * 
	 * @return a filled graph
	 */
	Graph (int numOfNodes, int numOfEdges, AdjacentList &adjacentList); // O(1)

	/**
	 * Returns the number of nodes in the graph.
	 */
	int getNumOfNodes (); // O(1)

	/**
	 * Returns the number of edges in the graph.
	 */
	int getNumOfEdges (); // O(1)

	/**
	 * Returns if the graph is connected.
	 */
	bool isConnectedGraph (); // O(|V|+|E|)

	/**
	 * Returns the adjacent list of the graph.
	 */
	AdjacentList getAdjacentList (); // O(1)

	/**
	 * Returns the number of connected components of the graph.
	 */
	int getNumOfConnectedComponents (); // O(|V|+|E|)

	/**
	 * Returns the connected components of the graph
	 */
	ConnectedComponents getConnectedComponents (); // O(|V|+|E|)

	/**
	 * Returns the largest connected component
	 */
	vector<int> getLargestConnectedComponent (); // O(|V|)

	/**
	 * Returns the size of the largest connected component
	 */
	int getSizeOfLargestConnectedComponent (); // O(1)
};
#endif