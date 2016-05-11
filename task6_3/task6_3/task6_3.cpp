#include "stdio.h"
#include <iostream>
#include <time.h>

using namespace std;
class timeInFunc
{
private:
	time_t t;
public:
	timeInFunc()
	{
		t = time(0);
		cout << "Function started" << endl;
	}
	~timeInFunc()
	{
		t -= time(0);
		cout << "Function finished " << -t << endl;
	}
};

void func()
{
	timeInFunc t;
	int i = 0;
	while (i < 10000000)
	{
		double k = sqrt(i);
		i++;
	}
}

int main()
{
	func();
	return 0;
}