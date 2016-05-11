#include "stdio.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>

void print(const vector<T>& v)
{
	for (auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	for (auto p = v.begin(); p != v.end();)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
}

int main()
{
	vector<int> v{ 1, 2, 3 };
	print(v);
	return 0;
}