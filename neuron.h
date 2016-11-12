#ifndef NEURON_H
#define NEURON_H

#include <math.h> 
#include <time.h>
#include <stdlib.h>

#include "list/list.h"

/*
 * fonction de seuil
 */

double sigmoid(double  x);

/*
 * structure neuron
 */

typedef struct NEURON {
	int nbNeighbors;
	int nbParent;
	List_i *neighbors;
	List_i *parent;
	List_f *weight;
} Neuron;	

Neuron * initNeuron();
void addNeuron(Neuron *neuron, int neighbor, double weight);
void addParentNeuron(Neuron *neuron, int parent);
double executeNeuron(Neuron * neuron, double *result);

#endif /* NEURON_H */
