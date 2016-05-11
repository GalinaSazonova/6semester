#include"stdio.h"
#include<iostream>
//#include <assert.h>

#define ASSERT(exp) if (exp) {  } else {cout << "Condition is not met" << endl;} 

using namespace std;

int main()
{
	int n = 0;
    ASSERT(n > 3);
	return 0;
}