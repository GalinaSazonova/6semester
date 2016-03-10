#include "stdafx.h"
#include <iostream>

using namespace std;

void order(int& a, int& b, int& c)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}

int main()
{
	int a = 3, b = 5, c = 1;
	order(a, b, c);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}

