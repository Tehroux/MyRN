#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

/*
 * structure neuron network
 */

typedef struct Network {
	int nbNeuron;
	Neuron **neurons;
	double *result;
} Network;

Network * initNetwork(int nbNeuron);
void inputNetwork(Network *network, double *input, int nbInput);
void executeNetwork(Network *network);

/*
 * builder
 */

Network * testNetwork();

#endif /* NETWORK_H */
