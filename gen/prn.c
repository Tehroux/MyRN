#include "prn.h"

/*
 * initialisation et remplissage de la matrice pnr
 */

struct PRN * initPRN()
{
	int i, j;
	struct PRN *prn = NULL;
	prn =  malloc(sizeof(struct PRN));
	printf("> enter your matrice's dimention (height width)\n ");
	scanf("%d %d", &(prn->height), &(prn->width));
	prn->value = malloc(prn->height * sizeof(int*));
	printf("> enter your matrice line by line\n");
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
 * affichage de la matrice
 */

void printPRN(struct PRN *prn)
{
	int i, j;
	printf("> size : %d x %d \n", prn->height, prn->width);
	for (i = 0; i < prn->height; i++) {
		for (j = 0; j < prn->width; j++) {
			printf(" %d", prn->value[i][j]);
		}
		printf("\n");
	}
}

/*
 * creation du fichier prn
 */

void genPRN(struct PRN *prn, char *path)
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
 * liberation de la structure prn
 */

void freePRN(struct PRN **prn)
{
	int i;
	for (i = 0; i < (*prn)->height; i++) {
		free((*prn)->value[i]);
	}
	free((*prn)->value);
	free(*prn);
	prn = NULL;
}
