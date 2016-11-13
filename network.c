#include "network.h"

Network * initNetwork(int nbNeuron, int input, int output)
{
	int i;
	srand(time(0));
	Network *network = NULL;
	network = malloc(sizeof(network));
	network->nbNeuron = nbNeuron;
	network->input = input;
	network->output = output;
	network->neurons = malloc(nbNeuron * sizeof(Neuron));
	network->result = malloc(nbNeuron * sizeof(double));
	for (i = 0; i < nbNeuron; i++) {
		network->neurons[i] = initNeuron();
	}
	return network;
}

void inputNetwork(Network *network, double *input, int nbInput)
{
	int i;
	for (i = 0; i < nbInput; i++) {
		network->result[i] = input[i];
	}
}

void outputNetwork(Network *network, double *output)
{
	int i;
	int startOutput = network->nbNeuron - network->output;
	for (i = startOutput; i < network->nbNeuron; i++) {
		output[i - startOutput] = network->result[i];
		
	}
}

void addNetwork(Network *network, int a, int b, double weight)
{
	addNeuron(network->neurons[b], a, weight);
	addParentNeuron(network->neurons[a], b);
}

void executeNetwork(Network *network)
{
	int i;
	for (i = 0; i < network->nbNeuron; i++) {
		if (network->neurons[i]->nbNeighbors != 0) {
			network->result[i] = executeNeuron(network->neurons[i],
					network->result);
		}
	}	
}

/*
 * learning algorithme : backpropagation
 */

double sommeSortiNeuron(Network *network, int indexNeuron, double *delta) {
	double ret = 0;
	Element_i *neighborsOut = network->neurons[indexNeuron]->parent->head;
	while (neighborsOut != NULL) {
		ret += delta[neighborsOut->value] * \
			getWeightNeuron(network->neurons[neighborsOut->value], 
					indexNeuron);
	}
	return ret;
}

void changeWeight(Network *network, double *delta)
{
	int i;
	Element_f *weight = NULL;
	for (i = network->input + 1; i < network->nbNeuron; i++) {
		weight = network->neurons[i]->weight->head;
		while (weight != NULL) {
			weight->value += EPSILON * delta[i] * weight->value;
		}
	}
}

void backPropagation(Network *network, double *x, double *y)
{
	int i;
	int startOutput = network->nbNeuron - network->output;
	double *delta = NULL;
	delta = malloc(network->nbNeuron * sizeof(double));
	inputNetwork(network, x, network->output);
	executeNetwork(network);
	for (i = startOutput; i < network->nbNeuron; i++) {
		delta[i] = network->result[i] * (1 - network->result[i]) * \
    				(y[i-startOutput] - network->result[i]);
	}
	for (i = startOutput - 1; i >= network->input; i--) {
		delta[i] = network->result[i] * (1 - network->result[i]) * \
				sommeSortiNeuron(network, i, delta);
	}
	changeWeight(network, delta);
}

/*
 * builder
 */

Network * testNetwork()
{
	Network *network = NULL;
	network = initNetwork(3, 2, 1);

	addNetwork(network, 0 ,2, 0.3);
	addNetwork(network, 1, 2, 0.3);

	return network;
}
