/**
 * Created by Luis Oriol Soler Cruz on 26/09/19
 */
#include "ConnectedComponentsExperiment.h"
#include <iostream>
#include <vector>

using namespace std;

enum Model { Binomial, Geometric };

void printReadMe ();
void printMenu ();
void generateDefaultNumOfNodes (vector<int> &listOfNumOfNodes);
void generateDefaultNumOfParamValues (vector<double> &listOfNumOfParamValues);
void runConnectedComponentsExperimentByDefault (Model model);
void runConnectedComponentsExperiment (Model model);

int main () {
	printReadMe();
	printMenu();

	int option;
	cout << "Enter the number of experiment:" << endl;
	while(cin >> option) {
		if (option == 0) {
			break;
		} else if (option == 1) {
			cout << "Do you want to run the default experiment? Enter 'yes', otherwise enter 'no'" << endl;
			string selection;
			cin >> selection;
			if (selection == "yes") {
				runConnectedComponentsExperimentByDefault(Geometric);
			} else {
				runConnectedComponentsExperiment(Geometric);
			}
		} else if (option == 2) {
			cout << "Do you want to run the default experiment? Enter 'yes', otherwise enter 'no'" << endl;
			string selection;
			cin >> selection;
			if (selection == "yes") {
				runConnectedComponentsExperimentByDefault(Binomial);
			} else {
				runConnectedComponentsExperiment(Binomial);
			}
		}
		printReadMe();
		printMenu();
		cout << "Enter the number of experiment:" << endl;
	}
	return 0;
}

void printReadMe () {
	cout << "************************" << endl;
	cout << "* ALGORITHMICS PROJECT *" << endl;
	cout << "************************" << endl;
	cout << endl;
	cout << "Project title:" << endl;
	cout << "  - Phase transition and connected components in random graphs" << endl;
	cout << endl;
	cout << "Team members:" << endl;
	cout << "  - José Camilo Romero Limones" << endl;
	cout << "  - Luis Oriol Soler Cruz" << endl;
	cout << "  - Pau Escofet Majoral" << endl;
	cout << "  - Roger González Herrera" << endl;
	cout << endl;
	cout << "------------------------" << endl;
	cout << endl;
}

void printMenu () {
	cout << "List of experiments:" << endl;
	cout << "- Experiments of the Expected value of the number of components:" << endl;
	cout << "    [Enter 1] for Geometric Model" << endl;
	cout << "    [Enter 2] for Binomial Model" << endl;
	cout << endl;
	cout << "[Enter 0] to exit" << endl;
	cout << endl;
}

void runConnectedComponentsExperimentByDefault (Model model) {
	vector<int> listOfNumOfNodes;
	generateDefaultNumOfNodes(listOfNumOfNodes);
	vector<double> listOfNumOfParamValues;
	generateDefaultNumOfParamValues(listOfNumOfParamValues);
	int numOfGraphs = 500;

	ConnectedComponentsExperiment experiment = ConnectedComponentsExperiment();

	if (model == Geometric) {
		experiment.startExperimentGeometric(listOfNumOfNodes, listOfNumOfParamValues, numOfGraphs);
	} else if (model == Binomial) {
		experiment.startExperimentBinomial(listOfNumOfNodes, listOfNumOfParamValues, numOfGraphs);
	}
}

void runConnectedComponentsExperiment (Model model) {	
	int numOfFunctions;
	cout << "********** Connected Components Experiment **********" << endl;
	// number of functions
	cout << "Enter the number of functions:" << endl;
	cin >> numOfFunctions;
	// number of nodes for each function
	vector<int> listOfNumOfNodes(numOfFunctions);
	for (int i = 0; i < numOfFunctions; ++i) {
		cout << "Enter the number of nodes for function #" << i << ":" << endl;
		cin >> listOfNumOfNodes[i];
	}
	// number of param values
	int numOfParamValues;
	cout << "Enter the number of param values:" << endl;
	cin >> numOfParamValues;
	// value for each param
	vector<double> listOfNumOfParamValues(numOfParamValues);
	for (int j = 0; j < numOfParamValues; ++j) {
		cout << "Enter the value for param value #" << j << ":" << endl;
		cin >> listOfNumOfParamValues[j];
	}

	// number of graphs to calculate
	int numOfGraphs;
	cout << "Enter the number of graphs to calculate:" << endl;
	cin >> numOfGraphs;

	ConnectedComponentsExperiment experiment = ConnectedComponentsExperiment();

	if (model == Geometric) {
		experiment.startExperimentGeometric(listOfNumOfNodes, listOfNumOfParamValues, numOfGraphs);
	} else if (model == Binomial) {
		experiment.startExperimentBinomial(listOfNumOfNodes, listOfNumOfParamValues, numOfGraphs);
	}
}

void generateDefaultNumOfNodes (vector<int> &listOfNumOfNodes) {
	listOfNumOfNodes = vector<int>(5);
	int numOfNodes = 20;
	for (int i = 0; i < 5; ++i) {
		listOfNumOfNodes[i] = numOfNodes;
		numOfNodes += 20;
	}
}

void generateDefaultNumOfParamValues (vector<double> &listOfNumOfParamValues) {
	listOfNumOfParamValues = vector<double>(19);
	double numOfParamValue = 0.000;
	for (int i = 0; i < 19; ++i) {
		listOfNumOfParamValues[i] = numOfParamValue;
		numOfParamValue += 0.025;
	}
}