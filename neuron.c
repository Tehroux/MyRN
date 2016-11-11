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

Neuron * initNeuron()
{
	Neuron * neuron = NULL;
	neuron = malloc(sizeof(Neuron));
	neuron->nbNeighbors = 0;
	neuron->neighbors = initList_i();
	neuron->weight = initList_f();
	return neuron;
}

void addNeuron(Neuron *neuron, int neighbor)
{
	neuron->nbNeighbors++;
	addList_i(neuron->neighbors, neighbor);
	addList_f(neuron->weight, rand() % 100 / 100);
}

double executeNeuron(Neuron *neuron, double *result)
{
	double r = 0;
	Element_i *neighbors = neuron->neighbors->head;
	Element_f *weight = neuron->weight->head;
	while (neighbors != NULL) {
		r += result[neighbors->value] * weight->value;
		neighbors = neighbors->next;
		weight = weight->next;
	}
	return sigmoid(r) - 0.5;
}
