#include "network.h"

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
        int i, n = network->size;
        
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

/*
 * TODO: refactor a and b name
 */
void Network_addNeuronLink(Network *network, int a, int b, float weight)
{
    if (network != NULL) {
        Neuron_addNeighborIn(network->neurons[b], a, weight);
        Neuron_addNeighbotOut(network->neurons[a], b);     
    }
}

void Network_execute(Network *network)
{
    if (network != NULL) {
        int i, n = network->size;
        
        for(i = 0; i < n; i++) {
            /* TODO: neighbors_in or out ? (nbNeighbors precedently) */
            if (size(network->neurons[i]->neighbors_out) != 0) {
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
                backpropagation(network, example[j][0], example[j][1]);
            }
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
