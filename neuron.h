#ifndef NEURON_H
#define NEURON_H

#include <math.h> 
#include <time.h>
#include <stdlib.h>

/*
 * fonction de seuil
 */

double sigmoid(double  x);

/

typedef struct NEURON {
	int nbWeight;
	double *weight;
} Neuron;	



#endif /* NEURON_H */
