#include "stdio.h"
#include <iostream>
//#include <vector>

using namespace std;

class res
{
public:
	//res();
	virtual ~res(){}
	virtual double resistance() = 0;
};

class resistor : public res
{
private:
	double res;
public:
	resistor(double r)
	{
		res = r;
	}
	~resistor()
	{}
	double resistance() override
	{
		return res;
	}
};

class parallel : public res
{
private:
	res* res1;
	res* res2;
public:
	parallel(res* r1, res* r2)
	{
		res1 = r1;
		res2 = r2;
	}
	~parallel()
	{}
	double resistance() override
	{
		return 1.0 / (1.0 / res1->resistance() + 1.0 / res2->resistance());
	}
};

class coherently : public res
{
private:
	res* res1;
	res* res2;
public:
	coherently(res* r1, res* r2)
	{
		res1 = r1;
		res2 = r2;
	}
	~coherently()
	{}
	double resistance() override
	{
		return res1->resistance() + res2->resistance();
	}
};

/*class sh
{
private:
	std::vector<res*> v;
	std::vector<bool> v1;
public:
	sh(){
		v.push_back(new resistor(0));
		v1.push_back(false);
	}
	~sh(){}
	void add(res* r, bool b)
	{
		v.push_back(r);
		v1.push_back(b);
	}

	double totalresistance()
	{
		double s = 0;
		double partS = 0;
		int j = 1;
		while (true)
		{
			if (v1[j])
			{
				partS += 1.0 / v[j]->resistance();
			}
			if (!v1[j] && v1[j - 1])
			{
				partS += 1.0 / v[j]->resistance();
				s += 1.0 / partS;
				partS = 0;
			}
			if (!v1[j] && !v1[j - 1])
				s += v[j]->resistance();
			j++;
			if (j >= v.size())
			{
				break;
			}
				
		}
		if (partS != 0)
			s += 1.0 / partS;
		return s;
	}
};*/

int main()
{
	res* sheme = new parallel(new coherently(new resistor(1), new resistor(2)), new coherently(new resistor(3), new resistor(4)));
	cout << sheme->resistance() << endl;
	return 0;
}