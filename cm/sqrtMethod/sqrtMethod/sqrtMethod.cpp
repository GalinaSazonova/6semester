#include "stdafx.h"
#include <iostream>
#include <complex>

using namespace std;
int main()
{
	complex<double> A[4][4] {{1, 1, 2, -3}, { 1, -1, 3, -2 }, { 2, 3, 2, 1 }, {-3, -2, 1, 1}};
	complex<double> U[4][4];
	complex<double> b[4] {3.5229, -2.8244, 6.7534, -12.5798};
	complex<double> x[4], y[4];
	int n = 4;
	complex<double> temp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			U[i][j] = 0;
		}
	cout << "A"<< endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j].real() << " ";
		}
		cout << endl;
	}
	cout << "b" << endl;
	for (int i = 0; i < n; i++)
		cout << b[i].real() << endl;

	for (int i = 0; i < n; i++)
	{
		temp = 0;
		for (int k = 0; k < i; k++)
			temp = temp + U[k][i] * U[k][i];
		U[i][i] = sqrt(A[i][i] - temp);
		for (int j = i; j < n; j++)
		{
			temp = 0;
			for (int k = 0; k < i; k++)
				temp = temp + U[k][i] * U[k][j];
			U[i][j] = (A[i][j] - temp) / U[i][i];
		}
	}
	cout << "S" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << U[i][j].real() << " + " << U[i][j].imag() << "i ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		temp = 0;
		for (int k = 0; k < i; k++)
			temp = temp + U[k][i] * y[k];
		y[i] = (b[i] - temp) / U[i][i];
	}
	cout << "y" << endl;
	for (int i = 0; i < n; i++)
		cout << y[i].real() << " + " << y[i].imag() << "i" << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		temp = 0;
		for (int k = i + 1; k < n; k++)
			temp = temp + U[i][k] * x[k];
		x[i] = (y[i] - temp) / U[i][i];
	}
	cout << "x" << endl;
	for (int i = 0; i < n; i++)
		cout << x[i].real() << endl;
	return 0;
}

