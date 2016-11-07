#ifndef PRN_H
#define PRN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/*
 * Management of PNR's datafile
 */

typedef struct PRN {
	int height;
	int width;
	int **value;
} PRN;

PRN * initPRN();
void printPRN(PRN *prn);
void genPRN(PRN *prn, char *path);
void freePRN(PRN **prn);

#endif /* PRN_H */
