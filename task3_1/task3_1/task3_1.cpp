#include "stdio.h"
#include <iostream>

int nod(int a, int b)
{
	while (b)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int nok(int a, int b)
{
	return (a * b) / nod(a, b);
}

using namespace std;

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	cout << nok(a, b) << endl;
}