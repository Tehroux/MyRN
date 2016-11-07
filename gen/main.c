#include "prn.h"

int main(int argc, char **argv)
{
	struct PRN *prn = NULL;
	prn = initPRN();
	genPRN(prn, "test");
	freePRN(&prn);
	return 0;
}
