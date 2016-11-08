#include "list.h"

/*
 * double type element function
 */

Element_f * initElement_f(double value, Element_f *next)
{
	Element_f *element = NULL;
	element = malloc(sizeof(Element_f));
	element->value = value;
	element->next = next;
	return element;
}

/*
 * double type list function
 */

List_f * initList_f()
{
	List_f *list = NULL;
	list = malloc(sizeof(List_f));
	list->nbElement = 0;
	list->head = NULL;
	return list;
}

void addList_f(List_f * list, double value)
{
	Element_f *element = NULL;
	element = initElement_f(value, list->head);
	list->head = element;
	list->nbElement++;
}

void printList_f(List_f *list)
{
	Element_f *tmp = list->head;
	while (tmp != NULL) {
		printf("%f ; ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

double popList_f(List_f *list)
{
	double ret = 0;
	Element_f *tmp = NULL;
	if (list->nbElement > 0) {
		list->nbElement--;
		ret = list->head->value;
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
	return ret;
}

void freeList_f(List_f **list)
{
	while ((*list)->nbElement > 0) {
		popList_f(*list);
	}
	free(*list);
	*list = NULL;
}

/*
 * integer type element function
 */

Element_i * initElement_i(int value, Element_i *next)
{
	Element_i * element = NULL;
	element = malloc(sizeof(Element_i));
	element->value = value;
	element->next = next;
	return element;
}

/*
 * integer type list function
 */

List_i * initList_i()
{
	List_i *list = NULL;
	list = malloc(sizeof(List_i));
	list->nbElement = 0;
	list->head = NULL;
	return list;
}

void addList_i(List_i *list, int value)
{
	Element_i *element = NULL;
	element = initElement_i(value, list->head);
	list->head = element;
	list->nbElement++;
}

void printList_i(List_i *list)
{
	Element_i *tmp = list->head;
	while (tmp != NULL) {
		printf("%d ; ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int popList_i(List_i * list)
{
	int ret = 0;
	Element_i * tmp = NULL;
	if (list->nbElement > 0) {
		list->nbElement--;
		ret = list->head->value;
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
	return ret;
}

void freeList_i(List_i **list)
{
	while ((*list)->nbElement > 0) {
		popList_i(*list);
	}
	free(*list);
	*list = NULL;
}
