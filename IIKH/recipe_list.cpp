#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "recipe.h"
#include "recipe_list.h"

using namespace std;

RecipeDB::RecipeDB() {
	ifstream read("RecipeDB.txt");
	string read_recipe;// txt���� �� ���پ� �����ϴ� ����
	if (read.is_open()) {
		while (!read.eof()) {
			while (getline(read, read_recipe)) {
				//text���Ͽ��� recipe_name �����ؼ� recipe_name�� ����
				int index = read_recipe.find('@');//index=������ ��ġ//�̸��� ������ @�� ����
				string recipe_name = read_recipe.substr(0, index);//0���� index��ŭ�� ���ڿ��� recipe_name�� ����

				//text���Ͽ��� ingredients �����ؼ� ingredients�� ����
				int temp = index + 1;//temp=���� ������ index
				index = read_recipe.find('@', temp);
				string ingredients = read_recipe.substr(temp, index - temp - 1);
				//ingredients += '%';//���������� �����ڸ� �־��༭ ��Ȱ�� �۵��ǵ��� ��

				string ing;
				int num;
				temp = 0; //temp �ʱ�ȭ
				map<string, int> ingredients_map;//�̸�@���#��ᰳ��%...���#��ᰳ��%�ð�@����@
				for (int i = 0; i < ingredients.size(); i++) {
					if (ingredients[i] == '#') {//ingredients��string(���) ������ #�� ����
						ing = ingredients.substr(temp, i - temp);
						temp = i + 1;
					}
					else if (ingredients[i] == '%') {//ingredients��int(��ᰳ��) ������ %�� ����
						num = stoi(ingredients.substr(temp, i - temp));//string�� int�� ��ȯ�Ͽ� num�� ����
						temp = i + 1;
						ingredients_map[ing] = num;
					}
				}
				temp += recipe_name.size() + 1;
				//text���Ͽ��� time �����ؼ� time�� ����
				index = read_recipe.find('@', recipe_name.size() + 1 + ingredients.size() + 1);
				int time = stoi(read_recipe.substr(temp, index - temp));

				//text���Ͽ��� description �����ؼ� description�� ����
				//index = read_recipe.find('@', recipe_name.size() + 1 + ingredients.size() + 1 + time.size() + 1);
				string description = read_recipe.substr(index + 1, read_recipe.size() - index - 2);

				//recipe_list�� �߰�
				add_recipelist(recipe_name, ingredients_map, time, description);
			}
		}
	}
	else std::cout << "Unable to open file";
	read.close();
}


//recipe�� recipe_list�� �߰�
void RecipeDB::add_recipelist(string recipe_name, map<string, int> ingredients, int time, string description) {
	Recipe r = { recipe_name, ingredients, time, description }; //recipe ��ü����
	recipe_list.push_back(r); //recipe_list�� ��ü ����
	//recipe_size++; //�����Ǹ� �ϳ� �߰��ϰ� ���� �迭�� �Ѿ���� ++����
}

//����ڰ� ���ο� �����Ǹ� �ϳ� �߰��Ϸ��� �� ��
void RecipeDB::add_recipe() {//�־��� ���Ŀ� �°� �����ǳ���ޱ� (�������̿�)
   //�Է��� ���ʴ�� �޾Ƽ� ����
	ofstream write("RecipeDB.txt", ios::app);//������ ���Ͽ� ���ٿ�����
	string new_recipe;
	getline(std::cin, new_recipe);//�ֿܼ��� ���� �� ������ ����
	write << new_recipe;//���Ͽ����� ����
}

//recipe_list���
void RecipeDB::show_recipe() {
	for (int i = 0; i < recipe_list.size(); i++)
	{
		recipe_list[i].print_recipe();//recipe_list�迭�� �ϳ��ϳ��� ��½�����
		cout << endl;
	}
}

//�˻��ϴ� ���� ���� 
void RecipeDB::browse_recipe(string keyword) {
	string find; //�Է¹��� ���ڿ�
	string line; //txt���� �� ���پ� �����ϴ� ���ڿ�

	std::cin >> find;

	vector <int> result;//�˻��� ������ ����
	int result_count = 0;//�˻��� ������ ���� �ο��ϱ� ���� ����
	for (int i = 0; i < recipe_list.size(); i++) {

		if (recipe_list[i].get_name().find(keyword) != string::npos) {//find�Լ� ���� recipe_name�� keyword�ִ��� �˻�
			recipe_list[i].print_recipe();//keyword����ִ� recipe ���
			result[result_count] = i;//result[]���� �˻��� �����ǵ鿡�� �����ο�
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

	//�˻��� �������߿� ���õ� ������ �����س���
	if (result_count == 0) { cout << "SORRY:(" << endl << "There is no recipe for that keyword."; }//�˻��Ȱ� ������
	else {
		int select;
		cout << "Choose recipe :";
		cin >> select;//����ڰ� �Է��� ���� select�� ����
		list_num = result[select - 1];//����ڰ� 1���� �����ؼ� �Է��Ѵٰ� ����
	}
}

void RecipeDB::delete_recipe(int list_num) {
	//recipe_list[list_num]�� ������
	recipe_list.erase(recipe_list.begin() + list_num);

	//RecipeDB.txt ���� ����� ���ο� recipe_list�� �־���
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