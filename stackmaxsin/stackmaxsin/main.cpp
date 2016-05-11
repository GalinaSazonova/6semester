#include <stdio.h>
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

void copy(int *a, int *b, int size)
{
	while (size != 0)
	{
		*b = *a;
		b++;
		a++;
		size--;
	}
}

class myStack{
public:
	myStack();
	~myStack();
	void push(int value);
	int pop();
	double maxsin() const;
private:
	int *stack;
	int n;
	int check;
	mutable double maxsinval = 0;
	mutable int index1 = -1;
	mutable int index2 = -1;
	mutable bool canCount = true;
};

myStack::myStack()
{
	n = 2;
	check = 0;
	stack = new int[n];
}

myStack::~myStack()
{
	delete[] stack;
}

void myStack::push(int value)
{
	if (check == n)
	{
		n *= 2;
		int *newst = new int[n];
		copy(stack, newst, n);
		int *p = stack;
		stack = newst;
		delete[] p;
	}
	stack[check] = value;
	check++;
	if (canCount || maxsinval != 0)
	{
		double k = sin(stack[check - 1] * stack[check - 2]);
		if (k > maxsinval)
		{
			maxsinval = k;
			index = check - 2;
		}
	}
}

int myStack::pop()
{
	check--;
	if (check != -1)
	{
		int k = stack[check];
		stack[check] = 0;
		if (index1 == check || index2 == check)
		{
			canCount = false;
		}
		return k;
	}
	check++;
	throw out_of_range("Stack is empty");
}

double myStack::maxsin() const
{
	if (maxsinval == 0 || !canCount)
	{
		canCount = true;
		maxsinval = 0;
		for (int i = 0; i < check; i++)
		{
			for (int j = 0; j < check; j++)
			{
				if (i != j)
				{
					double t = sin(stack[i] * stack[j]);
					if (maxsinval < t)
					{
						maxsinval = t;
						index1 = i;
						index2 = j;
					}
				}
			}
		}
	}
	return maxsinval;
}

int main()
{
	myStack s;
	s.push(1);
	s.push(4);
	s.push(3);
	s.push(2);
	cout << s.maxsin() << endl;
	s.pop();
	cout << s.maxsin() << endl;
	return 0;
}

