#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

class holidayClass
{
private:
	map<double, string> m;
public:
	holidayClass();
	~holidayClass();
	void addDate(double date, string holiday);
	string findHoliday(double date);
};

