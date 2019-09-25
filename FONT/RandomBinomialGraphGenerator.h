/**
 * Created by Pau Escofet Majoral on 25/09/19
 */
#ifndef RANDOM_BINOMIAL_GRAPH_GENERATOR_H
#define RANDOM_BINOMIAL_GRAPH_GENERATOR_H

#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"

using namespace std;

typedef vector <vector<int> > AdjacentList;

class RandomBinomialGraphGenerator {
  private:
  void generateRandomBinomialGraph(int numOfNodes, AdjacentList &adjacentList, float probOfEdge, int &numOfEdges);
  float generateRandom();

  public:
    /**
     * Constructs a random binomial graph generator.
     *
     * @return a random binomial graph generator.
     */
    RandomBinomialGraphGenerator ();

    /**
     * Generate a random binomial graph with 'numOfNodes' nodes and probability 'probOfEdge'
     *
     * @param numOfNodes	number of nodes in the graph.
     * @param probOfEdge		probability of edge between each pair of nodes.
     *
     * @return a random binomial graph.
     */
    Graph generateBinomialGraph (int numOfNodes, float probOfEdge);
};
#endif