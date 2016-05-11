#include "stdio.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string s;
	int n;
	int mark;
	map<string, int> m;
	cin >> n;
	while (n != 0)
	{
		n--;
		cin >> s;
		cin >> mark;
		if ((m[s] == 0 || m[s] < mark) && mark > 0 && mark < 6)
			m[s] = mark;
	}
	cout << "Result: " << endl;
	for (auto& i : m)
	{
		if (i.second != 0)
			cout << i.first << " " << i.second << endl;
	}
	return 0;
}