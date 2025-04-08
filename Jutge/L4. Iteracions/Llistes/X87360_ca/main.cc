#include <iostream>
#include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos) {
    list<int>::iterator u = uno.begin();
    list<int>::const_iterator d = dos.begin();
    while (u != uno.end() and d != dos.end()) {
        if (*u < *d) u = uno.erase(u);
        else if (*u > *d) ++d;
        else {
            ++u;
            ++d;
        }
    }
    while (u != uno.end()) u = uno.erase(u);
}