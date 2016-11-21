#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "network.h"
/* 
 * #include "neuron.h"
 *** #include "list.h"
 ***** #include "list_template.h"
 ******* #include <stdio.h>
 ******* #include <stdlib.h>
 */

Network * Network_init(int size, int input_size, int output_size)
{
    srand(time(0));
    int i;
    Network *network = NULL;
    
    network = (Network *) malloc(sizeof(Network));
    if (network == NULL) {
        return NULL;
    }
    
    network->size = size;
    network->inputSize = input_size;
    network->outputSize = output_size;
    network->neurons = (Neuron **) malloc(sizeof(Neuron *) * size);
    if (network->neurons == NULL) {
        free(network);
        return NULL;
    }
    network->results = (float *) malloc(sizeof(float) * size);
    if (network->results == NULL) {
        free(network->neurons);
        free(network);
        return NULL;
    }
    for (i = 0; i< size; i++) {
        network->neurons[i] = Neuron_init();
    }
    
    return network;
}

void Network_addInputValue(Network *network, float *value)
{
    if (network != NULL && value != NULL) {
        int i, n = network->inputSize;
        
        for (i = 0; i < n; i++) {
            network->results[i] = value[i];
        }
    }
}

void Network_addOutputValue(Network *network, float *value)
{
    if (network != NULL && value != NULL) {
        int i;
        int startIndex = network->size - network->outputSize; 
        int endIndex = network->size;
        
        for (i = startIndex; i < endIndex; i++) {
            value[i - startIndex] = network->results[i];
            printf("%f ; ", network->results[i]);
        }
        printf("\n");
    }
}

void Network_addNeuronLink(Network *network, int father_index, int child_index, \
        float weight)
{
    if (network != NULL) {
        Neuron_addNeighborIn(network->neurons[child_index], father_index, weight);
        Neuron_addNeighborOut(network->neurons[father_index], child_index);     
    }
}

void Network_execute(Network *network)
{
    if (network != NULL) {
        int i, n = network->size;
        
        for(i = 0; i < n; i++) {
            if(size(network->neurons[i]->neighbors_in) != 0) {
                network->results[i] = Neuron_execute(network->neurons[i],
                        network->results);
            }
        }
    }
}

void Network_learn(Network *network, float ***example, int example_size, \
        int learning_count)
{
    if (network != NULL && example != NULL) {
        int i, j;
        
        for (i = 0; i < learning_count; i++) {
            printf("Iteration number: %d\r", i);
            for (j = 0; j < example_size; j++) {
                /*backpropagation(network, example[j][0], example[j][1]);*/
            }
        }    
    }
}

void Network_free(Network **network)
{
    if ((*network) != NULL) {
        int i;
        
        for (i = 0; i < (*network)->size; i++) {
            Neuron_free(&((*network)->neurons[i]));        
        }
        free((*network)->results);
        free(*network);
        *network = NULL;
    }
}

/*
 * learning algorithme : backpropagation
 */
/*
float sommeSortiNeuron(Network *network, int indexNeuron, float *delta) {
	float ret = 0;
	Element(int) *neighborsOut = network->neurons[indexNeuron]->parent->head;
	while (neighborsOut != NULL) {
		ret += delta[neighborsOut->value] * \
			getWeightNeuron(network->neurons[neighborsOut->value], 
					indexNeuron);
		neighborsOut = neighborsOut->next;
	}
	return ret + network->neurons[indexNeuron]->threshold;
}

void changeWeight(Network *network, float *delta)
{
	int i;
	Element(float) *weight = NULL;
	for (i = network->input; i < network->nbNeuron; i++) {
		weight = network->neurons[i]->weight->head;
		while (weight != NULL) {
			weight->value += EPSILON * delta[i] * weight->value;
			weight = weight->next;
		}
	}
}

void backPropagation(Network *network, float *x, float *y)
{
	int i;
	int startOutput = network->nbNeuron - network->output;
	float *delta = NULL;
	delta = malloc(network->nbNeuron * sizeof(float));
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
*/
/*
 * builder
 */

Network * Network_createTest()
{
	Network *network = NULL;
	network = Network_init(5, 2, 1);

	Network_addNeuronLink(network, 0 ,2, 0);
	Network_addNeuronLink(network, 1, 2, 0);
	Network_addNeuronLink(network, 0, 3, 0);
	Network_addNeuronLink(network, 1, 3, 0);
	Network_addNeuronLink(network, 2, 4, 0);
	Network_addNeuronLink(network, 3, 4, 0);

	return network;
}

/*
 * example builder
 */

float *** andExample()
{
	int i;
	float ***example = NULL;
	example = malloc(4 * sizeof(float **));
	for (i = 0; i < 4; i++) {
		example[i] = malloc(2 * sizeof(float *));
		example[i][0] = malloc(2 * sizeof(float));
		example[i][1] = malloc(sizeof(float));
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
