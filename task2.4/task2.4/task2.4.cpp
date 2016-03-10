#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int a[10][10] {};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			a[i][j] = rand() % 100;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int* b[10];
	int checkArr[10]{};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			checkArr[i] += a[i][j];
			
		}
		cout << checkArr[i] << " ";
	}
	cout << endl;
	int max = 0;
	int maxi = -1;
	int k = 0;
	while (k < 10)
	{
		for (int i = 0; i < 10; i++)
		{
			if (checkArr[i] >= max)
			{
				max = checkArr[i];
				maxi = i;
			}
		}
		b[k] = a[maxi];
		k++;
		checkArr[maxi] = 0;
		max = 0;
		maxi = -1;
	}
	cout << b[0][1] << endl;
	return 0;
}

