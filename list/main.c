#include "list.h"

int main(int argc, char **argv)
{
	List_i * list = NULL;
	list = initList_i();
	addList_i(list, 5);
	addList_i(list, 5);
	printList_i(list);
	freeList_i(&list);	
	return 0;
}
