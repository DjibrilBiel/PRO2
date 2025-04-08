#include <iostream>
#include <stack>
using namespace std;

int main() {
    string line;
    while (cin >> line) {
        stack<char> s;
        int sum = 0;
        bool stop = false;

        int i = 0;
        while (i < line.size() and not stop) {
            if (line[i] == '(' or line[i] == '[') s.push(line[i]);
            else {
                stop = s.empty() or not ((s.top() == '(' and line[i] == ')') or (s.top() == '[' and line[i] == ']'));
                if (not stop) s.pop();
            }
            if (s.empty() and not stop) sum = i + 1;

            ++i;
        }

        cout << sum << endl;
    }
}