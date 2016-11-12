#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

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
void outputNetwork(Network *network);
void addNetwork(Network *network, int a, int b, double weight);
void executeNetwork(Network *network);

/*
 * builder
 */

Network * testNetwork();

#endif /* NETWORK_H */
