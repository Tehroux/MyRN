#include "prn.h"

/*
 * PNR matrice initialization and filling
 */
PRN * initPRN()
{

	int i, j;
	PRN *prn = NULL;
	prn =  malloc(sizeof(struct PRN));
	
	printf("> Enter your matrice's dimention (height width)\n ");
	scanf("%d %d", &(prn->height), &(prn->width));
	prn->value = malloc(prn->height * sizeof(int*));
	
	printf("> Enter your matrice line by line\n");
	for (i = 0; i < prn->height; i++) {
	
		prn->value[i] = malloc(prn->width * sizeof(int));
		printf(" ");
		for (j = 0; j < prn->width; j++) {
			scanf("%d", &(prn->value[i][j]));
		}
	
	}
	
	return prn;
	
}

/*
 * PNR matrice displaying
 */
void printPRN(PRN *prn)
{

	int i, j;
	
	printf("> Size: %d x %d \n", prn->height, prn->width);
	for (i = 0; i < prn->height; i++) {
		for (j = 0; j < prn->width; j++) {
			printf(" %d", prn->value[i][j]);
		}
		printf("\n");
	}
	
}

/*
 * PNR file generation
 */
void genPRN(PRN *prn, char *path)
{

	int i, j;
	int file;
	
	file = open(path, O_WRONLY | O_CREAT, S_IRWXU);
	write(file, &(prn->height), sizeof(int));
	write(file, &(prn->width), sizeof(int));
	
	for (i = 0; i < prn->height; i++) {
		for (j = 0; j < prn->width; j++) {
			write(file, &(prn->value[i][j]), sizeof(int));
		}
	}
	
	close(file);
	
}

/*
 * PNR structure releasing
 */
void freePRN(PRN **prn)
{

	int i;
	
	for (i = 0; i < (*prn)->height; i++) {
		free((*prn)->value[i]);
	}
	free((*prn)->value);
	free(*prn);
	prn = NULL;
	
}
