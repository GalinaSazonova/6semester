#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int thirdDegree(int n)
{
	return n * n * n;
}

double sumFinder(int n)
{
	double sum = 0;
	while (n >= 0)
	{
		sum += (1.0 / thirdDegree(2 * n + 1));
		n--;
	}
	return sum;
}

int main()
{
	int n = 0;
	cout << "Input n, please"<< endl;
	cin >> n;
	cout << endl;
	cout << "Result = " << sumFinder(n) << endl;
	return 0;
}

