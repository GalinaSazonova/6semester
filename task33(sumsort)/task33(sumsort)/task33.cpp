#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int numsum(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum = sum + (n % 10);
		n /= 10;
	}
	return sum;
}

void mysort(vector<int>& v, int n)
{
	int deg = pow(10, n);
	sort(v.begin(), v.end(), [n, deg](int i, int j){ return i % deg < j % deg; });
}

int main()
{
	vector<int> v;
	multimap<int, int> m;
	int t;
	while (true)
	{
		cin >> t;
		if (t == 0)
			break;
		v.push_back(t);
		m.insert(make_pair(numsum(t), t));
	}
	sort(v.begin(), v.end(), [](int i, int j) { return numsum(i) < numsum(j); });
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	mysort(v, 2);
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	auto p = m.begin();
	while (p != m.end())
	{
		cout << p->second << " ";
		p++;
	}
	cout << endl;

	return 0;
}