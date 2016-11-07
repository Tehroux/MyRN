#include "matrice.h"

/*
 * Descriptor
 */

Picture * pictureFromFile(char *path)
{
	int file;
	int i, j;
	Picture *pic = NULL;
	file = open(path, O_RDONLY);
	if (file == -1)
		return NULL;
	pic = malloc(sizeof(Picture));
	read(file, &(pic->height), sizeof(int));
	read(file, &(pic->width), sizeof(int));
	pic->value = malloc(pic->height * sizeof(int *));
	for (i = 0; i < pic->height; i++) {
		pic->value[i] = malloc(pic->width * sizeof(int));
		for (j = 0; j < pic->width; j++) {
			read(file, &(pic->value[i][j]), sizeof(int));
		}
	}
	return pic;
}

void freePicture(Picture *pic)
{

    int i;    
    for (i = 0; i<pic->height; i++) {
        free(pic->value[i]);
    }
    free(pic->value);
    
    free(pic);
    pic = NULL;
    
}

void displayPicture(const Picture *pic)
{

    int i, j;
    for (i = 0; i<pic->height; i++) {
        for (j = 0; j<pic->width; j++) {
            printf("%d ", pic->value[i][j]);
        }
        printf("\n");
    }

}

