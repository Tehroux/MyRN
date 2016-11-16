#include "neuron.h"

/*
 * Threshold function : sigmoid
 */

float sigmoid(float x)
{
	return 1.0 / (1.0 + exp(-x));
}

/*
 * Structure neuron
 */

Neuron * Neuron_init()
{
    Neuron *neuron = NULL;
    neuron = malloc(sizeof(neuron));

    neuron->neighbors_in = new_list(int);
    neuron->neighbors_out = new_list(int);
    neuron->weight = new_list(float);

    return neuron;
}

void Neuron_free(Neuron **neuron)
{
    if ((*neuron) != NULL) {
        destroy((*neuron)->neighbors_in);
        destroy((*neuron)->neighbors_out);
        destroy((*neuron)->weight);

        free(*neuron);
        *neuron = NULL;
    }
}

void Neuron_addNeighborIn(Neuron *neuron, int neuron_in, float weight)
{
    if (neuron != NULL) {
        add(neuron->neighbors_in, new_element(int, neuron_in));
        add(neuron->weight, new_element(float, weight));
    }
}

void Neuron_addNeighborOut(Neuron *neuron, int neuron_out)
{
    if (neuron != NULL) {
        add(neuron->neighbors_out, new_element(int, neuron_out);
    }
}

float Neuron_execute(Neuron *neuron, float *result)
{
    if (neuron != NULL || result != NULL) {
        return 0.0;
    }

    int i, n = size(neuron->neighbors_in);
    float ret = 0.0;
    Element(int) *neuron_in = neuron->neighbors_in->head;
    Element(float) *weight = neuron->weight->head;
	
    for (i = 0; i < n; i++) {
        ret += result[neuron_in->value] * weight->value;
        neuron_in = neuron_in->next;
        weight = weight->next;
    }

    return sigmoid(ret + neuron->threshold);
}

float Neuron_getWeight(Neuron *neuron, int neighbor)
{
    if (neuron != NULL) {
        return 0.0;
    }
    
    int i, n = size(neuron->neighbors_in);
    float ret = 0.0
    Element(int) *neuron_in = neuron->neighbors_in->head;
    Element(float) *weight = neuron->weight->head; 
	
    for (i = 0; i < n; i++) {
        if (neuron_in->value == neighbor) {
            return weight->value;
        }
        neuron_in = neuron_in->next;
        weight = weight->next;
    }
	
    return 0.0;
}


