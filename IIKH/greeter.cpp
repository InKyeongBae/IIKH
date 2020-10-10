#include "greeter.h"
#include "recipe_list.h"
#include "plan.h"
#include "plan_manager.h"

void Greeter::print_greeting() { 
	cout << "                                                                                                                          00000    00000    00000      0000000 000000        00000 " << '\n' ;
	cout << "                                                                                                                          00000    00000    00000    0000000   000000        00000 " << '\n' ;      
	cout << "                                                                                                                          00000    00000    00000  0000000     000000        00000 " << '\n' ;      
	cout << "                                                                                                                          00000    00000    000000000000       000000        00000 " << '\n' ;      
	cout << "000   00000  0000 00000000 0000     000000000   000000000   00000     00000  00000000      0000000000  00000000           00000    00000    0000000000         0000000000000000000 " << '\n' ;      
	cout << "0000  00000  000  000      0000    0000       00000    0000 000000   000000  000              0000   0000     000         00000    00000    00000 00000        0000000000000000000 " << '\n' ;      
	cout << " 000 000 0000000  0000000  0000    000        0000      000 0000000 0000000  0000000          0000   000      0000        00000    00000    00000   00000      000000        00000 " << '\n' ;      
	cout << "  000000 000000   000      0000    0000        000     0000 0000 0000000000  000              0000   0000    0000         00000    00000    00000    000000    000000        00000 " << '\n' ;      
	cout << "  00000   0000    00000000 00000000  00000000    00000000   0000  0000 0000  00000000         0000     000000000          00000    00000    00000      000000  000000        00000 " << '\n' ;      
       
}



void Greeter::show_all_recipe() {
	cout << "---------- List of Recipe ----------" << '\n';
	RecipeList::get_instance("RecipeDB.txt")->show_recipe();
}

void Greeter::browse_recipe() {
	string search_keyword;
	cout << "Enter keywords to search for (ex. salmon, lemon) :";
	cin >> search_keyword;
	RecipeList::get_instance("RecipeDB.txt")->browse_recipe(search_keyword);
	
}

void Greeter::add_recipe() {

}

void Greeter::show_all_plan() {
	cout << "---------- List of Plan ----------" << '\n';
	// Plan list에 있는 모든 plan 출력
	PlanManager::get_instance("PlanDB.txt")->print_plan_list();

}


void Greeter::add_plan() {
	string plan_date = "";
	string anniversary = "";
	vector<string> date;
	stringstream ss(plan_date);
	string temp;

	int num_meal = 1;
	int num_menu = 1;
	string meal_title = "";
	int num_people = 1;


	string search_keyword = "";
	int recipe_id;

	cout << "Let's make plan" << '\n';
	cout << "Enter date of plan (ex. 2020-04-26) : ";
	cin >> plan_date;


	if (plan_date.length == 0) {
		Date one_plan;
		cout << "Enter the number how many meals you want to plan : ";
		cin >> num_meal;
		for (int i = 0; i < num_meal; i++) {
			cout << "Enter the title of Meal : ";
			cin >> meal_title;
			cout << "How many people do you eat with? : ";
			cin >> num_people;
			Meal meal(meal_title, num_people);

			cout << "Enter the number how many menus you want to plan : ";
			cin >> num_menu;
			show_all_recipe();
			for (int j = 0; j < num_menu; j++) {
				cout << "Let's select menu by choose ID of recipe : ";
				cin >> recipe_id;
				meal.add_menu(RecipeList::get_instance("RecipeDB.txt")->get_recipe_list().at(recipe_id));
			}
			one_plan.add_meal(meal);
		}
		
		
		
		cout << "---------- Option ----------" << '\n';
		cout << "1. Add Menu for " << meal_title << '\n';
		cout << "2. Add Meal" << '\n';
		cout << "3. Return to Main Menu" << '\n';

		cout << "Select Option Number : ";
		cin >> option_choice;
	

	}

	else {
		cout << "Write anniversary annotation : ";
		cin >> anniversary;
		while (getline(ss, temp, '-')) {
			date.push_back(temp);
		}
		Date plan(stoi(date.at(0)), stoi(date.at(1)), stoi(date.at(2)), anniversary);
		
	}
}

void Greeter::add_meal() {
	cout << "Enter the title of Meal : ";
	cin >> meal_title;
	cout << "How many people do you eat with? : ";
	cin >> num_people;
	Meal meal(meal_title, num_people);

	show_all_recipe();
	cout << "Let's select menu by choose ID of recipe : ";
	cin >> recipe_id;
	meal.add_menu(RecipeList::get_instance("RecipeDB.txt")->get_recipe_list().at(recipe_id));
}


void Greeter::select_main_menu() {
	cout << "1. Show All Recipe" << '\n';
	cout << "2. Browse Recipe" << '\n';
	cout << "3. Add Recipe" << '\n';
	cout << "4. Show All Plan" << '\n';
	cout << "5. Add Plan" << '\n' << '\n';

	cout << "Select Option Number : ";
	cin >> option_choice;
	action_option(option_choice);

}





void Greeter::action_option(int option_choice){
	
	//Action Show_Recipe
	if (option_choice == 1) {
		show_all_recipe();
		cout << '\n' << '\n';
		cout << "---------- Option ----------" << '\n';
		cout << "1. Return Main Menu" << '\n' << '\n';

		cout << "Select Option Number : ";
		cin >> option_choice;
		if (option_choice == 1) {
			select_main_menu();
		}

	}

	//Action Browse_Recipe
	else if (option_choice == 2) {
		browse_recipe();	
		cout << '\n' << '\n';
		cout << "---------- Option ----------" << '\n';
		cout << "1. More browsing" << '\n';
		cout << "2. Return to Main Menu" << '\n' << '\n';

		cout << "Select Option Number : ";
		cin >> option_choice;

		if (option_choice == 1) {
			action_option(2);
		}
		else if (option_choice == 2) {
			select_main_menu();
		}
	}

	//Action Add_Recipe
	else if (option_choice == 3) {
		// 레시피 에드하는 메소드 호출, 필요한 인자 입력 받는거는 언니들한테 코드 받고나서 확인 고
		add_recipe();
	}

	//Action Show_Plan
	else if (option_choice == 4) {
		show_all_plan();
		cout << '\n' << '\n';
		cout << "---------- Option ----------" << '\n';
		cout << "1. Print the plan list" << '\n';
		cout << "2. Return Main Menu" << '\n' << '\n';

		cout << "Select Option Number : ";
		cin >> option_choice;

		if (option_choice == 1) {
			cout << "Printed. Chek out the printer!!" << '\n';
			exit;
		}
		else if (option_choice == 2) {
			select_main_menu();
		}
	}


	//Action Add_Plan
	else if (option_choice == 5) {
		// 애드 플랜 메소드 호출
		add_plan();
	}

	else {
		cout << "You have entered an invalid number. Please re-enter." << '\n';
		select_main_menu();
	}


}