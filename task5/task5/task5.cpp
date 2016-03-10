#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	int a[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int n = 20;
	int* begin = a;
	int* end = a + n - 1;
	while (begin <= end)
	{
		int temp = *begin;
		*begin = *end;
		*end = temp;
		begin += 1;
		end -= 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
 	return 0;
}

