#include "stdio.h"
#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List *list = createList();
	insertToHead(list, 1);
	insertToHead(list, 2);
	//cout << numberOfElements(list) << endl;
	insert(list, 3, 0);
	ListElement* p = last(list);
	p->value *= p->value;
	printList(list);
	List *l = reverse(list);
	printList(l);
	deleteList(list);
	return 0;
}