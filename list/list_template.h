#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLATE_H

#define DEFINE_LIST(type) \
typedef struct ELEMENT_##type { \
	##type value \
	struct ELEMENT_##type *next; \
} Element_##type;\
\
typedef LIST_##type { \
	int size; \
	Element_##type *head;
} \
\
Element_##type * Element_##type_init(##type value, \
		Element_##type *next); \
	

#define List(type) \
	list_##type

#endif /* LIST_TEMPLATE_H
