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
	std::vector<Date> dates;

public:
	Plan() {}
	Plan(std::vector<Date> dates) { this->dates = dates; }
	void set_dates(std::vector<Date> dates) { this->dates = dates; }
	std::vector<Date>& get_dates() { return dates; }

	void print_plan();
	void writePlanToFile(std::ostream& file);
	void writePlanToFile(std::string filename);

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
	int year, month, day;
	Meal breakfast, lunch, dinner;

public:
	bool init(int year, int month, int day);
	void set_breakfast(Meal breakfast) { this->breakfast = breakfast; }
	void set_lunch(Meal lunch) { this->lunch = lunch; }
	void set_dinner(Meal dinner) { this->dinner = dinner; }
	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
	Meal& get_breakfast() { return breakfast; }
	Meal& get_lunch() { return lunch; }
	Meal& get_dinner() { return dinner; }
	std::string to_string();
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