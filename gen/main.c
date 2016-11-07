#include "prn.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Syntax: prn [path]\n");
		return 0;
	}
	struct PRN *prn = NULL;
	prn = initPRN();
	genPRN(prn, argv[1]);
	freePRN(&prn);
	return 0;
}
