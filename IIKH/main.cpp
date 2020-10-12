
#include <iostream>
#include "greeter.h"
#include "recipe_list.h"
using namespace::std;

int main() {
	Greeter::print_greeting();
	Greeter a;
	RecipeList* recipeDB = RecipeList::get_instance("RecipeDB.txt");
	a.select_main_menu();


	return 0;
}