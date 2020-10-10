#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include "recipe.h"
#include "recipe_list.h"

using namespace std;

//textDB에서 parsing 후 recipe_list에 추가
void Recipe_list::add_recipelist(string read_recipe)
{
	stringstream ss(read_recipe);
	string token;
	vector<string> tokens;
	while (getline(ss, token, '@')) {
		tokens.push_back(token);
		//이름@ 
		//재료#재료개수%...재료#재료개수% 
		//시간@ 
		//설명@
	}
	//		for (int i = 0; i < tokens.size(); i++)
		//		cout << tokens[i] << '\n';

	stringstream st(tokens[1]);
	string ing_token;
	vector<string> ingrediant_data;
	while (getline(st, token, '%')) {
		stringstream sd(token);
		while (getline(sd, ing_token, '#')) {
			ingrediant_data.push_back(ing_token);
		}
	}
	map<string, int> ingrediants;
	for (int i = 0; i < ingrediant_data.size(); i += 2)
		ingrediants.insert(make_pair(ingrediant_data[i], stoi(ingrediant_data[i + 1]))); //maptype으로 저장 <string, int>

	/*
	cout << "----------------\n";
	map<string, int>::iterator iter;
	for (iter = ingrediants.begin(); iter != ingrediants.end(); iter++)
	{
		cout << "Key : " << iter->first << "Value : " << iter->second << endl;
	}
	*/

	Recipe recipe(tokens[0], ingrediants, stoi(tokens[2]), tokens[3]); //recipe 객체생성
	this->recipe_list.push_back(recipe);//recipe_list에 추가

}

Recipe_list::Recipe_list() {
	ifstream recipeDB;
	recipeDB.open("RecipeDB.txt");
	string read_recipe;// txt읽을 때 한줄씩 저장하는 변수
	if (recipeDB.is_open()) {
		while (!recipeDB.eof()) {
			while (getline(recipeDB, read_recipe)) {
				add_recipelist(read_recipe);
			}
		}
	}
	else cout << "Unable to open file";
	recipeDB.close();
}

//DB와 recipe_list에 새로운 recipe 저장
void Recipe_list::add_recipe() {//주어진 형식에 맞게 레시피내용받기 (구분자이용)
   //입력을 차례대로 받아서 저장

	string new_recipe;
	string r_name, i_name, i_amount, time;
	int num;

	cout << " Recipe name : ";
	cin >> r_name;
	cout << endl;
	cin.ignore(INT_MAX, '\n');
	new_recipe.append(r_name);
	new_recipe.append("@");

	cout << " The number of ingredients used in this recipe : ";
	cin >> num;
	cout << endl;


	for (int i = 0; i < num; i++) {

		cout << " " << i + 1 << ")" << " Ingredient name. Input like following format-> \"ex)egg(개)\" : ";
		cin >> i_name;

		new_recipe.append(i_name);
		new_recipe.append("#");

		cout << "    Ingredient amount (Only Input Integer for amount) : ";
		cin >> i_amount;
		cout << endl;

		new_recipe.append(i_amount);
		new_recipe.append("%");
	}
	new_recipe.append("@");

	cout << " Cooking Time Duration (Only Input Integer for minutes) : ";
	cin >> time;
	cout << endl;
	new_recipe.append(time);
	new_recipe.append("@");


	cout << " Describe \"How to Cook?\"" << endl;
	cout << " The number of Recipe description : ";
	cin >> num;
	string des;
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
	add_recipelist(new_recipe);//recipe_list에 추가

	cout << "\n----------------------------\n" << "   success" << "\n----------------------------\n";
	recipe_list.back().print_recipe();
}



//recipe_list출력
void Recipe_list::show_recipe() {
	for (int i = 0; i < recipe_list.size(); i++)
	{
		cout << "RECIPE ID: " << i << '\n';
		recipe_list[i].print_recipe();//recipe_list배열들 하나하나를 출력시켜줌
	}
}

//검색하는 동작 구현 
void Recipe_list::browse_recipe(string keyword) {
	vector <int> result;//검색된 레시피 저장

	cout << "\n----------------------------\n" << "Searching by recipe's name" << "\n----------------------------\n";
	for (int i = 0; i < recipe_list.size(); i++) {
		if (recipe_list[i].get_name().find(keyword) != string::npos) {//find함수 통해 recipe_name에 keyword있는지 검색
			cout << "RECIPE ID: " << i << '\n';
			recipe_list[i].print_recipe();//keyword들어있는 recipe 출력
			result.push_back(i);//result에 검색된 순서대로 recipe 들어감
		}
	}
	cout << "\n----------------------------\n" << "Searching by recipe's ingrediants" << "\n----------------------------\n";
	for (int i = 0; i < recipe_list.size(); i++) {
		map<string, int> temp = recipe_list[i].get_ingredients();
		for (auto iter = temp.begin(); iter != temp.end(); iter++) {//재료에 keyword있는지 검색
			if (iter->first.find(keyword) != string::npos) {
				if (find(result.begin(), result.end(), i) == result.end()) { //일치하는 원소가 없는 경우
					cout << "RECIPE ID: " << i << '\n';
					recipe_list[i].print_recipe();
					result.push_back(i);
				}
				else { //이미 이름으로 검색하여 출력된 경우
					cout << "Recipe Name: " << recipe_list[i].get_name() << '\n';
				}
				cout << '\n';
			}
		}
	}
	cout << '\n';
	//검색된 레시피중에 선택된 레시피 저장해놓기
	if (result.size() == 0) { cout << "SORRY:(" << endl << "There is no recipe for that keyword."; }//검색된게 없을시
	else {
		select_browse_menu();
	}
}

void Recipe_list::select_browse_menu()
{
	int menu_num;
	cout << "1. Select recipe" << '\n';
	cout << "2. Browose again" << '\n';
	cin >> menu_num;

	int select;
	if (menu_num == 1) {
		cout << "Choose recipe ID: ";
		cin >> select;//사용자가 입력한 숫자 select에 저장
		while (recipe_list.size() < select) {
			cout << "Wrong number" << endl;
			cout << "Choose recipe again :";
			cin >> select;
		}
		// 수정 menu 출력 -> 수정
		system("cls");
		edit_recipe(select);
	}
	else if (menu_num == 2) {
		string keyword;
		cout << "Please write keyword.\n";
		cin >> keyword;
		system("cls");
		browse_recipe(keyword);
	}
	else {
		select_browse_menu();
	}
}

//recipe를 검색한뒤 선택한 함수에 대해 삭제
void Recipe_list::delete_recipe(int list_num) {
	//recipe_list[list_num]을 지워줌
	recipe_list.erase(recipe_list.begin() + list_num);
}

void Recipe_list::edit_recipe(int select)
{
	cout << "1. Set recipe name" << '\n';
	cout << "2. Set recipe time" << '\n';
	cout << "3. add a ingrediant" << '\n';
	cout << "4. remove a ingrediant" << '\n';
	cout << "5. edit a ingrediant" << '\n';
	cout << "6. Set recipe description" << '\n';
	cout << "7. No edit" << '\n' << '\n';

	cout << "Select Option Number : ";
	int option_choice;
	cin >> option_choice;

	cout << "\n\n" << endl;
	switch (option_choice)
	{
	case 1:
		recipe_list[select].set_name();
		break;
	case 2:
		recipe_list[select].set_time();
		break;
	case 3:
		recipe_list[select].add_ingrediant();
		break;
	case 4:
		recipe_list[select].remove_ingrediant();
		break;
	case 5:
		recipe_list[select].edit_ingrediant();
		break;
	case 6:
		recipe_list[select].set_description();
		break;
	case 7:
		break;
	default:
		cout << "Please select right number!";
		system("cls");
		edit_recipe(select);
	}
	if (select != 7) {
		cout << "\n----------------------------\n" << "	success" << "\n----------------------------\n";
		recipe_list[select].print_recipe();
	}
	cout << "\n\n" << "any more edit?[y/n]: " << endl;
	string result;
	cin >> result;
	if (result == "y")
		edit_recipe(select);
	else
		return; //greeter로 가게 합치삼
}

void Recipe_list::save_recipe()
{
	//RecipeDB.txt 내용 지우고 새로운 recipe_list를 넣어줌
	ofstream recipeDB;
	recipeDB.open("RecipeDB.txt");
	if (recipeDB.is_open())
		for (int i = 0; i < recipe_list.size(); i++)
			recipeDB << recipe_list[i].toString() << endl;
	recipeDB.close();
}