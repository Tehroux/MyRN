#ifndef  MATRICE_H
#define  MATRICE_H

typedef struct Picture{
    int height;
    int width;
    int **value;
} Picture;

int main(int argc, char *argv[]);
Picture * pictureFromFile(const char *path);
void freePicture(Picture *pic);
void displayPicture(const Picture *pic);

#endif //MATRICE_H
