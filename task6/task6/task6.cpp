#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int **arrays = new int*[10];
	//int* a[10];
	//int* k = new int[3]{};
	//a[0] = k;
	for (int i = 0; i < 10; i++)
	{
		arrays[i] = new int[i + 1] {};
		arrays[i][i] = 1;
		for (int j = 0; j < i + 1; j++)
			cout << arrays[i][j] << " ";
		cout << endl;

	}
	for (int i = 0; i < 10; i++)
		delete [] arrays[i];
	delete[] arrays;
	return 0;
}

