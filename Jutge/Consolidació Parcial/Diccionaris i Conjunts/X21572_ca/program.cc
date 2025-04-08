#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    map<string, int> m;
    set<string> red;

    string inst;
    while (cin >> inst) {
        if (inst == "TRANSACTION") {
            string client;
            int integer;
            cin >> client >> integer;

            m[client] += integer;

            if (integer < 0 and not red.count(client) and m[client] < 0) red.insert(client);
            else if (integer >= 0 and red.count(client) and m[client] >= 0) red.erase(client);
        } else if (inst == "NUMBERINRED") {
            cout << red.size() << endl;
        } else {
            if (not red.empty()) {
                auto it = red.begin();
                cout << *it;
                for (++it; it != red.end(); ++it) cout << ' ' << *it;
            }
            cout << endl;
        }
    }
}