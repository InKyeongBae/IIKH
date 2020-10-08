#pragma once
#include <iostream>
#include <string>
#include <set>
#include <map>
#include "recipe.h"
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


class Meal
{
private:
	set<string> recipes;
	int num_people;
	map<string, int> ingrediants_list;
public:
	//getter
	set<string> get_recipes() { return recipes; }
	int get_num_people() { return num_people; }
	map<string, int> get_ingrediants_list() { return ingrediants_list; }
	//setter
	void set_reipes(set<string> rs) { recipes = rs; }
	void add_recipe(string& r) { recipes.insert(r); }
	void delete_recipe(string& r) { recipes.erase(r); }

	void set_num_people(int n) { num_people = n; }
	void set_ingrediants_list(); //recipe가 변경되면 자동으로 수행
};



class Date {

private:
	string full_date;
	string anniversary = "";
	map <string, int> grocery_list;

public:

	void set_date(string d, string a, string g_name, int g_amt);

	string get_full_date() { return full_date; }
	string get_anniversary() { return anniversary; }
	//컴파일 확인용 함수
	void show_date();

	Date(string d, string a, string g_name, int g_amt) {
		full_date = d;
		anniversary = a;
		grocery_list.insert(make_pair(g_name, g_amt));
	};



};
