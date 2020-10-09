#include "plan.h"

void Meal::add_menu(Recipe recipe) {
	menus.push_back(recipe);
}

bool Meal::remove_menu(int id) {
	for (int i = 0; i < menus.size(); i++) {
		if (menus[i].getId() == id) {
			menus.erase(menus.begin() + i);
			return true;
		}
	}
	return false;
}