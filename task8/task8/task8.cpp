#include "stdafx.h"
#include <iostream>

using namespace std;

void twice(int* i)
{
	*i = *i * 2;
}

int main()
{
	int i = 5;
	twice(&i);
	cout << i << endl;
	return 0;
}

