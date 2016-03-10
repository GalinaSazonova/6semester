#include "stdio.h"
#include <iostream>

using namespace std;

bool compare(const char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		if (*s2 == '\0')
			return false;
		if (*s1 != *s2)
			return false;
		s1++;
		s2++;
	}
	return true;
}

int main()
{
	char s1[100];
	char s2[100];
	cin.getline(s1, 100);
	cin.getline(s2, 100);
	cout << compare(s1, s2) << endl;
	return 0;
}