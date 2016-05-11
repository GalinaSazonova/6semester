#include "stdio.h"
#include <iostream>
#define pi 3.1415

using namespace std;

class Shape
{
public:
	Shape(double x, double y) : x(x), y(y){};
	Shape(){};
	virtual double area() = 0;
	virtual double perim() = 0;

private:
	double x = 0.0;
	double y = 0.0;
};

class Circle : Shape
{
public:
	Circle(double x, double y, double r) :Shape(x, y), r(r){};
	Circle(double r):Shape(), r(r){};

	double area() override
	{
		return pi * r * r;
	}
	double perim() override
	{
		return 2 * pi * r;
	}

private:
	double r = 1;
};

class Square  : Shape
{
public:
	Square(double x, double y, double half) : Shape(x, y), half(half) {};
	Square(double half) : Shape(), half(half) {};

	double area() override
	{
		return  4 * half * half;
	}

	double perim() override
	{
		return 8 * half;
	}

private:
	double half;
};


int main()
{
	Square sq(4);
	cout << "S = " << sq.area() << endl;
	cout << "P = " << sq.perim() << endl;

	Circle c(12);
	cout << "S = " << c.area() << endl;
	cout << "P = " << c.perim() << endl;
	return 0;
}