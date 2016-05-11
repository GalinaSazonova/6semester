#include "stdio.h"
#include <iostream>

using namespace std;

template<class T>
class my_numeric_limits{
public:
	static T max() { return T(); }
};

template<> class my_numeric_limits < short > { public : static short max(){ return SHRT_MAX; } };
template<> class my_numeric_limits < int > { public: static int max(){ return INT_MAX; } };
template<> class my_numeric_limits < double > { public : static double max(){ return DBL_MAX; }};
int main()
{
	cout << std::hex << std::showbase << my_numeric_limits<short>::max() << endl;
	cout << my_numeric_limits<int>::max() << endl;
	cout << my_numeric_limits<double>::max() << endl;
	return 0;
}