#include "stdio.h"
#include <iostream>

struct MyStruct
{
	int value;
	int amount;
};

int nod(int a, int b)
{
	while (b)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

using namespace std;

bool isPartitionable(const int *a, int n)
{
	MyStruct *arr = new MyStruct[n];
	int k = -1;
	while (n != 0)
	{
		if (arr[k].value != *a)
		{
			k++;
			arr[k] = MyStruct{ *a, 1 };
			a++;
			n--;
			continue;
		}
		if (arr[k].value == *a)
		{
			arr[k].amount++;
			a++;
			n--;
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (nod(arr[i].amount, arr[i + 1].amount) == 1)
		{
			return false;
		}
	}
	return true;
}



int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int k = n;
	while (k != 0)
	{
		cin >> a[k - 1];
		k--;
	}
	cout << isPartitionable(a, n) << endl;
	return 0;
}