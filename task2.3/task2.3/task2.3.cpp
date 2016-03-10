#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a[10] {1, 4, 7, 3, 10, 20, 30, 40, 50, 12};
	int* p = a;
	int* l = a + 9;
	bool check = false;
	while (!check && p != l)
	{
		while (p != l)
		{
			if (abs(*p - *l) == 1)
			{
				check = true;
				break;
			}
			l--;
		}
		p++;
		l = a + 9;
	}
	cout << check << endl;
	return 0;
}

