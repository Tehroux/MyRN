#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

#define EPSILON 1

/*
 * structure neuron network
 */

typedef struct Network {
	int nbNeuron;
	int input;
	int output;
	Neuron **neurons;
	double *result;
} Network;

Network * initNetwork(int nbNeuron, int input, int output);
void inputNetwork(Network *network, double *input, int nbInput);
void outputNetwork(Network *network, double *output);
void addNetwork(Network *network, int a, int b, double weight);
void executeNetwork(Network *network);

/*
 * learning algorithme : backpropogation
 */

double sommeSortiNeuron(Network *network, int indexNeuron, double *delta);
void changWeight(Network *network, double *delta);
void backPropagation(Network *network, double *x, double *y);

/*
 * builder
 */

Network * testNetwork();

#endif /* NETWORK_H */
