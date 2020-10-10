/*
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

#include "database.h"
#include "recipe.h"
#include "plan.h"
#include "greeter.h"

int main() {
	PlanDB planDB;
	RecipeDB recipeDB;
	std::vector<std::string> menu;
	Greeter greeter(menu, recipeDB, planDB);
	

	while (true)
	{
		// clear screen
		system("CLS");
		greeter.printMenu();
		greeter.selectMenu();

		// waits for user to continue
		system("pause");

	}
	return 0;

}
*/

#include <iostream>
#include "greeter.h"
#include "recipe_list.h"
using namespace::std;

int main() {
	Greeter::print_greeting();
	Greeter a;
	RecipeList* recipeDB = RecipeList::get_instance("RecipeDB.txt");
	a.select_main_menu();
	recipeDB->save_recipe();

	
	return 0;
}