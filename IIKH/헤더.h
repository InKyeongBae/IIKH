#pragma once
#include <string>
#include <map>
#include "Recipe.h"
#include <vector>

using namespace std;

class RecipeDB {
private:
	vector<Recipe> recipe_list;
	int list_num;//recipe_list[]에서 몇번째인지 받는 변수

public:
	//생성자
	RecipeDB();
	//recipe를 모두 보여주는 메소드
	void show_recipe();
	//recipe를 검색하는 메소드
	void browse_recipe(string keyword);
	//recipe add 메소드
	void add_recipe();
	//recipe를 recipe_list에 추가해주는 메소드
	void add_recipelist(string recipe_name, map<string, int> ingredients, int time, string description);
	//recipe 수정 메소드
	void edit_recipe();//일단 보류
	//recipe 삭제 메소드
	void delete_recipe(int list_num);

};