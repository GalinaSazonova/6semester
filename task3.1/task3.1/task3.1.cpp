#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int a[1000] {2, 3, 7, 9, 5, 6, 7, 8, 9, 10};
	int *p;
	p = a;
	int n = 1000;
	for (int i = 1; i < 11; i++)
	{
		n = n / 2 + n % 2;
		if (*(p + n) != 0)
		{
			p = p + n;
		}
	}
	cout << p - a + 1 << endl;
	return 0;
}

