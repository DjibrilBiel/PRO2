#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void inserta_don(list<string>& texto);

list<string> read_text() {
    list<string> text;
    string       word;
    while (cin >> word) {
        text.push_back(word);
    }
    return text;
}

void show_text(const list<string>& text) {
    auto it = text.begin();
    if (it != text.end()) {
        cout << *it;
        for (it++; it != text.end(); it++) {
            cout << " " << *it;
        }
    }
    cout << endl;
}

int main() {
    list<string> text = read_text();
    inserta_don(text);
    show_text(text);
    return 0;
}
