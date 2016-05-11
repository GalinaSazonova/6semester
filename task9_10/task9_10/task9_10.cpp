#include "stdafx.h"
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
	int& max();
	double maxsin() const;
private:
	int *stack;
	int n;
	int check;
	int maxElInd;
	mutable double maxsinval = 0;
	mutable int index = -1;
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
		delete [] p;
	}
	if (check == 0 || maxElInd < value)
		maxElInd = check;
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
		if (check == maxElInd)
		{
			maxElInd = 0;
			for (int i = 0; i < check; i++)
			{
				if (stack[i] > stack[maxElInd])
				{
					maxElInd = i;
				}
			}
		}
		if (index == check || index + 1 == check)
		{
			canCount = false;
			//maxsinval = 0;
		}			
		return k;
	}
	check++;
	//return -1000;
	throw out_of_range("Stack is empty");
}

double myStack::maxsin() const
{
	if (maxsinval == 0 || !canCount)
	{
		canCount = true;
		maxsinval = 0;
		for (int i = 0; i < check - 1; i++)
		{
			double t = sin(stack[i] * stack[i + 1]);
			if (maxsinval < t)
			{
				maxsinval = t;
				index = i;
			}
		}
	}
	return maxsinval;
}

int& myStack::max()
{
	canCount = false;
	return stack[maxElInd];
}

void f(myStack& s)
{
	int* p = new int[1000];
	try{
		cout << s.pop();
	}
	catch (const out_of_range& ex)
	{
		cout << ex.what();
		delete[] p;
	}
	delete[] p;
}

int main()
{
	myStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.maxsin() << endl;
	s.pop();
	cout << s.maxsin() << endl;
	return 0;
}

