#pragma once
#include <string>
#include <map>
#include "Recipe.h"
#include <vector>

using namespace std;

class RecipeDB {
private:
	vector<Recipe> recipe_list;
	int list_num;//recipe_list[]���� ���°���� �޴� ����

public:
	//������
	RecipeDB();
	//recipe�� ��� �����ִ� �޼ҵ�
	void show_recipe();
	//recipe�� �˻��ϴ� �޼ҵ�
	void browse_recipe(string keyword);
	//recipe add �޼ҵ�
	void add_recipe();
	//recipe�� recipe_list�� �߰����ִ� �޼ҵ�
	void add_recipelist(string recipe_name, map<string, int> ingredients, int time, string description);
	//recipe ���� �޼ҵ�
	void edit_recipe();//�ϴ� ����
	//recipe ���� �޼ҵ�
	void delete_recipe(int list_num);

};