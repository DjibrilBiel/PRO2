#include <iostream>
#include <utility>
using namespace std;

pair<int,int> divmod(int a, int b) {
   return make_pair(a / b, a % b);
}

int main() {
   int a, b;
   cin >> a >> b;
   pair<int, int> p = divmod(a, b);
   cout << p.first << ' ' << p.second << endl;
}
