#pragma once
#include <map>;
#include <iostream>;

using namespace std;
class Date {

private:
    string full_date;
    string anniversary = "";
    map <string, int> grocery_list;

public:

    void set_date(string d, string a, string g_name, int g_amt);

    string get_full_date() { return full_date; }
    string get_anniversary() { return anniversary; }
    //컴파일 확인용 함수
    void show_date();

    Date(string d, string a, string g_name, int g_amt) {
        full_date = d;
        anniversary = a;
        grocery_list.insert(make_pair(g_name, g_amt));
    };



};
