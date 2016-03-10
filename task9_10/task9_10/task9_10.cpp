#include "stdafx.h"
#include <stdio.h>
#include <iostream>

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
private:
	int *stack;
	int n;
	int check;
	void pushing();
};

myStack::myStack()
{
	n = 100;
	check = 0;
	stack = new int[n];
}

myStack::~myStack()
{
	delete[] stack;
}

void myStack::push(int value)
{
	pushing();
	stack[0] = value;
	check++;
}

void myStack::pushing()
{
	if (check == n)
	{
		n *= 2;
		int *newst = new int[n];
		copy(stack, newst, n);
		stack = newst;
	}
	for (int i = n - 1; i > 0; i--)
	{
		stack[i] = stack[i - 1];
	}
}

int myStack::pop()
{
	check--;
	if (check != -1)
	{
		int temp = stack[0];
		for (int i = 0; i < n; i++)
		{
			stack[i] = stack[i + 1];
		}
		return temp;
	}
	check++;
	return -1000;
}

int& myStack::max()
{
	int max = stack[0];
	int maxi = 0;
	for (int i = 0; i < check; i++)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			maxi = i;
		}
	}
	return stack[maxi];
}

int main()
{
	myStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.max() << endl;
	s.max()++;
	cout << s.max() << endl;
	s.max() = 7;
	cout << s.max() << endl;
	cout << s.pop() << endl;
	cout << s.max() << endl;
	s.max()++;
	cout << s.max() << endl;
	return 0;
}

