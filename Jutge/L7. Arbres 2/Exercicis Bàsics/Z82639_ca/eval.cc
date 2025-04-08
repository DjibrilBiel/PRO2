#include "eval.hh"
using namespace pro2;
#include <vector>
using namespace std;

bool evaluate(Tree<string> t) {
    if (t.value() == "0") return false;
    if (t.value() == "1") return true;

    vector<bool> eval(t.num_children());
    for (int i = 0; i < t.num_children(); ++i) eval[i] = evaluate(t.child(i));

    if (t.value() == "not") return not eval[0];
    if (t.value() == "or") {
        for (int i = 0; i < t.num_children(); ++i) if (eval[i] == true) return true;
        return false;
    }
    for (int i = 0; i < t.num_children(); ++i) if (eval[i] == false) return false;
    return true;
}