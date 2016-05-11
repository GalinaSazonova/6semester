#include "stdio.h"
#include <iostream>

using namespace std;

class abc{
public:
	static int i;
	abc()
	{
		i++;
	}
	~abc(){ i--; };
	static int num()
	{
		return i;
	}
};
int abc::i = 0;

int main()
{
	abc a;
	abc b;
	//b.~abc();
	cout << abc::num() << endl;
	return 0;
}