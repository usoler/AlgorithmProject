/**
 * Created by Luis Oriol Soler Cruz on 30/09/19
 */
#include "ConnectivityExperiment.h"

ConnectivityExperiment::ConnectivityExperiment () {
	// Empty
}

void ConnectivityExperiment::startExperimentGeometric (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs) {
	RandomGeometricGraphGenerator generator = RandomGeometricGraphGenerator();

	for (int i = 0; i < listOfNumberOfNodes.size(); ++i) {
		cout << "************************************************" << endl;
		cout << "Function n = " << listOfNumberOfNodes[i] << " :" << endl;

		for (int j = 0; j < listOfParamValues.size(); ++j) {
			int numberOfNodes = listOfNumberOfNodes[i];
			float param = listOfParamValues[j];
			double expectedValue = calculateProbabilityConnected(numberOfNodes, param, numOfGraphs, generator);
			cout << "Probability for param " << param << " = " << expectedValue << endl;
		}
		cout << "************************************************" << endl;
		cout << endl;
		cout << endl;
	}
}

void ConnectivityExperiment::startExperimentBinomial (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs) {
	RandomBinomialGraphGenerator generator = RandomBinomialGraphGenerator();

	for (int i = 0; i < listOfNumberOfNodes.size(); ++i) {
		cout << "************************************************" << endl;
		cout << "Function n = " << listOfNumberOfNodes[i] << " :" << endl;

		for (int j = 0; j < listOfParamValues.size(); ++j) {
			int numberOfNodes = listOfNumberOfNodes[i];
			float param = listOfParamValues[j];
			double expectedValue = calculateProbabilityConnected(numberOfNodes, param, numOfGraphs, generator);
			cout << "Probability for param " << param << " = " << expectedValue << endl;
		}
		cout << "************************************************" << endl;
		cout << endl;
		cout << endl;
	}
}

double ConnectivityExperiment::calculateProbabilityConnected (int numberOfNodes, float param, int numOfGraphs, RandomGeometricGraphGenerator generator) {
	int numOfConnectedGraphs = 0;
	Graph graph;
	for (int i = 0; i < numOfGraphs; ++i) {
		graph = generator.generateGraph(numberOfNodes, param);
		if (graph.isConnectedGraph()) {
			++numOfConnectedGraphs;
		}
	}
	return (double)((double)numOfConnectedGraphs / numOfGraphs);
}

double ConnectivityExperiment::calculateProbabilityConnected (int numberOfNodes, float param, int numOfGraphs, RandomBinomialGraphGenerator generator) {
	int numOfConnectedGraphs = 0;
	Graph graph;
	for (int i = 0; i < numOfGraphs; ++i) {
		graph = generator.generateGraph(numberOfNodes, param);
		if (graph.isConnectedGraph()) {
			++numOfConnectedGraphs;
		}
	}
	return (double)((double)numOfConnectedGraphs / numOfGraphs);
}