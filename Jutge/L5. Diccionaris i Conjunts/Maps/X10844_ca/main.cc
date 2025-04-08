#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    string s;
    int n;
    while (cin >> s >> n) m[s] += n;

    for (map<string,int>::iterator it = m.begin(); it != m.end(); ++it) cout << it -> first << ' ' << it -> second << endl;
}