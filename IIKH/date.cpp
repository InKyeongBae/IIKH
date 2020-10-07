#include "date.h";

void Date::set_date(int y, int m, int d, string a, string g_name, int g_amt) {
    year = y;
    month = m;
    day = d;
    anniversary = a;
    grocery_list.insert(make_pair(g_name, g_amt));
}

template <typename K, typename V>
void print_map(map<K, V>& m) {
    // ���� ��� ���ҵ��� ����ϱ�
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << " " << itr->second << endl;
    }
}

void Date::show_date() {
    cout << year << "��" << endl;
    cout << month << "��" << endl;
    cout << day << "��" << endl;
    cout << anniversary << " �����" << endl;
    print_map(grocery_list);
}

/*
int main() {
    Date d1(2020, 10, 07, "", "����(����)", 5);
    d1.show_date();
    Date d2(1010, 10, 03, "���ǻ���", "�ɰ�(����)", 10);
    d2.show_date();
    cout << "good";
    d2.set_date(2018, 07, 06, "", "����", 20);
    d2.show_date();
}
*/