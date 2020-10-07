#include <string>

#include "meal.h"
using namespace std;
class Plan
{
private:
	string plan_name;
	Meal breakfast;
	Meal lunch;
	Meal dinner;
public:
	//getter
	string get_name() { return plan_name; }
	Meal get_breakfast() { return breakfast; }
	Meal get_lunch() { return lunch; }
	Meal get_dinner() { return dinner; }
	//setter
	void set_name(string n) { plan_name = n; }
	void set_breakfast(Meal b) { breakfast = b; }
	void set_lunch(Meal l) { lunch = l; }
	void set_dinner(Meal d) { dinner = d; }
	
	void print();
};