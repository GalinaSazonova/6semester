#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkDigits(vector<int> v, const int n)
{
	return all_of(v.begin(), v.end(), [&](int i){ return i % 10 == n; });
}

int main()
{
	vector<int> v{ 12, 22, 52 };
	cout << checkDigits(v, 2) << endl;
	return 0;
}