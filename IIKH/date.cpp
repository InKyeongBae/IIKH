#include "plan.h";

bool Date::init(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
	return true;
}


string Date::toString() {
	string dateStr = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
	return dateStr;
}