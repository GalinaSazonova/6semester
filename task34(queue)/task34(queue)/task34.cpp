#include "stdio.h"
#include <iostream>
#include <list>

using namespace std;

template <typename T>
class queue
{
private:
	list<T> l;
public:
	queue(){}
	~queue(){}
	void push(T el)
	{
		l.push_back(el);
	}
	T pop()
	{
		if (!l.empty())
		{
			T temp = l.front();
			l.pop_front();
			return temp;
		}
		throw "Queue is empty!";
	}
};

int main()
{
	queue<int> q;
	q.push(3); q.push(7);
	q.push(11);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	return 0;
}