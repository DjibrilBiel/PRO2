#include "evaluate.hh"

bool evaluate(const BinTree<string> t) {
    if (t.value() == "true") return true;
    if (t.value() == "false") return false;

    if (t.value() == "and") {
        if (not evaluate(t.left())) return false;
        return evaluate(t.right());
    } 
    if (t.value() == "or") {
        if (evaluate(t.left())) return true;
        return evaluate(t.right());
    } 
    return not evaluate(t.left());
}