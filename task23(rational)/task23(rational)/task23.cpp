#include "stdio.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class rational1{
private:
	int numerator;
	int denominator;
public:
	rational1(int num) : denominator(1)
	{
		numerator = num;
	}
	rational1(int num, int den) : rational1(num)
	{
		if (den != 0)
		{
			denominator = den;
		}
	}
	~rational1()
	{
	}
	operator double() const
	{
		return (double)numerator / denominator;
	}
	friend ostream& operator<<(ostream& output, const rational1& r);
};

int NOD(int a, int b)
{
	while (a > 0 && b > 0)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

ostream& operator<<(ostream& output, const rational1& r)
{
	int nod = NOD(r.denominator, r.numerator);
	int a = (r.denominator / nod);
	int b = (r.numerator / nod);
	return output << b << "/" << a;
}



int main()
{
	auto t = rational1(6, 9);
	double k = t;
	cout << k << endl;
	cout << t << endl;
	return 0;
}