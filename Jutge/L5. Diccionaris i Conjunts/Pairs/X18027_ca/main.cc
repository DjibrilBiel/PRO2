
#include <iostream>
#include <map>
#include <list>
using namespace std;

list< pair<string, int> > all_pairs(map<string, int>& M) {
   list< pair<string, int> > l;
   
   map<string, int>::iterator it = M.begin();
   while (it != M.end()) {
      l.push_back(*it);
      ++it;
   }
   return l;
}

int main() {
   string s;
   int n;
   map<string, int> M;
   while (cin >> s >> n) {
      M[s] = n;
   }
   list< pair<string, int> > L = all_pairs(M);
   list< pair<string, int> >::iterator it = L.begin();
   for (; it != L.end(); it++) {
      cout << it->first << ' ' << it->second << endl;
   }
}
