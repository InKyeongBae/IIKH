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
	Plan(string n, Meal b, Meal l, Meal d)
	{
		plan_name = n;
		breakfast = b;
		lunch = l;
		dinner = d;
	}
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

	void date_console() {

		cout << "!!!!! You choose [3] add plan !!!!!" << endl;
		cout << "Please input each value, You must input date format like 'yyyy/mm/dd'" << endl << endl;
		cout << "plan_name : "; string n; cin >> n;
		cout << "date(8-digits_ex. 20201007) : "; string eight_date; cin >> eight_date;
		cout << "meal_time(choose only breakfast/lunch/dinner) : ";

	};
};

class PlanDB 
{
public:
	//Constructor
	PlanDB(); 
	//Destructor
	//~PlanDB() { save(); };

};