/**
 * Created by Pau Escofet Majoral on 25/09/19
 */
#include "RandomBinomialGraphGenerator.h"


RandomBinomialGraphGenerator::RandomBinomialGraphGenerator() {
  srand((unsigned)time(NULL));
}

Graph RandomBinomialGraphGenerator::generateBinomialGraph(int numOfNodes, float probOfEdge) {
  AdjacentList adjacentList = vector<vector<int> >(numOfNodes, vector<int>());
  int numOfEdges = 0;

  generateRandomBinomialGraph(numOfNodes, adjacentList, probOfEdge, numOfEdges);
  return Graph(numOfNodes, numOfEdges, adjacentList);
}

void RandomBinomialGraphGenerator::generateRandomBinomialGraph (int numOfNodes, AdjacentList &adjacentList, float probOfEdge, int &numOfEdges) {
	for (int i = 0; i < numOfNodes; ++i) {
		for (int j = i + 1; j < numOfNodes; ++j) {
			if ( generateRandom() <= probOfEdge ) {
				adjacentList[i].push_back(j);
				adjacentList[j].push_back(i);
				numOfEdges ++;
			}
		}
	}
}

float RandomBinomialGraphGenerator::generateRandom() {
  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}