#pragma once
#include <string>
#include <map>
#include <vector>
#include "recipe.h"
using namespace std;

class RecipeList {
private:
	static string file_name;
	vector<Recipe> recipe_list;
	RecipeList(string file_name) {
		this->file_name = file_name;
	}
	static RecipeList* instance;
public:
	//생성자
	static RecipeList* get_instance(string file_name);
	
	//recipe를 모두 보여주는 메소드
	void show_recipe();
	//recipe를 검색하는 메소드
	void browse_recipe(string keyword);
	//recipe add 메소드
	void add_recipe();
	//recipe를 recipe_list에 추가해주는 메소드
	void add_recipelist(string read_recipe);
	//recipe 수정 메소드
	void edit_recipe();//일단 보류
	//recipe 삭제 메소드
	void delete_recipe(int list_num);
	void save_recipe();
};