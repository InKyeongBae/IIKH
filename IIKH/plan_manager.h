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
	vector<Date> plan_list;
	PlanManager() {}
	static PlanManager* instance;
public:
	static PlanManager* get_instance();

	void add_plan(Date date);
	void print_plan_list();
	void print_grocery_list();


	vector<Date>& get_dates() { return plan_list; }


};