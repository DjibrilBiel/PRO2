#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> mapa;

    char codi;
    string paraula;
    while (cin >> codi >> paraula) {
        map<string, int>::iterator it = mapa.find(paraula);
        if (it != mapa.end()) {
            if (codi == 'a') it -> second++;
            else cout << it -> second << endl;
        } else {
            if (codi == 'a') mapa.insert(it, make_pair(paraula, 1));
            else cout << 0 << endl;
        }
    }
}