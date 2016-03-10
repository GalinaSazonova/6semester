#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	int a[10] {2, 3, 7, 9, 7, 0, 0, 0, 0, 0};
	int *p = a;
	while (*p != 0)
	{
		p++;
	}
	cout << p - a << endl;
	return 0;
}

