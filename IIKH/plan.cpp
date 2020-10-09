#include <iostream>
#include <fstream>
#include "plan.h"

void Plan::print_plan()
{
	writePlanToFile(cout);
}

void Plan::writePlanToFile(string filename)
{
	ofstream file;
	file.open(filename);
	writePlanToFile(file);
	file.close();
}

void Plan::writePlanToFile(ostream& file)
{
	vector<Ingredient> shoppingList;
	int dayCnt = 0;

	for (Date d : dates) {
		int btime = 0, ltime = 0, dtime = 0;
		Meal breakfast = d.get_breakfast(), lunch = d.get_lunch(), dinner = d.get_dinner();

		file << "[Day " << (++dayCnt) << "] ";
		file << d.get_year() << '/' << d.get_month() << '/' << d.get_day() << '\n' << '\n';


		file << '\n';
		file << "   Breakfast   " << '\n';
		file << '\n';

		for (Recipe r : breakfast.get_menus()) {
			file << '<' << r.get_recipe_name() << '>' << " (" << r.get_time() << " minutes)\n";
			for (Ingredient i : r.get_ingredients()) {
				file << " - " << i.get_name() << " (" << i.get_amount() * breakfast.get_people() << "g)" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].get_name() == i.get_name()) {
						shoppingList[s].set_amount(shoppingList[s].get_amount() + i.get_amount() * breakfast.get_people());
						inshoppinglist = true;
						break;
					}
				}
				if (!inshoppinglist) {
					i.set_amount(i.get_amount() * breakfast.get_people());
					shoppingList.push_back(i);
				}
			}
			file << "\n";
			btime += r.get_time();
		}
		file << "Total Time : " << btime << " minutes" << "\n\n\n\n\n";



		file << '\n';
		file << "   Lunch   " << '\n';
		file << '\n';

		for (Recipe r : lunch.get_menus()) {
			file << '<' << r.get_recipe_name() << '>' << " (" << r.get_time() << " minutes)\n";
			for (Ingredient i : r.get_ingredients()) {
				file << " - " << i.get_name() << " (" << i.get_amount() * lunch.get_people() << "g)" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].get_name() == i.get_name()) {
						shoppingList[s].set_amount(shoppingList[s].get_amount() + i.get_amount() * lunch.get_people());
						inshoppinglist = true;
						break;
					}
				}
				if (!inshoppinglist) {
					i.set_amount(i.get_amount() * lunch.get_people());
					shoppingList.push_back(i);
				}
			}
			file << "\n";
			ltime += r.get_time();
		}
		file << "Total Time : " << ltime << " minutes" << "\n\n\n\n\n";


		file << '\n';
		file << "   Dinner   " << '\n';
		file << '\n';

		for (Recipe r : dinner.get_menus()) {
			file << '<' << r.get_recipe_name() << '>' << " (" << r.get_time() << " minutes)\n";
			for (Ingredient i : r.get_ingredients()) {
				file << " - " << i.get_name() << " (" << i.get_amount() * dinner.get_people() << "g)" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].get_name() == i.get_name()) {
						shoppingList[s].set_amount(shoppingList[s].get_amount() + i.get_amount() * dinner.get_people());
						inshoppinglist = true;
						break;
					}
				}
				if (!inshoppinglist) {
					i.set_amount(i.get_amount() * dinner.get_people());
					shoppingList.push_back(i);
				}
			}
			file << '\n';
			dtime += r.get_time();
		}
		file << "Total Time : " << dtime << " minutes" << '\n' << '\n';
		file << '\n';
	}
	file << "\n\n";
	file << "###################" << '\n';
	file << '\n';
	file << "   Shopping List   " << '\n';
	file << '\n';
	file << "###################" << "\n\n";
	for (Ingredient i : shoppingList) {
		file << " - " << i.get_name() << " (" << i.get_amount() << "g)\n";
	}
}