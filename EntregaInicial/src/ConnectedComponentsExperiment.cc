/**
 * Created by Roger González Herrera on 27/09/19
 */
#include "ConnectedComponentsExperiment.h"

ConnectedComponentsExperiment::ConnectedComponentsExperiment () {
	// Empty
}

void ConnectedComponentsExperiment::startExperimentGeometric (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs) {
	RandomGeometricGraphGenerator generator = RandomGeometricGraphGenerator();

	for (int i = 0; i < listOfNumberOfNodes.size(); ++i){
		cout << "************************************************" << endl;
		cout << "Function n = " << listOfNumberOfNodes[i] << " :" << endl;
		bool reachedLimit = false;
		for (int j = 0; j < listOfParamValues.size(); ++j){
			int numberOfNodes = listOfNumberOfNodes[i];
			float param = listOfParamValues[j];
			double expectedValue;
			if (not reachedLimit) {
				expectedValue = calculateExpectedValue(numberOfNodes, param, numOfGraphs, generator);
				if (expectedValue == 1.000) {
					reachedLimit = true;
				}
			} else {
				expectedValue = 1.000;
			}
			cout << "Expected value for param " << param << " = " << expectedValue << endl;
		}
		cout << "************************************************" << endl;
		cout << endl;
		cout << endl;
	}
}

void ConnectedComponentsExperiment::startExperimentBinomial (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs) {
	RandomBinomialGraphGenerator generator = RandomBinomialGraphGenerator();

	for (int i = 0; i < listOfNumberOfNodes.size(); ++i){ // 4 values
		cout << "************************************************" << endl;
		cout << "Function n = " << listOfNumberOfNodes[i] << " :" << endl;
		bool reachedLimit = false;
		for (int j = 0; j < listOfParamValues.size(); ++j){ // 10 values
			int numberOfNodes = listOfNumberOfNodes[i];
			float param = listOfParamValues[j];
			double expectedValue;
			if (not reachedLimit) {
				expectedValue = calculateExpectedValue(numberOfNodes, param, numOfGraphs, generator);
				if (expectedValue == 1.000) {
					reachedLimit = true;
				}
			} else {
				expectedValue = 1.000;
			}
			cout << "Expected value for param " << param << " = " << expectedValue << endl;
		}
		cout << "************************************************" << endl;
		cout << endl;
		cout << endl;
	}
}

double ConnectedComponentsExperiment::calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomGeometricGraphGenerator generator) {
	double geometricSum = 0;
	Graph graph;
	for (int i = 0; i < numOfGraphs; ++i){
		graph = generator.generateGraph(numberOfNodes, param);
		geometricSum += graph.getNumOfConnectedComponents();
	}

	return (double) (geometricSum / numOfGraphs);
}

double ConnectedComponentsExperiment::calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomBinomialGraphGenerator generator) {
	double binomialSum = 0;
	Graph graph;
	for (int i = 0; i < numOfGraphs; ++i){
		graph = generator.generateGraph(numberOfNodes, param);
		binomialSum += graph.getNumOfConnectedComponents();
	}

	return (double) (binomialSum / numOfGraphs);
}