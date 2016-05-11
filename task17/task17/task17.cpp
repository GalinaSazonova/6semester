#include "stdafx.h"
#include "stdio.h"
#include <iostream>

using namespace std;

class Rhomb{
protected:
	double x = 0.0;
	double y = 0.0;
	double diag1;
	double diag2;
public:
	Rhomb(double longLength, double shortLength) 
	{
		diag1 = longLength;
		diag2 = shortLength;
	}

	Rhomb(double x, double y, double longLength, double shortLength) :x(x), y(y)
	{
		diag1 = longLength;
		diag2 = shortLength;
	}
	virtual void draw();
};

void Rhomb::draw()
{
	cout << "Rhomb coordinates" << endl;
	cout << "(" << x << "; " << y + diag1 / 2 << ")" << endl;
	cout << "(" << x + diag2 / 2 << "; " << y << ")" << endl;
	cout << "(" << x << "; " << y - diag1 / 2 << ")" << endl;
	cout << "(" << x - diag2 / 2 << "; " << y << ")" << endl;
}

class HighRhomb : public Rhomb
{
private:
	double dist = 0.4;
	double a;
public:

	HighRhomb(double x, double y, double longLength, double shortLength);
	void draw() override;
};

HighRhomb::HighRhomb(double x, double y, double longLength, double shortLength) :Rhomb(x, y, longLength, shortLength)
{
	a = sqrt((diag2 / 2) * (diag2 / 2) + (diag1 / 2) * (diag1 / 2));
}

void HighRhomb::draw()
{
	cout << "Rhomb coordinates" << endl;
	cout << "(" << x << "; " << y + diag1 / 2 << ")" << endl;
	cout << "(" << x + diag2 / 2 << "; " << y << ")" << endl;
	cout << "(" << x << "; " << y - diag1 / 2 << ")" << endl;
	cout << "(" << x - diag2 / 2 << "; " << y << ")" << endl;
	cout << "coordinates" << endl;
	double k = dist;
	while (k <= a)
	{
		cout << "(" << x + (k * a) / (diag2 / 2) << "; " << y + diag1 / 2 - ((k * a) / diag1 / 2) << ") : ";
		cout << "(" << x - diag2 / 2 + (k * a) / (diag2 / 2) << "; " << y - ((k * a) / diag1 / 2) << ")" << endl;
		k += dist;
	}

}

int main()
{
	Rhomb r(7, 5);
	r.draw();
	HighRhomb hr(0, 0, 7, 5);
	hr.draw();
	return 0;
}

