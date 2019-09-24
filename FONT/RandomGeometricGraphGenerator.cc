/**
 * Created by Jose Camilo Romero Limones on 23/09/19
 */
#include "RandomGeometricGraphGenerator.h"

RandomGeometricGraphGenerator::RandomGeometricGraphGenerator () {
	srand((unsigned)time(NULL));
}

Graph RandomGeometricGraphGenerator::generateGraph (int numOfNodes, float radius) {
	AdjacentList adjacentList = vector<vector<int> >(numOfNodes, vector<int>());
	vector<Point> graphPoints(numOfNodes);
	int numOfEdges = 0;

	generateSamples(graphPoints);
	generateRandomGeometricGraph(graphPoints, adjacentList, radius, numOfEdges);

	return Graph(numOfNodes, numOfEdges, adjacentList);
}

void RandomGeometricGraphGenerator::generateSamples (vector<Point> &graphPoints) {
	for (int i = 0; i < graphPoints.size(); ++i) {
		graphPoints[i].x = (float) (rand() % 10001) / 10000;
		graphPoints[i].y = (float) (rand() % 10001) / 10000;
	} 
}

void RandomGeometricGraphGenerator::generateRandomGeometricGraph (vector<Point> &graphPoints, 
	AdjacentList &adjacentList, float radius, int &numOfEdges) {

	int numOfNodes = adjacentList.size();
	for (int i = 0; i < numOfNodes; ++i) {
		for (int j = i + 1; j < numOfNodes; ++j) {
			if ( distance(graphPoints[i], graphPoints[j]) <= radius) {
				adjacentList[i].push_back(j);
				adjacentList[j].push_back(i);
				++numOfEdges;
			}
		}
	}
}

double RandomGeometricGraphGenerator::distance (Point &firstPoint, Point &secondPoint) {
	double term1 = pow(firstPoint.x - secondPoint.x, 2);
	double term2 = pow(firstPoint.y - secondPoint.y, 2);
	return sqrt(term1 + term2);
}