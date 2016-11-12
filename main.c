#include "network.h"

int main(int argc, char ** argv)
{
	double in[2] = {-0.5, 0.5};
	Network * network = NULL;
	network = testNetwork();
	inputNetwork(network, in, 2);
	executeNetwork(network);
	outputNetwork(network);
	return 0;
}
