#include "stdio.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int a;
	int result = 0;
	while (true)
	{
		cin >> a;
		if (a == 0)
			break;
		v.push_back(a);
		result += a;
	}
	double r = result * 1.0 / v.size();
	for (int k : v)
	{
		if (k > r)
			cout << k << " ";
	}
	cout << endl;
	cout << r << endl;
	return 0;
}