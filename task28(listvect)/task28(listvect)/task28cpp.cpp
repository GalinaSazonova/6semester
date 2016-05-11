#include "stdio.h"
#include <iostream>
#include <list>

using namespace std;

int main()
{
	int i;
	list<int> list;
	while (true)
	{
		cin >> i;
		if (i == 0)
			break;
		list.push_front(i);
	}
	for (auto p = list.begin(); p != list.end(); p++) 
	{
		cout << *p << " ";
	}
	cout << endl;
	return 0;
}