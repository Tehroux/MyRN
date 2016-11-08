#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/*
 * double type list
 */

typedef struct ELEMENT_F {
	double value;
	struct ELEMENT_F *next;
} Element_f;

Element_f * initElement_f(double value, Element_f *next);

typedef struct LIST_F {
	int nbElement;
	Element_f *head;
} List_f;

List_f * initList_f();
void addList_f(List_f *list, double value);
void printList_f(List_f *list);
double popList_f(List_f * list);
void freeList_f(List_f **list);

/*
 * integer type list
 */

typedef struct ELEMENT_I {
	int value;
	struct ELEMENT_I *next;
} Element_i;

Element_i * initElemet_i(int value, Element_i *next);

typedef struct LIST_I {
	int nbElement;
	Element_i *head;
} List_i;

List_i * initList_i();
void addList_i(List_i *list, int value);
void printList_i(List_i *list);
int popList_i(List_i *list);
void freeList_i(List_i **list);

#endif /* LIST_H */
