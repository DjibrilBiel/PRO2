#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> stack;

    string string;
    while (cin >> string) {
        int i = 1;
        for (int j = 0; j < string.size(); ++j) {
            cout << string[j];
            if (string[j] == '(') {
                stack.push(i);
                cout << i;
                ++i;
            } else {
                cout << stack.top();
                stack.pop();
            }
        }
        cout << endl;
    }
}