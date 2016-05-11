#include "stdio.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	list<string> list;
	string temp = "";
	int i = 0;
	while (true)
	{
		if (i == s.size())
		{
			list.push_front(temp);
			break;
		}
		if (s[i] == ' ')
		{
			list.push_front(temp);
			temp = "";
			i++;
			continue;
		}
		temp += s[i];
		i++;
	}
	for (auto& i : list)
	{
		cout << i << " ";
	}
	return 0;
}