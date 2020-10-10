#include "greeter.h"


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

void Greeter::show_all_recipe() {
	cout << "---------- List of Recipe ----------" << '\n';
	// recipeDB에 있는 모든 recipe 출력하는 함수 소환
}

void Greeter::browse_recipe() {
	cout << "Enter keywords to search for (ex. salmon, lemon) :";
	cin >> search_keyword;
	// recipe 객체 하나 생성해서 객체.browse_recipe(search_keyword);
	cout << '\n' << '\n';

	cout << "---------- Option ----------" << '\n';
	cout << "1. More browsing" << '\n';
	cout << "2. Return Main Menu" << '\n' << '\n';

	cout << "Select Option Number : ";
	cin >> option_choice;

	if (option_choice == 1) {
		action_option(2);
	}
	else if (option_choice == 2) {
		select_main_menu();
	}
}

void Greeter::add_recipe() {

}

void Greeter::show_all_plan() {
	cout << "---------- List of Plan ----------" << '\n';
	// Plan list에 있는 모든 plan 출력
	PlanManager::get_instance("plan_data_")->print_plan_list();
}

void Greeter::action_option(int option_choice){
	
	//Action Show_Recipe
	if (option_choice == 1) {
		show_all_recipe();
	}

	//Action Browse_Recipe
	else if (option_choice == 2) {
		browse_recipe();	
	}

	//Action Add_Recipe
	else if (option_choice == 3) {
		// 레시피 에드하는 메소드 호출, 필요한 인자 입력 받는거는 언니들한테 코드 받고나서 확인 고

	}

	else if (option_choice == 4) {
		
	}

	else if (option_choice == 5) {
		// 애드 플랜 메소드 호출
		string plan_date = "";
		string anniversary = "";
		vector<string> date;
		stringstream ss(plan_date);
		string temp;

		cout << "Let's make plan" << '\n';
		cout << "Enter date of plan (ex. 2020-04-26) : ";
		cin >> plan_date;


		if (plan_date.length == 0) {
			Date one_plan();
			
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

	else {
		cout << "You have entered an invalid number. Please re-enter." << '\n';
		select_main_menu();
	}


}