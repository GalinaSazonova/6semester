#include "stdio.h"
#include <iostream>

using namespace std;
template <typename T>

void swp(T &x1, T &x2)
{
	T temp = x1;
	x1 = x2;
	x2 = temp;
}

int main()
{
	double a = 1.1, b = 2.2;
	swp(a, b);
	cout << a << " " << b << endl;
	return 0;
}