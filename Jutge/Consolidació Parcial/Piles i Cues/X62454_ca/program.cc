#include <iostream>
#include <stack>
using namespace std;

int main() {
    string line;
    while (cin >> line) {
        stack<char> s;
        int sum = 0;

        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '(' or line[i] == '[') s.push(line[i]);
            else {
                if ((line[i] == ')' and s.top() == '[') or (line[i] == ']' and s.top() == '(')) ++sum;
                s.pop();
            }
        }

        cout << sum << endl;
    }
}