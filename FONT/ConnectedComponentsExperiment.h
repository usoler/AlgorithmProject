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
	/**
     * Constructs an experiment with connected components of binomial and geometric model.
     *
     * @return an experiment with connected components.
     */
	ConnectedComponentsExperiment ();

	/**
     * Start an experiment with connected components of geometric model.
     *
     * @param listOfNumberOfNodes list of number of nodes to experiment.
     * @param listOfParamValues list of param values (radius).
     * @param numOfGraphs number of graphs with which to make an average value
     */
	void startExperimentGeometric (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);
	
	/**
     * Start an experiment with connected components of binomial model.
     *
     * @param listOfNumberOfNodes list of number of nodes to experiment.
     * @param listOfParamValues list of param values (probability of edge).
     * @param numOfGraphs number of graphs with which to make an average value
     */
	void startExperimentBinomial (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);
};
#endif