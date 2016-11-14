#include "network.h"

int main(int argc, char ** argv)
{
    int i = 0;
	srand(time(0));
	double in[2] = {-0.5, -0.5};
	double out[1];
	double ***example = andExample();
	Network * network = NULL;
	
	network = testNetwork();
	learnNetwork(network, example, 4);
	inputNetwork(network, in, 2);
	executeNetwork(network);
	outputNetwork(network, out);
	
	free(network->neurons);
	free(network->result);
	free(network);
	
	for (i = 0; i < 4; i++) {
	    free(example[i][0]);
	    free(example[i][1]);
	    free(example[i]);
	}
	free(example);
	
	return 0;
}
