#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a[10]{1, 2, 3, 4, 5, 6, 11, 8, 9, 10};
	int max = a[0];
	//int delta = 0;
	int *p = a;
	int *maxel;
	for (int i = 0; i < 10; i++)
	{
		if (*p >= max)
		{
			max = *p;
			maxel = p;
		}
		p++;
	}
	//p = a;
	*maxel = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}

