
#include <iostream>
#include <list>
using namespace std;

list<string>::const_iterator longest(const list<string>& text);

int main() {
    string       word;
    list<string> text;
    while (cin >> word) {
        text.push_back(word);
    }
    auto i = longest(text);
    if (i != text.end()) {
        cout << *i << endl;
    } else {
        cout << "<empty sequence>" << endl;
    }
    return 0;
}
