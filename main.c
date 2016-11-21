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

int main(int argc, char **argv)
{
	srand(time(0));
	
    int i = 0;	
	float in[2] = {-0.5, -0.5};
	float out[1];
	float ***example = andExample();
	Network *network = NULL;
	
	network = Network_createTest();
	
	/*Network_learn(network, example, 4, 500);*/
	Network_addInputValue(network, in);
	Network_execute(network);
	Network_addOutputValue(network, out);
	
	Network_free(&network);
		
	for (i = 0; i < 4; i++) {
	    free(example[i][0]);
	    free(example[i][1]);
	    free(example[i]);
	}
	free(example);
	
	return 0;
}
