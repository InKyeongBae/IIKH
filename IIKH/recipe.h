#pragma once
#include <string>
#include <map>

using namespace std;

class Recipe {
private:
	//Recipe's name
	string recipe_name;
	//Recipe's ingrediendts & amount
	map< string, int> ingredients;
	//Recipe's cooking time
	int time;
	//Recipe's description
	string description;

public:
	/* GET */
	//get Recipe name
	string get_name();
	//get Recipe ingrediendts & amount
	map< string, int> get_ingredients();
	//get Recipe time
	int get_time();
	//get Recipe description
	string get_description();

	/* SET */
	//sets Recipe name
	void set_name(string rn);
	//sets Recipe time
	void set_time(int t);
	//sets Recipe description
	void set_description(string d);

	/* Functions */
	void print_recipe();

	//奄沙持失切
	Recipe();

	//持失切
	Recipe(string recipe_name, map<string, int> ingredients, int time, string description);

};
