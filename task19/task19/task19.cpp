#include "stdio.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class time {
private:
	int hour = 12;
	int min = 0;
public:
	~time()
	{}

	time(int h, int m)
	{
		if (h > 24 || h < 0)
		{
			throw exception("Wrong format of hours!");
		}
		if (m > 59 || m < 0)
		{
			throw exception("Wrong format of minutes!");
		}

		hour = h;
		min = m;
	}

	bool operator<(time second)
	{
		if (this->hour < second.hour || (this->hour == second.hour && this->min < second.min))
			return true;
		return false;
	}
};


int main()
{
	try
	{
		time t(25, 1);
	}
	catch (exception &exc)
	{
		cout << exc.what() << endl;
	}
	time n1(10, 20);
	time n2(12, 21);
	cout << (n1 < n2) << endl;
	return 0;
}