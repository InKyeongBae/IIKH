#include "date.h";

void Date::set_date(int y, int m, int d, bool a, string g_name, int g_amt) {
    year = y;
    month = m;
    day = d;
    anniversary = a;
    grocery_list.insert(make_pair(g_name, g_amt));
}

template <typename K, typename V>
void print_map(map<K, V>& m) {
    // 맵의 모든 원소들을 출력하기
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << " " << itr->second << endl;
    }
}

void Date::show_date() {
    cout << year << "년" << endl;
    cout << month << "월" << endl;
    cout << day << "일" << endl;
    cout << anniversary << "기념일 여부" << endl;
    print_map(grocery_list);
}

int main() {
    Date d1(2020, 10, 07, 0, "새우(마리)", 5);
    d1.show_date();
    Date d2(1010, 10, 03, 1, "꽃게(마리)", 10);
    d2.show_date();

    d2.set_date(2018, 07, 06, 0, "설탕", 20);
    d2.show_date();
}