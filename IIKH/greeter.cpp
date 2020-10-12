#include "greeter.h"
#include "recipe_list.h"
#include "plan.h"
#include "plan_manager.h"
#include <Windows.h>

void Greeter::print_greeting() {

	cout << "                                                                                                                          " << "\n";
	cout << "000   00000  0000 00000000 0000     000000000   000000000   00000     00000  00000000    " << "\n";   Sleep(200);
	cout << "0000  00000  000  000      0000    0000       00000    0000 000000   000000  000           " << "\n";   Sleep(200);
	cout << " 000 000 0000000  0000000  0000    000        0000      000 0000000 0000000  0000000        " << "\n";    Sleep(200);
	cout << "  000000 000000   000      0000    0000        000     0000 0000 0000000000  000              " << "\n";      Sleep(200);
	cout << "  00000   0000    00000000 00000000  00000000    00000000   0000  0000 0000  00000000       " << "\n\n";      Sleep(200);
	cout << "\n\n      0000000000  00000000\n"; Sleep(200);
	cout << "         0000   0000     000\n"; Sleep(200);
	cout << "         0000   000      0000\n"; Sleep(200);
	cout << "         0000   0000    0000 \n"; Sleep(200);
	cout << "         0000     000000000\n\n\n"; Sleep(200);
	cout << "00000    00000    00000      0000000 000000        00000\n"; Sleep(200);
	cout << "00000    00000    00000    0000000   000000        00000\n"; Sleep(200);
	cout << "00000    00000    00000  0000000     000000        00000\n"; Sleep(200);
	cout << "00000    00000    000000000000       000000        00000\n"; Sleep(200);
	cout << "00000    00000    0000000000         0000000000000000000\n"; Sleep(200);
	cout << "00000    00000    00000 00000        0000000000000000000 \n"; Sleep(200);
	cout << "00000    00000    00000   00000      000000        00000\n"; Sleep(200);
	cout << "00000    00000    00000    000000    000000        00000\n"; Sleep(200);
	cout << "00000    00000    00000      000000  000000        00000 \n\n\n"; Sleep(500);

}

void Greeter::print_exit() {
	cout << "Thanks to use our IIKH Program!\nThis program is made by OOP class01 Team 2\n";
}


void Greeter::show_all_recipe() {
	cout << "\n[       List of All Recipes       ]" << "\n";
	RecipeList::get_instance()->show_recipe();
}

void Greeter::save_recipe() {
	RecipeList::get_instance()->save_recipe();
}

bool Greeter::browse_recipe() {
	string search_keyword;
	cout << "\n> Enter keywords to search for (ex. salmon, lemon) :";
	std::cin >> search_keyword;
	return RecipeList::get_instance()->browse_recipe(search_keyword);

}

void Greeter::add_recipe() {
	cout << "\n[       Add New Recipe       ]" << "\n";
	RecipeList::get_instance()->add_recipe();
}

bool Greeter::show_all_plan() {
	cout << "\n\n[       List of Plan       ]" << "\n";
	// Plan list에 있는 모든 plan 출력
	return PlanManager::get_instance()->print_plan_list();

}


void Greeter::add_plan() {
	string plan_date = "";
	string anniversary = "";
	vector<string> date;

	string temp;

	int num_meal = 1;
	int num_menu = 1;
	string meal_title = "";
	int num_people = 1;


	string search_keyword = "";
	int recipe_id;

	cout << " Let's make plan" << "\n";
	cout << "> Enter date of plan (ex. 2020-04-26) : ";
	cin >> plan_date;
	stringstream ss(plan_date);
	cout << "> Write anniversary annotation : ";

	cin.ignore();
	getline(cin, anniversary);



	while (getline(ss, temp, '-')) {
		date.push_back(temp);
	}

	Date plan(stoi(date.at(0)), stoi(date.at(1)), stoi(date.at(2)), anniversary);

	cout << "\n> Enter the number how many meals you want to plan : ";
	cin >> num_meal;
	for (int i = 0; i < num_meal; i++) {
		int n = i + 1;
		cout << "\n================================================================\n\n";
		cout << " " << n << " ) Enter the title of Meal : ";
		cin >> meal_title;
		cout << "   " << " -> How many people do you eat with? : ";
		cin >> num_people;
		Meal meal(meal_title, num_people);

		cout << "   " << " -> Enter the number how many menus you want to plan : ";
		cin >> num_menu;
		show_all_recipe();
		for (int j = 0; j < num_menu; j++) {
			int k = j + 1;

			cout << "-> Let's select menu by choose ID of menu_" << k << " : ";
			cin >> recipe_id;
			meal.add_menu(RecipeList::get_instance()->get_recipe_list().at(recipe_id));

		}
		plan.add_meal(meal);

	}
	PlanManager::get_instance()->add_plan(plan);
}

void Greeter::print_grocery_list() {
	PlanManager::get_instance()->print_grocery_list();
}

void Greeter::select_main_menu() {

	cout << "-------- Main Menu --------\n";
	cout << "| 1. Show All Recipe      |" << "\n";
	cout << "| 2. Browse Recipe        |" << "\n";
	cout << "| 3. Add Recipe           |" << "\n";
	cout << "| 4. Show All Plan        |" << "\n";
	cout << "| 5. Add Plan             |" << "\n";
	cout << "| 6. Print Grocery_List   |" << "\n";
	cout << "| 7. Exit Program         |" << "\n";
	cout << "---------------------------\n";

	cout << "> Select Option Number : ";
	cin >> option_choice;
	action_option(option_choice);

}





void Greeter::action_option(int option_choice) {

	///Action Show_Recipe
	if (option_choice == 1) {
		show_all_recipe();
		cout << "\n";
		while (true) {
			cout << "------ Option  Menu ------" << "\n";
			cout << "| 1. Return Main Menu    |" << "\n";
			cout << "--------------------------\n";
			cout << "> Select Option Number : ";
			cin >> option_choice;
			if (option_choice == 1) {
				system("cls");
				select_main_menu();
			}
			else {
				cout << "You have to input \"1\" to continue\n\n";
			}
		}


	}

	//Action Browse_Recipe
	else if (option_choice == 2) {
		bool flag = browse_recipe();
		int select;

		if (flag) {
			cout << "\n------ Option  Menu ------" << "\n";
			cout << "| 1. More Browsing       |" << "\n";
			cout << "| 2. Edit recipe         |\n";
			cout << "| 3. Return Main Menu    |" << "\n";
			cout << "--------------------------\n";
			cout << "> Select Option Number : ";

			cin >> option_choice;
			while (true) {
				if (option_choice == 1) {
					action_option(2);
				}
				else if (option_choice == 3) {
					system("cls");
					select_main_menu();
				}
				else if (option_choice == 2) {
					cout << "> Choose Recipe ID: ";
					cin >> select;//사용자가 입력한 숫자 select에 저장
					while (RecipeList::get_instance()->get_recipe_list().size() < select) {
						cout << "Wrong number" << endl;
						cout << "> Choose Recipe ID again :";
						cin >> select;
					}
					// 수정 menu 출력 -> 수정
					cout << "\n\n";
					RecipeList::get_instance()->edit_recipe(select);
					select_main_menu();
				}
				else {
					cout << "You have to input \"1\" or \"2\" or \"3\" to continue \n\n";
				}
			}
		}
		else {
			while (true) {
				cout << "\n------ Option  Menu ------" << "\n";
				cout << "| 1. Return Main Menu    |" << "\n";
				cout << "--------------------------\n";
				cout << "> Select Option Number : ";
				cin >> option_choice;
				if (option_choice == 1) {
					system("cls");
					select_main_menu();
				}
				else {
					cout << "You have to input \"1\" to continue\n\n";
				}
			}
		}





	}

	//Action Add_Recipe
	else if (option_choice == 3) {

		add_recipe();

		while (true) {
			cout << "------ Option  Menu ------" << "\n";
			cout << "| 1. Return Main Menu    |" << "\n";
			cout << "--------------------------\n";
			cout << "> Select Option Number : ";
			cin >> option_choice;
			if (option_choice == 1) {
				system("cls");
				select_main_menu();
			}
			else {
				cout << "You have to input \"1\" to continue\n\n";
			}
		}

	}

	//Action Show_Plan
	else if (option_choice == 4) {

		cout << "\n" << "\n";

		bool t = show_all_plan();
		if (t) {
			cout << "------ Option  Menu ------" << "\n";
			cout << "| 1. Print the plan list |" << "\n";
			cout << "| 2. Return Main Menu    |" << "\n";
			cout << "--------------------------\n";

			cout << "> Select Option Number : ";
			cin >> option_choice;

			if (option_choice == 1) {
				PlanManager::get_instance()->print_grocery_list();
			}
			else if (option_choice == 2) {
				system("cls");
				select_main_menu();
			}
			else {
				cout << "You have entered an invalid number. Restart!" << "\n";
				select_main_menu();
			}
		}
		else {
			while (true) {
				cout << "------ Option  Menu ------" << "\n";
				cout << "| 1. Return Main Menu    |" << "\n";
				cout << "--------------------------\n";
				cout << "> Select Option Number : ";
				cin >> option_choice;
				if (option_choice == 1) {
					system("cls");
					select_main_menu();
				}
				else {
					cout << "You have to input \"1\" to continue\n\n";
				}
			}
		}

	}


	//Action Add_Plan
	else if (option_choice == 5) {
		// 애드 플랜 메소드 호출
		add_plan();

		cout << "\n\n------ Option  Menu ------" << "\n";
		cout << "| 1. Add another plan    |" << "\n";
		cout << "| 2. Return Main Menu    |" << "\n";
		cout << "--------------------------\n";
		cout << "> Select Option Number : ";
		cin >> option_choice;

		if (option_choice == 1) {
			system("cls");
			action_option(5);
		}
		else if (option_choice == 2) {
			system("cls");
			select_main_menu();
		}
		else {
			cout << "You have entered an invalid number. Restart!" << "\n";
			select_main_menu();
		}

	}

	else if (option_choice == 6) {
		PlanManager::get_instance()->print_grocery_list();
	}

	else if (option_choice == 7) {
		save_recipe();
		print_exit();
		exit(0);
	}

	else {
		cout << "You have entered an invalid number. Please re-enter." << "\n";
		select_main_menu();
	}

}