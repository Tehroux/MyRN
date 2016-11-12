#include "list_template.h"

int main()
{

    List(int) *list = new_list(int);
    if (list != NULL) free(list);
    
    return 0;

}
