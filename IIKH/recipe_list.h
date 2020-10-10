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
	//������
	static RecipeList* get_instance(string file_name);
	
	//recipe�� ��� �����ִ� �޼ҵ�
	void show_recipe();
	//recipe�� �˻��ϴ� �޼ҵ�
	void browse_recipe(string keyword);
	//recipe add �޼ҵ�
	void add_recipe();
	//recipe�� recipe_list�� �߰����ִ� �޼ҵ�
	void add_recipelist(string read_recipe);
	//recipe ���� �޼ҵ�
	void edit_recipe();//�ϴ� ����
	//recipe ���� �޼ҵ�
	void delete_recipe(int list_num);
	void save_recipe();
};