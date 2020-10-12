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
		cout << "> Enter edited_recipe name: ";
		getchar();
		getline(cin, recipe_name);
	}
	//sets Recipe time
	void set_time()
	{
		cout << "> Enter edited_recipe time(minute): ";
		cin >> time;
	}
	//sets Recipe description
	void set_description()
	{
		int num;
		cout << "> The number of Recipe description : ";
		cin >> num;
		string des;
		string new_recipe;
		for (int i = 1; i <= num; i++) {
			cout << i << ")";
			string s = std::to_string(i);
			new_recipe.append(s);
			new_recipe.append(". ");
			cin.ignore();
			getline(cin, des);
			new_recipe.append(des);
			if (i != num) {
				new_recipe.append(" / ");
			}
		}

		description = new_recipe;

	}
	//sets Recipe ingrediant
	void add_ingredient()
	{
		string ing_name;
		int ing_size;
		cout << "> Enter New ingredient name. Input like following format-> \"ex)egg(개)\" : ";
		getchar();
		cin >> ing_name;
		cout << "> Enter New ingredient amount (Only Input Integer for amount) : ";
		cin >> ing_size;
		ingredients.insert(make_pair(ing_name, ing_size));
	}
	void edit_ingredient()
	{
		cout << "> Enter ingredient name for edit amount : ";
		string key;
		getchar();
		cin >> key;
		if (ingredients.find(key) == ingredients.end()) {
			cout << "> Enter correct ingredient name : ";
			this->remove_ingredient();
		}
		else {
			cout << "> Enter edited_ingredient amount : ";
			cin >> ingredients.find(key)->second;
		}
	}
	void remove_ingredient()
	{
		cout << "> Enter ingredient name for remove ingredient : ";
		string key;
		getchar();
		cin >> key;
		if (!ingredients.erase(key)) {
			cout << "> Enter correct ingredient name";
			this->remove_ingredient();
		}
	}

	/* Functions */
	void print_recipe();
	string toString();

	//기본생성자
	Recipe();

	//생성자
	Recipe(string recipe_name, map<string, int> ingredients, int time, string description);

};
