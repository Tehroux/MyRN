#ifndef NEURON_H
#define NEURON_H

    #include "list.h"

    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <time.h>

    /*
     * Threshold function : sigmoid
     */

    float sigmoid(float x);

    /*
     * Structure Neuron : 
     * weight apply on neighbord_in
     */

    typedef struct _neuron {
	    List(int) 	*neighbors_in;
	    List(int)	*neighbors_out;
	    List(float)	*weight;
	    float 		threshold;
    } Neuron;

    Neuron * Neuron_init();
    void 	 Neuron_free(Neuron **neuron);

    void	 Neuron_addNeighborIn(Neuron *neuron, int neuron_in, float weight);
    void	 Neuron_addNeighborOut(Neuron *neuron, int neuron_out);
    float	 Neuron_execute(Neuron *neuron, float *result);
    float    Neuron_getWeight(Neuron *neuron, int neighbor);

#endif /* NEURON_H */
