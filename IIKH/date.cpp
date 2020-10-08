#include "plan.h";

void Date::set_date(string d, string a, string g_name, int g_amt) {
    full_date = d;
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
    cout << full_date << " 8자리 date" << endl;
    cout << anniversary << " 기념일" << endl;
    print_map(grocery_list);
}