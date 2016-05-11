#include "stdio.h"
#include <iostream>
#include <functional>
#include <cmath>

double a = 0;
int N = 100;

using namespace std;

double f(double x)
{
	return x * x * x;
}

double integral(function<double(double)> F, double b) 
{
	double h = (b - a) / N;
	double I = 0;
	for (int k = 1; k <= N; k++) {
		I += F(a + (k - 0.5) *h);
	}
	return I*h;
}

int main()
{
	cout << integral(f, 2) << endl;
	cout << integral([](double x){ return sin(x); }, 3.14) << endl;
	return 0;
}