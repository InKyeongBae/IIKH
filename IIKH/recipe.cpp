#include "recipe.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

/* GET */
//get Recipe name
string Recipe::get_name() { return recipe_name; }
//get Recipe ingrediendts & amount
map< string, int>Recipe::get_ingredients() { return ingredients; }
//get Recipe time
int Recipe::get_time() { return time; }
//get Recipe description
string Recipe::get_description() { return description; }

/* SET */
//sets Recipe name
void Recipe::set_name(string rn) { recipe_name = rn; }
//sets Recipe time
void Recipe::set_time(int t) { time = t; }
//sets Recipe description
void Recipe::set_description(string d) { description = d; }

//Recipe 출력 메소드
void Recipe::print_recipe() {
	cout << "Recipe Name:" << recipe_name << endl;
	cout << "Ingredients:" << endl;
	for (auto iter = ingredients.begin(); iter != ingredients.end(); iter++) {
		cout << iter->first << ' ' << iter->second << endl;
	}
	cout << "Cooking Time(min):" << time << endl;
	cout << "Description:" << description << endl;
	cout << endl;
}

//생성자 메소드
Recipe::Recipe(string recipe_name, map<string, int> ingredients, int time, string description) {
	this->recipe_name = recipe_name;
	this->ingredients = ingredients;
	this->time = time;
	this->description = description;
};