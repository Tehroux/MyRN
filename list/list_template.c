#include "list_template.h"

/* Basic collections */
define_list(int)

int main()
{

    List(int) *list = new_list(int);
    if (list != NULL) {
        
        printf("%s\n", (is_empty(list)? "True" : "False"));
        
        Element(int) *e = new_element(int, 1);
        if (e != NULL) {
        
            printf("e->value = %d\n", e->value);
            
            add(list, e);
            printf("%s\n", (is_empty(list)? "True" : "False"));
            
            free(e);
        }
        free(list);
        
    }
    
    return 0;

}
