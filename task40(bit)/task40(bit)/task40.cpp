#include"stdio.h"
#include <iostream>

using namespace std;

int bit(int n) {
	int count = 0;
	while (n != 0) {
		count++;
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	int n = 5;
	cout << bit(n) << endl;
	return 0;
}