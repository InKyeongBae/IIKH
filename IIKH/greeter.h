#pragma once
#include <sstream>
#include "plan.h"
#include "plan_manager.h"
using namespace std;

class Greeter {
private:
	int option_choice = 0;
	string search_keyword = "";
	

public:
	Greeter() {}

	static void print_greeting();
	void select_main_menu();
	void action_option(int option);	
	void show_all_recipe();
	void browse_recipe();
	void add_recipe();
	void show_all_plan();
	void add_plan();

	int get_option_choice() { return option_choice; }
	void set_option_choice(int choice) { option_choice = choice; }
};