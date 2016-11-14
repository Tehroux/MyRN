#ifndef LIST_TEMPLATE_H
#define LIST_TEMPLACE_H

    #include <stdio.h>
    #include <stdlib.h>

    #define define_list(type) \
    \
        struct _list_##type; \
        struct _list_element_##type; \
        \
        typedef struct \
        { \
            int     (*is_empty) (const struct _list_##type*); \
            size_t  (*size)     (const struct _list_##type*); \
            void    (*add)      (struct _list_##type*, struct _list_element_##type*); \
            type    (*pop)      (struct _list_##type*); \
            void    (*clear)    (struct _list_##type*); \
            void    (*destroy)  (struct _list_##type*); \
        } _list_functions_##type; \
        \
        typedef struct _list_element_##type \
        { \
            type                        value; \
            struct _list_element_##type *next; \
        } list_element_##type; \
        \
        typedef struct _list_##type \
        { \
            size_t                  size; \
            list_element_##type     *head; \
            list_element_##type     *queue; \
            _list_functions_##type  *functions; \
        } list_##type; \
        \
        /* Functions prototype */ \
        list_##type *           new_list_##type(); \
        list_element_##type *   new_element_##type(const type value); \
        int                     list_is_empty_##type(const list_##type *list); \
        size_t                  list_size_##type(const list_##type *list); \
        void                    list_add_##type(list_##type *list, list_element_##type *e); \
        type                    list_pop_##type(list_##type *list); \
        void                    list_clear_##type(list_##type *list); \
        void                    list_destroy_##type(list_##type *list); \
        \
        /* Functions defining */ \
        int list_is_empty_##type(const list_##type *list) \
        { \
            if (list == NULL) return 1; \
            return list->size == 0; \
        } \
        \
        size_t list_size_##type(const list_##type *list) \
        { \
            if (list == NULL) return 0; \
            return list->size; \
        } \
        \
        void list_add_##type(list_##type *list, list_element_##type *e) \
        { \
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
        type list_pop_##type(list_##type *list) \
        { \
            if (list == NULL || list->head == NULL) return 0; \
            list_element_##type * tmp = list->head; \
            type v = tmp->value; \
            list->head = list->head->next; \
            list->size--; \
            free(tmp); \
            return v; \
        } \
        \
        void list_clear_##type(list_##type *list) \
        { \
            int i = 0, n = list_size_##type(list); \
            for (i=0; i<n; i++) { \
                list_pop_##type(list); \
            } \
        } \
        \
        void list_destroy_##type(list_##type *list) \
        { \
            if (list != NULL) { \
                list_clear_##type(list); \
                free(list); \
            } \
        } \
        \
        _list_functions_##type _list_func_##type = { \
            &list_is_empty_##type, \
            &list_size_##type, \
            &list_add_##type, \
            &list_pop_##type, \
            &list_clear_##type, \
            &list_destroy_##type \
        }; \
        \
        list_##type * new_list_##type() \
        { \
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
    #define pop(collection) collection->functions->pop(collection)
    #define clear(collection) collection->functions->clear(collection)
    #define destroy(collection) collection->functions->destroy(collection)
    
    /*
     * Call define_list(type) in top of your code to call the define preprocess.
     * To use the list, use List(type) *list and Element(type) *elem.
     * 
     * To instanciate the list you have to use new_liste(type) :
     * > List(type) *var = new_list(type);
     * To instanciate a list element you have to use new_element(type) :
     * > Element(type) *elem = new_element(type);
     *
     * The following functions are implemented :
     * + void add(list, elem)
     *  -> Append elem to the list, do nothing if the list is null
     * + type pop(list)
     *  -> Remove the first element to the list and return the value, 
           return 0 if the list or the head are null
     * + void clear(list)
     *  -> Remove all the list, do nothig if the list is null
     * + void destroy(list)
     *  -> Remove all the list and free the list, do nothing if the list is null
     */
    
#endif /* LIST_TEMPLATE_H */
