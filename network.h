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
void * inputNetwork(Network *network, int *input, int nbInput);

/*
 * builder
 */

Network * testNetwork();

#endif /* NETWORK_H */
