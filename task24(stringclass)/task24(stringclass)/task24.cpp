#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <iostream>

//using namespace std;

class string{
	char* p;
	int len;
public:
	string(const char* s = "")
	{
		len = strlen(s);
		p = new char[len + 1];
		strcpy(p, s);
	}

	~string()
	{
		delete[] p;
	}

	string& operator=(
		const string& from)
	{
		if (this != &from) {
			len = from.len;
			delete[] p;
			p = new char[len + 1];
			strcpy(p, from.p);
		}
		return *this;
	}
	string(const string& from) :
		len(from.len)
	{
		p = new char[len + 1];
		strcpy(p, from.p);
	}
	string& operator+=(string s)
	{
		auto temp = *this;
		delete[] p;
		p = new char[s.len + temp.len + 1];
		strcpy(p, temp.p);
		strcat(p, s.p);
		len = strlen(p);
		return *this;
	}
	void print()
	{
		std::cout << this->p << std::endl;
	}
	friend void swp(string &x1, string &x2);
};

void swp(string &x1, string &x2)
{
	auto u = x1.p;
	x1.p = x2.p;
	x2.p = u;
	auto i = x1.len;
	x1.len = x2.len;
	x2.len = i;
}

int main()
{
	string s1("abc"), s2("klm");
	s1 += s2;
	s1.print();
	swp(s1, s2);
	s1.print();
	s2.print();
	return 0;
}