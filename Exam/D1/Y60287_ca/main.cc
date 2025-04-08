#include "vstack.hh"
#include "html_elem.hh"

#include <iostream>
using namespace std;

int main() {
    VStack vs;
    
    string s;
    while (cin >> s) {
        if (is_tag(s)) {
            cout << s << " ";
            if (not is_close_tag(s)) vs.push(tag_name(s));
            else vs.pop();
        } else {
            if (not vs.empty() and vs.top(0) == "script") {
                if (vs.size() >= 3 and vs.top(-1) == "head" and vs.top(-2) == "html") cout << s << " ";
            } else cout << s << " ";
        }
    }
}