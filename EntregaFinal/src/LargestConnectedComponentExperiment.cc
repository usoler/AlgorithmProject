/**
 * Created by Luis Oriol Soler Cruz on 14/10/19
 */
#include "LargestConnectedComponentExperiment.h"

LargestConnectedComponentExperiment::LargestConnectedComponentExperiment () {
	// Empty
}

void LargestConnectedComponentExperiment::startExperimentGeometric (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs) {
	RandomGeometricGraphGenerator generator = RandomGeometricGraphGenerator();

	for (int i = 0; i < listOfNumberOfNodes.size(); ++i){
		cout << "************************************************" << endl;
		cout << "Function n = " << listOfNumberOfNodes[i] << " :" << endl;
		for (int j = 0; j < listOfParamValues.size(); ++j){
			int numberOfNodes = listOfNumberOfNodes[i];
			float param = listOfParamValues[j];
			double expectedValue;
			expectedValue = calculateExpectedValue(numberOfNodes, param, numOfGraphs, generator);
			cout << "Expected value for param " << param << " = " << expectedValue << endl;
		}
		cout << "************************************************" << endl;
		cout << endl;
		cout << endl;
	}
}

void LargestConnectedComponentExperiment::startExperimentBinomial (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs) {
	RandomBinomialGraphGenerator generator = RandomBinomialGraphGenerator();

	for (int i = 0; i < listOfNumberOfNodes.size(); ++i){ // 4 values
		cout << "************************************************" << endl;
		cout << "Function n = " << listOfNumberOfNodes[i] << " :" << endl;
		for (int j = 0; j < listOfParamValues.size(); ++j){ // 10 values
			int numberOfNodes = listOfNumberOfNodes[i];
			float param = listOfParamValues[j];
			double expectedValue;
			expectedValue = calculateExpectedValue(numberOfNodes, param, numOfGraphs, generator);
			cout << "Expected value for param " << param << " = " << expectedValue << endl;
		}
		cout << "************************************************" << endl;
		cout << endl;
		cout << endl;
	}
}

double LargestConnectedComponentExperiment::calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomGeometricGraphGenerator generator) {
	double geometricSum = 0;
	Graph graph;
	for (int i = 0; i < numOfGraphs; ++i){
		graph = generator.generateGraph(numberOfNodes, param);
		// cout << "Number of connected components: " << graph.getConnectedComponents().size() << endl;
		// cout << "Graph #" << i << endl;
		// for (int j = 0; j < graph.getConnectedComponents().size(); ++j) {
		// 	cout << "Connected component #" << j << endl;
		// 	for (int k = 0; k < graph.getConnectedComponents()[j].size(); ++k) {
		// 		cout << "node = " << graph.getConnectedComponents()[j][k] << endl;
		// 	}
		// }
		geometricSum += graph.getSizeOfLargestConnectedComponent();
		// cout << "Size of largest connected component: " << graph.getSizeOfLargestConnectedComponent() << endl;
	}
	return (double) (geometricSum / numOfGraphs);
}

double LargestConnectedComponentExperiment::calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomBinomialGraphGenerator generator) {
	double binomialSum = 0;
	Graph graph;
	for (int i = 0; i < numOfGraphs; ++i){
		graph = generator.generateGraph(numberOfNodes, param);
		// cout << "Number of connected components: " << graph.getConnectedComponents().size() << endl;
		// cout << "Graph #" << i << endl;
		// for (int j = 0; j < graph.getConnectedComponents().size(); ++j) {
		// 	cout << "Connected component #" << j << endl;
		// 	for (int k = 0; k < graph.getConnectedComponents()[j].size(); ++k) {
		// 		cout << "node = " << graph.getConnectedComponents()[j][k] << endl;
		// 	}
		// }
		binomialSum += graph.getSizeOfLargestConnectedComponent();
		// cout << "Size of largest connected component: " << graph.getSizeOfLargestConnectedComponent() << endl;
	}

	return (double) (binomialSum / numOfGraphs);
}