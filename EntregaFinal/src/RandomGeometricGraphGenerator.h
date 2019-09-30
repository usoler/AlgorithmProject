/**
 * Created by Jose Camilo Romero Limones on 23/09/19
 */
#ifndef RANDOM_GEOMETRIC_GRAPH_GENERATOR_H
#define RANDOM_GEOMETRIC_GRAPH_GENERATOR_H

#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"

using namespace std;

typedef vector<vector<int> > AdjacentList;
typedef struct { float x; float y; } Point;

class RandomGeometricGraphGenerator {
private:
	void generateSamples (vector<Point> &graphPoints);
	void generateRandomGeometricGraph (vector<Point> &graphPoints, AdjacentList &adjacentList, float radius, int &numOfEdges);
	double distance (Point &firstPoint, Point &secondPoint);
public:
	/**
	 * Constructs a random geometric graph generator.
	 *
	 * @return a random geometric graph generator.
	 */
	RandomGeometricGraphGenerator ();

	/**
	 * Generate a random geometric graph with 'n' nodes and radius 'r'
	 *
	 * @param numOfNodes	number of nodes in the graph.
	 * @param radius		radius of adjacent nodes.
	 *
	 * @return a random geometric graph.
	 */
	Graph generateGraph (int numOfNodes, float radius);
};
#endif