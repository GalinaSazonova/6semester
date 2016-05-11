#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <iostream>
#include <vector>


struct MyStruct
{
	int x;
	int y;
	double distanceToO;
};

using namespace std;

int main()
{
	vector<MyStruct> v;
	int a = 0;
	int b = 0;
	double min = 100;
	while (true)
	{
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		double k = a * a * 1.0 + b * b * 1.0;
		if (k < min)
			min = k;
		v.push_back(MyStruct{ a, b, k});
	}
	cout << endl;
	for (auto& i : v)
	{
		if (i.distanceToO == min)
		{
			cout << i.x << " " << i.y << " ";
			cout << endl;
		}
	}
	return 0;
}