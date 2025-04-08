#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    map<int, int> n;
    
    string inst;
    while (cin >> inst) {
        if (inst == "ADD") {
            string name;
            int numcoins;
            cin >> name >> numcoins;
            m[name] = numcoins;
            ++n[numcoins];
        } else if (inst == "DELETE") {
            string name;
            cin >> name;
            --n[m[name]];
            m.erase(name);
        } else {
            int numcoins;
            cin >> numcoins;
            cout << n[numcoins] << endl;
        }
    }
}