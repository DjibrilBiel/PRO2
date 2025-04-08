#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    int temp;
    for (int i = 0; i < n / 2; ++i) {
        cin >> temp;
        s.push(temp);
    }

    if (n % 2 == 1) cin >> temp;

    bool palindrom = true;
    int i = 0;
    while (i < n / 2 and palindrom) {
        cin >> temp;
        palindrom = (s.top() == temp);
        s.pop();
        ++i;
    }

    if (palindrom) cout << "SI";
    else cout << "NO";
    cout << endl;
}