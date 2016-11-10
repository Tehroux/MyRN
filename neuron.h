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
	List_i neighbors;
	List_f weight;
} Neuron;	

Neuron * initNeuron(int nbNeighbors, List_i *neighbors);
double executeNeuron(Neuron * neuron, double *result);

#endif /* NEURON_H */
