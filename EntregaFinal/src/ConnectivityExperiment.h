/**
 * Created by Luis Oriol Soler Cruz on 30/09/19
 */
#ifndef CONNECTIVITY_EXPERIMENT_H
#define CONNECTIVITY_EXPERIMENT_H

#include <iostream>
#include <vector>
#include "RandomBinomialGraphGenerator.h"
#include "RandomGeometricGraphGenerator.h"

using namespace std;

class ConnectivityExperiment {
private:
	double calculateProbabilityConnected (int numberOfNodes, float param, int numOfGraphs, RandomGeometricGraphGenerator generator);
	double calculateProbabilityConnected (int numberOfNodes, float param, int numOfGraphs, RandomBinomialGraphGenerator generator);
public:
	/**
	 * Constructs an experiment about connectivity in binomial and geometric models.
	 *
	 * @return an experiment about connectivity.
	 */
	ConnectivityExperiment ();

	/**
	 * Start an experiment about connectivity in geometric model.
	 *
	 * @param listOfNumberOfNodes list of number of nodes to experiment.
	 * @param listOfParamValues list of param values (radius).
	 * @param numOfGraphs number of graphs with which to make an average value.
	 */
	void startExperimentGeometric (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);

	/**
	 * Start an experiment about connectivity in binomial model.
	 *
	 * @param listOfNumberOfNodes list of number of nodes to experiment.
	 * @param listOfParamValues list of param values (probability of edge).
	 * @param numOfGraphs number of graphs with which to make an average value.
	 */
	void startExperimentBinomial (vector<int> &listOfNumberOfNodes, vector<double> &listOfParamValues, int numOfGraphs);
};
#endif