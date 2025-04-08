#include <iostream>
#include <map>
#include <list>
using namespace std;

int main() {
    map<string, int> mapa;
    map<int, list<string> > mapa2;

    string nom;
    int num;
    while (cin >> nom >> num) {
        mapa[nom] = num;
        mapa2[num].push_back(nom);
    }

    for (map<string,int>::iterator it_map = mapa.begin(); it_map != mapa.end(); ++it_map) {
        cout << it_map->first;
        
        int res = -it_map->second;
        list<string> l = mapa2[res];
        for (list<string>::iterator it_list = l.begin(); it_list != l.end(); ++it_list) {
            if (it_map->first != *it_list) cout << ' ' << *it_list;
        }
        cout << endl;
    }
}