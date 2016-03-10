#include "stdafx.h"
#include <iostream>

using namespace std;

void clear(int *a, int size)
{
	while (size != 0)
	{
		*a = 0;
		a++;
		size--;
	}
}

void copy(const int *a, int *b, int size)
{
	while (size != 0)
	{
		*b = *a;
		b++;
		a++;
		size--;
	}
}

int main()
{
	int a[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	clear(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int b[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//clear(b, 10);
	copy(a, b, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}

