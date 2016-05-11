#include "stdio.h"
#include <iostream>
#include <complex>
#include <cmath>
#define eps 0.000001

using namespace std;

int main()
{
	const double a[3][3] = { { 1.12, 4.45, 0.38 }, { 4.45, 1.31, 0.56 }, { 0.38, 0.56, 0.56 } };
	double y[3] = { 1, 1, 1 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	double r[3]{0};
	int k = 0;
	bool check = true;
	while (check)
	{
		k++;
		cout << k;
		double y_1[3]{0};
		double r_1[3]{0};
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				y_1[i] += a[i][j] * y[j];
			}
			r_1[i] = y_1[i] / y[i];
			cout << " " << r_1[i];
		}
		cout << endl;
		for (int i = 0; i < 3; i++)
		{
			if (abs(r_1[i] - r[i]) < eps)
				check = !check;
			y[i] = y_1[i];
			r[i] = r_1[i];
		}
	}
	cout << "Answer: " << r[1] << endl;




	cout << "-------------" << endl;
	cout << "Yakoby 1" << endl;
	//double t[3][3]{{0}};
	double c[3][3]{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = a[i][j];
		}
	}
	check = true;
	k = 0;
	while (check)
	{
		k++;
		cout << k << " ";
		double t_1[3][3]{{0}};
		double c_1[3][3]{{0}};
		double m[3][3]{{0}};
		double max = 0;
		int maxi, maxj;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j && fabs(c[i][j]) > fabs(max))
				{
					max = c[i][j];
					maxi = i;
					maxj = j;
				}
			}
		}
		for (int i = 0; i < 3; i++)
			t_1[i][i] = 1;
		double d = sqrt(pow(c[maxi][maxi] - c[maxj][maxj], 2) + 4.0 * pow(c[maxi][maxj], 2));
		t_1[maxi][maxi] = sqrt(0.5 * (1 + (fabs(c[maxi][maxi] - c[maxj][maxj]) / d)));
		t_1[maxj][maxj] = t_1[maxi][maxi];
		
		int sign = 1;
		if (c[maxi][maxj] * (c[maxi][maxi] - c[maxj][maxj]) < 0)
			sign = -1;
		if (c[maxi][maxj] * (c[maxi][maxi] - c[maxj][maxj]) == 0)
			sign = 0;
		t_1[maxj][maxi] = sign * sqrt(0.5 * (1 - fabs(c[maxi][maxi] - c[maxj][maxj]) / d));
		t_1[maxi][maxj] = -t_1[maxj][maxi];
		//cout << "sin phi = " << t_1[maxj][maxi] << endl;
		//t_1[maxi][maxj] = t_1[maxj][maxi];
		//t_1[maxj][maxi] = -t_1[maxj][maxi];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
					m[i][j] += c[i][k] * t_1[k][j];
			}
		}

		t_1[maxi][maxj] = t_1[maxj][maxi];
		t_1[maxj][maxi] = -t_1[maxj][maxi];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
					c_1[i][j] += t_1[i][k] * m[k][j];
			}
		}

		for (int i = 0; i < 3; i++)
		{
			cout << c_1[i][i] << " ";
		}
		cout << endl;
		if (abs(c_1[0][0] - c[0][0]) < eps && abs(c_1[1][1] - c[1][1]) < eps && abs(c_1[2][2] - c[2][2]) < eps)
		//if (k == 3)
			check = !check;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				c[i][j] = c_1[i][j];
			}
		}
		cout << endl;
		cout << "-------C----------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << c[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
	}

	cout << "-----------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}


	cout << endl;

	cout << "-----------------" << endl;
	cout << "Yakoby 2" << endl;

	double q[3][3]{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			q[i][j] = a[i][j];
		}
	}

	check = true;
	k = 0;
	while (check)
	{
		k++;
		cout << k << " ";
		double c_1[3][3]{{0}};
		double max = 0;
		int maxi, maxj;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j && fabs(q[i][j]) > fabs(max))
				{
					max = q[i][j];
					maxi = i;
					maxj = j;
				}
			}
		}
		double d = sqrt(pow(q[maxi][maxi] - q[maxj][maxj], 2) + 4.0 * pow(q[maxi][maxj], 2));
		double cosphi = sqrt(0.5 * (1 + (abs(q[maxi][maxi] - q[maxj][maxj]) / d)));
		
		int sign = 1;
		if (q[maxi][maxj] * (q[maxi][maxi] - q[maxj][maxj]) < 0)
			sign = -1;
		if (q[maxi][maxj] * (q[maxi][maxi] - q[maxj][maxj]) == 0)
			sign = 0;
		double sinphi = sign * sqrt(0.5 * (1 - abs(q[maxi][maxi] - q[maxj][maxj]) / d));
		int sign2 = 1;
		if (q[maxi][maxi] - q[maxj][maxj] < 0)
			sign2 = -1;
		if (q[maxi][maxi] - q[maxj][maxj] == 0)
			sign2 = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != maxi && i != maxj && j != maxi && j != maxj)
				{
					c_1[i][j] = q[i][j];
					c_1[i][maxi] = cosphi * q[i][maxi] + sinphi * q[i][maxj];
					c_1[maxi][i] = c_1[i][maxi];
					c_1[j][maxj] = -sinphi * q[j][maxi] + cosphi * q[j][maxj];
					c_1[maxj][j] = c_1[j][maxj];
				}
			}
		}
		c_1[maxi][maxi] = (q[maxi][maxi] + q[maxj][maxj]) / 2.0 + (sign2 * d) / 2.0;
		c_1[maxj][maxj] = (q[maxi][maxi] + q[maxj][maxj]) / 2.0 - (sign2 * d) / 2.0;
		c_1[maxi][maxj] = 0;
		c_1[maxj][maxi] = 0;

		for (int i = 0; i < 3; i++)
		{
			cout << c_1[i][i] << " ";
		}
		cout << endl;
		if (fabs(c_1[0][0] - q[0][0]) < eps && fabs(c_1[1][1] - q[1][1]) < eps && fabs(c_1[2][2] - q[2][2]) < eps)
		//if (k == 5)
			check = !check;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				q[i][j] = c_1[i][j];
		cout << endl;

		cout << "--------C---------" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << q[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	cout << "--------C---------" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << q[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}