#ifndef PRN_H
#define PRN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/*
 * gestion des fichier de donnee PRN
 */

struct PRN {
	int height;
	int width;
	int **value;
};

struct PRN * initPRN();
void printPRN(struct PRN *prn);
void genPRN(struct PRN *prn, char *path);

#endif
