#include <string>
#include <set>
#include <map>

#include "recipe.h"
using namespace std;

class Meal
{
private:
	set<string> recipes;
	int num_people;
	map<string, int> ingrediants_list;
public:
	//getter
	set<string> get_recipes() { return recipes; }
	int get_num_people() { return num_people; }
	map<string, int> get_ingrediants_list() { return ingrediants_list; }
	//setter
	void set_reipes(set<string> rs) { recipes = rs; }
	void add_recipe(string& r) { recipes.insert(r); }
	void delete_recipe(string& r) { recipes.erase(r); }

	void set_num_people(int n) { num_people = n; }
	void set_ingrediants_list(); //recipe가 변경되면 자동으로 수행
}