#include "plan.h"

Meal::Meal(string meal_title, int num_people) {
	this->meal_title = meal_title;
	this->num_people = num_people;
}

void Meal::add_menu(Recipe recipe) {
	//레시피에서 ingredients 인원수 만큼 증가시키기
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