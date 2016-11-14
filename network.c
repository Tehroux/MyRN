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
		printf("%f ; ", network->result[i]);
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

void learnNetwork(Network *network, double ***example, int nbExample)
{
	int i, j;
	for (i = 0; i < NBLEARN; i++) {
		/* printf("Iter %d\r", i); */
		for (j = 0; j < nbExample; j++) {
			backPropagation(network, example[j][0], example[j][1]);
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
		neighborsOut = neighborsOut->next;
	}
	return ret + network->neurons[indexNeuron]->threshold;
}

void changeWeight(Network *network, double *delta)
{
	int i;
	Element_f *weight = NULL;
	for (i = network->input; i < network->nbNeuron; i++) {
		weight = network->neurons[i]->weight->head;
		while (weight != NULL) {
			weight->value += EPSILON * delta[i] * weight->value;
			weight = weight->next;
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
	free(delta);
}

/*
 * builder
 */

Network * testNetwork()
{
	Network *network = NULL;
	network = initNetwork(5, 2, 1);

	addNetwork(network, 0 ,2, 0);
	addNetwork(network, 1, 2, 0);
	addNetwork(network, 0, 3, 0);
	addNetwork(network, 1, 3, 0);
	addNetwork(network, 2, 4, 0);
	addNetwork(network, 3, 4, 0);

	return network;
}

/*
 * example builder
 */

double *** andExample()
{
	int i;
	double ***example = NULL;
	example = malloc(4 * sizeof(double **));
	for (i = 0; i < 4; i++) {
		example[i] = malloc(2 * sizeof(double *));
		example[i][0] = malloc(2 * sizeof(double));
		example[i][1] = malloc(sizeof(double));
	}
	example[0][0][0] = 0.5;
	example[0][0][1] = 0.5;
	example[0][1][0] = 0.5;
	
	example[1][0][0] = 0.5;
	example[1][0][1] = -0.5;
	example[1][1][0] = -0.5;
	
	example[2][0][0] = -0.5;
	example[2][0][1] = 0.5;
	example[2][1][0] = -0.5;
	
	example[3][0][0] = -0.5;
	example[3][0][1] = -0.5;
	example[3][1][0] = -0.5;

	return example;
}
