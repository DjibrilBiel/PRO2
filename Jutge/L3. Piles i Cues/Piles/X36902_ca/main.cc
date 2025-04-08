#include <iostream>
#include <stack>
using namespace std;

bool comp(char p, stack<char>& s) {
    if (s.size() == 0) return false;
    bool b = s.top() == p;
    s.pop();
    return b;
}

int main() {
    char c;
    stack<char> s;
    bool correctesa = true;
    int cont = 0;

    while (cin >> c and correctesa and c != '.') {
        if (c == '(' or c == '[') s.push(c);
        else if (c == ')') correctesa = comp('(', s);
        else correctesa = comp('[', s);
        ++cont;
    }

    if (not correctesa or s.size() > 0) cout << "Incorrecte " << cont;
    else cout << "Correcte";
    cout << endl;
}