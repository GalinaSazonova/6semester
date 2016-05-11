#include "stdio.h"
#include <iostream>

using namespace std;

int main()
{
	double a;
	cin >> a;
	auto p = (int*)&a;
	for (int i = 0; i < 2; i++)
		cout << p[i] << " ";
	return 0;
}