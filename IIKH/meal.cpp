#include "plan.h"
#include <map>
Meal::Meal(string meal_title, int num_people) {
	this->meal_title = meal_title;
	this->num_people = num_people;
}

void Meal::add_menu(Recipe recipe) {
	//레시피에서 ingredients 인원수 만큼 증가시키기
	menus.push_back(recipe);
}

void Meal::adjust_ingredients(vector<Recipe> menus){
	for (Recipe menu : menus) {
		map<string, int> ingredients = menu.get_ingredients();
		for (auto iter = ingredients.begin(); iter != ingredients.end(); iter++) {
			iter->second *= num_people;
		}
	}
}