#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.h"

#define EPSILON 10
#define NBLEARN 5000

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
void learnNetwork(Network *network ,double ***example, int nbExample);

/*
 * learning algorithme : backpropogation
 */

double sommeSortiNeuron(Network *network, int indexNeuron, double *delta);
void changWeight(Network *network, double *delta);
void backPropagation(Network *network, double *x, double *y);

/*
 * network builder
 */

Network * testNetwork();

/*
 * example builder
 */

double *** andExample();

#endif /* NETWORK_H */
