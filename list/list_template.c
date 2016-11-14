#include "list_template.h"

/* Basic collections */
define_list(int)

int main()
{
    List(int) *list = new_list(int);
    printf("%s\n", (is_empty(list)? "True" : "False"));
        
    printf("new_element(int, 1) ->\n");
    Element(int) *e = new_element(int, 1);
    if (e != NULL)
        printf("e->value = %d\n", e->value);    
                
    add(list, e);
 	add(list, new_element(int, 42)); 
    printf("%s\n", (is_empty(list)? "True" : "False"));

    destroy(list);
    return 0;    
}
