#include "stdio.h"
#include <iostream>
#include "holidayClass.h"
#include <string>

using namespace std;

int main()
{
	holidayClass h;
	h.addDate(1.01, "New Year");
	h.addDate(9.05, "Victory Day");
	h.addDate(8.03, "Women's Day");
	h.addDate(7.01, "Christmas");
	cout << h.findHoliday(1.01) << endl;
	cout << h.findHoliday(2.04) << endl;
	cout << h.findHoliday(8.03) << endl;
	return 0;
}