#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "plan.h"

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

void Date::add_meal(Meal meal) {
	meals.push_back(meal);
}

