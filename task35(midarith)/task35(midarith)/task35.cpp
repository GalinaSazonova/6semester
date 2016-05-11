#include "stdio.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>

double average1(T b, T e)
{
	int n = 0;
	//работают оба варианта, и вроде больше некуда
	T::value_type sum = 0;
	//decltype(*b + 0) sum = 0;
	for (T p = b; p != e; p++)
	{
		if (*p > 0)
		{
			sum += *p;
			n++;
		}
	}
	return sum * 1.0 / n;
}

int main()
{
	list<int> l{ 1, 2, -3, 0, 7};
	vector<double> v{ 1, 2, -9, 3, 1.1 };
	cout << average1(l.begin(), l.end()) << endl;
	cout << average1(v.begin(), v.end()) << endl;
	return 0;
}