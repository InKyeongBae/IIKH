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
	//������
	Recipe_list();
	//recipe�� ��� �����ִ� �޼ҵ�
	void show_recipe();
	//recipe�� �˻��Ͽ� recipe_list������ ��ġ ��ȯ
	void browse_recipe(string keyword);
	//recipe add �޼ҵ�
	void add_recipe();
	//recipe�� recipe_list�� �߰����ִ� �޼ҵ�
	void add_recipelist(string read_recipe);
	//recipe ���� �޼ҵ�
	void select_browse_menu();
	void edit_recipe(int select);
	//recipe ���� �޼ҵ�
	void delete_recipe(int list_num);
	void save_recipe();
};