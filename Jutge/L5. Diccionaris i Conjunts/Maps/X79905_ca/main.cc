#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> mapa;

    char codi;
    string paraula;
    while (cin >> codi >> paraula) {
        if (codi == 'a') ++mapa[paraula];
        else if (codi == 'e') {
            if (mapa[paraula] > 0) --mapa[paraula];
        } else cout << mapa[paraula] << endl;
    }
}