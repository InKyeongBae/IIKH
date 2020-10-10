#pragma once
#include <iostream>
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
	const string& get_name() const { return recipe_name; }
	//get Recipe ingrediendts & amount
	map< string, int>& get_ingredients() { return ingredients; }
	//get Recipe time
	int get_time() const { return time; }
	//get Recipe description
	string get_description() const { return description; }

	/*edit recipe*/
	//sets Recipe name
	void set_name()
	{
		cout << "Enter recipe name: " << endl;
		getchar();
		getline(cin, recipe_name);
	}
	//sets Recipe time
	void set_time()
	{
		cout << "Enter recipe time(minute): " << endl;
		cin >> time;
	}
	//sets Recipe description
	void set_description()
	{
		cout << "Enter recipe description: " << endl;
		getchar();
		getline(cin, description);
	}
	//sets Recipe ingrediant
	void add_ingrediant()
	{
		string ing_name;
		int ing_size;
		cout << "Enter ingrediant name: " << endl;
		getchar();
		cin >> ing_name;
		cout << "Enter ingrediant amount: " << endl;
		cin >> ing_size;
		ingredients.insert(make_pair(ing_name, ing_size));
	}
	void edit_ingrediant()
	{
		cout << "Enter ingrediant name: " << endl;
		string key;
		getchar();
		cin >> key;
		if (ingredients.find(key) == ingredients.end()) {
			cout << "Enter correct ingrediant name" << endl;
			this->remove_ingrediant();
		}
		else {
			cout << "Enter ingrediant amount: " << endl;
			cin >> ingredients.find(key)->second;
		}
	}
	void remove_ingrediant()
	{
		cout << "Enter ingrediant name: " << endl;
		string key;
		getchar();
		cin >> key;
		if (!ingredients.erase(key)) {
			cout << "Enter correct ingrediant name" << endl;
			this->remove_ingrediant();
		}
	}


	/* Functions */
	void print_recipe();
	string toString();

	//奄沙持失切
	Recipe();

	//持失切
	Recipe(string recipe_name, map<string, int> ingredients, int time, string description);

};
