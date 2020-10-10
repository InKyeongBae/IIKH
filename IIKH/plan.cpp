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

void Plan::add_plan(Date& date)
{

	while (true)
	{

		cout << endl;
		cout << "  Daily Plan Menu (" << date.toString() << ")" << endl;
		cout << endl;

		cout << " ##   1. Add to Breakfast   ##" << endl;
		cout << " ##   2. Add to Lunch       ##" << endl;
		cout << " ##   3. Add to Dinner      ##" << endl;
		cout << " ##   4. Set People         ##" << endl;
		cout << " ##   5. Show daily plan    ##" << endl;
		cout << " ##   0. Save & Exit        ##" << endl;

		cout << endl;

		cout << "  Select Operation Number : ";
		int selector;
		cin >> selector;


		int mealType, id;
		string input;
		Recipe recipe(-1);
		switch (selector)
		{
		case 0:
			return;

		case 1: case 2: case 3:
			mealType = selector;

			clrscr();
			cout << endl;
			cout << " Select a recipe that you want to add" << endl;

			id = rui.showRecipeList(false);
			if (id == -1) break;

			clrscr();
			recipe = rdb.get_recipe(id);
			recipe.print_recipe();
			cout << endl;


			switch (mealType)
			{
			case 1:
				date.get_breakfast().add_menu(recipe);
				break;
			case 2:
				date.get_lunch().add_menu(recipe);
				break;
			case 3:
				date.get_dinner().add_menu(recipe);
			}


			cout << endl;
			cout << " Success." << endl;
			cout << " Press Enter to Continue... ";
			//Enter 치는 옵션
			break;

		case 4:
			int breakfastP, lunchP, dinnerP;
			cout << endl;
			cout << " 1) Breakfast People Count : ";
			cin >> breakfastP;
			cout << " 2) Lunch People Count : ";
			cin >> lunchP;
			cout << " 3) Dinner People Count : ";
			cin >> dinnerP;
			date.get_breakfast().set_people(breakfastP);
			date.get_lunch().set_people(lunchP);
			date.get_dinner().set_people(dinnerP);

			cout << endl;
			cout << " Success." << endl;
			cout << " Press Enter to Continue... ";
			//Enter 치는 옵션
			break;

		case 5:
			vector<Date> temp;
			Plan plan;
			temp.push_back(date);
			plan.set_dates(temp);

			clrscr();
			plan.print_plan();
			cout << endl;
			cout << " Press Enter to Continue... ";
			//Enter 치는 옵션
		}
	}
}

void Plan::add_plan_form()
{
	if (rdb.get_recipeslist().empty())
	{
		cout << endl;
		cout << " You don't have any recipes!" << endl;
		cout << endl;
		cout << " Press Enter to Continue... ";
		//enter 누르도록 하는 코드 추가
		return;
	}

	Plan plan;
	vector<Date>& dates = plan.getDates();

	for (int i = 1; ; i++)
	{
		clrscr();
		cout << endl;

		cout << " #####   Add Planner   #####" << endl;

		cout << endl;

		cout << " (Input 0 to print & save a file)" << endl;
		cout << " (Input -1 to quit)" << endl;

		for (int j = 1; j < i; j++) {
			cout << endl;
			cout << endl;
			cout << " [Day " << j << "]" << endl;
			cout << " " << dates[j - 1].toString() << " Saved." << endl;;
		}

		int year, month, day;
		Date date;

		cout << endl;
		cout << endl;
		cout << " [Day " << i << "]" << endl;
		cout << " Date (yyyy mm dd) : ";
		cin >> year;

		if (year == -1)
		{
			return;
		}

		if (year == 0)
		{
			clrscr();
			Plan plan;
			plan.setDates(dates);
			plan.printPlan();
			plan.writePlanToFile("plan.txt");


			cout << endl << endl;
			cout << " Success! Write the plan to \"plan.txt\". Check the file." << endl;
			cout << " Press Enter to Continue... ";
			//Enter 누르게
			break;
		}

		cin >> month >> day;


		if (!date.init(year, month, day))
		{
			cout << endl;
			cout << " Invalid Date! Please write again." << endl;
			cout << " Press Enter to Continue... ";
			//Enter 누르게
			i--;
			continue;
		}

		add_plan(date);
		dates.push_back(date);
	}
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