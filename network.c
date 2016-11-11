#include "network.h"

Network * initNetwork(int nbNeuron)
{
	int i;
	Network *network = NULL;
	network = malloc(sizeof(network));
	network->nbNeuron = nbNeuron;
	network->neurons = malloc(nbNeuron * sizeof(Neuron));
	network->result = malloc(nbNeuron * sizeof(double));
	for (i = 0; i < nbNeuron; i++) {
		network->neurons[i] = initNeuron();
	}
	return network;
}

void * inputNetwork(Network *network, int *input, int nbInput)
{
	int i;
	for (i = 0; i < nbInput; i++) {
		network->result[i] = input[i];
	}
}

/*
 * builder
 */

Network * testNetwork()
{
	Network *network = NULL;
	network = initNetwork(9);

	addNeuron(network->neurons[0], 3);
	addNeuron(network->neurons[0], 4);
	addNeuron(network->neurons[0], 5);
	addNeuron(network->neurons[1], 3);
	addNeuron(network->neurons[1], 4);
	addNeuron(network->neurons[1], 5);
	addNeuron(network->neurons[2], 3);
	addNeuron(network->neurons[2], 4);
	addNeuron(network->neurons[2], 5);
	
	addNeuron(network->neurons[3], 6);
	addNeuron(network->neurons[3], 7);
	addNeuron(network->neurons[3], 8);
	addNeuron(network->neurons[4], 6);
	addNeuron(network->neurons[4], 7);
	addNeuron(network->neurons[4], 9);
	addNeuron(network->neurons[4], 6);
	addNeuron(network->neurons[5], 7);
	addNeuron(network->neurons[5], 8);

	return network;
}
