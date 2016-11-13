#include "network.h"

int main(int argc, char ** argv)
{
	srand(time(0));
	double in[2] = {-0.5, 0.5};
	double out[1];
	double ***example = andExample();
	Network * network = NULL;
	network = testNetwork();
	learnNetwork(network, example, 4);
	inputNetwork(network, in, 2);
	executeNetwork(network);
	outputNetwork(network, out);
	return 0;
}
