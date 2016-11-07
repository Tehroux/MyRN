#ifndef  MATRICE_H
#define  MATRICE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct Picture {
    int height;
    int width;
    int **value;
} Picture;

int main(int argc, char *argv[]);
Picture * pictureFromFile(char *path);
void freePicture(Picture *pic);
void displayPicture(const Picture *pic);

#endif
