#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "plan.h"
using namespace std;

class PlanManager {
private:
	static string file_name;
	vector<Date> plan_list;
	PlanManager(string file_name) {
		this->file_name = file_name;
	}
	static PlanManager* instance;
public:
	static PlanManager* get_instance(string file_name);

	//PlanManager(vector<Date> plan_list) { this->plan_list = plan_list; }

	void add_plan(Date date);
	void print_plan_list();
	void print_grocery_list();


	vector<Date>& get_dates() { return plan_list; }

	void add_plan(Date& date);
	void add_plan_form();
	void writePlanToFile(ostream& file);
	void writePlanToFile(string filename);

};