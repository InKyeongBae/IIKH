#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include "recipe.h"
#include "recipe_list.h"

using namespace std;

RecipeList::RecipeList(string file_name) {
	ifstream recipeDB;
	recipeDB.open(file_name);
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

RecipeList* RecipeList::instance = nullptr;

RecipeList* RecipeList::get_instance(string filename) {
	if (instance == nullptr) {
		instance = new RecipeList(filename);
		return instance;
	}
	else {
		return instance;
	}
}

//textDB에서 parsing 후 recipe_list에 추가
void RecipeList::add_recipelist(string read_recipe)
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



//DB와 recipe_list에 새로운 recipe 저장
void RecipeList::add_recipe() {//주어진 형식에 맞게 레시피내용받기 (구분자이용)
   //입력을 차례대로 받아서 저장
	ofstream recipeDB;
	recipeDB.open(file_name, ios::app);
	if (recipeDB.is_open()) {
		string new_recipe;
		cout << "새로운 recipe를 입력해 주세요.\n" << "<recipe_name>@<ingrediant_name(용량)>#<ingrediant_data>%...@<time>@<description>" << endl;
		getline(std::cin, new_recipe);//콘솔에서 받은 것 변수에 저장
		add_recipelist(new_recipe);//recipe_list에 추가
		recipeDB << new_recipe << endl;//파일에까지 저장

		cout << "\n----------------------------\n" << "	success" << "\n----------------------------\n";
		recipe_list.back().print_recipe();
	}
	else cout << "Unable to open file";
	recipeDB.close();
}

//recipe_list출력
void RecipeList::show_recipe() {
	for (int i = 0; i < recipe_list.size(); i++)
	{
		cout << "RECIPE ID: " << i << '\n';
		recipe_list[i].print_recipe();//recipe_list배열들 하나하나를 출력시켜줌
	}
}

//검색하는 동작 구현 
void RecipeList::browse_recipe(string keyword) {
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
		int select; //차후 vector 로 변경하여 여러가지 레시피를 저장해놓을 수 있도록 기능 구현 가능
		cout << "Choose recipe ID: ";
		cin >> select;//사용자가 입력한 숫자 select에 저장
		if (recipe_list.size() < select) {
			cout << "Wrong number" << endl;
			cout << "Choose recipe again :";
			cin >> select;
		}
	}
}

//recipe를 검색한뒤 선택한 함수에 대해 삭제
void RecipeList::delete_recipe(int list_num) {
	//recipe_list[list_num]을 지워줌
	recipe_list.erase(recipe_list.begin() + list_num);

	//RecipeDB.txt 내용 지우고 새로운 recipe_list를 넣어줌
	ofstream recipeDB;
	recipeDB.open("RecipeDB.txt");
	if (recipeDB.is_open())
		for (int i = 0; i < recipe_list.size(); i++)
			recipeDB << recipe_list[i].toString() << endl;
	recipeDB.close();
}