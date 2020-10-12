#pragma once
#include <sstream>
#include "plan.h"
#include "plan_manager.h"
using namespace std;

class Greeter {
private:
	int option_choice = 0;


public:
	Greeter() {}

	static void print_greeting();
	void select_main_menu();
	void action_option(int option);
	void print_exit();
	void show_all_recipe();
	bool browse_recipe();
	void add_recipe();
	bool show_all_plan();
	void add_plan();
	void print_grocery_list();
	void save_recipe();
	int get_option_choice() { return option_choice; }
	void set_option_choice(int choice) { option_choice = choice; }
};