#include "stdafx.h"
#include <iostream>

using namespace std;

bool prime(int n)
{
	if (n == 2)
	{
		return true;
	}
	double k = sqrt(n);
	for (int i = 2; i <= k + 1; i++)
	{
		if ((n % i) == 0)
		{
			return false;
		}
	}
	return true;
}

bool almostPrime(int n)
{
	int k = sqrt(n) + 1;
	for (int i = 2; i <= k; i++)
	{
		if ((n % i == 0) && prime(n / i))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//return false;
}

bool isSumOfAlmostPrimes(int n)
{
	for (int i = 2; i < n / 2; i++)
	{
		if (almostPrime(i) && almostPrime(n - i))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	//cout << prime(3);
	//cout << almostPrime(21);
	//cout << isSumOfAlmostPrimes(27);
	int n;
	cout << "Please, enter number to check" << endl;
	cin >> n;
	cout << "Is sum of almost primes: " << isSumOfAlmostPrimes(n) << endl;
	return 0;
}

