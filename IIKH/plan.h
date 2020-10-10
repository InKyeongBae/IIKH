#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "recipe.h"
using namespace std;




class Plan {
private:
	vector<Date> dates;
	RecipeDB& rdb;

public:
	Plan() {}
	Plan(vector<Date> dates) { this->dates = dates; }
	void set_dates(vector<Date> dates) { this->dates = dates; }
	vector<Date>& get_dates() { return dates; }

	void print_plan();
	void add_plan(Date& date);
	void add_plan_form();
	void writePlanToFile(ostream& file);
	void writePlanToFile(string filename);

};


class PlanDB 
{
public:
	//Constructor
	PlanDB(); 
	//Destructor
	//~PlanDB() { save(); };

};


class Meal {
private:
	string meal_title;
	vector<Recipe> menus;
	int num_people;

public:
	Meal(string meal_title, int num_people);

	void add_menu(Recipe recipe);
	//bool remove_menu(int id);
	
	void print_grocery_list(vector<Recipe> menus);

	vector<Recipe> get_menus() {
		return menus;
	}
	
	string get_meal_title() {
		return meal_title;
	}

	int get_num_people() {
		return num_people;
	}

	void set_title(string meal_title) {
		this->meal_title = meal_title;
	}

	void set_num_people(int num_people) {
		this->num_people = num_people;
	}

};



class Date {
private:
	int year, month, day;
	string anniversary;
	vector<Meal> meals;
	//Meal breakfast, lunch, dinner;

public:
	//bool init(int year, int month, int day);
	Date() {}
	Date(int year, int month, int day, string anniversary = "") {}

	void add_meal(Meal meal);
	void print_grocery_list(vector<Meal> meals);


	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
	string get_anniversary() { return anniversary; }

	vector<Meal> get_meals() { return meals; }

	Meal& get_breakfast() { return breakfast; }
	Meal& get_lunch() { return lunch; }
	Meal& get_dinner() { return dinner; }

	void set_breakfast(Meal breakfast) { this->breakfast = breakfast; }
	void set_lunch(Meal lunch) { this->lunch = lunch; }
	void set_dinner(Meal dinner) { this->dinner = dinner; }


	string to_string();
};


class Ingredient {
private:
	string name;
	int amount;
public:
	string get_name() {
		return name;
	}
	int get_amount() {
		return amount;
	}
	void set_name(string name) {
		this->name = name;
	}
	void set_amount(int amount) {
		this->amount = amount;
	}

	/*
	bool read_file(istream& in) {
		 string token;

		 if (in.peek() == '\n') {
			 in.ignore();
			 return false;
		 }

		 getline(in, name, ';');
		 getline(in, token, ';');
		 amount = stoi(token);

		 return true;
	 }
	bool writeFile(ostream& out) {
		 out << name << ';'
			 << amount << ';';

		 return true;
	 }

	*/
};