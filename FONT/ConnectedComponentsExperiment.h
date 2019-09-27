/**
 * Created by Roger González Herrera on 27/09/19
 */
#ifndef CONNECTED_COMPONENTS_EXPERIMENT_H
#define CONNECTED_COMPONENTS_EXPERIMENT_H

#include <iostream>
#include <vector>
#include "RandomBinomialGraphGenerator.h"
#include "RandomGeometricGraphGenerator.h"

using namespace std;

class ConnectedComponentsExperiment {
private:
	double calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomGeometricGraphGenerator generator);
	double calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomBinomialGraphGenerator generator);

public:
	ConnectedComponentsExperiment ();
	void startExperimentGeometric (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);
	void startExperimentBinomial (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);
};
#endif