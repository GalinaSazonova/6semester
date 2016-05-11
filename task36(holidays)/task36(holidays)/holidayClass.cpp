#include "holidayClass.h"

holidayClass::holidayClass()
{
}


holidayClass::~holidayClass()
{
}

void holidayClass:: addDate(double date, string holiday)
{
	m.insert(make_pair(date, holiday));
}

string holidayClass::findHoliday(double date)
{
	if (m.empty() || m.count(date) == 0)
	{
		return "no such holiday";
	}
	auto k = m.find(date);
	return k->second;
}