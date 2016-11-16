#ifndef NETWORK_H
#define NETWORK_H

    #include "neuron.h"

    #define EPSILON 10
    #define NBLEARN 5000

    /*
     * structure neuron network
     */

    typedef struct _network {
        int size;
        int inputSize;
        int outputSize;
        Neuron **neurons;
        float *results;
    } Network;

    Network * Network_init(int size, int input_size, int output_size);
    void Network_addInputValue(Network *network, float *value);
    void Network_addOutputValue(Network *network, float *value);
    void Network_addNeuronLink(Network *network, int father_index, \
            int child_index, float weight);
    void Network_execute(Network *network);
    void Network_learn(Network *network, float ***example, int example_size, \
            int learning_count);
    void Network_free(Network **network);
           
    /*
     * learning algorithme : backpropogation
     */

    float sommeSortiNeuron(Network *network, int indexNeuron, float *delta);
    void changWeight(Network *network, float *delta);
    void backPropagation(Network *network, float *x, float *y);

    /*
     * network builder
     */

    Network * testNetwork();

    /*
     * example builder
     */

    float *** andExample();

#endif /* NETWORK_H */
