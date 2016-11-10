#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

/*
 * structure neuron network
 */

typedef struct Network {
	Neuron *neurons;
	double *result;
} Network;

Network * initNetwork();

/*
 * builder
 */

#endif /* NETWORK_H */
