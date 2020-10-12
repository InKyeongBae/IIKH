#include "plan_manager.h"
#include <algorithm>
#include <map>
#include <Windows.h>
using namespace std;

PlanManager* PlanManager::instance = nullptr;

PlanManager* PlanManager::get_instance() {
    if (instance == nullptr) {
        instance = new PlanManager();
        return instance;
    }
    else {
        return instance;
    }
}


bool PlanManager::print_plan_list() {
    if (plan_list.empty()) {
        cout << "You don't have any plan!" << '\n';
        return false;
    }

    else {
        for (int i = 0; i < plan_list.size(); i++) {
            cout << "< PLAN " << i + 1 << ">" << '\n' << '\n';
            Date date = plan_list.at(i);
            cout << "�� Date : " << date.get_year() << '-' << date.get_month() << '-' << date.get_day() << '\n';
            cout << "�� Anniversary Annotation : " << date.get_anniversary() << '\n';
            for (int j = 0; j < date.get_meals().size(); j++) {
                Meal meal = date.get_meals().at(j);
                cout << "�� Meal Title: " << meal.get_meal_title() << '\n';
                for (int k = 0; k < meal.get_menus().size(); k++) {
                    Recipe menu = meal.get_menus().at(k);
                    cout << k + 1 << " menu : " << menu.get_name() << '\n';
                }
                cout << '\n';
            }
            cout << '\n' << '\n';
        }
        return true;
    }
}


void PlanManager::add_plan(Date date) {
    plan_list.push_back(date);
}


//��plan��(��¥����) grocery list ���
void PlanManager::print_grocery_list() {
    system("cls");
    cout << "====== ( Loading Grocery List. Wait a minute! ) ======\n";
    Sleep(1000);
    if (plan_list.empty()) {
        cout << "\nThere is No Plan\n\n";
    }
    else {
        for (Date plan : plan_list) { //�� ��¥�� plan �ҷ�����
            map<string, int> grocery_list;

            //��¥ ���
            cout << "\n========== Date : " << plan.get_year() << '-' << plan.get_month() << '-' << plan.get_day() << " ==========\n";

            /*recipe * �ο� ��: �� �Ļ��� ��� ��� ���� >> merge_ingredients(map<string,int> &grocery_list, Recipe recipe, int n)�Լ� ���� */
            for (Meal meal : plan.get_meals()) { // ��plan�� meal �ҷ�����
                cout << "      <" << meal.get_meal_title() << ">\n"; //meal title ���
                cout << "�� Having meal with " << meal.get_num_people() << " people\n"; //�� meal�� �ο��� ���

                for (Recipe recipe : meal.get_menus()) {
                    merge_ingredients(grocery_list, recipe, meal.get_num_people());
                    cout << "�� Menu : " << recipe.get_name() << '\n'; // �ش� �Ļ翡 ���Ե� recipe ���
                }
                cout << "--------------------------------------------------\n";
            }
            //�ش� plan�� grocery_list ���
            cout << "\n\n====== Grocery list ======\n";
            map<string, int>::iterator iter;
            for (iter = grocery_list.begin(); iter != grocery_list.end(); iter++) {
                cout << iter->first << ": " << iter->second << "\n";
            }
            cout << '\n' << endl;
        }
    }


}

void PlanManager::merge_ingredients(map<string, int>& grocery_list, Recipe recipe, int n)
{
    /*�����ڷ� ���� grocery list�� ���ڷ� ���� recipe�� ��Ḧ �ջ�
    - �ջ�: ����� amount * �ο����� ���Ѵ�.
    - find
    */

    map<string, int>::iterator iter;
    for (iter = recipe.get_ingredients().begin(); iter != recipe.get_ingredients().end(); iter++) {
        int amount = iter->second * n;
        /*grocery_list�� ���� Ű���� ���� ��ᰡ �ִ� �� �˻�*/
        if (grocery_list.find(iter->first) != grocery_list.end()) {
            grocery_list[iter->first] += amount;
        }
        else {
            grocery_list.insert(make_pair(iter->first, amount));
        }
    }
}