#include "neuron.h"

/*
 * threshold function
 */

double sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

/*
 * neuron structure fuction
 */

Neuron * initNeuron(int nbNeighbors, List_i *neighbors)
{
	int i;
	Neuron * neuron = NULL;
	neuron = malloc(sizeof(Neuron));
	neuron->nbNeighbors = nbNeighbors;
	neuron->neighbors = neighboors;
	neuron->weight = initList_f();
	for (i = 0; i < nbNeighbors; i++) {
		addList_f(neuron->weight, (rand() % 100) / 100);
	}
	return neuron;
}

double executeNeuron(Neuron *neuron, double *result)
{
	double result = 0;
	Element_i *neighbors = neuron->neighbors->head;
	Element_f *weight = neuron->weight->head;
	while (neighbors != NULL) {
		result 
	}
}
