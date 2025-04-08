#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    map<string, string> dic;

    string line;
    while (getline(cin, line) and not line.empty()) {
        stringstream ss(line);
        string p1, p2;
        ss >> p1 >> p2;
        dic[p1] = p2;
    }
    
    string word;
    while (cin >> word) {
        map<string, string>::iterator it = dic.find(word);
        if (it != dic.end()) cout << it -> second << endl;
        else cout << "<not found>" << endl;
    }
}
