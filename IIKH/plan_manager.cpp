#include "plan_manager.h"
#include <algorithm>
#include <map>

using namespace std;

PlanManager* PlanManager::instance = nullptr;

PlanManager* PlanManager::get_instance() {
	if (instance == nullptr) {
		instance = new PlanManager();
		return instance;
	}
	else {
		return instance;
	}
}


void PlanManager::print_plan_list() {
	if (plan_list.empty()) {
		cout << "You don't have any plan!" << '\n';
	}

	else {
		for (int i = 0; i < plan_list.size(); i++) {
			cout << "< PLAN " << i + 1 << ">" << '\n' << '\n';
			Date date = plan_list.at(i);
			cout << "¢º Date : " << date.get_year() << '-' << date.get_month() << '-' << date.get_day() << '\n';
			cout << "¢º Anniversary Annotation : " << date.get_anniversary() << '\n';
			for (int j = 0; j < date.get_meals().size(); j++) {
				Meal meal = date.get_meals().at(j);
				cout << "¢º Meal Title: " << meal.get_meal_title() << '\n';
				for (int k = 0; k < meal.get_menus().size(); k++) {
					Recipe menu = meal.get_menus().at(k);
					cout << "menu : " << k + 1 << menu.get_name() << '\n';
				}
				cout << '\n';
			}
			cout << '\n' << '\n';
		}
	}
}


void PlanManager::add_plan(Date date) {
	plan_list.push_back(date);
}

void PlanManager::print_grocery_list() {
	//map<string, int> temp;
	//map<string, int>::iterator it;
	for (Date plan : plan_list) {
		cout << "Date : " << plan.get_year() << '-' << plan.get_month() << '-' << plan.get_day()<<'\n';
		for (Meal meal : plan.get_meals()) {
			cout << "Having meal with " << meal.get_num_people() << " people" << '\n';
			for (Recipe recipe : meal.get_menus()) {
				cout << "Menu : " << recipe.get_name() << '\n';
				cout << "Grocery List : " << '\n';
				for (auto iter = recipe.get_ingredients().begin(); iter != recipe.get_ingredients().end(); iter++) {
					//it = find(iter, recipe.get_ingredients().end(),iter->first);
					cout << "¢º " << iter->first << " : " << iter->second * meal.get_num_people() << endl;
				}
			}
		}
		cout << '\n' << '\n';
	}
}