#pragma once
#include <string>
#include <map>
#include <vector>
#include "recipe.h"
using namespace std;

class Recipe_list {
private:
	vector<Recipe> recipe_list;
public:
	//생성자
	Recipe_list();
	//recipe를 모두 보여주는 메소드
	void show_recipe();
	//recipe를 검색하여 recipe_list에서의 위치 반환
	void browse_recipe(string keyword);
	//recipe add 메소드
	void add_recipe();
	//recipe를 recipe_list에 추가해주는 메소드
	void add_recipelist(string read_recipe);
	//recipe 수정 메소드
	void select_browse_menu();
	void edit_recipe(int select);
	//recipe 삭제 메소드
	void delete_recipe(int list_num);
	void save_recipe();
};