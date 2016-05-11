#include "stdio.h"
#include <iostream>

bool compare_ignoring_spaces(const char *s1, const char *s2)
{
	while (true)
	{
		while (*s1 == ' ')
			*s1++;
		while (*s2 == ' ')
			*s2++;
		if (*s1 != *s2)
			return false;
		if (*s2 == '\0' && *s1 == '\0')
			return true;
		s1++;
		s2++;
	}
}

using namespace std;

int main()
{
	char s1[100];
	char s2[100];
	cin.getline(s1, 100);
	cin.getline(s2, 100);
	cout << compare_ignoring_spaces(s1, s2) << endl;
	return 0;
}