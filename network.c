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

void outputNetwork(Network *network)
{
	int i;
	for (i = network->nbNeuron - network->output; 
			i < network->nbNeuron; i++) {
		printf("%f ; ",network->result[i]);
	}
	printf("\n");
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
