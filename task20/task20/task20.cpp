#include "stdio.h"
#include <iostream>
#include <string>

using namespace std;

void firstLastSpace(string s, int& i1, int& i2)
{
	int k = 0;
	while (s[k] != '\0')
	{
		if (s[k] == ' ' && i1 == -1)
		{
			i1 = k;
		}
		if (s[k] == ' ')
		{
			i2 = k;
			k++;
			continue;
		}
		k++;
	}
}

int main()
{
	int i1 = -1;
	int i2 = -1;
	string s;
	getline(cin, s);
	firstLastSpace(s, i1, i2);
	cout << i1 << " " << i2 << endl;
	return 0;
}