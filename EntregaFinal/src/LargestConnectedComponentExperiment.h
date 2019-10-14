/**
 * Created by Luis Oriol Soler Cruz on 14/10/19
 */
#ifndef LARGEST_CONNECTED_COMPONENT_EXPERIMENT_H
#define LARGEST_CONNECTED_COMPONENT_EXPERIMENT_H

#include <iostream>
#include <vector>
#include "RandomBinomialGraphGenerator.h"
#include "RandomGeometricGraphGenerator.h"

using namespace std;

class LargestConnectedComponentExperiment {
private:
	double calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomGeometricGraphGenerator generator);
	double calculateExpectedValue (int numberOfNodes, float param, int numOfGraphs, RandomBinomialGraphGenerator generator);

public:
	/**
	 * Constructs an experiment about size of largest connected component
	 * in binomial and geometric models.
	 *
	 * @return an experiment about size of largest connected component.
	 */
	LargestConnectedComponentExperiment ();

	/**
	 * Start an experiment about size of largest connected component
	 * in geometric model.
	 *
	 * @param listOfNumberOfNodes list of number of nodes to experiment.
	 * @param listOfParamValues list of param values (radius).
	 * @param numOfGraphs number of graphs with which to make an average value.
	 */
	void startExperimentGeometric (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);

	/**
	 * Start an experiment about size of largest connected component 
	 * in binomial model.
	 *
	 * @param listOfNumberOfNodes list of number of nodes to experiment.
	 * @param listOfParamValues list of param values (probability of edge).
	 * @param numOfGraphs number of graphs with which to make an average value.
	 */
	void startExperimentBinomial (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);
};
#endif