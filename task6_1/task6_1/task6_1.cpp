#include "stdio.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	string str2("april");
	getline(cin, str);
	int i = 0;
	int pl = 0;
	while (true)
	{
		pl = str.find(str2, pl);
		if (pl == -1)
			break;
		pl += str2.length();
		i++;
	}
	cout << i << endl;
	return 0;
}