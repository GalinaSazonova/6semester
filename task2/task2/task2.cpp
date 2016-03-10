#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	int k = -1;
	int count = 0;
	double result = 0;
	cout << "Input numbers using enter" << endl;
	while (k != 0)
	{
		cin >> k;
		count++;
		result += k;
	}
	//cout << result << endl;
	//cout << count << endl;
	cout << result / (count - 1) << endl;
	return 0;
}

