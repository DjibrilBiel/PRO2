#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector< queue<string> > v(n);

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string client;
        while (ss >> client) v[i].push(client);
    }

    cout << "SORTIDES" << endl << "--------" << endl;

    string s;
    int m;
    while (cin >> s) {
        if (s == "SURT") {
            cin >> m;
            if (m > 0 and m <= n) if (v[m - 1].size() > 0) {
                cout << v[m - 1].front() << endl;
                v[m - 1].pop();
            }
        } else {
            string nom;
            cin >> nom >> m;
            if (m > 0 and m <= n) v[m - 1].push(nom);
        }
    }

    cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;

    for (int i = 0; i < n; ++i) {
        cout << "cua " << i + 1 << ':';
        while (v[i].size() > 0) {
            cout << ' ' << v[i].front();
            v[i].pop();
        }
        cout << endl;
    }
}