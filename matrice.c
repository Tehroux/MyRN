#include "matrice.h"

/*
 * Create a picture from a .prn file
 */
 
Picture * Picture_createFromFile(const char *path)
{
    int file, i, j;
    Picture *pic = NULL;
    
    file = open(path, O_RDONLY);
    if (file == -1)
        return NULL;
    
    pic = (Picture *) malloc(sizeof(Picture));
    if (pic == NULL)
        return NULL;
        
    read(file, &(pic->height), sizeof(int));
    read(file, &(pic->width), sizeof(int));
    pic->value = (int **) malloc(sizeof(int *) * pic->height);
    
    for (i = 0; i < pic->height; i++) {
        pic->value[i] = (int *) malloc(sizeof(int) * pic->width);
        for (j = 0; j < pic->width; j++) {
            read(file, &(pic->value[i][j]), sizeof(int));
        }
    }

    close(file);
    return pic;
}

void Picture_free(Picture *pic)
{
    int i;
    
    if (pic != NULL) {
        for (i = 0; i < pic->height; i++) {
            free(pic->value[i]);
        }
        
        free(pic->value);
        free(pic);
        pic = NULL;
    }
}

void Picture_display(const Picture *pic)
{
    int i, j;
    
    if (pic != NULL) {
        for (i = 0; i < pic->height; i++) {
            for (j = 0; j < pic->width; j++) {
                printf("%d ", pic->value[i][j]);
            }
            printf("\n");
        }
    }
}
