#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "recipe.h"
#include "recipe_list.h"

using namespace std;

RecipeDB::RecipeDB() {
	ifstream read("RecipeDB.txt");
	string read_recipe;// txt읽을 때 한줄씩 저장하는 변수
	if (read.is_open()) {
		while (!read.eof()) {
			while (getline(read, read_recipe)) {
				//text파일에서 recipe_name 구분해서 recipe_name에 저장
				int index = read_recipe.find('@');//index=구분자 위치//이름의 구분자 @로 설정
				string recipe_name = read_recipe.substr(0, index);//0부터 index만큼의 문자열을 recipe_name에 저장

				//text파일에서 ingredients 구분해서 ingredients에 저장
				int temp = index + 1;//temp=갱신 이전의 index
				index = read_recipe.find('@', temp);
				string ingredients = read_recipe.substr(temp, index - temp - 1);
				//ingredients += '%';//마지막에도 구분자를 넣어줘서 원활히 작동되도록 함

				string ing;
				int num;
				temp = 0; //temp 초기화
				map<string, int> ingredients_map;//이름@재료#재료개수%...재료#재료개수%시간@설명@
				for (int i = 0; i < ingredients.size(); i++) {
					if (ingredients[i] == '#') {//ingredients의string(재료) 구분자 #로 설정
						ing = ingredients.substr(temp, i - temp);
						temp = i + 1;
					}
					else if (ingredients[i] == '%') {//ingredients의int(재료개수) 구분자 %로 설정
						num = stoi(ingredients.substr(temp, i - temp));//string을 int로 변환하여 num에 넣음
						temp = i + 1;
						ingredients_map[ing] = num;
					}
				}
				temp += recipe_name.size() + 1;
				//text파일에서 time 구분해서 time에 저장
				index = read_recipe.find('@', recipe_name.size() + 1 + ingredients.size() + 1);
				int time = stoi(read_recipe.substr(temp, index - temp));

				//text파일에서 description 구분해서 description에 저장
				//index = read_recipe.find('@', recipe_name.size() + 1 + ingredients.size() + 1 + time.size() + 1);
				string description = read_recipe.substr(index + 1, read_recipe.size() - index - 2);

				//recipe_list에 추가
				add_recipelist(recipe_name, ingredients_map, time, description);
			}
		}
	}
	else std::cout << "Unable to open file";
	read.close();
}


//recipe를 recipe_list에 추가
void RecipeDB::add_recipelist(string recipe_name, map<string, int> ingredients, int time, string description) {
	Recipe r = { recipe_name, ingredients, time, description }; //recipe 객체생성
	recipe_list.push_back(r); //recipe_list에 객체 대입
	//recipe_size++; //레시피를 하나 추가하고 다음 배열로 넘어가려고 ++해줌
}

//사용자가 새로운 레시피를 하나 추가하려고 할 때
void RecipeDB::add_recipe() {//주어진 형식에 맞게 레시피내용받기 (구분자이용)
   //입력을 차례대로 받아서 저장
	ofstream write("RecipeDB.txt", ios::app);//기존의 파일에 덧붙여쓰기
	string new_recipe;
	getline(std::cin, new_recipe);//콘솔에서 받은 것 변수에 저장
	write << new_recipe;//파일에까지 저장
}

//recipe_list출력
void RecipeDB::show_recipe() {
	for (int i = 0; i < recipe_list.size(); i++)
	{
		recipe_list[i].print_recipe();//recipe_list배열들 하나하나를 출력시켜줌
		cout << endl;
	}
}

//검색하는 동작 구현 
void RecipeDB::browse_recipe(string keyword) {
	string find; //입력받을 문자열
	string line; //txt읽을 때 한줄씩 저장하는 문자열

	std::cin >> find;

	vector <int> result;//검색된 레시피 저장
	int result_count = 0;//검색된 레시피 순서 부여하기 위한 변수
	for (int i = 0; i < recipe_list.size(); i++) {

		if (recipe_list[i].get_name().find(keyword) != string::npos) {//find함수 통해 recipe_name에 keyword있는지 검색
			recipe_list[i].print_recipe();//keyword들어있는 recipe 출력
			result[result_count] = i;//result[]통해 검색된 레시피들에게 순서부여
			result_count++;
		}
		else
			for (auto iter = recipe_list[i].get_ingredients().begin(); iter != recipe_list[i].get_ingredients().end(); iter++) {
				if (iter->first.find(keyword) != string::npos) {
					recipe_list[i].print_recipe();
					result[result_count] = i;
					result_count++;
				}
			}
	}

	//검색된 레시피중에 선택된 레시피 저장해놓기
	if (result_count == 0) { cout << "SORRY:(" << endl << "There is no recipe for that keyword."; }//검색된게 없을시
	else {
		int select;
		cout << "Choose recipe :";
		cin >> select;//사용자가 입력한 숫자 select에 저장
		list_num = result[select - 1];//사용자가 1부터 선택해서 입력한다고 가정
	}
}

void RecipeDB::delete_recipe(int list_num) {
	//recipe_list[list_num]을 지워줌
	recipe_list.erase(recipe_list.begin() + list_num);

	//RecipeDB.txt 내용 지우고 새로운 recipe_list를 넣어줌
	ofstream rewrite("RecipeDB.txt");
	while (!rewrite.eof()) {
		for (int i = 0; i < recipe_list.size(); i++) {
			rewrite << recipe_list[i].get_name(); rewrite << '@';
			for (auto iter = recipe_list[i].get_ingredients().begin();
				iter != recipe_list[i].get_ingredients().end(); iter++) {
				rewrite << iter->first << '#' << iter->second << '%';
			}
			rewrite << recipe_list[i].get_time(); rewrite << '@';
			rewrite << recipe_list[i].get_description(); rewrite << '@';
		}
	}
	rewrite.close();
}