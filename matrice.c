#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"

int main(int argc, char *argv[])
{

    if (argc == 2) {
    
        printf(" - \n");
        Picture *pic = pictureFromFile(argv[1]);
        if (pic != NULL) {
        
            printf(" -- \n");
            displayPicture(pic);
            printf(" --- \n");
            freePicture(pic);
        
        }        
    
    } else {
        printf("USAGE: %s [file]\n", argv[0]);
    }
    
    return 0;

}

/*
 * Descriptor
 */
Picture * pictureFromFile(const char *path)
{

    int i, j;
    Picture *pic = NULL;
    FILE *fp = NULL;
    
    fp = fopen(path, "rb");    
    if (fp == NULL) {
        //Log.e("fopen");
        return NULL;
    }
    
    pic = (Picture*) malloc(sizeof(Picture) * 1);
    fread(&pic->height, sizeof(int), 1, fp);
    fread(&pic->width, sizeof(int), 1, fp);
    
    if ((!pic->height || !pic->width) && \
        ( pic->height !=  pic->width)) {
        //Log.e("height or width invalid");
        free(pic);
        fclose(fp);
        return NULL;
    }
    
    pic->value = (int**) malloc(sizeof(int*) * pic->height);
    for (i = 0; i<pic->height; i++) {
        pic->value[i] = (int*) malloc(sizeof(int) * pic->width);
    }
    
    for (i = 0; i<pic->height; i++) {
        for (j = 0; j<pic->width; j++) {
            fread(&pic->value[i][j], sizeof(int), 1, fp);
        }
    }
    
    fclose(fp);
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

