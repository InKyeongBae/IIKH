#include "Recipe.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

//생성자 메소드
Recipe::Recipe(string recipe_name, map<string, int> ingredients, int time, string description) {
	this->recipe_name = recipe_name;
	this->ingredients = ingredients;
	this->time = time;
	this->description = description;
};

//Recipe 출력 메소드
void Recipe::print_recipe() {
	cout << "Recipe Name: " << recipe_name << endl;
	cout << "Ingredients: " << endl;
	for (auto iter = ingredients.begin(); iter != ingredients.end(); iter++) {
		cout << "▶ " << iter->first << " : " << iter->second << endl;
	}
	cout << "Cooking Time(min):" << time << endl;
	cout << "Description:" << description << endl;
	cout << endl;
}



string Recipe::toString()
{
	string recipe = recipe_name + "@";
	for (auto iter = ingredients.begin(); iter != ingredients.end(); iter++) {
		recipe.append(iter->first + "#");
		recipe.append(to_string(iter->second) + "%");
	}
	recipe.append("@");
	recipe.append(to_string(time) + "@");
	recipe.append(description);
	return recipe;
}