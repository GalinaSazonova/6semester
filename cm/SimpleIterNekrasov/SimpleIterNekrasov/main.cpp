#include "stdio.h"
#include <iostream>

#define eps 0.0000001

using namespace std;

int main()
{
	double a[3][4] = { { 668.72, 0.80267, -2.0646, 1.71509 }, { 0.80267, 507.82, 0.48036, -4.484721 }, { -2.0646, 0.48036, 402.93, 0.09906 } };
	cout << "A" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "b" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << a[i][3] << endl;
	}

	double x_k[3] { 0 };
	int count = 0;
	while (true)
	{
		double x_kk[3];
		for (int i = 0; i < 3; i++)
		{
			x_kk[i] = a[i][3];
			for (int j = 0; j < 3; j++)
			{
				if (i != j)
				{
					x_kk[i] -= a[i][j] * x_k[j];
				}
			}
			x_kk[i] /= a[i][i];
		}

		long double error = 0.0;
		for (int i = 0; i < 3; i++)
		{
			error += abs(x_kk[i] - x_k[i]);
		}
		if (error < eps)
			break;
		cout << count << ") ";
		for (int i = 0; i < 3; i++)
		{
			cout << x_kk[i] << " ";
		}
		cout << endl;
		count++;
		for (int i = 0; i < 3; i++)
		{
			x_k[i] = x_kk[i];
		}
	}
	cout << "x = ";
	for (int i = 0; i < 3; i++)
	{
		cout << x_k[i] << " ";
		x_k[i] = 0;
	}
	cout << endl;

	cout << "Nekrasov" << endl;
	count = 0;
	
	while (true)
	{
		double x_kk[3];
		for (int i = 0; i < 3; i++)
		{
			x_kk[i] = a[i][3];
			for (int j = 0; j < 3; j++)
			{
				if (i < j)
				{
					x_kk[i] -= a[i][j] * x_k[j];
				}
				if (i > j)
				{
					x_kk[i] -= a[i][j] * x_kk[j];
				}
			}
			x_kk[i] /= a[i][i];
		}

		long double error = 0.0;
		for (int i = 0; i < 3; i++)
		{
			error += abs(x_kk[i] - x_k[i]);
		}
		if (error < eps)
			break;
		cout << count << ") ";
		for (int i = 0; i < 3; i++)
		{
			cout << x_kk[i] << " ";
		}
		cout << endl;
		count++;
		for (int i = 0; i < 3; i++)
		{
			x_k[i] = x_kk[i];
		}
	}

	cout << "x = ";
	for (int i = 0; i < 3; i++)
	{
		cout << x_k[i] << " ";
	}
	cout << endl;

	return 0;
}