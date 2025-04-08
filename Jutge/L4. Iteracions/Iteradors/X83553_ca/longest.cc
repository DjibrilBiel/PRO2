#include <list>
#include <string>
using namespace std;

list<string>::const_iterator longest(const list<string>& text) {
    int len_max = 0;
    list<string>::const_iterator it = text.end();
    for (list<string>::const_iterator i = text.begin(); i != text.end(); ++i) {
        string s = *i;
        if (len_max < s.size()) {
            len_max = s.size();
            it = i;
        }
    }
    return it;
}