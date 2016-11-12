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
	neuron->nbParent = 0;
	neuron->neighbors = initList_i();
	neuron->parent = initList_i();
	neuron->weight = initList_f();
	return neuron;
}

void addNeuron(Neuron *neuron, int neighbor, double weight)
{
	neuron->nbNeighbors++;
	addList_i(neuron->neighbors, neighbor);
	if (weight == 0)
		addList_f(neuron->weight, rand() % 100 / 100);
	else
		addList_f(neuron->weight, weight);
}

void addParentNeuron(Neuron *neuron, int parent)
{
	neuron->nbParent++;
	addList_i(neuron->parent, parent);
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
