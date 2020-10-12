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
	RecipeList(string file_name);
	static RecipeList* instance;
public:
	//������
	//RecipeList();
	static RecipeList* get_instance(string file_name);
	static RecipeList* get_instance();
	//recipe�� ��� �����ִ� �޼ҵ�
	void show_recipe();
	//recipe�� �˻��Ͽ� recipe_list������ ��ġ ��ȯ
	bool browse_recipe(string keyword);
	//recipe add �޼ҵ�
	void add_recipe();
	//recipe�� recipe_list�� �߰����ִ� �޼ҵ�
	void add_recipelist(string read_recipe);
	//recipe ���� �޼ҵ�
	void edit_recipe(int select);
	//recipe ���� �޼ҵ�
	void delete_recipe(int select);
	void save_recipe();

	vector<Recipe> get_recipe_list() {
		return recipe_list;
	}
};