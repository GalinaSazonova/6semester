#include "stdio.h"
#include <iostream>
#include <vector>
#include <memory>
#define pi 3.1415

using namespace std;

class Shape
{
public:
	Shape(double x, double y) : x(x), y(y){}
	Shape(){}
	virtual double area() = 0;
	virtual double perim() = 0;
	virtual bool contains(double x1, double y1) = 0;

//private:
	double x = 0.0;
	double y = 0.0;
};

class Circle : public Shape
{
public:
	Circle(double x, double y, double r) :Shape(x, y), r(r){}
	Circle(double r) :Shape(), r(r){}

	double area() override
	{
		return pi * r * r;
	}
	double perim() override
	{
		return 2 * pi * r;
	}
	bool contains(double x1, double y1) override
	{
		return sqrt(pow(x - x1, 2) + pow(y - y1, 2)) <= r;
	}
private:
	double r = 1;
};

class Square : public Shape
{
public:
	Square(double x, double y, double half) : Shape(x, y), half(half) {}
	Square(double half) : Shape(), half(half) {}

	double area() override
	{
		return  4 * half * half;
	}

	double perim() override
	{
		return 8 * half;
	}

	bool contains(double x1, double y1) override
	{
		return x1 <= x + half && x1 >= x - half && y1 <= y + half && y1 >= y - half;
	}

private:
	double half;
};

class shapeCollection
{
private:
	vector<unique_ptr<Shape>> s;

public:
	shapeCollection()
	{}
	void add(unique_ptr<Shape> el)
	{
		s.push_back(el);
	}
	double area()
	{
		double sum = 0;
		for (auto& i : s)
		{
			sum += i->area();
		}
		return sum;
	}
	double perim()
	{
		double sum = 0;
		for (auto& i : s)
		{
			sum += i->perim();
		}
		return sum;
	}
	bool contains(double x1, double y1)
	{
		bool t = false;
		for (auto& i : s)
		{
			if (i->contains(x1, y1))
			{
				t = true;
				break;
			}	
		}
		return t;
	}
	//shapeCollection& operator=(const shapeCollection sh) = delete;
	//shapeCollection(const shapeCollection& from) = delete;
};

int main()
{
	shapeCollection col;
	col.add(unique_ptr<Square>(new Square(1)));
	col.add(unique_ptr<Circle>(new Circle(1)));
	cout << col.area() << endl;
	cout << col.perim() << endl;
	Circle c(-2, 1, 1);
	cout << c.contains(-2, 0.5) << endl;
	Square s(-2, 1, 1);
	cout << s.contains(-2.5, 1) << endl;
	cout << col.contains(0.5, 0.5) << endl;
	return 0;
}