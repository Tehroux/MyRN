#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLACE_H

    #include <stdio.h>
    #include <stdlib.h>

    #define define_list(type)                       \
        \
        struct _list_##type;                        \
        \
        typedef struct{       \
            \
            int (*is_empty)(const _list_##type*);   \
            size_t (*size)(const _list_##type*);    \
            \
        } _list_functions_##type;    \
        \
        typedef struct _list_element_##type{     \
            \
            type value;                             \
            struct _list_element_##type *next;      \
            \
        } list_element_##type;                  \
        \
        typedef struct _list_##type{     \
            \
            size_t                  size;           \
            list_element_##type     *head;          \
            list_element_##type     *queue;         \
            _list_functions_##type  *functions;     \
            \
        } list_##type;                  \
        \
        /* Functions prototype */ \
        list_##type * new_list_##type();                    \
        int list_is_empty_##type(const list_##type *list);  \
        size_t list_size_##type(const list_##type *list);   \
        \
        /* Functions defining */ \
        list_functions_##type list_func_##type{     \
            &list_is_empty_##type,  \
            &list_size_##type       \
        };                                           \
        \
        int list_is_empty_##type(const list_##type *list){      \
            if (list == NULL) return 1; \
            return list->size == 0;     \
        }                                                       \
        \
        size_t list_size_##type(const list_##type *list){       \
            if (list == NULL) return 0; \
            return list->size;          \
        }                                                       \
        \
        list_##type * new_list_##type(){    \
            list_##type *list = (list_##type *) malloc(sizeof(list_##type));    \
            list->size =        0;                                              \
            list->head =        NULL;                                           \
            list->queue =       NULL;                                           \
            list->functions =   &list_functions_##type;                         \
            return list;                                                        \
        }                                   \
        \
        
    /* Define to use the list */
    #define List(type) list_##type
    #define new_list(type) new_list_##type()   
    
    /* Basic collections */
    define_list(int);
    define_list(char);
    define_list(float);
    define_list(double);
    
    /* Pointer collections */
    typedef char * String;
    define_list(String);

#endif /* LIST_TEMPLATE_H */
