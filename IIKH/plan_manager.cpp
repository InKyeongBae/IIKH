#include "plan_manager.h"
#include <fstream>

PlanManager* PlanManager::instance = nullptr;

PlanManager* PlanManager::get_instance(string filename) {
	if (instance == nullptr) {
		instance = new PlanManager(filename);
		return instance;
	}
	else {
		return instance;
	}
}


void PlanManager::print_plan_list() {
	string line;
	ifstream plan_data_file(this->file_name);
	streampos begin, end;
	if (plan_data_file.is_open()) {

		begin = plan_data_file.tellg();
		plan_data_file.seekg(0, ios::end);
		end = plan_data_file.tellg();
		
		if (end - begin != 0) {
			plan_data_file.seekg(0);
			while (getline(plan_data_file, line)) {
				cout << line << '\n';
			}
		}
		else {
			cout << "You don't have any plan!" << '\n';
		}
		plan_data_file.close();
	}
	else cout << "Unable to open file";
}


void PlanManager::add_plan(Date date) {
	plan_list.push_back(date);
	

	ofstream plan_data_file(this->file_name, ios::app);
	if (plan_data_file.is_open()) {
		plan_data_file << "Date : " << date.get_year << '-' << date.get_month << '-' << date.get_day << '\n';
		if (date.get_anniversary().length != 0) {
			plan_data_file << "Anniversary Annotation : " << date.get_anniversary << '\n';
		}
		for (Meal meal : date.get_meals) {
			plan_data_file << "Meal Name : " << meal.get_meal_title << '\n';
			for (Recipe menu : meal.get_menus) {
				plan_data_file << "menu : " << menu.get_name << '\n';
			}
		}
		plan_data_file.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void PlanManager::print_grocery_list() {
	for (Date plan : plan_list) {
		for (Meal meal : plan.get_meals) {
			for (Recipe recipe : meal.get_menus) {
				cout << "Menu : " << recipe.get_name <<""
			}
		}
	}
}