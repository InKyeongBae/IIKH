#include <ctime>
#include "plan.h";

Date::Date() {
	time_t now = time(NULL);
	struct tm* now_time = localtime(&now);

	this->year = now_time->tm_year + 1900;
	this->month = now_time->tm_mon + 1;
	this->day = now_time->tm_mday;
	this->anniversary = "";
}


Date::Date(int year, int month, int day, string anniversary) {
	this->year = year;
	this->month = month;
	this->day = day;
	this->anniversary = anniversary;
}

/*bool Date::init(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
	return true;
}*/

void Date::add_meal(Meal meal) {
	meals.push_back(meal);
}

string Date::toString() {
	string dateStr = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
	return dateStr;
}