#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLACE_H

    #include <stdio.h>
    #include <stdlib.h>

    #define define_list(type) \
    \
        struct _list_##type; \
        struct _list_element_##type; \
        \
        typedef struct { \
            \
            int (*is_empty)(const struct _list_##type*); \
            size_t (*size)(const struct _list_##type*); \
            void (*add)(struct _list_##type*, struct _list_element_##type*); \
            \
        } _list_functions_##type; \
        \
        typedef struct _list_element_##type { \
            \
            type value; \
            struct _list_element_##type *next; \
            \
        } list_element_##type; \
        \
        typedef struct _list_##type { \
            size_t                  size; \
            list_element_##type     *head; \
            list_element_##type     *queue; \
            _list_functions_##type  *functions; \
            \
        } list_##type; \
        \
        /* Functions prototype */ \
        list_##type * new_list_##type(); \
        list_element_##type * new_element_##type(const type value); \
        int list_is_empty_##type(const list_##type *list); \
        size_t list_size_##type(const list_##type *list); \
        void list_add_##type(list_##type *list, list_element_##type *e); \
        \
        /* Functions defining */ \
        int list_is_empty_##type(const list_##type *list){ \
            if (list == NULL) return 1; \
            return list->size == 0; \
        } \
        \
        size_t list_size_##type(const list_##type *list){ \
            if (list == NULL) return 0; \
            return list->size; \
        } \
        void list_add_##type(list_##type *list, list_element_##type *e){ \
            if (list != NULL) { \
                if (list->head == NULL) { \
                    list->head = e; \
                    list->queue = e; \
                } else { \
                    list->queue->next = e; \
                    list->queue = e; \
                } \
                list->size++; \
            } \
        } \
        \
        _list_functions_##type _list_func_##type = { \
            &list_is_empty_##type, \
            &list_size_##type, \
            &list_add_##type \
        }; \
        \
        list_##type * new_list_##type(){ \
            list_##type *list = (list_##type *) malloc(sizeof(list_##type)); \
            list->size =        0; \
            list->head =        NULL; \
            list->queue =       NULL; \
            list->functions =   &_list_func_##type; \
            return list; \
        } \
        \
        list_element_##type * new_element_##type(const type value){ \
            list_element_##type *e = (list_element_##type *) malloc(sizeof(list_element_##type)); \
            e->value = value; \
            e->next = NULL; \
            return e; \
        } \
        
    /* Define to use the list */
    #define List(type) list_##type
    #define Element(type) list_element_##type
    #define new_list(type) new_list_##type()
    #define new_element(type, value) new_element_##type(value)
    
    #define is_empty(collection) collection->functions->is_empty(collection)
    #define size(collection) collection->functions->size(collection)
    #define add(collection, element) collection->functions->add(collection, element)
    
#endif /* LIST_TEMPLATE_H */
