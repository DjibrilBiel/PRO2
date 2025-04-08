#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;
    auto it = l.begin();
    int size = 0, n;

    string ins;
    while (cin >> ins) {
        if (ins == "push_front") {
            cin >> n;
            l.push_front(n);
            if (size == 0) it = l.begin();
            else if (size % 2 == 0) --it;
            ++size;
        } else if (ins == "push_back") {
            cin >> n;
            l.push_back(n);
            if (size == 0) it = l.begin();
            else if (size % 2 != 0) ++it;
            ++size;
        } else if (ins == "pop_front") {
            if (size == 0) cout << "error" << endl;
            else if (size == 1) {
                l.pop_front();
                --size;
                it = l.end();
            } else {
                if (size % 2 == 0) ++it;
                l.pop_front();
                --size;
            }
        } else if (ins == "pop_back") {
            if (size == 0) cout << "error" << endl;
            else if (size == 1) {
                l.pop_back();
                --size;
                it = l.end();
            } else {
                if (size % 2 != 0) --it;
                l.pop_back();
                --size;
            }
        } else {
            if (size % 2 != 0) cout << *it << endl;
            else cout << "error" << endl;
        }
    }
}