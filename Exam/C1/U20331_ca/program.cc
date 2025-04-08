#include <iostream>
#include <set>
#include <map>
#include <utility>
using namespace std;

int main() {
    map<pair<int, string>, set<string>> reg;

    int year;
    string name, city;
    while (cin >> name >> year >> city) reg[make_pair(year, city)].insert(name);

    for (auto it_reg = reg.begin(); it_reg != reg.end(); ++it_reg) {
        auto list_names = it_reg->second;
        if (list_names.size() > 1) {
            cout << it_reg->first.first << ' ' << it_reg->first.second << ':';
            for (auto it_names = list_names.begin(); it_names != list_names.end(); ++it_names) cout << ' ' << *it_names;
            cout << endl;
        }
    }
}