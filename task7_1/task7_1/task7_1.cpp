#include"stdio.h"
#include <iostream>
#include <list>

using namespace std;

int secmax(const list<int>& l)
{
	int max = l.front();
	int secmax = l.front();
	for (auto i : l)
	{
		if (i > max)
		{
			secmax = max;
			max = i;
		}
		if (i > secmax && i < max || (secmax == max))
		{
			secmax = i;
		}
	}
	return secmax;
}

list<int> noCommon(const list<int>& l1, const list<int>& l2)
{
	if (l1.empty())
	{
		return l2;
	}
	if (l2.empty())
	{
		return l1;
	}
	auto f = l1.begin();
	auto s = l2.begin();
	list<int> noCom;
	while (true)
	{
		while (*f < *s)
		{
			noCom.push_back(*f);
			f++;
			if (f == l1.end())
				return noCom;
		}
		while (*f > *s)
		{
			s++;
		}
		if (*f == *s)
		{
			f++;
			s++;
		}
		if (s == l2.end() && f != l1.end())
		{
			while (f != l1.end())
			{
				noCom.push_back(*f);
				f++;
			}
		}
		if (f == l1.end())
		{
			//noCom.push_back(*f);
			break;
		}
	}
	return noCom;
}

bool broken(const list<int>& ml,const list<int>& fp,const list<int>& sp)
{
	auto f = ml.begin();
	auto s = fp.begin();
	list<int> result;
	while (true)
	{
		if (*s == *f)
		{
			f++;
			s++;
		}
		if (s == fp.end())
		{
			while (f != ml.end())
			{
				result.push_back(*f);
				f++;
			}
			break;
		}
		if (f == ml.end() && s != fp.end())
			return false;

		while (*f != *s)
		{
			result.push_back(*f);
			f++;
			if (f == ml.end())
				return false;
		}
	}
	if (result.size() != sp.size())
		return false;
	auto u = result.begin();
	auto e = sp.begin();
	while (u != result.end())
	{
		if (*u != *e)
			return false;
		u++;
		e++;
	}
	return true;
}

bool broken2(const list<int>& ml, const list<int>& fp, const list<int>& sp)
{
	
}

int main()
{
	cout << secmax(list < int > {-2, -5, -6}) << endl;
	list<int> k = noCommon(list < int > {1, 2, 3, 4, 5, 8, 9}, list < int > {4, 5, 7, 8});
	cout << broken(list < int > {1, 3, 1, 2}, list < int > {1, 2}, list < int > {1, 3}) << endl;
	return 0;
}