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
	string read_recipe;// txt���� �� ���پ� �����ϴ� ����
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

//textDB���� parsing �� recipe_list�� �߰�
void RecipeList::add_recipelist(string read_recipe)
{
	stringstream ss(read_recipe);
	string token;
	vector<string> tokens;
	while (getline(ss, token, '@')) {
		tokens.push_back(token);
		//�̸�@ 
		//���#��ᰳ��%...���#��ᰳ��% 
		//�ð�@ 
		//����@
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
		ingrediants.insert(make_pair(ingrediant_data[i], stoi(ingrediant_data[i + 1]))); //maptype���� ���� <string, int>

	/*
	cout << "----------------\n";
	map<string, int>::iterator iter;
	for (iter = ingrediants.begin(); iter != ingrediants.end(); iter++)
	{
		cout << "Key : " << iter->first << "Value : " << iter->second << endl;
	}
	*/

	Recipe recipe(tokens[0], ingrediants, stoi(tokens[2]), tokens[3]); //recipe ��ü����
	this->recipe_list.push_back(recipe);//recipe_list�� �߰�

}



//DB�� recipe_list�� ���ο� recipe ����
void RecipeList::add_recipe() {//�־��� ���Ŀ� �°� �����ǳ���ޱ� (�������̿�)
   //�Է��� ���ʴ�� �޾Ƽ� ����
	ofstream recipeDB;
	recipeDB.open(file_name, ios::app);
	if (recipeDB.is_open()) {
		string new_recipe;
		cout << "���ο� recipe�� �Է��� �ּ���.\n" << "<recipe_name>@<ingrediant_name(�뷮)>#<ingrediant_data>%...@<time>@<description>" << endl;
		getline(std::cin, new_recipe);//�ֿܼ��� ���� �� ������ ����
		add_recipelist(new_recipe);//recipe_list�� �߰�
		recipeDB << new_recipe << endl;//���Ͽ����� ����

		cout << "\n----------------------------\n" << "	success" << "\n----------------------------\n";
		recipe_list.back().print_recipe();
	}
	else cout << "Unable to open file";
	recipeDB.close();
}

//recipe_list���
void RecipeList::show_recipe() {
	for (int i = 0; i < recipe_list.size(); i++)
	{
		cout << "RECIPE ID: " << i << '\n';
		recipe_list[i].print_recipe();//recipe_list�迭�� �ϳ��ϳ��� ��½�����
	}
}

//�˻��ϴ� ���� ���� 
void RecipeList::browse_recipe(string keyword) {
	vector <int> result;//�˻��� ������ ����

	cout << "\n----------------------------\n" << "Searching by recipe's name" << "\n----------------------------\n";
	for (int i = 0; i < recipe_list.size(); i++) {
		if (recipe_list[i].get_name().find(keyword) != string::npos) {//find�Լ� ���� recipe_name�� keyword�ִ��� �˻�
			cout << "RECIPE ID: " << i << '\n';
			recipe_list[i].print_recipe();//keyword����ִ� recipe ���
			result.push_back(i);//result�� �˻��� ������� recipe ��
		}
	}
	cout << "\n----------------------------\n" << "Searching by recipe's ingrediants" << "\n----------------------------\n";
	for (int i = 0; i < recipe_list.size(); i++) {
		map<string, int> temp = recipe_list[i].get_ingredients();
		for (auto iter = temp.begin(); iter != temp.end(); iter++) {//��ῡ keyword�ִ��� �˻�
			if (iter->first.find(keyword) != string::npos) {
				if (find(result.begin(), result.end(), i) == result.end()) { //��ġ�ϴ� ���Ұ� ���� ���
					cout << "RECIPE ID: " << i << '\n';
					recipe_list[i].print_recipe();
					result.push_back(i);
				}
				else { //�̹� �̸����� �˻��Ͽ� ��µ� ���
					cout << "Recipe Name: " << recipe_list[i].get_name() << '\n';
				}
				cout << '\n';
			}
		}
	}
	cout << '\n';
	//�˻��� �������߿� ���õ� ������ �����س���
	if (result.size() == 0) { cout << "SORRY:(" << endl << "There is no recipe for that keyword."; }//�˻��Ȱ� ������
	else {
		int select; //���� vector �� �����Ͽ� �������� �����Ǹ� �����س��� �� �ֵ��� ��� ���� ����
		cout << "Choose recipe ID: ";
		cin >> select;//����ڰ� �Է��� ���� select�� ����
		if (recipe_list.size() < select) {
			cout << "Wrong number" << endl;
			cout << "Choose recipe again :";
			cin >> select;
		}
	}
}

//recipe�� �˻��ѵ� ������ �Լ��� ���� ����
void RecipeList::delete_recipe(int list_num) {
	//recipe_list[list_num]�� ������
	recipe_list.erase(recipe_list.begin() + list_num);

	//RecipeDB.txt ���� ����� ���ο� recipe_list�� �־���
	ofstream recipeDB;
	recipeDB.open("RecipeDB.txt");
	if (recipeDB.is_open())
		for (int i = 0; i < recipe_list.size(); i++)
			recipeDB << recipe_list[i].toString() << endl;
	recipeDB.close();
}