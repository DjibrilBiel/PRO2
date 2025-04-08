#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string, int> jugadors;
    string cognom;
    while (cin >> cognom and cognom != ".") jugadors[cognom];

    int n;
    cin >> n;

    vector< set<string> > activitats(n);
    for (int i = 0; i < n; ++i) {
        while (cin >> cognom and cognom != ".") activitats[i].insert(cognom);
    }
    
    for (int i = 0; i < n; ++i) {
        for (set<string>::iterator it = activitats[i].begin(); it != activitats[i].end(); ++it) {
            map<string,int>::iterator x = jugadors.find(*it);
            if (x != jugadors.end()) ++(x->second);
        }
    }
    
    cout << "Totes les activitats:";
    for (map<string,int>::iterator it = jugadors.begin(); it != jugadors.end(); ++it) if (it->second == n) cout << ' ' << it->first;
    cout << endl << "Cap activitat:";
    for (map<string,int>::iterator it = jugadors.begin(); it != jugadors.end(); ++it) if (it->second == 0) cout << ' ' << it->first;
    cout << endl;
}