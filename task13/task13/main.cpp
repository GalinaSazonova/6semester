#include "stdio.h"
#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	List *list = createList();
	for (int i = n; i > 0; i--)
	{
		insertToHead(list, i);
	}
	printList(list);
	deleteList(list);
	return 0;
}