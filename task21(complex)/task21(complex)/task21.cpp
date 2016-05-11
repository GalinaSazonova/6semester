#include "stdio.h"
#include <iostream>

using namespace std;

class complex {
	double re, im;
public:
	complex(double re_ = 0, double im_ = 0) :
		re(re_), im(im_)
	{}

	friend complex operator+(complex c1, complex c2);
	friend complex operator*(complex c1, complex c2);
	complex& operator+=
		(complex c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}

	complex& operator*= (complex c)
	{		
		complex k = operator*(*this, c);
		re = k.re;
		im = k.im;
		return *this;
	}

	friend void printComplex(complex c);
};

complex operator+(complex c1, complex c2)
{
	return complex(c1.re + c2.re,
		c1.im + c2.im);
}

complex operator*(complex c1, complex c2)
{
	return complex(c1.re * c2.re - c1.im *c2.im, c1.re * c2.im + c1.im * c2.re);
}

void printComplex(complex c)
{
	cout << c.re << " + " << c.im << "i" << endl;
}

int main()
{
	complex x1{ 1, 2 };
	complex c1{ 3, 5 };
	printComplex(x1 + c1);
	c1 += x1;
	printComplex(c1);
	printComplex(x1 * c1);
	x1 *= c1;
	printComplex(x1);
	return 0;
}