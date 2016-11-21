#ifndef MATRICE_H
#define MATRICE_H
    
    typedef struct _picture {
        int height;
        int width;
        int **value;    
    } Picture;
    
    Picture * Picture_createFromFile(const char *path);
    void Picture_free(Picture *pic);
    void Picutre_display(const Picture *pic);
    
#endif /* MATRICE_H */
