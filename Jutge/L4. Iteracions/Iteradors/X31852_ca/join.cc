#include <iostream>
#include <vector>
using namespace std;

string join(vector<string>::iterator begin, vector<string>::iterator end, string sep) {
    string s;
    for (vector<string>::iterator i = begin; i != end; ++i) {
        s += *i;
        if (i != end - 1) s += sep;
    }
    return s;
}