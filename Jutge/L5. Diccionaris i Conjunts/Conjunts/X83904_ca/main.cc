#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    set<string> cognom;
    map<string, int> activitat;
    string s;
    while (cin >> s and s != ".") {
        cognom.insert(s);
        activitat[s] = 0;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        set<string> counted;
        while (cin >> s and s != ".") {
            if (cognom.count(s) and not counted.count(s)) {
                ++activitat[s];
                counted.insert(s);
            }
        }
    }

    cout << "Totes les activitats:";
    for (set<string>::iterator it = cognom.begin(); it != cognom.end(); ++it){
        if (activitat[*it] == n) cout << ' ' << *it;
    }
    cout << endl << "Cap activitat:";
    for (set<string>::iterator it = cognom.begin(); it != cognom.end(); ++it) if (activitat[*it] == 0) cout << ' ' << *it;
    cout << endl;
}