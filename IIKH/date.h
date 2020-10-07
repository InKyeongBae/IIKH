#pragma once
#include <map>;
#include <iostream>;

using namespace std;
class Date {

private:
    int year, month, day;
    bool anniversary = 0;
    map <string, int> grocery_list;

public:

    void set_date(int y, int m, int d, bool a, string g_name, int g_amt);

    int get_year() { return year; }
    int get_month() { return month; }
    int get_day() { return day; }
    bool get_anniversary() { return anniversary; }
    //컴파일 확인용 함수
    void show_date();

    Date(int y, int m, int d, bool a, string g_name, int g_amt) {
        year = y;
        month = m;
        day = d;
        anniversary = a;
        grocery_list.insert(make_pair(g_name, g_amt));
    };



};
