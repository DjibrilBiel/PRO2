#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Access {
    int time;
    string path;
};

int main() {
    map<string, vector<Access>> log;
    map<string, set<string>> bots;

    string ip, path;
    int time;

    while (cin >> ip >> path >> time) log[ip].push_back({time, path});

    for (auto it = log.begin(); it != log.end(); ++it) {
        const string currIP = it->first;
        const vector<Access> &accesses = it->second;
        int n = accesses.size();
        if (n >= 20) {
            bool isBot = false;

            for (int i = 0; i <= n - 20 and not isBot; ++i) {
                bool validWindow = true;
                for (int j = i; j < i + 19 and validWindow; ++j) validWindow = not (accesses[j+1].time - accesses[j].time >= 100);
                isBot = validWindow;
            }

            if (isBot) {
                for (auto acc = accesses.begin(); acc != accesses.end(); ++acc) bots[currIP].insert(acc->path);
            }
        }
    }

    if (bots.empty()) cout << "No bots" << endl;
    else {
        for (auto i = bots.begin(); i != bots.end(); ++i) {
            cout << i->first;

            auto x = i->second;
            for (auto j = x.begin(); j != x.end(); ++j) cout << ' ' << *j;
            cout << endl;
        }
    }
}