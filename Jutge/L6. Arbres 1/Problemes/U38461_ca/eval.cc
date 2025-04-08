#include "eval.hh"
#include "util.hh"
using namespace pro2;
using namespace std;

int evaluate(BinTree<string> t) {
    int n, ln = 0, rn = 0;
    if (not t.left().empty()) ln = evaluate(t.left());
    if (not t.right().empty()) rn = evaluate(t.right());
    
    if (is_number(t.value())) {
        n = string_to_int(t.value());
        return n;
    }
    
    if (t.value() == "+") return ln + rn;
    if (t.value() == "-") return ln - rn;
    return ln * rn;
}